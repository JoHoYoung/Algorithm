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

int N, K;

int board[2001][2001];
int p[100001];

int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};

int parent(int idx) {
  while (idx != p[idx]) idx = p[idx];
  return idx;
}

void uni(int a, int b) {
  a = parent(a);
  b = parent(b);
  if (a > b) p[b] = a;
  else p[a] = b;
}

queue<P> Q;
queue<P> Q2;

// merge BFS;
void bfs() {
  while (!Q.empty()) {
    P cur = Q.front();
    Q.pop();
    Q2.push(cur);
    int curI = cur.first;
    int curJ = cur.second;

    for (int d = 0; d < 4; d++) {
      int ni = curI + Di[d];
      int nj = curJ + Dj[d];
      if (ni <= 0 || ni > N || nj <= 0 || nj > N) continue;
      if (board[ni][nj] > -1 && board[ni][nj] != board[curI][curJ]) {
        int pa = parent(board[curI][curJ]);
        int pb = parent(board[ni][nj]);
        if (pa == pb) continue;
        uni(pa, pb);
        K--;
      }
    }
  }
}

void bfs2() {

  while (!Q2.empty()) {
    P cur = Q2.front();
    Q2.pop();
    int curI = cur.first;
    int curJ = cur.second;
    for (int d = 0; d < 4; d++) {
      int ni = curI + Di[d];
      int nj = curJ + Dj[d];
      if (ni <= 0 || ni > N || nj <= 0 || nj > N) continue;
      if (board[ni][nj] != -1) continue;
      board[ni][nj] = board[curI][curJ];
      Q.push({ni, nj});
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K;
  memset(board, -1, sizeof(board));

  int cont = 1;
  for (int i = 0; i < K; i++) {
    p[i + 1] = i + 1;
    int a, b;
    cin >> a >> b;
    board[a][b] = cont++;
    Q.push({a, b});
  }


  for (int k = 0; k <= K; k++) p[k] = k;
  int ans = 0;

  while (1) {
    bfs();
    if (K == 1) {
      cout << ans << '\n';
      return 0;
    }
    bfs2();
    ans++;
  }
}

