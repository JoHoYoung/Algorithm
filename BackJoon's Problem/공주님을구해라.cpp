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

int board[100][100];
int visited[100][100];
int N, M, T;

int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};

int min(int a, int b) {
  if (a > b) return b;
  return a;
}

void bfs() {

  queue<P> Q;
  Q.push({0, 0});
  visited[0][0] = 1;
  while (!Q.empty()) {
    P cur = Q.front();
    Q.pop();
    for (int d = 0; d < 4; d++) {
      int ni = cur.first + Di[d];
      int nj = cur.second + Dj[d];
      if (ni < 0 || ni > N - 1 || nj < 0 || nj > M - 1 || board[ni][nj] == 1) continue;
      if (!visited[ni][nj] || visited[ni][nj] == INF) {
        visited[ni][nj] = visited[cur.first][cur.second] + 1;
        Q.push({ni, nj});
      }
    }
  }
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> T;

  P S;
  memset(visited, 0, sizeof(visited));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
      if (board[i][j] == 2) S = {i, j};
    }
  }
  bfs();

  if (visited[N - 1][M - 1] == 0) {
    if (visited[S.first][S.second] == 0) {
      cout << "Fail";
    } else {
      int dst = visited[S.first][S.second] - 1 + (N - 1 - S.first) + (M - 1 - S.second);
      if (dst > T) cout << "Fail";
      else cout << dst;
    }
  } else {
    if (visited[S.first][S.second] == 0) {
      if (visited[N - 1][M - 1] - 1 > T) cout << "Fail";
      else cout << visited[N - 1][M - 1] - 1;
    } else {
      int dst = visited[S.first][S.second] - 1 + (N - 1 - S.first) + (M - 1 - S.second);
      dst = min(visited[N - 1][M - 1] - 1, dst);
      if (dst > T) cout << "Fail";
      else cout << dst;
    }
  }
  return 0;
}