// Sample input 3, in CPP.

#include <cassert>

long long GetLength() {
  return 10LL;
}

char GetScrollOne(long long i) {
  switch ((int)i) {
    case 0: return 'D';
    case 1: return 'B';
    case 2: return 'B';
    case 3: return 'A';
    case 4: return 'A';
    case 5: return 'A';
    case 6: return 'A';
    case 7: return 'A';
    case 8: return 'A';
    case 9: return 'C';
    default: assert(0);
  }
}

char GetScrollTwo(long long i) {
  switch ((int)i) {
    case 0: return 'C';
    case 1: return 'B';
    case 2: return 'B';
    case 3: return 'B';
    case 4: return 'B';
    case 5: return 'B';
    case 6: return 'B';
    case 7: return 'B';
    case 8: return 'A';
    case 9: return 'D';
    default: assert(0);
  }
}
