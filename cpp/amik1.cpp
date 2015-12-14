#include <iostream>
#include <mutex>
#include <set>

using namespace std;

class ID //### Name can be improved, conflicts with idx can be IdManager or IdPool
{
    int idx;
    set<int> freed;
    mutex mutex_;
    public :
    ID()
    {
        idx = 0;
    }

    int assign()
    {
        std::lock_guard<std::mutex> lock(mutex_); // ### lock to handle cuncurrency

        if(freed.size() > 0) // if present in free pool
        {
            int val = *(freed.begin());
            // ### O(logn) can be improve that??? use unordered_map for O(1)
            freed.erase(freed.begin());
            return val;
        }
        else return idx++;
    }

    void release(int n)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        if(n>=idx || freed.count(n) > 0)
        {
          return; // ### optionally throw std::invalid_argument("id is not valid");
        }
        freed.insert(n); // ### O(logn)
        cout<<"Freed "<<n<<"\n";
    }
};

int main()
{
    ID id;
    for(int i=0;i<5;i++)
    cout<<id.assign()<<"\n";

    id.release(3);

    for(int i=0;i<5;i++)
    cout<<id.assign()<<"\n";

}
