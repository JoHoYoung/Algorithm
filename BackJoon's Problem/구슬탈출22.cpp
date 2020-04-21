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

int N, M;
char board[11][11];

P hole;
P sR;
P sB;

typedef struct unit {
    P R, B;
    int depth, upperDirection;
};
int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};

P go(int dir, P pos) {
  while (board[pos.first][pos.second] != '#') {
    if (board[pos.first][pos.second] == 'O') return {-1, -1};
    pos.first += Di[dir];
    pos.second += Dj[dir];
  }
  pos.first -= Di[dir];
  pos.second -= Dj[dir];
  return pos;
}

// 빨간게 파란거보다 먼저 움직였느냐
bool isFirst(int dir, P R, P B) {
  // 위
  if (dir == 0) {
    return R.first < B.first;
    // 오른쪽
  } else if (dir == 1) {
    return R.second > B.second;
    // 아래
  } else if (dir == 2) {
    return R.first > B.first;
    // 왼쪽
  } else if (dir == 3) {
    return R.second < B.second;
  }
}

int ans = -1;

// 왼 오 위 아래 기울이기
void BFS() {
  queue<unit> Q;
  Q.push({sR, sB, 0, -1});
  while (!Q.empty()) {
    unit cur = Q.front();
    Q.pop();
    if (cur.depth >= 10) return;
    // cout<<"HELLO\n";

    for (int d = 0; d < 4; d++) {
      //if (d % 2 == cur.upperDirection % 2) continue;
      P sR = go(d, cur.R);
      P sB = go(d, cur.B);
//      cout << "D " << d << " " << "red : " << sR.first << " " << sR.second << " blue: " << sB.first << " " << sB.second
//           << endl;
      if (sB.first == -1) continue;
      if (sR.first == -1) {
        ans = cur.depth + 1;
        return;
      }

      if (sR.first == sB.first && sR.second == sB.second) {

        if (isFirst(d, cur.R, cur.B)) {
          sB.first -= Di[d];
          sB.second -= Dj[d];
        } else {
          sR.first -= Di[d];
          sR.second -= Dj[d];
        }
//        cout << "Same " << " " << "red : " << sR.first << " " << sR.second << " blue: " << sB.first << " " << sB.second
//             << endl;
      }
      if (sR.first == cur.R.first && sR.second == cur.R.second && sB.first == cur.B.first &&
          sB.second == cur.B.second)
        continue;
      Q.push({sR, sB, cur.depth + 1, d});
    }
  }
}

// 빨간색만 구멍에 빠져
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'O') hole = {i, j};
      if (board[i][j] == 'R') sR = {i, j};
      if (board[i][j] == 'B') sB = {i, j};
    }
  }

  BFS();
  cout << ans;
  return 0;
}


