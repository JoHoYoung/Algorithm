#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

#define MAXN 4000001
#define ll long long

using namespace std;
using P = pair<long, long>;
int N, M;

int board[1010][1010];

typedef struct unit {
    int i, j, depth, numberOfDestory;
};

queue<unit> Q;

int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};

bool visited[1010][1010][2];

int min(int a, int b) {
  if (a > b) return b;
  return a;
}

int result = MAXN;
void bfs() {

  while (!Q.empty()) {

    unit now = Q.front();
    Q.pop();

    if (now.i == N - 1 && now.j == M - 1 ) {
      result = min(now.depth, result);
    }

    for (int d = 0; d < 4; d++) {
      int nextI = now.i + Di[d];
      int nextJ = now.j + Dj[d];

      if (nextI < 0 || nextI > N - 1 || nextJ < 0 || nextJ > M - 1) continue;
      if(visited[nextI][nextJ][now.numberOfDestory]) continue;

      if (board[nextI][nextJ] == 1 && now.numberOfDestory == 0) {
        Q.push({nextI, nextJ, now.depth + 1, 1});
      } else if(board[nextI][nextJ] == 0){
        visited[nextI][nextJ][now.numberOfDestory] = true;
        Q.push({nextI, nextJ, now.depth + 1, now.numberOfDestory});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  char input[M];
  for (int i = 0; i < N; i++) {
    cin >> input;
    for (int j = 0; j < M; j++) {
      board[i][j] = input[j] - '0';
    }
  }
  memset(visited, false, sizeof(visited));

  visited[0][0][0] = true;
  visited[0][0][1] = true;
  Q.push({0, 0, 1, 0});
  bfs();

  result = result == MAXN ? -1 : result;

  cout << result;

  return 0;
}