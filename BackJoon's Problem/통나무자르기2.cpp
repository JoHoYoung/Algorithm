#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>

#define MAXN 31
#define INF 98765432
#define MAX 1000000

using namespace std;
using ll = long long;
using P = pair<int, int>;

int L, K, C;

vector<int> el;

//C번 자를 수 있고,가장 긴 조각의 최솟값
// 휴개소가 없는 구간의 최댓값의 최솟값
// 많아야 C번

bool sol(int mid) {

  int sum = el[0];
  int cnt = 0;
  for (int i = 1; i < el.size(); i++) {
    int dst = el[i] - el[i - 1];
    if (dst > mid) return false;
    sum += dst;
    // cut
    if (sum > mid) {
      sum = dst;
      cnt++;
    }
  }
  return cnt <= C;
}


int min(int a, int b) {
  return a > b ? b : a;
}

int ans = (int)(1e9 + 1);

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> L >> K >> C;
  el.push_back(0);
  el.push_back(L);
  for (int i = 0; i < K; i++) {
    int tmp;
    cin >> tmp;
    el.push_back(tmp);
  }
  sort(el.begin(), el.end());

  int l = 0;
  int r = (int)(1e9 + 1);
  while (l <= r) {
    int mid = (l + r) / 2;
    if (sol(mid)) {
      ans = min(ans, mid);
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  int pos;
  int cnt = 0;
  int diff = 0;
  for (int i = el.size() - 2; i >= 0; i--) {
    diff += el[i + 1] - el[i];
    if (diff > ans) {
      diff = el[i + 1] - el[i];
      pos = i + 1;
      cnt++;
    }
  }

  sol(ans);
  cout << ans << " ";
  if (cnt < C) cout << el[1];
  else cout << el[pos];

  return 0;
}

