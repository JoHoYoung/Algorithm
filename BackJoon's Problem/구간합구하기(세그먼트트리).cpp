#include <iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;
using P = pair<int, int>;

long long N, M, K, a, b, c;

long long data[1000000];
long long tree[5000000];
// update: 변경하고자하는 노드번호, 변경하려는 값, 레프트는1번, 라이트는 n으로
// 높이는 logN 배열은 (2^높이+1)

long long init(int l, int r, int node) {

  if (l == r) {
    return tree[node] = data[l];
  }
  int mid = (l + r) / 2;
  return tree[node] = init(l, mid, node * 2) + init(mid + 1, r, node * 2 + 1);
}

void update(int index, int dif, int node, int l, int r) {
  if (index < l || index > r)
    return;
  tree[node] += dif;
  //cout<<"ADD to "<<node<<" this "<<dif<<endl;
  if (l != r) {
    long long mid = (l + r) / 2;
    update(index, dif, node * 2, l, mid);
    update(index, dif, node * 2 + 1, mid + 1, r);
  }
}

long long sum(int node, int start, int end, int l, int r) {
  if (end < l || start > r) return 0;
  if (start >= l && end <= r) return tree[node];
  int mid = (start + end) / 2;
  return sum(node * 2, start, mid, l, r) + sum(node * 2 + 1, mid + 1, end, l, r);
}


int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> K;
  for (int i = 0; i < N; i++) {
    cin >> data[i];
  }

  init(0, N - 1, 1);
  vector<long long> result;
  for (int i = 0; i < M + K; i++) {
    cin >> a >> b >> c;
    b--;
    if (a == 2) {
      c--;
      result.push_back(sum(1, 0, N - 1, b, c));
    } else {
      update(b, c - data[b], 1, 0, N - 1);
      data[b] = c;
    }
  }
  for (auto it = result.begin(); it != result.end(); it++) {
    cout << *it << "\n";
  }

  return 0;
}