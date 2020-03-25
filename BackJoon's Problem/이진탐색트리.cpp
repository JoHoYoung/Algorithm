#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>

#define INF 987654321
#define MAX 1000000
using namespace std;
using ll = long long;
using P = pair<int, int>;

int N;

map<int, int> depth = { { 0,-1 },{ 300001,-1 } };;
vector<int> re;
ll acc = 0;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>N;
  for(int i=0;i<N;i++){
    int tmp;
    cin>>tmp;
    auto it = depth.upper_bound(tmp);
    int t = (it--)->second;
    acc += depth[tmp] = max(it->second, t) +1;
    cout<<acc<<'\n';
  }
  return 0;
}

