#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;
int T, N;
//0은 배치 할 수 없다.

int board[11][11];
int visited[1 << 11][11];

int max(int a, int b) {
  if (a > b) return a;
  return b;
}

// 누구누구 까지 고른 상태에서, 현재 포지션 cur 고려.
int DFS(int trace, int cur) {
  // cout<< trace<<" "<<cur<<endl;
  if (trace == (1 << 11) - 1) return 0;

  int ref = visited[trace][cur];
  if (ref != -1) return ref;

  ref = -987654321;
  for (int i = 0; i < 11; i++) {
    if (trace & (1 << i)) continue;
    if (board[i][cur] == 0) continue;
    int nTrace = (trace | (1 << i));
    ref = max(ref, board[i][cur] + DFS(nTrace, cur+1));
  }
  return ref;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  while (T--) {
    for (int i = 0; i < 11; i++) {
      for (int j = 0; j < 11; j++) {
        cin >> board[i][j];
      }
    }
    memset(visited, -1, sizeof(visited));
    cout<<DFS(0,0)<<'\n';
  }
  return 0;
}
