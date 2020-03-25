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

int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};

int transD(int orign) {
  switch (orign) {
    case 1:
      return 1;
    case 2:
      return 3;
    case 3:
      return 2;
    case 4:
      return 0;
  }
}
// Trun : 90도씩 회전명령
// Go : 1,2,3 만큼 해당방향으로 GO

typedef struct ROBOT {
    int i, j, d;
};

typedef struct unit {
    int i, j, d, depth;
};

ROBOT S, E;

int board[101][101];
int visited[101][101][4];

int dr[3] = {0, 1, 3};

void BFS() {

  queue<unit> Q;
  Q.push({S.i, S.j, S.d, 0});
  visited[S.i][S.j][S.d] = 0;

  while (!Q.empty()) {
    unit cur = Q.front();
    Q.pop();
    int curI = cur.i;
    int curJ = cur.j;
    int curD = cur.d;
    int curDepth = cur.depth;

    for (int t = 0; t < 3; t++) {

      int d = (curD + dr[t]) % 4;
      int nDepth = t == 0 ? curDepth : curDepth + 1;

      for (int k = 0; k < 4; k++) {
        int kni = curI + k * Di[d];
        int knj = curJ + k * Dj[d];
        int knd = nDepth;
        if (k != 0) knd += 1;
        if (kni < 0 || kni > N - 1 || knj < 0 || knj > M - 1 || board[kni][knj] == 1) break;
        if (visited[kni][knj][d] != -1 && visited[kni][knj][d] <= knd) continue;
        visited[kni][knj][d] = knd;
        Q.push({kni, knj, d, knd});
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
    }
  }
  memset(visited, -1, sizeof(visited));

  cin >> S.i >> S.j >> S.d;
  cin >> E.i >> E.j >> E.d;

  S.i--;
  S.j--;
  S.d = transD(S.d);

  E.i--;
  E.j--;
  E.d = transD(E.d);
  BFS();
  cout << visited[E.i][E.j][E.d];
  return 0;
}

