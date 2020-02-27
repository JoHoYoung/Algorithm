#include <iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;
using P = pair<int, int>;

int tc, N, M;
int board[200002];
int tree[800008];
int pos[100001];

int init(int node, int l, int r) {
  if (l == r) {
    if (l <= M) {
      return tree[node] = 0;
    } else {
      return tree[node] = 1;
    }
  }
  int mid = (l + r) / 2;
  return tree[node] = init(node * 2, l, mid) + init(node * 2 + 1, mid + 1, r);
}

void update(int index, int node, int dif, int l, int r) {
  if (index < l || index > r) return;
  tree[node] += dif;
  // cout<<"Update at "<<node<<" += "<<dif<<endl;
  if (l != r) {
    int mid = (l + r) / 2;
    update(index, node * 2, dif, l, mid);
    update(index, node * 2 + 1, dif, mid + 1, r);
  }
}

int query(int node, int start, int end, int l, int r) {
  if (start > r || end < l) return 0;
  if (start >= l && end <= r) return tree[node];
  int mid = (start + end) / 2;
  return query(node * 2, start, mid, l, r) + query(node * 2 + 1, mid + 1, end, l, r);
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> tc;
  int t = 0;
  while (t < tc) {

    vector<int> R;

    cin >> N >> M;

    int leftest = M + 1;

    for (int i = 1; i <= N; i++) {
      pos[i] = M+i;
    }

    init(1, 1, M+N);

    for (int i = 0; i < M; i++) {
      cin >> board[i];
    }

    for (int i = 0; i < M; i++) {
      R.push_back(query(1, 1, M + N, 1, pos[board[i]] - 1));
      update(pos[board[i]], 1, -1, 1, M+N);
      update(--leftest, 1, 1, 1, M+N);
      pos[board[i]] = leftest;
    }

    for (auto it = R.begin(); it != R.end(); it++) {
      cout << *it << " ";
    }
    cout << endl;
    t++;
  }
  return 0;
}