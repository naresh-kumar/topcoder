// https://www.codechef.com/NOV10/status/CIRCUITS,nemausus
// https://www.codechef.com/viewplaintext/372667
#include <stdio.h>

#define LAC 1000000

int main() {
  int test_cases;
  scanf("%d", &test_cases);
  
  while(test_cases--) {
    int n;
    scanf("%d", &n);
    int array[300];
    double result[100];
    int count = 0;
    int i;
    for (i = 0; i < n; ++i) {
      scanf("%d", &array[count++]);
      if(array[count-1] != 0) {
        scanf("%d", &array[count++]);
        array[count-1] -= 1;
        scanf("%d", &array[count++]);
        array[count-1] -= 1;
      }
    }

    int min = 0, max = 1000000;
    int mid;
    while( max > min+1) {
      mid = (min + max) / 2;
      //cout << mid;
      double prob = (double) mid / LAC;
      //cout << prob <<endl;
      int count = 0;
      int i = 0;
      for(i = 0; i < n; ++i) {
        if(array[count] == 0) {
          result[i] = prob;
          ++count;
        }
        else if(array[count] == 1) {
          double p1 = result[array[count+1]];
          double p2 = result[array[count+2]];
          result[i] = p1 + p2 - p1*p2;
          count += 3;
        }
        else if(array[count] == 2) {
          double p1 = result[array[count+1]];
          double p2 = result[array[count+2]];
          result[i] = p1*p2;
          count += 3;
        }
        else
          printf("this line should never be printed\n");
      }
      if(result[n-1] == .5) {
        min = max = mid;
        break;
      }
      else if(result[n-1] < (double).5) min = mid;
      else max = mid;
      //else min = mid;
    }
    printf("%.5f\n", (double) (min+max) / (2*LAC));
  }
  return 0;
}

