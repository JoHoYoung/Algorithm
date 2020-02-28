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
int board[1025][1025];
vector<vector<long long>> tree;
// 펜윅트리 //
// 탐색 : 최하위 1 지우면서
// 업데이트 : 최하위 1에 1 더하면서

void update(int x, int y, int dif) {
  for (int i = x; i <= N; i += (i & -i)) {
    for (int j = y; j <= N; j += (j & -j)) {
      tree[i][j] += dif;
    }
  }
}

long long query(int x, int y) {
  long long sum = 0;
  for (int i = x; i > 0; i -= (i & -i)) {
    for (int j = y; j > 0; j -= (j & -j)) {
      sum += tree[i][j];
    }
  }
  return sum;
}

void init() {
  for (int i = 0; i <= N; i++) {
    vector<long long> a(N + 1, 0);
    tree.push_back(a);
  }
}

long long getWidth(int x1, int y1, int x2, int y2) {
  long long result = 0;
  result += query(x2, y2);
  result -= query(x1 - 1, y2);
  result -= query(x2, y1 - 1);
  result += query(x1 - 1, y1 - 1);
  return result;
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;

  init();
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> board[i][j];
      update(i, j, board[i][j]);
    }
  }

  int w, x, y, c, x1, y1, x2, y2;

  vector<long long> R;

  for (int i = 0; i < M; i++) {
    cin >> w;
    if (w == 0) {
      cin >> x >> y >> c;
      update(x, y, c - board[x][y]);
      board[x][y] = c;
    } else {
      cin >> x1 >> y1 >> x2 >> y2;
      R.push_back(getWidth(x1, y1, x2, y2));
    }
  }
  for (auto it = R.begin(); it != R.end(); it++) {
    cout << *it << "\n";
  }

  return 0;
}