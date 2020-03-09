#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;
using P = pair<int, int>;
const int INF = 987654321;

int N, M;
// 위, 좌, 아래, 우
int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, -1, 0, 1};
// 회전하는 법 :  nd =  (d+1)%4
// 반대방향은 +2 %2;
int board[100][100];
bool visited[100][100];

// 현재 방향을 기준으로 왼쪽방향부터
// 동 서 남 북
// 바라보는 방향으로부터 왼쪽
// 바라보는 방향으로 한칸 후진
// 왼쪽으로 계속회전
// 그냥 계속 앞을 보는걸로 생각
// 왼쪽에 있으면 한칸 전진 없으면 없으면 회전
// 한칸 전진할때마다 회전해야함
// 네방향모두 청소 OR 벽일경우 후진
// 다청소가 되어있을때, 후진하려 했더니 벽이면 종료
// 청소가 되어있는것은 벽으로 처리해도 될것 같구나
// 안된다 후진을 할 수도 있으니까 분리를 하자
// 벽은 별도의 숫자로 처리하자
// 벽은 -1, 청소한곳은 1,

// 방향과, 청소를 할 수 있는지 리턴.
bool action(int &curI, int &curJ, int& d){

  int leftside = (d+1)%4;
  int ni = curI + Di[leftside];
  int nj = curJ + Dj[leftside];
  // 청소가 이미 되어있거나, 벽인경우, 또는 인덱스를 벗어날경우
  if(ni < 0 || ni > N-1 || nj <0 || nj > M-1 ||board[ni][nj] != 0) {
    d = (d+1)%4;
    return false;
  }
  // 청소할 경우가 있는 경우
  // 그 방향으로 전진하고 회전
  curI = ni;
  curJ = nj;
  d = (d+1)%4;
  return true;
}
void print(){
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cout<<board[i][j]<<" ";
    }
    cout<<endl;
  }
}
int clnCnt = 1;
void solv(int i, int j,int d){
  int failCnt = 0;
  board[i][j] = 1;

  //cout<<i<<" "<<j<<" init D"<<d<<endl;
  while(1){
//
 //   cout<<i<<" "<<j<<" " <<d<<endl;
    if(failCnt == 4){
      int backd = (d+2)%4;
      int ni = i + Di[backd];
      int nj = j + Dj[backd];
      if(board[ni][nj] == -1) return;
      failCnt = 0;
      i = ni;
      j = nj;
    }

    if(!action(i,j,d)) {
      failCnt++;
      continue;
    }

    board[i][j] = 1;
    clnCnt ++;
    failCnt = 0;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  int sI, sJ, sD;
  cin>>sI>>sJ>>sD;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
      if(board[i][j] == 1) board[i][j] = -1;
    }
  }
  if(sD == 1 || sD == 3) sD = (sD+2)%4;
  solv(sI, sJ, sD);
 // print();
  cout<<clnCnt;
  return 0;
}