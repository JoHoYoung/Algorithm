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
vector<int> seat;

int C, N, M;

int DP[10][2000];
char board[10][10];

int max(int a, int b) {
  if (a > b) return a;
  return b;
}

bool match(int n, int m) {
  return (m & (n * 2)) == 0 && (n & (m * 2)) == 0;
}

bool broken(int n, int depth) {

  for (int i = 0; i < M; i++) {
    int cand = 1 << i;
    if ((cand & n) == 0) continue;
    if (board[depth][i] == 'x') return false;
  }
  return true;
}

int count(int bit) {
  int ret = 0;
  while (bit) {
    if (bit & 1)++ret;
    bit >>= 1;
  }
  return ret;
}

int sol(int depth, int trace) {

  if (depth < 0) return 0;

  int &ref = DP[depth][trace];
  if (ref != -1) return ref;

  ref = 0;
  for (int i = 0; i < seat.size(); i++) {
    if (!match(trace, seat[i])) continue;
    if (!broken(seat[i], depth)) continue;
    ref = max(ref, count(seat[i]) + sol(depth - 1, seat[i]));
  }

  return ref;
}

void getseat() {
  seat.clear();
  for (int i = 0; i <= (1 << M) - 1; i++) {
    if (((i * 2) & i) == 0) {
      seat.push_back(i);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> C;
  while (C--) {
    cin >> N >> M;
    memset(DP, -1, sizeof(DP));
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        cin >> board[i][j];
      }
    }
    getseat();
    cout << sol(N - 1, 0) << '\n';
  }
}

