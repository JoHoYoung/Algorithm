#include <iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#define MAXN 200020
#define ll long long
using namespace std;
using P = pair<long, long>;

int N;

ll tree[MAXN+1];
ll tree2[MAXN+1];

int DIV = 1000000007;

void update(ll* tree, int x, ll val) {
  for (int i = x; i <= MAXN; i += (i&-i))tree[i] += val;
}

ll _sum(ll* tree, int x) {
  ll ret = 0;
  for (int i = x; i > 0; i -= (i&-i)) ret += tree[i];
  return ret;
}
ll sum(ll* tree, int s, int e) {
  if (s > e) return 0;
  return (_sum(tree, e) - _sum(tree, s - 1));
}

// 합 : 빼면서
// 업데이트 : 더하면서
int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  ll temp;
  cin >> temp;

  temp++;
  update(tree, temp,(ll)1);
  update(tree2,temp, temp);

  vector<long long> ans(N+1, 0);

  for (int i = 2; i <= N; i++) {
    cin >> temp;
    temp++;
    ans[i] += sum(tree2, (int)temp + 1, MAXN) - temp*sum(tree, (int)temp + 1, MAXN);
    ans[i] += temp*sum(tree, 1, (int)temp - 1) - sum(tree2, 1, (int)temp - 1);
    ans[i] %= DIV;
    update(tree, temp, 1);
    update(tree2, temp, temp);
  }

  long long mul = 1;
  for (int i = 2; i <= N; i++) {
    mul *= ans[i];
    mul %= DIV;
  }
  cout<<mul<<endl;
  return 0;
}