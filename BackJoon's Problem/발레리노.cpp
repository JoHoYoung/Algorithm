#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>

#define MAXN 31
#define INF 987654321
#define MAX 1000000
using namespace std;
using ll = long long;
using P = pair<int, int>;

int Di[8] = {-2, -1, +1, +2, +2, +1, -1, -2};
int Dj[8] = {-1, -2, -2, -1, +1, +2, +2, +1};
int N, M;

int board[31][31];
int gr[31][31][31][31];
int dst[31][31];
ll cnt[31][31];
P S, E;
queue<P> Q;

void sol() {

  memset(gr, 0, sizeof(gr));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] != 0) continue;

      gr[i][j][i][j] = 1;

      Q.push({i, j});
      while (!Q.empty()) {
        int curI = Q.front().first;
        int curJ = Q.front().second;
        Q.pop();
        for (int d = 0; d < 8; d++) {
          int ni = curI + Di[d];
          int nj = curJ + Dj[d];
          if (ni < 0 || ni > N - 1 || nj < 0 || nj > M - 1) continue;
          if (gr[i][j][ni][nj] != 0) continue;
          if (board[ni][nj] != 1) continue;
          gr[i][j][ni][nj] = 1;
          Q.push({ni, nj});
        }
      }

      for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
          if (gr[i][j][x][y] != 1) continue;

          for (int d = 0; d < 8; d++) {
            int ni = x + Di[d];
            int nj = y + Dj[d];
            if (ni < 0 || ni > N - 1 || nj < 0 || nj > M - 1) continue;
            if (board[ni][nj] != 0 || gr[i][j][ni][nj] != 0) continue;
            gr[i][j][ni][nj] = 2;
          }
        }
      }
    }
  }

  memset(dst, -1, sizeof(dst));
  dst[S.first][S.second] = 0;
  cnt[S.first][S.second] = 1;
  Q.push(make_pair(S.first, S.second));

  while (!Q.empty()) {

    int curI = Q.front().first;
    int curJ = Q.front().second;
    Q.pop();

    for (int ni = 0; ni < N; ni++) {
      for (int nj = 0; nj < M; nj++) {
        if (gr[curI][curJ][ni][nj] == 2) {
          if (dst[ni][nj] == -1) {
            dst[ni][nj] = dst[curI][curJ] + 1;
            cnt[ni][nj] = cnt[curI][curJ];
            Q.push({ni, nj});
          } else if (dst[ni][nj] == dst[curI][curJ] + 1) {
            cnt[ni][nj] += cnt[curI][curJ];
          }
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
      if (board[i][j] == 3) {
        board[i][j] = 0;
        S = {i, j};
      }
      if (board[i][j] == 4) {
        board[i][j] = 0;
        E = {i, j};
      }
    }
  }
  sol();
  if (dst[E.first][E.second] == -1) cout << -1 << endl;
  else cout << dst[E.first][E.second] - 1 << endl << cnt[E.first][E.second] << endl;

  return 0;
}

