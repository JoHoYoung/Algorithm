#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

#define MAXN 99999999

using namespace std;
using P = pair<int, int>;
int N, M;

// 위 오른쪽 아래 왼쪽
int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};

int board[10][10];
bool visited[10][10];

// 1,2,3,4,5 회전
// 1번 : 4가지경우 2번 : 2가지경우 3,4번 : 4가지경우, 5번 : 1가지경우

//5번 CCTV는 회전할 필요가 없다.
//특정 방향의 레이저를 쏘는 개념.

typedef struct CCTV {
    int i, j, num;
};

vector<vector<int>> cctvDir[6];

void initDir() {
  vector<int> temp;
  temp.push_back(0);
  cctvDir[1].push_back(temp);
  temp.clear();
  temp.push_back(1);
  cctvDir[1].push_back(temp);
  temp.clear();
  temp.push_back(2);
  cctvDir[1].push_back(temp);
  temp.clear();
  temp.push_back(3);
  cctvDir[1].push_back(temp);
  temp.clear();

  temp.push_back(0);
  temp.push_back(2);
  cctvDir[2].push_back(temp);
  temp.clear();

  temp.push_back(1);
  temp.push_back(3);
  cctvDir[2].push_back(temp);
  temp.clear();

  temp.push_back(0);
  temp.push_back(1);
  cctvDir[3].push_back(temp);
  temp.clear();
  temp.push_back(1);
  temp.push_back(2);
  cctvDir[3].push_back(temp);

  temp.clear();
  temp.push_back(2);
  temp.push_back(3);
  cctvDir[3].push_back(temp);
  temp.clear();

  temp.push_back(3);
  temp.push_back(0);
  cctvDir[3].push_back(temp);
  temp.clear();


  temp.push_back(3);
  temp.push_back(0);
  temp.push_back(1);
  cctvDir[4].push_back(temp);
  temp.clear();

  temp.push_back(0);
  temp.push_back(1);
  temp.push_back(2);
  cctvDir[4].push_back(temp);
  temp.clear();

  temp.push_back(1);
  temp.push_back(2);
  temp.push_back(3);
  cctvDir[4].push_back(temp);
  temp.clear();

  temp.push_back(0);
  temp.push_back(2);
  temp.push_back(3);
  cctvDir[4].push_back(temp);
  temp.clear();

  temp.push_back(0);
  temp.push_back(1);
  temp.push_back(2);
  temp.push_back(3);
  cctvDir[5].push_back(temp);
  temp.clear();
}

//1 : [[1]. [2], [3], [4]]
//2 : [[1,3],[0,4]
//

vector<CCTV> cctvPos;

typedef struct unit {
    int i, j, d;
};

queue<unit> bfsQ;

void BFS(vector<unit> Q) {
  int idx = 0;
  for(int i=0;i<cctvPos.size();i++){
    visited[cctvPos[i].i][cctvPos[i].j] = true;
  }
  while (idx < Q.size()) {

   // cout<<"BFS "<<idx<<endl;
    unit cur = Q[idx];
    int ni = cur.i;
    int nj = cur.j;
    visited[ni][nj] = true;
    while (1) {
   //   cout<<"NI : "<<ni<<" NJ : "<<nj<<endl;
      ni += Di[cur.d];
      nj += Dj[cur.d];
      if (ni < 0 || ni > N - 1 || nj < 0 || nj > M - 1 || board[ni][nj] == 6) break;
      visited[ni][nj] = true;
    }
    idx++;
  }
}


int min(int a, int b) {
  if (a > b) return b;
  return a;
}

int result = 999999;

int countNonVisited() {
  int cnt = N * M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (visited[i][j]) cnt--;
    }
  }
  return cnt;
}

void print(){
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cout<<visited[i][j]<< " ";
    }
    cout<<endl;
  }
}
void enQueueDFS(int idx, vector<unit> pos) {

  //cout<<"IDX : "<<idx<<" "<<cctvPos.size()<<endl;
  if (idx == cctvPos.size()) {
    BFS(pos);
   // print();
   // cout<<endl;
   // cout<<"NUM : "<<countNonVisited()<<endl;
    result = min(result, countNonVisited());
    memset(visited, false, sizeof(visited));
    return;
  }

  CCTV cctv = cctvPos[idx];
  //cout<<cctv.i<<" "<<cctv.j<<" to true"<<endl;
  vector<vector<int>> dirs = cctvDir[cctv.num];
  for (int i = 0; i < dirs.size(); i++) {
    int pushcnt = 0;
    vector<int> nowDir = dirs[i];
   // cout<<"SIZE : "<<nowDir.size()<<endl;
    for (int j = 0; j < nowDir.size(); j++) {
      int d = nowDir[j];
      int ni = cctv.i + Di[d];
      int nj = cctv.j + Dj[d];
      if (ni < 0 || ni > N - 1 || nj < 0 || nj > M - 1 || board[ni][nj] == 6) continue;
      pos.push_back({ni, nj, d});
      pushcnt++;
    }
   // cout<<"HERE"<<endl;
    enQueueDFS(idx + 1,pos);
    for(int i=0;i<pushcnt;i++){
      pos.pop_back();
    }
  }
}

int numberOfSix = 0;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
      if (board[i][j] != 0 && board[i][j] != 6) cctvPos.push_back({i, j, board[i][j]});
      if (board[i][j] == 6) numberOfSix ++;
    }
  }

  initDir();
  vector<unit> a;
  enQueueDFS(0, a);

 // cout<<cctvPos.size()<<endl;
  cout<<result - numberOfSix;
  return 0;
}
