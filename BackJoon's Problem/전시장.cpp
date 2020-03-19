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

int N, S;

int max(int a, int b) {
  if (a > b) return a;
  return b;
}

bool cmp(P a, P b) {
  return a.first < b.first;
}

vector<P> el;

int upperBound(int target, int eidx) {
  int l = 0;
  int r = eidx - 1;

  while (l <= r) {
    int mid = (l + r) / 2;
    if (el[mid].first > target) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return r;
}

int DP[300000];
int accMax[300000];

void sol() {
  DP[0] = el[0].second;
  accMax[0] = DP[0];
  for (int i = 1; i < el.size(); i++) {
    int h = el[i].first;
    int c = el[i].second;
    int upperb = upperBound(h - S, i);
    if (upperb == -1) DP[i] = max(DP[i - 1], c);
    else DP[i] = max(accMax[upperb] + c, DP[i - 1]);
    accMax[i] = DP[i] > accMax[i - 1] ? DP[i] : accMax[i - 1];
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> S;
  for (int i = 0; i < N; i++) {
    int h, c;
    cin >> h >> c;
    el.push_back({h, c});
  }
  sort(el.begin(), el.end(), cmp);
  sol();
  cout << DP[N - 1];
  return 0;
}

