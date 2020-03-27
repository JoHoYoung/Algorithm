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
char board[101][101];
int visited[101][101];

int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};

int contNo = 0;
void BFS(P S){
  queue<P> Q;
  Q.push(S);
  visited[S.first][S.second] = contNo;
  while(!Q.empty()){
    int curI = Q.front().first;
    int curJ = Q.front().second;
    Q.pop();
    for(int d=0;d<4;d++){
      int ni = curI + Di[d];
      int nj = curJ + Dj[d];
      if(ni < 0 || ni > N-1 || nj<0 || nj > N-1 || visited[ni][nj] != -1 ) continue;
      if(board[ni][nj] != board[curI][curJ]) continue;
      visited[ni][nj] = contNo;
      Q.push({ni,nj});
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }
  memset(visited, -1, sizeof(visited));
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(visited[i][j] != -1)continue;
      BFS({i,j});
      contNo ++;
    }
  }
  memset(visited, -1, sizeof(visited));

  int ansA = contNo;
  contNo = 0;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(board[i][j] == 'G') board[i][j] = 'R';
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(visited[i][j] != -1)continue;
      BFS({i,j});
      contNo ++;
    }
  }
  cout<<ansA<<" "<<contNo<<endl;
  return 0;
}

