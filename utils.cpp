template<class T>
T gcd(T a, T b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

struct Point {
  int x;
  int y;
}

void printMap(T m) {
    for(const auto& i : m) {
      cout << i.first << " " << i.second << " ";
    }
    cout << endl;
}

template<typename T>
void printList(T l) {
    for(const auto& i : l) {
      cout << i << " ";
    }
    cout << endl;
}

