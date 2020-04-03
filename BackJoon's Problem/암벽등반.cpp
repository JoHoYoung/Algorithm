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

int abs(int a) {
  return a < 0 ? -a : a;
}

int n, T;
bool visited[50001];

vector<P> el;

int ans = INF;

int min(int a, int b) {
  return a > b ? b : a;
}

bool cmp(P a, P b) {
  if (a.first == b.first) {
    return a.second < b.second;
  }
  return a.first < b.first;
}

// target보다 크거나 같은 처음 인덱스
int lower_index(int target) {
  int l = 0;
  int r = el.size()-1;
  while (l < r) {
    int mid = (l + r) / 2;
    if (el[mid].first < target) l = mid + 1;
    else r = mid;
  }
  return r;
}


typedef struct unit {
    int x, y, d;
};

bool canGo(P from, P to) {
  return abs(from.first - to.first) <= 2 && abs(from.second - to.second) <= 2;
}

void BFS() {
  queue<unit> Q;
  Q.push({0, 0, 0});
  visited[0] = true;
  while (!Q.empty()) {
    int curX = Q.front().x;
    int curY = Q.front().y;
    int curD = Q.front().d;
    Q.pop();
    if (curY >= T) {
      ans = min(ans, curD);
      return;
    }
    int l = lower_index(curX - 2);
    int r = lower_index(curX + 3);
    for (int i = l; i <= r; i++) {
      if (visited[i] || !canGo({curX, curY}, el[i])) continue;
      visited[i] = true;
      Q.push({el[i].first, el[i].second, curD + 1});
    }

  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> T;
  el.push_back({0, 0});
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    el.push_back({x, y});
  }
  memset(visited, false, sizeof(visited));

  sort(el.begin(), el.end(), cmp);
  BFS();

  if (ans == INF)cout << -1;
  else cout << ans;

}

