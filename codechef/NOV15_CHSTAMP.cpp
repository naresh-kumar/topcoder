// https://www.codechef.com/NOV15/status/CHSTAMP,nemausus
// https://www.codechef.com/viewplaintext/8766006
//author Naresh
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define rep(i, a, b) for(int i=(a); i<(b); ++i)
#define iter(i,v) for(auto &i : (v))

typedef long long ll;

// fast input
#define gc getchar_unlocked
template<class T> inline T readnum() { int i=gc(),f=1; for(;i<'0'||i>'9';i=gc()) if(i=='-') { f=-1;i=gc();break; } T ret = 0; for(;i>='0'&&i<='9';i=gc()) { ret = ret*10 + (i-'0'); } return f*ret; }
inline int si() { return readnum<int>(); }

template<class T> inline void println(T t) { cout << t << endl; }
template<class T> inline void prints(T t, string s = " ") { cout << t << s; }
template<class T> inline void printlist(T *l, int n) { rep(i,0,n) prints(*(l+i)); cout << endl; }

// general utils
template<class T> inline void setmax(T &a, T b) { if(b > a) a = b; }

const int MAX = 50001;
int fre[MAX];
int answer[MAX];
int tt[MAX];

struct Edge {
  int t;
  int id;
};

struct Node {
  int id;
  vector<Edge> edges;
};

int dfs(vector<Node>& graph, int id, int t) {
  if (tt[id] <= t) return max(id, answer[id]);
  tt[id] = t;
  int m = id;
  iter(e, graph[id].edges) {
    if (e.t >= t) {
      setmax(m, dfs(graph, e.id, e.t));
    }
  }
  answer[id] = max(answer[id], m);
  return answer[id];
}

int main() {
  //freopen("in.txt", "r", stdin);
  int tests = si();
  while(tests--) {
    memset(fre, 0, sizeof(fre));
    memset(answer, 0, sizeof(answer));
    rep(i, 1, MAX) tt[i] = MAX+1;
    int n = si();
    int m = si();
    rep(i, 0, n) fre[si()]++;
    vector<Node> graph(MAX);
    rep(i, 0, m) {
      int t = si();
      int a = si();
      int b = si();
      Edge bp = {t, b};
      Edge ap = {t, a};
      graph[a].edges.push_back(bp);
      graph[b].edges.push_back(ap);
    }
    ll ans = 0;
    rep(i, 1, MAX) {
      if (fre[i]) {
        ans += fre[i] * (ll)dfs(graph, i, 1);
      }
    }
    println(ans);
  }
  return 0;
}

