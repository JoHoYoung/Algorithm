#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>

#define MAXN 31
#define INF 98765432
#define MAX 1000000

using namespace std;
using ll = long long;

typedef struct P {
    int k, i, j;
};

typedef struct unit {
    P p;
    int depth;
};

P S, E;

int Di[6] = {0, 0, -1, 0, 1, 0};
int Dj[6] = {0, 0, 0, 1, 0, -1};
int Dk[6] = {1, -1, 0, 0, 0, 0};

int L, R, C;

char board[31][31][31];
int visited[31][31][31];

void BFS() {
  queue<unit> Q;
  visited[S.k][S.i][S.j] = 0;
  Q.push({S.k,S.i,S.j});
  while (!Q.empty()) {
    unit cur = Q.front();
    Q.pop();
    P curP = cur.p;
    int curD = cur.depth;
    //cout<<curP.k<<" "<<curP.i<<" "<<curP.j<<" dep "<<curD<<endl;
    for (int d = 0; d < 6; d++) {
      int ni = curP.i + Di[d];
      int nj = curP.j + Dj[d];
      int nk = curP.k + Dk[d];

      if(ni < 0 || nj < 0 || nk < 0 || ni > R-1 || nj > C-1 || nk > L-1 || visited[nk][ni][nj] != -1) continue;
      if(board[nk][ni][nj] == '#') continue;
      visited[nk][ni][nj] = curD + 1;
     // cout<<"PUSH"<<endl;
      Q.push({{nk,ni,nj},curD + 1});
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  while (1) {
    cin >> L >> R >> C;
    if (L == 0 && R == 0 && C == 0) return 0;
    memset(visited, -1, sizeof(visited));
    for (int k = 0; k < L; k++) {
      for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
          cin >> board[k][i][j];
          if (board[k][i][j] == 'S') S = {k, i, j};
          if (board[k][i][j] == 'E') E = {k, i, j};
        }
      }
    }
    BFS();
    if(visited[E.k][E.i][E.j] == -1) cout<<"Trapped!\n";
    else cout<<"Escaped in "<<visited[E.k][E.i][E.j]<<" minute(s).\n";

  }
}

