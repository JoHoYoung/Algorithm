#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll INF = 9999999999999999;
int N;

vector<ll> mp;

ll ABS(ll a) {
  if (a < 0) return -a;
  return a;
}

vector<ll> R;
ll ans = INF;

//0에 가까운 세 용액
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  ll temp;
  for (int i = 0; i < N; i++) {
    cin >> temp;
    mp.push_back(temp);
  }
  sort(mp.begin(), mp.end());
  //cout << endl;

  for (int i = 0; i < mp.size(); i++) {
    ll leftest = mp[i];
    ll l = i + 1;
    ll r = mp.size() - 1;
    while (l < r) {
      ll sum = leftest + mp[l] + mp[r];
      if (ans > ABS(sum)) {
        ans = ABS(sum);
        R.clear();
        R.push_back(mp[i]);
        R.push_back(mp[l]);
        R.push_back(mp[r]);
      }
      if (sum < 0) l++;
      else if (sum > 0) r--;
      else {
        i = N;
        break;
      }
    }
  }
  sort(R.begin(), R.end());
  for (int i = 0; i < R.size(); i++) cout << R[i] << " ";
  return 0;
}