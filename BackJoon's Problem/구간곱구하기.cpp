#include <iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;
using P = pair<int, int>;

long long DIV = 1000000007;

int N, M, K;
int board[1000001];
long long tree[4000001];

long long init(int node, int l, int r) {
  if (l == r) return tree[node] = board[l];
  int mid = (l + r) / 2;
  return tree[node] = ((init(node * 2, l, mid) % DIV) * (init(node * 2 + 1, mid + 1, r) % DIV)) % DIV;
}

void update(int index, int value, int node, int l, int r) {
  if (index < l || index > r) return;
  if (l != r) {
    int mid = (l + r) / 2;
    update(index, value, node * 2, l, mid);
    update(index, value, node * 2 + 1, mid + 1, r);
    tree[node] = ((tree[node*2]%DIV) * (tree[node*2+1]%DIV))%DIV;
  }else{
    tree[node] = value;
  }
}

long long query(int node, int start, int end, int l, int r) {
  //cout<<start<<" "<<end<<" "<<l<<" "<<r<<endl;
  if (start > r || end < l) return 1;
  if (start >= l && end <= r) return tree[node];
  int mid = (start + end) / 2;
  return ((query(node * 2, start, mid, l, r) % DIV) * (query(node * 2 + 1, mid + 1, end, l, r) % DIV)) % DIV;
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> K;
  for (int i = 1; i <= N; i++) {
    cin >> board[i];
  }
  int a, b, c;
  init(1, 1, N);
  vector<long long> R;
  for (int i = 0; i < M + K; i++) {
    cin >> a >> b >> c;
    if (a == 1) {
      update(b, c, 1, 1, N);
      board[b] = c;
    } else {
      R.push_back(query(1, 1, N, b, c) % DIV);
    }
  }
  for (auto it = R.begin(); it != R.end(); it++) {
    cout << *it << "\n";
  }
  return 0;
}