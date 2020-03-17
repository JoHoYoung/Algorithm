#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>

#define INF 987654321
#define MAX 1000000
using namespace std;
using ll = long long;
using P = pair<int, int>;

int N, M;

int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};

bool visited[51][51];
int DP[51][51];
char el[51][51];

bool cycle = false;

int max(int a, int b) {
  if (a > b) return a;
  return b;
}

int sol(int i, int j) {

  if (cycle) return -1;

  if (visited[i][j]) {
    cycle = true;
    return -1;
  }

  int &ref = DP[i][j];
  if (ref != -1) return ref;
  visited[i][j] = true;
  ref = 0;

  int cur = el[i][j] - '0';
  for (int d = 0; d < 4; d++) {
    int ni = i + cur * Di[d];
    int nj = j + cur * Dj[d];
    if (ni < 0 || ni > N - 1 || nj > M - 1 || nj < 0 || el[ni][nj] == 'H') continue;
    ref = max(ref, 1 + sol(ni, nj));
  }
  visited[i][j] = false;
  if (cycle) return -1;
  return ref;
}


int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(visited, false, sizeof(visited));
  memset(DP, -1, sizeof(DP));

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> el[i][j];
    }
  }

  int re = sol(0, 0);
  if (re == -1) cout << -1<<'\n';
  else cout << re + 1<<'\n';
  return 0;
}

