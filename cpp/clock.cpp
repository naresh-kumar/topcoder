#include <iostream>
#include <chrono>
#include <unordered_map>

using namespace std;

double getRealTime() {
  return std::chrono::duration_cast<std::chrono::duration<int64_t, std::ratio<1l, 1000000l> > >(
      std::chrono::system_clock::now().time_since_epoch()).count() / 1000000.0;
}

int64_t getMonotonicTime() {
  return std::chrono::duration_cast<std::chrono::milliseconds>(
      std::chrono::steady_clock::now().time_since_epoch()).count();
}

double getCurrentTime() {
  return std::chrono::duration<double>(
      std::chrono::system_clock::now().time_since_epoch())
    .count();
}

int main() {
  cout << "real time:      " << std::to_string(getRealTime()) << endl;
  cout << "monotonic time: " << std::to_string(getMonotonicTime()) << endl;
  cout << "current time:   " << std::to_string(getCurrentTime()) << endl;
  unordered_map<int, int> kv;
  kv[4] = 5;
  kv[4] = 6;
  cout << kv.size() << endl;
  cout << kv[4] << endl;
  cout << sizeof(bool) << endl;
  return 0;
}
