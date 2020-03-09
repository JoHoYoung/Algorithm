#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 987654321;

int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};

// 내릴때만 그리기
// 올리면 지나가기

bool board[1002][1002];
bool visited[1002][1002];

void swap(int& a, int &b){
  int temp =a;
  a=b;
  b=temp;
}
void drawPoint(int x1, int x2, int y1, int y2) {
  if(x1  > x2){
    swap(x1,x2);
  }
  // 작은 좌표부터 진행
  if(y1>y2){
    swap(y1,y2);
  }

  for(int i=x1;i<=x2;i++){
    board[y1][i] = true;
    board[y2][i] = true;
  }
  for(int i=y1;i<=y2;i++){
    board[i][x1] = true;
    board[i][x2] = true;
  }
}

int getPointCount() {
  int cnt = 0;
  for (int i = 0; i < 1002; i++) {
    for (int j = 0; j < 1002; j++) {
      if (board[i][j]) cnt++;
    }
  }
  return cnt;
}

int numberOfPoint;
int ans = INF;


//status true : 내려가있는 상태
//다음점이 안그리는 상태일때만 올리는건가?
void DFS(int i, int j, int depth, int fillN, int upCount, bool status) {
  if (fillN == numberOfPoint) {
    //cout<<"FIND"<<endl;
    ans = min(upCount, ans);
    return;
  }
  visited[i][j] = true;
  cout<<i<<" "<<j<<endl;
  // 지금위치가 안그리는점이면 -> 이동할때 올린상태로, 지금위치가 안그리는 점인데 내려와있는 상태는 없다
  // 올리고 내리고는 항상 그려야하는 점에서 결정.
  // 지금위치가 그리는 점이면 -> 이동할때는 다음친구의 상황에 따라
  for (int d = 0; d < 4; d++) {
    int ni = i + Di[d];
    int nj = j + Dj[d];
    if (ni < 0 || ni > 1001 || nj < 0 || nj > 1001 || visited[ni][nj]) continue;
    //cout<<board[i][j]<<" "<<board[ni][nj]<<" "<<endl;

    // 다음 블록의 상태에 따라 행동
    // 지금 점이 그려야하는 점
    //visited[ni][nj] = true;
    if (board[i][j]) {
      // 다음 점이 그려야하는 점이면
      if (board[ni][nj]) {
        // 내려가있는 상태면
        if (status) {
          DFS(ni, nj, depth + 1, fillN + 1, upCount, status);
        } else {
          DFS(ni, nj, depth + 1, fillN + 2, upCount, !status);
        }
      } else {
        if (status) {
          DFS(ni, nj, depth + 1, fillN, upCount + 1, !status);
        } else {
          DFS(ni, nj, depth + 1, fillN, upCount, status);
        }
      }
      // 지금점이 안그려야하는 점이면
    }else{
      DFS(ni, nj,depth +1, fillN, upCount, status);
    }
 }
  visited[i][j] = false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1 += 500;
    y1 += 500;
    x2 += 500;
    y2 += 500;
    drawPoint(x1,x2,y1,y2);
  }
  memset(visited, false, sizeof(visited));
  memset(board, false, sizeof(false));
  numberOfPoint = getPointCount();
//  for(int i=500;i<510;i++){
//    for(int j=500;j<510;j++){
//      cout<<board[i][j]<<" ";
//    }
//    cout<<endl;
//  }
  //cout<<numberOfPoint<<endl;
  DFS(500,500,0,0,0,true);

  cout<<ans;
  return 0;
}