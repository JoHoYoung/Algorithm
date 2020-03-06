#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;
using P = pair<int, int>;
const int INF = 987654321;

int N, L, R;
int board[101][101];

// 차이가 1인곳에만 경사로 놓을 수 있다 겹치는거안됨
// 경사로는 연속된 총 L의 길이를 차지함
//한쪽?에서 다른끝으로

vector<vector<int>> road;

bool hasContinuous(vector<int> a, int from, int d, int target, bool *visited) {

  int cur = from;
  int cnt = 0;
  while (1) {
    if (cnt == L) return true;
    if (cur < 0 || cur > N - 1 || visited[cur] || a[cur] != target) return false;
    cnt++;
    visited[cur] = true;
    cur += d;
  }
}

bool canGo(vector<int> a) {
  bool visited[N];
  memset(visited, false, sizeof(visited));
  int upper = a[0];
  for (int i = 1; i < a.size(); i++) {
    int cur = a[i];
    int dif = cur - upper;
    if (dif > 1 || dif < -1) return false;
    if (dif == 0) continue;
    if (dif == -1 && hasContinuous(a, i, 1, cur, visited)) {
      upper = cur;
      continue;
    }
    if (dif == 1 && hasContinuous(a, i - 1, -1, upper, visited)) {
      upper = cur;
      continue;
    }
    return false;
  }
  return true;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> L;

  vector<int> col[N];
  for (int i = 0; i < N; i++) {
    vector<int> a;
    int temp;
    for (int j = 0; j < N; j++) {
      cin >> temp;
      col[j].push_back(temp);
      a.push_back(temp);
    }
    road.push_back(a);
  }
  for (int i = 0; i < N; i++) road.push_back(col[i]);

  int result = 0;
  for (int i = 0; i < road.size(); i++) {
    if (canGo(road[i])) result++;
  }
  cout << result;
  return 0;
}