#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

#define MAXN 4000001
#define ll long long

using namespace std;
using P = pair<long, long>;
int N, M;

char board[50][50];

int water[50][50];
int moveTo[50][50];


queue<P> Q;

int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};

void BFS(int arr[][50]) {

  while (!Q.empty()) {
    P now = Q.front();
    Q.pop();
    for (int d = 0; d < 4; d++) {
      int ni = now.first + Di[d];
      int nj = now.second + Dj[d];
      if (ni < 0 || ni > N - 1 || nj < 0 || nj > M - 1 || arr[ni][nj] != 0 ||  board[ni][nj] == 'X' || board[ni][nj] == 'D') continue;
      arr[ni][nj] = arr[now.first][now.second] + 1;
      Q.push({ni, nj});
    }
  }
}

void BFSMove(){

  while (!Q.empty()) {
    P now = Q.front();
    Q.pop();
    for (int d = 0; d < 4; d++) {
      int ni = now.first + Di[d];
      int nj = now.second + Dj[d];
      if (ni < 0 || ni > N - 1 || nj < 0 || nj > M - 1 || moveTo[ni][nj] != 0 ||  board[ni][nj] == 'X') continue;
      if( moveTo[now.first][now.second] + 1 >= water[ni][nj] && water[ni][nj] != 0) {
        continue;
      }

      moveTo[ni][nj] = moveTo[now.first][now.second] + 1;
      Q.push({ni, nj});
    }
  }
}

void print(int arr[][50]){
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
}

// From S to D
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  P S;
  P D;

  vector<P> X;
  vector<P> W;

  // 매분 이동 && 매분 물 참
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'S') S = {i, j};
      if (board[i][j] == 'D') D = {i, j};
      if (board[i][j] == 'X') X.push_back({i, j});
      if (board[i][j] == '*') W.push_back({i, j});
    }
  }

  memset(water, 0, sizeof(water));
  memset(moveTo, 0, sizeof(moveTo));
  for(auto it = W.begin() ; it != W.end(); it++){
    Q.push(*it);
    water[(*it).first][(*it).second] = 1;
  }

  BFS(water);

  while(!Q.empty()){
    Q.pop();
  }

  Q.push(S);
  moveTo[S.first][S.second] = 1;
  water[D.first][D.second] = MAXN;
  BFSMove();

//  print(water);
//  cout<<endl;
//  print(moveTo);

  if(moveTo[D.first][D.second] == 0){
    cout<<"KAKTUS";
  }else{
    cout<<moveTo[D.first][D.second]-1;
  }

  return 0;
}