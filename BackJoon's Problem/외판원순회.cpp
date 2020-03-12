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
int N;

int board[20][20];
int DP[1 << 16][20] = {0};

//int DP[1<<16][20];
//모든곳을 다 돌고 .. 오는 경우
vector<P> gr[20];


// 지난경로, 지금위치
int DFS(int trace, int cur) {

  if (trace == (1 << N) - 1) {
    if (board[cur][0] == 0) return INF;
    return board[cur][0];
  }

  if (DP[trace][cur] != 0) return DP[trace][cur];
  DP[trace][cur] = INF;

  for (int v = 0; v < gr[cur].size(); v++) {
    int nNode = gr[cur][v].first;
    int nCost = gr[cur][v].second;
    int nTrace = trace | (1 << nNode);

    if ((trace & (1 << nNode))) continue;
    DP[trace][cur] = min(DP[trace][cur], DFS(nTrace, nNode) + nCost);
  }
  return DP[trace][cur];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
      if (board[i][j] == 0) continue;
      gr[i].push_back({j, board[i][j]});
    }
  }
  cout << DFS(1, 0);
  return 0;
}