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
int DP[501][501];

vector<P> el;

int min(int a, int b) {
  if (a > b) return b;
  return a;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    int r, c;
    cin >> r >> c;
    el.push_back({r, c});
  }
  memset(DP, false, sizeof(DP));
  // 대각선으로
  for (int d = 1; d < N; d++) {
    for (int i = 0; i + d < N; i++) {
      DP[i][i + d] = INF;
      for (int k = 0; k < d; k++) {
        DP[i][i + d] = min(DP[i][i + d],
                           DP[i][i + k] + DP[i + k + 1][i + d] + el[i].first * el[i+k+1].first * el[i + d].second);
      }
    }
  }
  cout << DP[0][N - 1] << endl;
  return 0;
}