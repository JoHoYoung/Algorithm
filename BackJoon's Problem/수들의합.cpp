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

ll tree[4000004];

ll query(int node, int start, int end, int l, int r) {
  if (start > r || end < l) return 0;
  if (start >= l && end <= r) return tree[node];
  int mid = (start + end) / 2;
  return query(node * 2, start, mid, l, r) + query(node * 2 + 1, mid + 1, end, l, r);
}

void update(int idx, int node, int l, int r, int dif) {
  if (idx < l || idx > r) return;
  if (l != r) {
    int mid = (l + r) / 2;
    update(idx, node * 2, l, mid, dif);
    update(idx, node * 2 + 1, mid + 1, r, dif);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
  } else {
    tree[node] = dif;
  }
}

//켜거나끄거나
//부분합
void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  memset(tree, false, sizeof(tree));

  for (int i = 0; i < M; i++) {
    int O, S, T;
    cin >> O >> S >> T;
    if (O == 1) {
      update(S, 1, 1, N, T);
    } else {
      if (S > T) swap(S, T);
      cout << query(1, 1, N, S, T) << "\n";
    }
  }
  return 0;
}