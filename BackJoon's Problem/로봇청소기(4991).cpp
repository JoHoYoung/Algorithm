#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>

#define INF 987654321
#define MAX 1000000
using namespace std;
using ll = long long;
using P = pair<int, int>;

int N, M;

int visited[1 << 10][21][21];
P S;
int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};

char board[21][21];
int all;

map<P, int> m;

typedef struct unit {
    int i, j, depth, trace;
};

int tsp() {

  queue<unit> Q;
  Q.push({S.first, S.second, 0, 0});
  visited[0][S.first][S.second] = 0;
  while (!Q.empty()) {

    unit cur = Q.front();
    Q.pop();

    int curI = cur.i;
    int curJ = cur.j;
    int curD = cur.depth;
    int curTrace = cur.trace;
    if (curTrace == all) return curD;
    for (int d = 0; d < 4; d++) {
      int ni = curI + Di[d];
      int nj = curJ + Dj[d];
      if (ni < 0 || ni > N - 1 || nj < 0 || nj > M - 1 || board[ni][nj] == 'x') continue;
      int nTrace = curTrace;
      int nD = curD + 1;

      if (board[ni][nj] == '*') {
        int dirtNum = m[{ni, nj}];
        nTrace = (nTrace | (1 << dirtNum));
      }

      if (visited[nTrace][ni][nj] != -1) continue;
      visited[nTrace][ni][nj] = nD;
      Q.push({ni, nj, nD, nTrace});
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  while (1) {
    m.clear();
    cin >> M >> N;
    if (M == 0 && N == 0) break;
    memset(visited, -1, sizeof(visited));
    int no = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        cin >> board[i][j];
        if (board[i][j] == 'o') S = {i, j};
        if (board[i][j] == '*') m[{i, j}] = no++;
      }
    }
    all = (1 << no) - 1;
    cout << tsp() << '\n';
  }

  return 0;
}

