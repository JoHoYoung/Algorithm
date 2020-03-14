#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

#define INF 987654321

using namespace std;
using ll = long long;
using P = pair<int, int>;

int N;
int tree[160004];

int ans = -1;

vector<P> el;

void update(int idx, int node, int start, int end, int target) {
  if (idx < start || idx > end) return;
  tree[node] = max(tree[node],target);
  if (start != end) {
    int mid = (start + end) / 2;
    update(idx, node * 2, start, mid, target);
    update(idx, node * 2 + 1, mid + 1, end, target);
  }
}

int query(int node, int start, int end, int l, int r) {
  if (start > r || end < l) return 0;
  if (start >= l && end <= r) return tree[node];
  int mid = (start + end) / 2;
  return max(query(node * 2, start, mid, l, r),query(node * 2 + 1, mid + 1, end, l, r));
}

bool cmp(P A, P B) {
  return A.first < B.first;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    el.push_back({tmp, i + 1});
  }

  sort(el.begin(), el.end(), cmp);
  memset(tree, false, sizeof(tree));
  for (int i = 0; i < el.size(); i++) {
    int val = query(1, 1, N, 1, el[i].second - 1);
    ans = max(ans, val+1);
    update(el[i].second, 1, 1, N, val+1);
  }
  cout << ans;
  return 0;
}