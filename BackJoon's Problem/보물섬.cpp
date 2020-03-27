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

int N, M;
char board[51][51];
int visited[51][51];

int max(int a, int b) {
  return a > b ? a : b;
}

int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};

int ans = -1;
void BFS(P S) {
  queue<P> Q;
  Q.push(S);
  visited[S.first][S.second] = 0;
  while (!Q.empty()) {

    int curI = Q.front().first;
    int curJ = Q.front().second;
    Q.pop();

    for(int d =0;d<4;d++){
      int ni = curI + Di[d];
      int nj = curJ + Dj[d];
      if(ni< 0||ni>N-1 || nj<0||nj>M-1) continue;
      if(visited[ni][nj] != -1 || board[ni][nj] == 'W') continue;
      visited[ni][nj] = visited[curI][curJ]+1;
      ans = max(ans, visited[ni][nj]);
      Q.push({ni,nj});
    }
  }

}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] == 'W') continue;
      memset(visited, -1, sizeof(visited));
      BFS({i, j});
    }
  }
  cout<<ans;
  return 0;
}

