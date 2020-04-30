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

int N, M, L;

vector<int> el;

bool sol(int mid) {

  int cnt = 0;
  for (int i = 1; i < el.size(); i++) {
    int dst = el[i] - el[i-1];
    if (dst > mid) {
      cnt += dst / mid;
      cnt += (dst % mid) == 0 ? -1 : 0;
     // cnt -= 1;
    }
  }
  return cnt <= M;
}

int min(int a, int b) {
  return a > b ? b : a;
}

int ans = INF;

// ÈÞ°³¼Ò°¡ ¾ø´Â ±¸°£ÀÇ ÃÖ´ñ°ªÀÇ ÃÖ¼Ú°ª
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> L;

  el.push_back(0);
  el.push_back(L);
  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    el.push_back(tmp);
  }
  sort(el.begin(), el.end());
  int l = 0;
  int r = 1001;

  while (l <= r) {
    int mid = (l + r) / 2;
    if (sol(mid)) {
      ans = min(ans, mid);
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout<<ans;
  return 0;
}

