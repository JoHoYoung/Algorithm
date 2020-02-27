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
int M;

int MIN = 2000000000;
int MAX = -1;

int min(int a, int b) {
  if (a > b) return b;
  return a;
}

int max(int a, int b) {
  if (a > b) return a;
  return b;
}

int board[100001];
P tree[400004];

P init(int node, int l, int r) {

  if (l == r)
    return tree[node] = {board[l], board[l]};
  int mid = (l + r) / 2;
  P left = init(node * 2, l, mid);
  P right = init(node * 2 + 1, mid + 1, r);

//  cout<<"init none leaf "<<node<<" "<<min(left.first, right.first)<<" "<<max(left.second, right.second)<<endl;
  return tree[node] = {min(left.first, right.first), max(left.second, right.second)};
}

// index는 데이터의 인덱스와, 트리 매칭 판단
void update(int index, int target, int node, int l, int r) {

  if (index < l || index > r) return;

  tree[node].first = min(tree[node].first, target);
  tree[node].second = max(tree[node].second, target);

  if (l != r) {
    int mid = (l + r) / 2;
    update(index, target, node * 2, l, mid);
    update(index, target, node * 2 + 1, mid, r);
  }
}

P query(int node, int start, int end, int l,int r){

  if(start > r || end < l) return {MIN, MAX};
  if(start >= l && end <= r) return tree[node];

  int mid = (start + end)/2;
  P left = query(node*2, start, mid, l, r);
  P right = query(node*2 + 1, mid +1 ,end, l, r);
  return {min(left.first, right.first), max(left.second, right.second)};

}
int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    cin >> board[i];
  }
  init(1, 1, N);
  vector<P> result;
  int a,b;
  for(int i=0;i<M;i++){
    cin >>a>>b;
    result.push_back(query(1, 1, N, a, b));
  }

  for(auto it = result.begin(); it != result.end(); it++){
    cout<<(*it).first<<" "<<(*it).second <<"\n";
  }

  return 0;
}