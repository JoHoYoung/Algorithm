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

int N, M, K;

vector<int> el;

// 가장 가까운 두 심판의 거리 최대
bool sol(int mid) {
  int cnt = 1;
  int upper = el[0];
  for (int i = 1; i < el.size(); i++) {
    int dst = el[i] - upper;
    if (mid <= dst) {
      upper = el[i];
      cnt++;
    }
  }
  return cnt >= M;
}

int max(int a,int b){
  return a>b? a: b;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> K;

  for (int i = 0; i < K; i++) {
    int k;
    cin >> k;
    el.push_back(k);
  }
  int l = 0;
  int r = 1000000;
  int ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (sol(mid)) {
      l = mid + 1;
      ans = max(ans, mid);
    } else {
      r = mid - 1;
    }
  }
  cout<<1;
  int upper = el[0];
  int cnt = 1;
  for(int i=1;i<el.size();i++){
    int dst = el[i] - upper;
    if(ans <= dst && cnt < M){
      cout<<1;
      cnt++;
      upper = el[i];
    }else{
      cout<<0;
    }
  }
 // cout<<ans;
  return 0;
}


