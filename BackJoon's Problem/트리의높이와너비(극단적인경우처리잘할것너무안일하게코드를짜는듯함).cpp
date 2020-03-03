#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

#define MAXN 5000001
using namespace std;
using P = pair<int, int>;
int N, k, s;
int board[10001][2];
bool visited[10001];
P depthInfo[10001];

//first 에는 leftest,
//second 에는 rightest
int max(int a, int b) {
  if (a > b) return a;
  return b;
}

int min(int a, int b) {
  if (a < b) return a;
  return b;
}

// 배열에서 비어있는 인덱스는 없다.
// board[][0] : 왼쪽노드, board[][1] : 오른쪽노드//
// 특정 노드의 인덱스 : 루트노드의 인덱스 + 자기 왼쪽의 노드갯수
// 특정 레벨의 넓이 : 같은 레벨의 가장오른쪽인덱스 - 가장 왼쪽인덱스 + 1
//
// 왼쪽애들이나 오른쪽애들이나 가장 젤 왼쪽을.. 고려해야함
// 자기가 가지고 있는 자식의 수를 리턴하는 dfs 함수
int depthMax = 0;

int dfs(int node, int leftest, int depth) {

  depthMax = max(depthMax, depth);
  int numberOfLeft;
  if (board[node][0] == -1) {
    numberOfLeft = 0;
  } else {
    numberOfLeft = dfs(board[node][0], leftest, depth + 1);
  }
  int numberOfRight;
  if (board[node][1] == -1) {
    numberOfRight = 0;
  } else {
    numberOfRight = dfs(board[node][1], leftest + numberOfLeft + 1, depth + 1);
  }

  depthInfo[depth].first = min(depthInfo[depth].first, leftest + numberOfLeft);
  depthInfo[depth].second = max(depthInfo[depth].second, leftest + numberOfLeft);

  return numberOfLeft + numberOfRight + 1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  int temp;
  // 노드의 번호.
  memset(visited, false, sizeof(visited));
  for (int i = 1; i <= N; i++) {
    cin >> temp >> board[temp][0] >> board[temp][1];
    visited[board[temp][0]] = true;
    visited[board[temp][1]] = true;
  }

  for (int i = 1; i <= N; i++) {
    depthInfo[i].first = N;
    depthInfo[i].second = 0;
  }

  int rootIdx;
  for (int i = 1; i <= N; i++) {
    if (!visited[i]) {
      rootIdx = i;
      break;
    }
  }

  dfs(rootIdx, 0, 1);
  int maxResult = -1;
  int maxDepth = 0;

  for (int i = 1; i <= depthMax; i++) {
    int dif = depthInfo[i].second - depthInfo[i].first + 1;
    if (dif > maxResult) {
      maxResult = dif;
      maxDepth = i;
    }
  }

  cout << maxDepth << " " << maxResult;
  return 0;

}
