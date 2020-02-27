#include <iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;
using P = pair<int, int>;

int N, M;
int h[100001];
int tree[400004];

int MIN = 10000000000;

int init(int node, int l, int r) {
  if (l == r) return tree[node] = l;
  int mid = (l + r) / 2;
  int left = init(node * 2, l, mid);
  int right = init(node * 2 + 1, mid + 1, r);
  return tree[node] = h[left] < h[right] ? left : right;
}

int query(int node, int start, int end, int l, int r) {

  if (start > r || end < l) return 0;
  if (start >= l && end <= r) return tree[node];

  int mid = (start + end) / 2;

  int left = query(node * 2, start, mid, l, r);
  int right = query(node * 2 + 1, mid + 1, end, l, r);

  return h[left] < h[right] ? left : right;
}

long long int sol(int l, int r) {
  int minColPosition = query(1, 1, N, l, r);
  long long area = (long long int)h[minColPosition] * (r - l + 1);
  if (minColPosition > l) {
    area = max(area, sol(l, minColPosition - 1));
  }
  if (minColPosition < r) {
    area = max(area, sol(minColPosition + 1, r));
  }
  return area;
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  h[0] = MIN;

  while (1) {
    cin >> N;
    if (N == 0) break;
    for (int i = 1; i <= N; i++) {
      cin >> h[i];
    }
    init(1, 1, N);
    cout << sol(1, N) << "\n";
  }
  return 0;
}