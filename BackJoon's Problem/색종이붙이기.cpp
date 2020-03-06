#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;
using P = pair<int, int>;
const int INF = 987654321;

// 1로 이루어진 사각형의 갯수 찾기
// 크기는 1부터 ~ 5까지 있음

int N, M, D;
bool board[11][11];
// 연결되어 있는걸 찾아서 일단, 그다음에 0으로 바꿔주는 작업을 해야한다.
int remainPaper[6] = {0, 5, 5, 5, 5, 5};

bool canAttatch(int paperNum, int curi, int curj) {
  if (curi + paperNum - 1 > 9 || curj + paperNum - 1 > 9) return false;
  for (int i = 0; i < paperNum; i++) {
    for (int j = 0; j < paperNum; j++) {
      int ni = curi + i;
      int nj = curj + j;
      if (!board[ni][nj]) return false;
    }
  }
  return true;
}

void attatch(int paperNum, int curi, int curj) {
  for (int i = 0; i < paperNum; i++) {
    for (int j = 0; j < paperNum; j++) {
      int ni = curi + i;
      int nj = curj + j;
      board[ni][nj] = false;
    }
  }
}

void detatch(int paperNum, int curi, int curj) {
  for (int i = 0; i < paperNum; i++) {
    for (int j = 0; j < paperNum; j++) {
      int ni = curi + i;
      int nj = curj + j;
      board[ni][nj] = true;
    }
  }
}

int result = INF;

int min(int a, int b) {
  if (a > b) return b;
  return a;
}

int numberToFill = 0;

void dfs(int curi, int curj, int fillNum, int usingPaper) {

  if (curj == 10) {
    dfs(curi + 1, 0, fillNum, usingPaper);
    return;
  }

  if (curi == 10 || fillNum == numberToFill) {
    result = min(result, usingPaper);
    return;
  }

  if (!board[curi][curj]) {
    dfs(curi, curj + 1, fillNum, usingPaper);
    return;
  }

  for (int paper = 1; paper <= 5; paper++) {
    if (remainPaper[paper] == 0 || !canAttatch(paper, curi, curj)) {
      continue;
    }
    remainPaper[paper]--;
    attatch(paper, curi, curj);
    dfs(curi, curj + paper, fillNum + paper * paper, usingPaper + 1);
    detatch(paper, curi, curj);
    remainPaper[paper]++;
  }

}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> board[i][j];
      if (board[i][j]) numberToFill++;
    }
  }

  dfs(0, 0, 0, 0);
  if (result == INF) cout << -1;
  else cout << result;
  return 0;
}