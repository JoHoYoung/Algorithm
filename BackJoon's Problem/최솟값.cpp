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

int data[100001];
int tree[400004];

int MIN = 2000000000;

int min(int a, int b) {
  if (a > b) return b;
  return a;
}

int init(int node, int l, int r) {
  if (l == r) return tree[node] = data[l];
  int mid = (l + r)/2;
  return tree[node] = min(init(node * 2, l, mid), init(node * 2+1, mid + 1, r));
}

// node 노드가 가질수있는 L,r 의 범위가 들어옴
void update(int index, int node, int target, int l, int r) {
  if (index < l || index > r) return;

  tree[node] = min(tree[node], target);
  if (l != r) {
    int mid = (l + r) / 2;
    update(index, node * 2, target, l, mid);
    update(index, node * 2, target, mid + 1, r);
  }
}

int query(int node, int start, int end, int l, int r){
  if(end < l || start > r) return MIN;
  if(end <= r && start >= l) return tree[node];
  int mid = (start + end)/2;
  return min(query(node*2, start, mid, l,r ), query(node*2+1, mid +1, end, l, r));
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    cin >> data[i];
  }
  int a, b;

  init(1,1,N);
  vector<int> result;


  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    result.push_back(query(1,1,N,a,b));
  }

  for(auto it = result.begin(); it != result.end(); it++){
    cout<<*it<<"\n";
  }
  return 0;
}