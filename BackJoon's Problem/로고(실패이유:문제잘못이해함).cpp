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

int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};

// 내릴때만 그리기
// 올리면 지나가기
// 떨어진 블락찾기
int board[1002][1002];
bool visited[1002][1002];

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void drawPoint(int x1, int x2, int y1, int y2) {
  if (x1 > x2) {
    swap(x1, x2);
  }
  // 작은 좌표부터 진행
  if (y1 > y2) {
    swap(y1, y2);
  }
  for (int i = x1; i <= x2; i++) {
    board[y1][i] = 1;
    board[y2][i] = 1;
  }
  for (int i = y1; i <= y2; i++) {
    board[i][x1] = 1;
    board[i][x2] = 1;
  }
}

int contiCount = 1;

queue<P> Q;
void BFS(P s) {

  visited[s.first][s.second] = true;
  visited[s.first][s.second] = contiCount;
  while (!Q.empty()) {
    P cur = Q.front();
    Q.pop();
    int curI = cur.first;
    int curJ = cur.second;
    board[curI][curJ] = contiCount;
    for (int d = 0; d < 4; d++) {
      int ni = curI + Di[d];
      int nj = curJ + Dj[d];
      if (ni < 0 || ni > 1000 || nj < 0 || nj > 1000 || visited[ni][nj] || board[ni][nj] == 0) continue;
      visited[ni][nj] = true;
      board[ni][nj] = contiCount;
      Q.push({ni, nj});
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1 += 500;
    y1 += 500;
    x2 += 500;
    y2 += 500;
    drawPoint(x1, x2, y1, y2);
  }

  memset(visited, false, sizeof(visited));
  memset(board, false, sizeof(false));

  for (int i = 0; i < 1001; i++) {
    for (int j = 0; j < 1001; j++) {
      if (board[i][j] == 0 || visited[i][j]) continue;
      Q.push({i, j});
      BFS({i, j});
      contiCount++;
    }
  }

  if (board[500][500] == 0) contiCount++;
  for (int i = 500; i < 510; i++) {
    for (int j = 500; j < 510; j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
  cout << contiCount - 1;
  return 0;
}