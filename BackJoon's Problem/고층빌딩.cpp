#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

#define INF 987654321
#define MAX 1000000007
using namespace std;
using ll = long long;
using P = pair<int, int>;

int N, L, R;

ll DP[101][101][101];

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> L >> R;
  memset(DP, 0, sizeof(DP));
  DP[1][1][1] = 1;
  for(int n=2;n<=N;n++){
    for(int l=1;l<=L;l++){
      for(int r=1;r<=R;r++){
        DP[n][l][r] = DP[n-1][l][r]*(n-2) + DP[n-1][l-1][r] + DP[n-1][l][r-1];
        DP[n][l][r] %= MAX;
      }
    }
  }
  cout<<DP[N][L][R]%MAX;
  return 0;
}