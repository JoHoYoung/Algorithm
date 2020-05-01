#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>

#define MAXN 31
#define INF 98765432
#define MAX 1000000

using namespace std;
using ll = long long;
using P = pair<int, int>;

int R, C;

char board[1001][1001];
int f[1001][1001];
bool visited[1001][1001];

vector<P> F;
P J;

typedef struct unit {
    P pos;
    int depth;
};

int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};

void BFS() {
  queue<unit> Q;
  for (int i = 0; i < F.size(); i++) {
    f[F[i].first][F[i].second] = 0;
    Q.push({{F[i].first, F[i].second}, 0});
  }
  while (!Q.empty()) {
    unit cur = Q.front();
    Q.pop();
    int curI = cur.pos.first;
    int curJ = cur.pos.second;
    int curD = cur.depth;
    for (int d = 0; d < 4; d++) {
      int ni = curI + Di[d];
      int nj = curJ + Dj[d];
      if (ni < 0 || nj < 0 || ni > R - 1 || nj > C - 1 || board[ni][nj] == '#' || f[ni][nj] != -1) continue;
      f[ni][nj] = curD + 1;
      Q.push({{ni, nj}, curD + 1});
    }
  }
}

int tBFS() {
  queue<unit> Q;
  visited[J.first][J.second] = true;
  Q.push({{J.first, J.second}, 0});

  while (!Q.empty()) {
    unit cur = Q.front();
    Q.pop();
    int curI = cur.pos.first;
    int curJ = cur.pos.second;
    int curD = cur.depth;
    if (curI == 0 || curI == R - 1 || curJ == 0 || curJ == C - 1) return curD;
    for (int d = 0; d < 4; d++) {
      int ni = curI + Di[d];
      int nj = curJ + Dj[d];
      if (ni < 0 || nj < 0 || ni > R - 1 || nj > C - 1 || board[ni][nj] == '#' || (f[ni][nj] <= curD + 1 && f[ni][nj] != -1)) continue;
      visited[ni][nj] = true;
      Q.push({{ni, nj}, curD + 1});
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> R >> C;
  memset(f, -1, sizeof(f));
  memset(visited, false, sizeof(visited));

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'F') F.push_back({i, j});
      if (board[i][j] == 'J') J = {i, j};
    }
  }

  BFS();
  int ans = tBFS();
  if(ans == -1)cout<<"IMPOSSIBLE";
  else cout<<ans+1;
  return 0;
}

