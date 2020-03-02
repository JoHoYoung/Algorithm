#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;
using P = pair<int, int>;

int N;

int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};

int board[101][101];
bool visited[101][101];
int depth[101][101];

typedef struct unit {
    int i, j, color, depth;
};

queue<P> dstQ;

queue<unit> Q;
void distinctContinentBfs(int color) {
  while (!dstQ.empty()) {
    P now = dstQ.front();
    dstQ.pop();
    board[now.first][now.second] = color;
    Q.push({now.first,now.second, color, 0});
    // 위아래 좌우로 바다가 아닌지 검사 -1이면 육지인데, 위아래 또는 좌우중 하나가
    // 육지인 경우는 첫번째 뎁스 밖에 없음

    for (int d = 0; d < 4; d++) {
      int ni = now.first + Di[d];
      int nj = now.second + Dj[d];
      if (ni < 0 || ni > N - 1 || nj < 0 || nj > N - 1 || board[ni][nj] == 0 || visited[ni][nj]) continue;
      visited[ni][nj] = true;
      dstQ.push({ni, nj});
    }
  }
}

int result = 10000;
int min(int a,int b){
  if(a > b) return b;
  return a;
}
void BfsTravel() {
  while (!Q.empty()) {
    unit now = Q.front();
    Q.pop();
    for (int d = 0; d < 4; d++) {
      int ni = now.i + Di[d];
      int nj = now.j + Dj[d];
      if (ni < 0 || ni > N - 1 || nj < 0 || nj > N - 1 || board[ni][nj] == now.color) continue;
      if (board[ni][nj] != 0) {
      //  cout<<"TEMP : "<<now.depth + depth[ni][nj]<<endl;
        result =min(result, now.depth + depth[ni][nj]);
      //  return;
      } else {
        board[ni][nj] = now.color;
        depth[ni][nj] = now.depth + 1;
        visited[ni][nj] = true;
        Q.push({ni, nj, now.color, now.depth + 1});
      }
    }
  }
}

void print(int target[][101]){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cout<<target[i][j]<<" ";
    }
    cout<<endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
      board[i][j] = board[i][j] == 1 ? -1 : 0;
    }
  }

  memset(visited, false, sizeof(visited));
  int color = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (!visited[i][j] && board[i][j] == -1) {
        visited[i][j] = true;
        dstQ.push({i, j});
        distinctContinentBfs(color++);
      }
    }
  }

  BfsTravel();
  cout <<result;
//  print(board);
//  cout<<endl;
//  print(depth);
  return 0;
}
