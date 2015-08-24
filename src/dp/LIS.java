package dp;

// longest increasing sub-sequence
public class LIS {
  public int[] getLIS(int[] array) {
    int len = array.length;
    int[] lis = new int[len];
    int[] prev = new int[len];
    int[] m = new int[len];

    int ans = 0;
    int lastIndex = -1;
    for (int i = 0; i < len; ++i) {
      // n2 solution
      int max = 0;
      int index = -1;
      for (int j = 0; j < i; ++j) {
        if (array[j] < array[i]) {
          if (max < lis[j]) {
            max = lis[j];
            index = j;
          }
        }
      }
      lis[i] = max + 1;
      prev[i] = index;
      if (ans < lis[i]) {
        ans = lis[i];
        lastIndex = i;
      }

      // nlogn solution
      int low = 0;
      int high = i - 1;

      while (low < high) {
        int mid = (low + high) / 2;
        if (array[m[mid]] < array[i]) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      }

      if (array[m[low]] > array[i]) {
        m[low] = i;
      }

      lis[i] = low + 1;

    }

    int[] seq = new int[ans];

    for (int i = ans - 1; i >= 0; --i) {
      seq[i] = array[lastIndex];
      lastIndex = prev[lastIndex];
    }
    return seq;
  }
}
