#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;
using ll = long long;

vector<ll> ans;

void sol(int N, ll sum){

  if(N == -1){
    ans.push_back(sum);
    return ;
  }
  sol(N-1, sum);
  sol(N-1, sum*10 + N);
}
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin>>N;
  sol(9,0);
  sort(ans.begin(),ans.end());
  if(N>=ans.size()-1) cout<<-1;
  else cout<<ans[N+1];
  return 0;
}