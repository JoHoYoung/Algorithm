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
int board[101][101];
bool visited[101][101];
// »¡°£»ö¸¸ ±¸¸Û¿¡ ºüÁ®
int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};

int abs(int a) {
  return a > 0 ? a : -a;
}
int min(int a, int b) {
  return a > b ? b : a;
}

int max(int a, int b) {
  return a > b ? a : b;
}

typedef struct unit{
  int i,j,m,M;
};

void BFS(int l,int r) {
  queue<P> Q;
  Q.push({0, 0});
  memset(visited, false, sizeof(visited));
  visited[0][0] = true;
  if(board[0][0] < l || board[0][0] > r) return;
  while (!Q.empty()) {
    P cur = Q.front();
    int curI = cur.first;
    int curJ = cur.second;

    Q.pop();
    for (int d = 0; d < 4; d++) {
      int ni = curI + Di[d];
      int nj = curJ + Dj[d];
      if (ni < 0 || ni > N - 1 || nj < 0 || nj > N - 1 || visited[ni][nj]) continue;
      if(board[ni][nj] < l || board[ni][nj] > r) continue;
      visited[ni][nj] = true;
      Q.push({ni, nj});
    }
  }
}

int ans = INF;

set<int> s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
      s.insert(board[i][j]);
    }
  }
  auto l = s.begin();
  auto r = s.begin();
  while(r != s.end()){
    while(l != s.end()){
      BFS(*l, *r);
      if(visited[N-1][N-1]){
        ans = min((*r - *l),ans);
        l++;
      }else{
        break;
      }
    }
    r++;
  }
  cout<<ans;
  return 0;
}


