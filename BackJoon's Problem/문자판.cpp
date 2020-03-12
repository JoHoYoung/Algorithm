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

int N, M, K;
char board[100][100];
int DP[100][100][100];

int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};

string RS;
int ans = 0;

// 특정 위치에서 다음글자를 찾는 경우의 수
int dfs(int i, int j, int depth) {

  if (depth == RS.size()) {
    return 1;
  }
  if(DP[i][j][depth] != 0 ) return DP[i][j][depth];
  int r = 0;
  for (int d = 0; d < 4; d++) {
    for (int k = 1; k <= K; k++) {
      int ni = i + k * Di[d];
      int nj = j + k * Dj[d];
      if (ni < 0 || ni > N - 1 || nj < 0 || nj > M - 1 || RS[depth] != board[ni][nj]) continue;
      r += dfs(ni, nj, depth + 1);
    }
  }
  return DP[i][j][depth] = r;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> K;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];;
    }
  }
  cin >> RS;
  memset(DP, 0, sizeof(DP));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] == RS[0]) {
        ans += dfs(i, j, 1);
      }
    }
  }

  cout << ans;
  return 0;
}