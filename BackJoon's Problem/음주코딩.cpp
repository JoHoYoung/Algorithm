#include <iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include <bitset>

using namespace std;
using P = pair<int, int>;


int N, K;

int board[100001];

vector<int> R(10);

// 펜윅트리 //
// 탐색 : 최하위 1 지우면서
// 업데이트 : 최하위 1에 1 더하면서
int tree[400004];
void update(int index, int node, int target, int l, int r) {
  if (index < l || index > r) return;
  if (l != r) {
    int mid = (l + r) / 2;
    update(index, node * 2, target, l, mid);
    update(index, node * 2 + 1, target, mid + 1, r);
    tree[node] = tree[node * 2] * tree[node * 2 + 1];
  } else {
    tree[node] = target;
  }
}

int query(int node, int start, int end, int l, int r) {
  if (start > r || end < l) return 1;
  if (start >= l && end <= r) return tree[node];
  int mid = (start + end) / 2;
  return query(node * 2, start, mid, l, r) * query(node * 2 + 1, mid + 1, end, l, r);
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while (cin >> N) {
    cin >> K;
    memset(tree, 1, sizeof(tree));
    for (int i = 1; i <= N; i++) {
      update(i, 1, 1, 1, N);
    }

    for (int i = 1; i <= N; i++) {
      cin >> board[i];
      if(board[i]> 0){
        board[i] = 1;
      }
      if(board[i] < 0){
        board[i] = -1;
      }
      update(i, 1, board[i], 1, N);
    }


    vector<char> R;
    char a;
    int b, c;
    for (int i = 0; i < K; i++) {
      cin >> a >> b >> c;
      if (a == 'C') {
        if (c > 0) {
          c = 1;
        }
        if (c < 0) {
          c = -1;
        }
        update(b, 1, c, 1, N);
        board[b] = c;
      } else {
        int result = query(1, 1, N, b, c);
        if (result == 0) {
          R.push_back('0');
        } else if (result > 0) {
          R.push_back('+');
        } else {
          R.push_back('-');
        }
      }
    }

    for (auto it = R.begin(); it != R.end(); it++) {
      cout << *it;
    }
    cout << "\n";

  }

  return 0;
}