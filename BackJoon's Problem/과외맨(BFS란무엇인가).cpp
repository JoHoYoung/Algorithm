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

int N;
int board[501][1002];
int boardNum[501][1002];

int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};

int visited[501][1002];
int trace[501 * 501];
int maxBlockNum = -1;
typedef struct unit {
    int i, j, depth;
};

vector<int> tr;

void getTrace() {
  int idx = maxBlockNum;
  tr.clear();
  while (trace[idx] != idx) {
    tr.push_back(idx);
    idx = trace[idx];
  }
  tr.push_back(1);
}

vector<P> el[501 * 501];
int minN[501 * 501];

//세로로 500개. 가로로 500개
void BFS() {

  queue<unit> Q;
  Q.push({0, 0, 1});
  Q.push({0, 1, 1});
  visited[0][0] = 1;
  visited[0][1] = 1;
  trace[1] = 1;

  while (!Q.empty()) {
    unit cur = Q.front();
    Q.pop();
    int curI = cur.i;
    int curJ = cur.j;
    int curBlock = boardNum[curI][curJ];
    int curNum = board[curI][curJ];
    if (maxBlockNum <= curBlock) maxBlockNum = curBlock;

    for (int d = 0; d < 4; d++) {
      int ni = curI + Di[d];
      int nj = curJ + Dj[d];
      if (ni < 0 || ni > N - 1 || nj < 0 || nj > N * 2 - 1 || board[ni][nj] == -1) continue;
      if (visited[ni][nj] != -1) continue;
      int nBlock = boardNum[ni][nj];
      int nNum = board[ni][nj];
      if (curNum != nNum) continue;

      bool left = false;
      if (nj - 1 >= 0 && boardNum[ni][nj - 1] == nBlock) left = true;
      visited[ni][nj] = cur.depth + 1;
      Q.push({ni, nj, cur.depth + 1});
      if (left) {
        visited[ni][nj - 1] = cur.depth + 1;
        Q.push({ni, nj - 1, cur.depth + 1});
      } else {
        visited[ni][nj + 1] = cur.depth + 1;
        Q.push({ni, nj + 1, cur.depth + 1});
      }
      trace[nBlock] = curBlock;
    }
  }
}

// 인접간선이 없는 노드끼리의 집합
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  memset(boardNum, -1, sizeof(boardNum));
  memset(visited, -1, sizeof(visited));
  memset(minN, -1, sizeof(minN));

  int boardN = 1;
  for (int i = 0; i < N; i++) {
    int cnt = 0;
    for (int j = 0; j < N * 2; j++) {
      if (i % 2 != 0 && (j == 0 || j == N * 2 - 1)) {
        board[i][j] = -1;
        continue;
      }
      cin >> board[i][j];
      boardNum[i][j] = boardN;
      el[boardN].push_back({i, j});
      cnt++;
      if (cnt == 2) {
        boardN++;
        cnt = 0;
      }
    }
  }

  BFS();
  getTrace();
  cout << tr.size() << endl;
  for (int i = tr.size() - 1; i >= 0; i--) {
    cout << tr[i] << " ";
  }
  return 0;
}

