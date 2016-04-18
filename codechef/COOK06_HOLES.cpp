// https://www.codechef.com/COOK06/status/HOLES,nemausus
// https://www.codechef.com/viewplaintext/430402
#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <cstdlib>
//#include <ext/hash_map>

using namespace std;
int holes[26] = {1,2,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0};
int main() {
  int n;
  scanf("%d", &n);
  while(n--) {
    char* text = new char[100];
    scanf("%s", text);
    int count = 0;
    while(*text) {
      count += holes[*text - 'A'];
      ++text;
    }
    printf("%d\n", count);
  }
  return 0;
}
