#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 987654321;
int N, p;
string s;
int board[17][17];

int visited[1 << 18][17];


int min(int a, int b) {
  if (a > b) return b;
  return a;
}

int countSetBits(int n) {
  int count = 0;
  while (n) {
    count += n & 1;
    n >>= 1;
  }
  return count;
}


int DFS(int trace, int cur) {

  //cout<<"FROM "<<cur<<endl;
  if (countSetBits(trace) >= p) return 0;

  int &ref = visited[trace][cur];

  if (ref != -1) return ref;
  ref = INF;

  for (int v = 0; v < N; v++) {
    // 켜져있으면 생략
    if (!(trace & (1 << v))) {
      int nTrace = trace | (1 << v);
      for (int j = 0; j < N; j++) {
        if ((nTrace & (1 << j))){
          ref = min(ref, board[cur][v] + DFS(nTrace, j));
        }
      }
    }
    // 켜고

  }
  return ref;
}


int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> board[i][j];
  cin >> s;
  int initTrace = 0;

  vector<int> S;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'N') continue;
    S.push_back(i);
    initTrace |= (1 << i);
  }
  cin >> p;
  memset(visited, -1, sizeof(visited));

  int ans = INF;

  if (p == 0) {
    cout << 0;
    return 0;
  }
  else
    for (int i = 0; i < S.size(); i++)
      ans = min(ans, DFS(initTrace, S[i]));
  if (ans == INF) cout << -1;
  else cout << ans;
  return 0;
}
