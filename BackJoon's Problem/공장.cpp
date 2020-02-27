#include <iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;
using P = pair<int, int>;

int N;

int A[500001];
int B[1000001];
long long tree[2000004];

int init(int node, int l, int r) {
  if (l == r) return tree[node] = 0;
  int mid = (l + r) / 2;
  return tree[node] = init(node * 2, l, mid) + init(node * 2 + 1, mid + 1, r);
}

long long query(int node, int start, int end, int l, int r) {

  if (start > r || end < l) return 0;
  if (start >= l && end <= r) {
    return tree[node];
  }
  int mid = (start + end) / 2;
  return query(node * 2, start, mid, l, r) + query(node * 2+1, mid + 1, end, l, r);
}

void update(int index, int dif, int node, int l, int r) {

  if (index < l || index > r) return;
  tree[node] += dif;

  if(l != r){
    int mid = (l + r) / 2;
    update(index, dif, node * 2, l, mid);
    update(index, dif, node * 2 + 1, mid + 1, r);
  }
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  int temp;
  for (int i = 1; i <= N; i++) {
    cin >> temp;
    B[temp] = i;
  }

  init(1,1,N);
  long long result = 0;

  for (int i = 1; i <= N; i++) {
   // cout<<B[A[i]]<<" ~ "<<N<<endl;
    result += query(1, 1, N, B[A[i]], N);
   // cout<<result<<endl;
    update(B[A[i]], 1, 1, 1, N);
  }

  cout<<result;
  return 0;
}