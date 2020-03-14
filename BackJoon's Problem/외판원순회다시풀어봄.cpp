#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

#define INF 987654321

using namespace std;
using ll = long long;

int N;
int board[17][17];
int visited[1 << 16][17];

int min(int a, int b) {
  if (a > b) return b;
  return a;
}

int tsp(int trace, int cur) {
  if (trace == (1 << N) - 1) {
    if(board[cur][0] == 0) return INF;
    return board[cur][0];
  }

  int &ref = visited[trace][cur];

  if (ref != -1) return ref;
  ref = INF;
  for (int i = 0; i < N; i++) {
    // 이미 방문된 곳이라면
    if ((trace & (1 << i)) || board[cur][i] == 0) continue;
    int nTrace = trace | (1 << i);
    ref = min(ref, board[cur][i] + tsp(nTrace, i));
  }
  return ref;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  memset(visited, -1, sizeof(visited));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }
  cout << tsp(1,0);
  return 0;
}