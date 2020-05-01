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

int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};

int N, M;

char board[51][51];
int visited[1 << 6][51][51];

//열쇠는 a,b,c,d,e,f

P S, E;
int ans = INF;

int min(int a, int b) {
  return a > b ? b : a;
}

typedef struct unit {
    P pos;
    int depth, key;
};

void BFS() {
  queue<unit> Q;
  Q.push({S, 0, 0});
  visited[0][S.first][S.second] = 0;
  while (!Q.empty()) {
    int curI = Q.front().pos.first;
    int curJ = Q.front().pos.second;
    int curD = Q.front().depth;
    int curKey = Q.front().key;
    Q.pop();

    if (board[curI][curJ] == '1') ans = min(ans, curD);
    for (int d = 0; d < 4; d++) {
      int ni = curI + Di[d];
      int nj = curJ + Dj[d];
      int nKey = curKey;
      if (ni < 0 || nj < 0 || ni > N - 1 || nj > M - 1 || board[ni][nj] == '#') continue;
      // 열쇠인경우
      if ('a' <= board[ni][nj] && board[ni][nj] <= 'f') {
        int nKey = curKey | (1 << (board[ni][nj] - 'a'));
        if ((visited[nKey][ni][nj] != -1 && visited[nKey][ni][nj] <= curD + 1)) continue;
        visited[nKey][ni][nj] = curD + 1;
        Q.push({{ni, nj}, curD + 1, nKey});
        continue;
      }

      // 문인경우
      if ('A' <= board[ni][nj] && board[ni][nj] <= 'F') {
        if ((curKey & (1 << (board[ni][nj] - 'A'))) == 0) {
          //cout<<"BREAK"<<endl;
          continue;
        }
        if ((visited[curKey][ni][nj] != -1 && visited[curKey][ni][nj] <= curD + 1)) continue;
        visited[curKey][ni][nj] = curD + 1;
        Q.push({{ni, nj}, curD + 1, curKey});
        continue;
      }

      if ((visited[curKey][ni][nj] != -1 && visited[curKey][ni][nj] <= curD + 1)) continue;
      visited[curKey][ni][nj] = curD + 1;
      Q.push({{ni, nj}, curD + 1, curKey});

    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  memset(visited, -1, sizeof(visited));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
      if (board[i][j] == '0') S = {i, j};
      if (board[i][j] == '1') E = {i, j};
    }
  }
  BFS();
  ans = ans == INF ? -1 : ans;
  cout << ans;
  return 0;
}