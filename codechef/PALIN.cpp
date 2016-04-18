// https://www.codechef.com/status/PALIN,nemausus
// https://www.codechef.com/viewplaintext/429572
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

bool ispalin(char* n) {
  int len = strlen(n);
  for(int i = 0; i < len/2; ++i)
    if(n[i] != n[len-i-1]) return false;
  return true;
}

int main() {
  int test_cases;
  cin >> test_cases;
  while(test_cases--) {
    char n[1000001];
    scanf("%s", n);
    int len = strlen(n);
    if(atoi(n) == 0) {
      cout << 1 <<endl;
      continue;
    }
    if(ispalin(n)) {
      int j = 1;
      while(n[len-j] == '9') {
        n[len-j] = '0';
        if(len-j == 0) {
          n[j+1] = '\0';
          while(j > 0) {
            n[j] = n[j-1];
            j--;
          }
          j = len++;
        }
        j++;
      }
      n[len-j]++;
    }
    for(int i = 0; i < len/2; ++i) {
      if(n[len-i-1] <= n[i]) n[len-i-1] = n[i];
      else {
        int j = 0;
        while(n[len-i-2-j] == '9') {
          n[len-i-2-j] = '0';
          j++;
        }
        n[len-i-2-j]++;
        n[len-i-1] = n[i];
      }
    }
    cout << n << endl;
  }
  return 0;
}
