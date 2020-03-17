#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#define INF 987654321
#define MAX 1000000000
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll n, p, q;

// 배수의 갯수
map<ll, ll> DP;
ll sol(ll t){

  if(DP.count(t)) return DP[t];
  DP[t] = 0;
  DP[t] += sol(t/p);
  DP[t] += sol(t/q);

  return DP[t];
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> p >> q;
  DP[0] = 1;
  cout<<sol(n);
  return 0;
}

