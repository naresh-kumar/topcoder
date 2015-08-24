#include <iostream>
#include <chrono>
#include <unordered_map>

using namespace std;

int64_t getRealTime() {
  return std::chrono::duration_cast<std::chrono::milliseconds>(
      std::chrono::system_clock::now().time_since_epoch()).count();
}

int64_t getMonotonicTime() {
  return std::chrono::duration_cast<std::chrono::milliseconds>(
      std::chrono::steady_clock::now().time_since_epoch()).count();
}

double getCurrentTime() {
  return static_cast<std::chrono::duration<double> >(
      std::chrono::system_clock::now().time_since_epoch())
    .count();
}

int main() {
  cout << "real time:      " << std::to_string(getRealTime()/1000.0) << endl;
  cout << "monotonic time: " << std::to_string(getMonotonicTime()) << endl;
  cout << "current time:   " << std::to_string(getCurrentTime()) << endl;
  unordered_map<int, int> kv;
  kv[4] = 5;
  kv[4] = 6;
  cout << kv.size() << endl;
  cout << kv[4] << endl;
  return 0;
}
