#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;
using P = pair<long, long>;

int board[301][301];
int temp[301][301];

int N, M;

int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};

int NumberOfZero(int i, int j) {
  int cnt = 0;
  for (int d = 0; d < 4; d++) {
    if (board[i + Di[d]][j + Dj[d]] == 0) cnt++;
  }
 // cout<<"RETRUN "<<cnt<<endl;
  return cnt;
}

vector<P> nonZero;

// vector의 범위와......

int visited[301][301];

queue<P> Q;

bool bfs() {

  while (!Q.empty()) {
    P now = Q.front();
    //cout << now.first << " " << now.second << endl;
    Q.pop();

    for (int d = 0; d < 4; d++) {
      int ni = now.first + Di[d];
      int nj = now.second + Dj[d];
      // out of index체크 필요 없음
      if (visited[ni][nj] || board[ni][nj] == 0) continue;
      visited[ni][nj] = true;
      Q.push({ni, nj});
    }
  }
  return false;
}

void copyArr(int from[][301], int to[][301]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      to[i][j] = from[i][j];
    }
  }
}


vector<P> timePass() {

  vector<P> newZero;
  copyArr(board, temp);
  for (auto it = nonZero.begin(); it != nonZero.end(); it++) {
    P pos = *it;
    int zeroAround = NumberOfZero(pos.first, pos.second);
    //cout<<"NUM ZERO AT "<<pos.first<<" "<<pos.second<<" : "<<zeroAround<<endl;
    int nextValue = board[pos.first][pos.second] - zeroAround;
    temp[pos.first][pos.second] = nextValue < 0 ? 0 : nextValue;
    if (temp[pos.first][pos.second] != 0) newZero.push_back({pos.first, pos.second});
  }
  copyArr(temp, board);
  return newZero;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;

  // input
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
      if (board[i][j] != 0) nonZero.push_back({i, j});
    }
  }

  bool isFind = false;
  int timeGone = 0;
  int result = 0;
  while (nonZero.size() > 0) {
   // print();
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    for (auto it = nonZero.begin(); it != nonZero.end(); it++) {
      P pos = *it;
      if (!visited[pos.first][pos.second]) {
        Q.push(pos);
        bfs();
        cnt++;
      }

      if (cnt >= 2) {
        isFind = true;
        break;
      }
    }
    if (isFind) {
      result = timeGone;
      break;
    }
    timeGone++;
    nonZero = timePass();
   // cout << nonZero.size() << endl;
  }
  cout << result;
  return 0;
}