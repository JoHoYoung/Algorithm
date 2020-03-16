#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

#define INF 987654321
#define MAX_K 1000000000
using namespace std;
using ll = long long;
using P = pair<int, int>;

int n;
vector<int> el;
long long DP[100][21];

void sol(){
  DP[0][el[0]] ++;

  for(int i=1;i<el.size()-1;i++){
    for(int j=0;j<=20;j++){
      if(DP[i-1][j] == 0 ) continue;
      int l = j - el[i];
      int r = j + el[i];
      if(l >= 0) DP[i][l] += DP[i-1][j];
      if(r <= 20) DP[i][r] += DP[i-1][j];
    }
  }
}
//20이 안넘고, 0보다 안작고
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    el.push_back(tmp);
  }

  memset(DP, false, sizeof(DP));
  sol();

  cout<<DP[n-2][el[n-1]];
  return 0;
}