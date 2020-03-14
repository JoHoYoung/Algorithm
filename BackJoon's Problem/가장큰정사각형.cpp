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
using P = pair<int, int>;

int N, M;
// 정사각형 판단 : 왼쪽 아래
// 특정.. N개 특정 정 사각형이 갖고있는게..
// 아래, 위 점검
// 맨마지막 끝점 점검

//특정 정사각형의 왼쪽 위점이 시작이고, 그가 가지고 있는 정사각형 크기
int DP[1001][1001];


int max(int a, int b) {
  if (a > b) return a;
  return b;
}

int min(int a, int b) {
  if (a > b) return b;
  return a;
}

int ans = 0;

void sol() {
  for (int i = N - 2; i >= 0; i--) {
    for (int j = M - 2; j >= 0; j--) {
      if (DP[i][j] == 0) continue;
      DP[i][j] += min(DP[i + 1][j], min(DP[i][j + 1], DP[i + 1][j + 1]));
      ans = max(ans, DP[i][j]);
    }
  }
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;

  memset(DP, 0, sizeof(DP));
  memset(board, false, sizeof(board));

  string s;
  for (int i = 0; i < N; i++) {
    cin >> s;
    for (int j = 0; j < M; j++) {
      DP[i][j] = s[j] - '0';
      if (DP[i][j]) ans = 1;
    }
  }

  sol();
  cout << ans * ans << '\n';
  return 0;
}