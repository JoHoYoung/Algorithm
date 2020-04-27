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

int N;
char board[51][51];
int H[51][51];
bool visited[51][51];

P S;
vector<P> E;

vector<int> el;

int Di[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int Dj[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int vv = 0;

void BFS(int l, int h) {

  if (H[S.first][S.second] < l || H[S.first][S.second] > h) return;
  queue<P> Q;
  Q.push({S.first, S.second});
  visited[S.first][S.second] = true;
  while (!Q.empty()) {
    P cur = Q.front();
    Q.pop();
    if (board[cur.first][cur.second] == 'K') vv++;

    for (int d = 0; d < 8; d++) {
      int ni = cur.first + Di[d];
      int nj = cur.second + Dj[d];
      if (ni < 0 || nj < 0 || ni > N - 1 || nj > N - 1 || visited[ni][nj] || H[ni][nj] < l || H[ni][nj] > h) continue;
      visited[ni][nj] = true;
      Q.push({ni, nj});
    }
  }
}


int revv = 0;
// 가장 작은 피로도
int ans = INF;

int min(int a, int b) {
  return a > b ? b : a;
}


int main() {

  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'P') S = {i, j};
      if (board[i][j] == 'K') revv++;

    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> H[i][j];
      el.push_back(H[i][j]);
    }
  }

  sort(el.begin(), el.end());
  int l = 0;
  int r = 0;
  while (r < el.size()) {
    while (l < el.size()) {
      vv = 0;
      memset(visited, false, sizeof(visited));
      BFS(el[l], el[r]);
      if (vv == revv) {
        ans = min(ans, el[r] - el[l]);
        l++;
      } else {
        break;
      }
    }
    r++;
  }
  cout << ans;
  return 0;
}

