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

int tc, n;
vector<int> el;

int max(int a, int b) {
  return a > b ? a : b;
}

int min(int a, int b) {
  return a > b ? b : a;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  tc = 10;
  int no = 0;
  while (tc--) {
    no++;
    el.clear();
    el.push_back(0);
    el.push_back(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      el.push_back(a);
    }
    el.push_back(0);
    el.push_back(0);

    int ans = 0;
    for (int i = 2; i < n + 2; i++) {
      int l = max(el[i - 2], el[i - 1]);
      int r = max(el[i + 1], el[i + 2]);
      //cout<<"lr"<<l<<" "<<el[i]<<" "<<r<<endl;
      if (el[i] < l || el[i] < r) continue;
      ans += min(el[i] - l, el[i] - r);
      //cout<<i<<" "<<ans<<endl;
    }
    cout<<"#"<<no<<" "<<ans<<"\n";
  }
  return 0;
}


