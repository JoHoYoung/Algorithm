#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

#define MAXN 5000001
using namespace std;
//using P = pair<int, int>;

typedef struct P {
    int k, i, j, depth;
};
P S, E;
int L, R, C;
char board[31][31][31];
bool visited[31][31][31];
// 북 동 남 서 하 상

int Di[6] = {-1, 0, 1, 0, 0, 0};
int Dj[6] = {0, 1, 0, -1, 0, 0};
int Dk[6] = {0, 0, 0, 0, -1, 1};

queue<P> Q;
int result = MAXN;
bool isFind = false;
int min(int a, int b) {
  if (a > b) return b;
  return a;
}

void bfs() {
  while (!Q.empty()) {
    P now = Q.front();
    Q.pop();
    //cout<<now.k<<" "<<now.i<<" "<<now.j<<endl;
    if (now.k == E.k && now.i == E.i && now.j == E.j) {
      isFind = true;
     // cout<<"VISIT "<<E.k<<" "<<E.i<<" "<<E.j<<endl;
      result = min(result, now.depth);
    }

    for (int d = 0; d < 6; d++) {
      int nk = now.k + Dk[d];
      int ni = now.i + Di[d];
      int nj = now.j + Dj[d];

      if (nk < 0 || nk > L - 1 || ni < 0 || ni > R - 1 || nj < 0 || nj > C - 1 || visited[nk][ni][nj] || board[nk][ni][nj] == '#') continue;
      visited[nk][ni][nj] = true;
      //cout<<"VISIT "<<nk<<" "<<ni<<" "<<nj<<endl;
      Q.push({nk, ni, nj, now.depth + 1});
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  while(1){
    cin >>L >>R >> C;
    if(L==0 && R==0 && C==0)return 0;
    isFind = false;
    result = MAXN;
    while(!Q.empty()) Q.pop();
    memset(visited, false, sizeof(visited));
    for (int k = 0; k < L; k++) {
      for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
          cin >> board[k][i][j];
          if (board[k][i][j] == 'S') S = {k, i, j};
          if (board[k][i][j] == 'E') E = {k, i, j};
        }
      }
    }
    Q.push({S.k, S.i, S.j, 0});
    bfs();
    if(isFind){
      cout<<"Escaped in "<<result<<" minute(s).\n";
    }else{
      cout<<"Trapped!\n";
    }
  }
  return 0;
}
