#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>

#define MAXN 31
#define INF (int)2e9
#define MAX 1000000

using namespace std;
using ll = long long;
using P = pair<int, int>;

int L, K, C;

vector<int> el;

int min(int a, int b) {
  return a > b ? b : a;
}

bool dfs(int mid) {

  int r = el[K];
  int cnt = 0;

  for (int i = K-1; i >= 0; i--) {
    int l = el[i];
    if (r - l <= mid) continue;
    if (el[i + 1] - el[i] > mid) {
      return false;
    } else {
      r = el[i + 1];
      cnt++;
    }
  }
  if (cnt > C) return false;
  return true;
}

int ans = INF;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> L >> K >> C;

  for (int i = 0; i < K; i++) {
    int tmp;
    cin >> tmp;
    el.push_back(tmp);
  }

  el.push_back(0);
  el.push_back(L);
  ++K;
  sort(el.begin(), el.end());

  int lt = 0;
  int rt = (int)(1e9 + 1);

  while (lt <= rt) {
    int mid = (lt + rt) / 2;
    if (dfs(mid)) {
      ans = min(ans, mid);
      rt = mid - 1;
    } else {
      lt = mid + 1;
    }
  }

  int diff = 0, cnt = 0;

  int idx = K;
  for (int k = K - 1;k >= 0;k--) {
    diff += el[k + 1] - el[k];
    if (diff > ans) {
      cnt++;
      diff = el[k + 1] - el[k];
      idx = k + 1;
    }
  }

  if (cnt < C) idx = 1;
  printf("%d %d\n", ans, el[idx]);
  return 0;

}

