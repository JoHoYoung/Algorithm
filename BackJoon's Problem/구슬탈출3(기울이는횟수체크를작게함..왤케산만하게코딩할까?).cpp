#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>


using namespace std;
using P = pair<int, int>;
int N, M;

// 오른쪽 위쪽, 왼쪽, 아래
// 0 2 | 1 3
int Di[4] = {0, -1, 0, 1};
int Dj[4] = {1, 0, -1, 0};

char Ds[4] = {'R', 'U', 'L', 'D'};

char board[11][11];

//특정방향에 따라 같은 위치인지, 그리고 뭐가 먼저인지
// 리턴값의 second.first가 먼저 움직여야 하는것이다

// 빨간공이 파란공보다 먼저가야 하는지만 리턴
bool existInSameLayer(P R, P B, int d) {
  // 오른쪽이면 j가 더 큰거
  if (d == 0) {
    if (R.first != B.first) return false;
    if (R.second > B.second) return true;
    return false;
  } else if (d == 1) {
    if (R.second != B.second) return false;
    if (R.first < B.first) return true;
    return false;
  } else if (d == 2) {
    if (R.first != B.first) return false;
    if (R.second < B.second) return true;
    return false;
  } else if (d == 3) {
    if (R.second != B.second) return false;
    if (R.first > B.first) return true;
    return false;
  }
}

bool isFind = false;
string resultPath;
int result = 100;

P mvForD(P ball, int d, bool &meetHole, string nowPath) {
  while (1) {
    ball.first += Di[d];
    ball.second += Dj[d];
    if (board[ball.first][ball.second] == '#' || ball.first < 0 || ball.first > N - 1
        || ball.second < 0 || ball.second > M - 1) {
      ball.first -= Di[d];
      ball.second -= Dj[d];
      return {ball.first, ball.second};
    }
    if (board[ball.first][ball.second] == 'O') {
      meetHole = true;
    }
  }
}

void DFS(P R, P B, int depth, int upperDirection, string path) {

  if (depth > 9) return;

  for (int d = 0; d < 4; d++) {
    if (d == upperDirection || (d + 2) % 4 == upperDirection) continue;
    bool redGoFirst = existInSameLayer(R, B, d);
    bool redMeatHole = false;
    string nowPath = path + Ds[d];
    P newR = mvForD(R, d, redMeatHole, nowPath);
    bool blueMeatHole = false;
    P newB = mvForD(B, d, blueMeatHole, nowPath);

    if (newR.first == newB.first && newR.second == newB.second) {
      if (!redGoFirst) {
        newR.first -= Di[d];
        newR.second -= Dj[d];
      } else {
        newB.first -= Di[d];
        newB.second -= Dj[d];
      }
    }

    if (!blueMeatHole && redMeatHole) {
      isFind = true;
      if (result > depth + 1) {
        result = depth + 1;
        resultPath = nowPath;
      }
    }

    if (!blueMeatHole && !redMeatHole) {
      DFS(newR, newB, depth + 1, d, nowPath);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;

  P R;
  P B;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'R') R = {i, j};
      if (board[i][j] == 'B') B = {i, j};
    }
  }

  DFS(R, B, 0, -1, "");

  if (!isFind) {
    cout << -1;
  } else {
    cout << result << '\n' << resultPath;
  }

  return 0;
}
