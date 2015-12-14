#include <iostream>
using namespace std;

// ### generally its a good practice to make a seperate class and defin API
class LogCounter {
  public:
    getLogCount() {
    }

    addNewHit(int64_t timestamp) {
    }
}

int main()
{
    int N = 5; //### you can pass this in ctor of LogCounter to make it configurable
    int * arr = new int[N];
    for(int i=0;i<N;i++)arr[i] = 0; // ### you are an experienced engineer so you
    // are supposed to follow good coding practices like proper space and formatting
    // etc
    // for (int i = 0; i < N; ++i) {
    //   arr[i] = 0;
    // }

    int prev_slot = 0;
    while(1)
    {
        //receive hit with say time t;
        int t = rand()%967; // this is random, but in reality times would be sequential
        int slot = t%5;
        // ### Issues with this algo
        // 1) you are assuming that time is in minute
        // 2) you will give wrong answer if t0 = 6 and t1 = 11  it should be
        // differnet slot. basically you are assuming that timstamps are continuous
        // 3) same as last one if you don't receive any hit in a minute then that
        // would no be cleared
        if(slot != prev_slot) //new minute
        {
            arr[slot] = 0;//clear it
        }
        prev_slot = slot;
        arr[slot]++;
    }
}
