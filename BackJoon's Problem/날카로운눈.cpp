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
const int INF = 987654321;
int N, M;

// 홀수개 존재하는 정수 찾기
// A + 0B / A + 1B / A +2B ... A + KB
//2만개
// 4lg2
// ads
vector<pair<int, P>> el;

int min(int a, int b) {
  if (a > b)return b;
  return a;
}

ll cntOflessNumber(int target) {
  ll cnt = 0;
  for (int i = 0; i < el.size(); i++) {
    int s, e, mult;
    s = el[i].second.first;
    e = el[i].second.second;
    mult = el[i].first;
    if (target < s) continue;
    cnt += (min(e, target) - s) / mult + 1;
  }
  return cnt;
}

int cntOfTargetNumber(int target) {
  int cnt = 0;
  for (int i = 0; i < el.size(); i++) {
    int s, e, mult;
    s = el[i].second.first;
    e = el[i].second.second;
    mult = el[i].first;
    if (target < s || target > e) continue;
    if ((target - s) % mult == 0) cnt++;
  }
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  for (int i = 0; i < N; i++) {
    int a, b, c;
    // start, end , mult
    cin >> a >> b >> c;
    el.push_back({c, {a, b}});
  }
  ll l = 1;
  ll r = 2147483647;
  ll md;
  int Rr = INF;
  int cnt;
  while (l < r) {
    md = (l + r) / 2;
    cnt = cntOflessNumber(md);
    // 홀수개면
    if (cnt % 2 == 1 || cnt == 0) {
      Rr = md;
      r = md;
    } else l = md + 1;
  }
  if (Rr == INF) {
    cout << "NOTHING";
    return 0;
  }
  cout << Rr << " " << cntOfTargetNumber(Rr);
  return 0;
}