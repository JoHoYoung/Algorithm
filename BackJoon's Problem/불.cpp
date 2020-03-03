#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

#define MAXN 1000000
using namespace std;
using P = pair<int, int>;
int N, M;
P J;
int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};

char board[1001][1001];
int fireMap[1001][1001];
bool visited[1001][1001];

typedef struct unit {
    int i, j, depth;
};

queue<unit> Q;
vector<P> firePos;

int min(int a, int b) {
  if (a > b) return b;
  return a;
}

void fireMapBfs() {
  for (auto it = firePos.begin(); it != firePos.end(); it++) {
    Q.push({(*it).first, (*it).second, 1});
    fireMap[(*it).first][(*it).second] = 1;
  }
  while (!Q.empty()) {
    unit now = Q.front();
    Q.pop();

    for (int d = 0; d < 4; d++) {
      int ni = now.i + Di[d];
      int nj = now.j + Dj[d];

      if (ni < 0 || ni > N - 1 || nj < 0 || nj > M - 1 || fireMap[ni][nj] != 0) continue;
      fireMap[ni][nj] = now.depth + 1;
      Q.push({ni, nj, now.depth + 1});
    }
  }
}

bool isFind = false;
int result = MAXN;

void travel() {
  Q.push({J.first, J.second, 1});

  while (!Q.empty()) {
    unit now = Q.front();
    Q.pop();
    if (now.i == N - 1 || now.i ==0 || now.j ==0 || now.j == M-1) {
      isFind = true;
      result = min(result, now.depth);
    }

    for (int d = 0; d < 4; d++) {
      int ni = now.i + Di[d];
      int nj = now.j + Dj[d];
      if (ni < 0 || ni > N - 1 || nj < 0 || nj > M - 1 || visited[ni][nj] || (fireMap[ni][nj] != 0 &&fireMap[ni][nj] <= now.depth + 1)) continue;
      visited[ni][nj] = true;
      Q.push({ni, nj, now.depth + 1});
    }
  }

}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;

  // 불이 몇시에 퍼지는지
  // 지훈이가 이동하는 시간이 불이 이동하는 시간이랑 같으면, 즉 숫자가 같은곳으로는 이동할 수 있음
  // 숫자가 큰 곳으로는 이동 할 수 없음
  // 벽은 최대시간값으로 채워놓고. 절대 못가도록
  memset(visited, false, sizeof(visited));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'F') firePos.push_back({i, j});
      if (board[i][j] == 'J') J = {i, j};
      if (board[i][j] == '#') fireMap[i][j] = -1;
      if (board[i][j] == '.') fireMap[i][j] = 0;
      if (board[i][j] == 'J' || board[i][j] == 'F') fireMap[i][j] = 0;
    }
  }

  fireMapBfs();
  travel();
  if (isFind) {
    cout << result;
  } else {
    cout << "IMPOSSIBLE";
  }

  return 0;

}
