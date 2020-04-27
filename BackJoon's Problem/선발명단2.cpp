#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>

#define MAXN 31
#define INF 987654321
#define MAX 1000000

using namespace std;
using ll = long long;
using P = pair<int, int>;

int tc;
int board[11][11];
int dp[1<<11][11];

int max(int a, int b) {
  return a > b ? a : b;
}

int DFS(int cur, int visit) {

  //if (visit == (1 << 11) - 1) return 0;
  if(cur > 10) return 0;
  int &ans = dp[visit][cur];
  if(ans != -1) return ans;
  ans = -987654321;
  //cout<<cur<<endl;
  for (int i = 0; i < 11; i++) {
    if ((visit & (1 << i)) != 0 || board[cur][i] == 0) continue;
    ans = max(ans, DFS(cur+1, (visit | (1<<i))) + board[cur][i]);
  }
  return ans;
}

int main() {

  cin >> tc;
  while (tc--) {
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < 11; i++) {
      for (int j = 0; j < 11; j++) {
        cin >> board[i][j];
      }
    }
    cout<<DFS(0,0)<<'\n';
  }
  return 0;
}

