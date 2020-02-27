#include <iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;
using P = pair<int, int>;

int N, Q;
long long board[100001];
long long tree[400004];

long long init(int node, int l, int r) {
  if (l == r) {
   // cout<<node<<" with"<<board[l];
    return tree[node] = board[l];
  }
  int mid = (l + r) / 2;
  return tree[node] = init(node * 2, l, mid) + init(node * 2 + 1, mid + 1, r);
}

void update(int index, long long dif, int node, int l, int r) {
  if (index < l || index > r) return;
  tree[node] += dif;
  if (l != r) {
    int mid = (l + r) / 2;
    update(index, dif, node * 2, l, mid);
    update(index, dif, node * 2+1, mid + 1, r);
  }
}

long long query(int node, int start, int end, int l, int r) {
  if (start > r || end < l) return 0;
  if (start >= l && end <= r) return tree[node];
  int mid = (start + end) / 2;
  return query(node * 2, start, mid, l, r) + query(node * 2 + 1, mid + 1, end, l, r);
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> Q;
  for (int i = 1; i <= N; i++) {
    cin >> board[i];
  }

  init(1,1,N);
  int x, y, a, b;
  vector<long long> R;
  for (int i = 0; i < Q; i++) {
    cin >> x >> y >> a >> b;
    if (x > y) {
      long dif = x - y;
      x = y;
      y += dif;
    }
    R.push_back(query(1, 1, N, x, y));
    update(a, b - board[a], 1, 1, N);

    board[a] = b;
    //cout<<a<<" "<<board[a]<<endl;
  }
  for (auto it = R.begin(); it != R.end(); it++) {
    cout << *it << "\n";
  }

  return 0;
}