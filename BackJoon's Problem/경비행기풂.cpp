#include <iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>

using namespace std;

int min(int a, int b) {
  if (a > b) return b;
  return a;
}

int result = 1000000;
int N, K;


struct pos {
    int i, j;
};
long long dist[1002][1002];
bool visited[1002];
long long limit;
vector<pos> V;

bool isFind = false;

void dfs(int i, int j, int depth, int idx) {

  if (depth > K) return;
  if (isFind) return;

  visited[idx] = true;
  for (int v = 1; v <= N + 1; ++v) {
    pos now = V[v];
    int nextI = now.i;
    int nextJ = now.j;

    if (dist[idx][v] > limit * 10 * limit * 10) continue;
    if (nextI == 10000 && nextJ == 10000) {
      visited[v] = true;
      isFind = true;
      return;
    }

    if (visited[v]) continue;
    if (!isFind && depth + 1 <= K) {
      dfs(nextI, nextJ, depth + 1, v);
    }
  }
}


int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K;

  int i, j;

  V.push_back(pos{0, 0});
  for (int tc = 0; tc < N; tc++) {
    cin >> i >> j;
    V.push_back(pos{i, j});
  }
  V.push_back(pos{10000, 10000});

  for (int i = 0; i <= N; ++i) {
    for (int j = i; j <= N + 1; ++j) {
      if (i == j) dist[i][j] = 1e9;
      else dist[i][j] = dist[j][i] = pow(V[i].i - V[j].i, 2) + pow(V[i].j - V[j].j, 2);
    }
  }
  int left = 0;
  int right = 10001;

  while (left <= right) {
    memset(visited, 0, sizeof(visited));
    limit = (left + right) / 2;

    visited[0] = true;
    isFind = false;
    dfs(0, 0, 0, 0);
    if (isFind) {
      result = min(result, limit);
      right = limit - 1;
    } else {
      left = limit + 1;
    }
  }
  cout << result;
  return 0;
}

