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

int tree[400004];
int lazy[400004];

void s_lazy(int node, int l, int r) {
  if (!lazy[node]) return;
  tree[node] = (r - l + 1) - tree[node];
  if (l != r) {
    lazy[node * 2] ^= 1;
    lazy[node * 2 + 1] ^= 1;
  }
  lazy[node] = 0;
}

int query(int node, int start, int end, int l, int r) {
  s_lazy(node, start, end);
  if (end < l || r < start) return 0;
  if (start >= l && end <= r)return tree[node];
  int mid = (start + end) / 2;
  return query(node * 2, start, mid, l, r) + query(node * 2 + 1, mid + 1, end, l, r);
}

int update(int l, int r, int node, int start, int end, int dif) {

  s_lazy(node, start, end);
  if (start > r || end < l) return tree[node];
  if (start >= l && end <= r) {
    lazy[node] ^= 1;
    s_lazy(node, start, end);
    return tree[node];
  }
  int mid = (start + end) / 2;
  return tree[node] = update(l, r, node * 2, start, mid, dif) + update(l, r, node * 2 + 1, mid + 1, end, dif);
}

int N, M;

// 인접간선이 없는 노드끼리의 집합
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 // cout << (0^1);
  cin >> N >> M;
  memset(tree, 0, sizeof(tree));
  memset(lazy, 0, sizeof(lazy));
  vector<int> re;
  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 0) {
      update(b, c, 1, 1, N,1);
    } else {
      re.push_back(query(1, 1, N, b, c));
    }
  }

  for (int i = 0; i < re.size(); i++) {
    cout << re[i] << '\n';
  }

}

