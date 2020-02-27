#include <iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;
using P = pair<int, int>;

int tree[4000004];

int N;

int init(int node, int l, int r) {
  if (l == r) return tree[node] = 0;
  int mid = (l + r) / 2;
  return tree[node] = init(node * 2, l, mid) + init(node * 2 + 1, mid + 1, r);
}

void update(int index, int node, int dif, int l, int r) {
  if (index < l || index > r) return;
  tree[node] += dif;
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
  cin >> N;

  vector<int> R;
  init(1,1,1000000);
  for (int i = 0; i < N; i++) {
    int A, B, C;
    cin >> A;

    // ������ �ִ� ���
    if (A == 2) {
      cin >> B >> C;
      update(B, 1, C, 1, 1000000);
      // ������ ���� ���
    } else {
      cin >> B;
      // ���� �������� �̺� Ž��
      int left =0;
      int right = 1000000;
      while(left<= right){
        int mid = (left + right)/2;
        // mid���� �����ų� �Ȱ��� ������ ������ ã������ �������� ������, ���� �÷�
        // ������ �װ� ��
        int pivot = query(1,1,1000000, 1, mid);
        // ������ �÷�
        if(pivot<B){
          left = mid+1;
          // ũ�ų� ������ �ٿ�
        }else{
          right = mid -1;
        }
      }
      R.push_back(left);
      update(left, 1, -1, 1,1000000);
    }
  }
  for(auto it = R.begin(); it!=R.end();it++){
    cout<<*it<<"\n";
  }
  return 0;
}