#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>

#define MAXN 31
#define INF 987654321
#define MAX 1000000

using namespace std;
using ll = long long;
using P = pair<int, int>;

int R, C;
char board[10001][1001];
// 돌을 m개 제거
// 중복되는 최대길이
// 중복이 있는 최대길이

vector<string> el;

int max(int a, int b) {
  return a > b ? a : b;
}

bool isTrue(int mid) {
  set<string> s;
  for (int i = 0; i < el.size(); i++) s.insert(el[i].substr(el[i].size() - mid, el[i].size()));
  return s.size() == el.size();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> R >> C;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> board[i][j];
    }
  }
  for (int j = 0; j < C; j++) {
    string s;
    for (int i = 0; i < R; i++) {
      s.push_back(board[i][j]);
    }
    el.push_back(s);
  }
  int l = 0;
  int r = el[0].size();
  int ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    //중복이 나타나면
    if (!isTrue(mid)) {
      l = mid + 1;
      ans = max(ans, mid);
      // 중복이 나타나지 않으면
    } else {
      r = mid - 1;
    }
  }
  cout << (el[0].size() - ans) - 1;
  return 0;
}
