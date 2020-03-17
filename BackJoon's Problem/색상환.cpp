#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>

#define INF 987654321
#define MAX 1000000003
using namespace std;
using ll = long long;
using P = pair<int, int>;

int N, K;

int DP[1001][1001];

void sol() {

  DP[1][1] = 1;
  DP[2][1] = 2;
  DP[3][1] = 3;
  for (int i = 4; i <= N; i++) {
    for (int d = 1; d <= i/2; d++) {
      if(d == 1) DP[i][d] = i;
      else DP[i][d] = (DP[i-2][d-1] + DP[i-1][d])%MAX;
    }
  }
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K;
  sol();
  cout<<DP[N][K];
  return 0;
}

