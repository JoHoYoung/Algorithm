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
int W, H;
char board[100][100];
int visited[100][100];
// 방향이 달라지면 거울 +1;
// 반대방향은 불가능
int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};
P S, E;

int re = INF;

int min(int a, int b) {
  if (a > b) return b;
  return a;
}

typedef struct unit {
    int i, j, d, nM;
};

queue<unit> Q;

void bfs(P S) {

  Q.push({S.first, S.second, -1, 0});
  while (!Q.empty()) {
    unit cur = Q.front();
    Q.pop();
    if (cur.i == E.first && cur.j == E.second) {
      re = min(re, cur.nM);
    }
    for (int d = 0; d < 4; d++) {
      int ni = cur.i + Di[d];
      int nj = cur.j + Dj[d];
      if (ni < 0 || ni > H - 1 || nj < 0 || nj > W - 1 || board[ni][nj] == '*') continue;

      if(visited[ni][nj] >= cur.nM || visited[ni][nj] == 0){
        visited[ni][nj] = cur.nM;
        if (d == cur.d || cur.d == -1) Q.push({ni, nj, d, cur.nM});
        else Q.push({ni, nj, d, cur.nM + 1});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> W >> H;
  vector<P> el;
  memset(visited, false, sizeof(visited));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'C') el.push_back({i, j});
    }
  }
  S = el[0];
  E = el[1];

  //dfs(S.first, S.second, -1, 0);
  bfs(S);
  cout << re;
  return 0;
}