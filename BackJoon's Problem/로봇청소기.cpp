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
// ��, ��, �Ʒ�, ��
int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, -1, 0, 1};
// ȸ���ϴ� �� :  nd =  (d+1)%4
// �ݴ������ +2 %2;
int board[100][100];
bool visited[100][100];

// ���� ������ �������� ���ʹ������
// �� �� �� ��
// �ٶ󺸴� �������κ��� ����
// �ٶ󺸴� �������� ��ĭ ����
// �������� ���ȸ��
// �׳� ��� ���� ���°ɷ� ����
// ���ʿ� ������ ��ĭ ���� ������ ������ ȸ��
// ��ĭ �����Ҷ����� ȸ���ؾ���
// �׹����� û�� OR ���ϰ�� ����
// ��û�Ұ� �Ǿ�������, �����Ϸ� �ߴ��� ���̸� ����
// û�Ұ� �Ǿ��ִ°��� ������ ó���ص� �ɰ� ������
// �ȵȴ� ������ �� ���� �����ϱ� �и��� ����
// ���� ������ ���ڷ� ó������
// ���� -1, û���Ѱ��� 1,

// �����, û�Ҹ� �� �� �ִ��� ����.
bool action(int &curI, int &curJ, int& d){

  int leftside = (d+1)%4;
  int ni = curI + Di[leftside];
  int nj = curJ + Dj[leftside];
  // û�Ұ� �̹� �Ǿ��ְų�, ���ΰ��, �Ǵ� �ε����� ������
  if(ni < 0 || ni > N-1 || nj <0 || nj > M-1 ||board[ni][nj] != 0) {
    d = (d+1)%4;
    return false;
  }
  // û���� ��찡 �ִ� ���
  // �� �������� �����ϰ� ȸ��
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