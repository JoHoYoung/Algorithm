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

int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};

bool board[101][101];
bool visited[101][101];

int result = INF;
int min(int a,int b ){
  if(a>b) return b;
  return a;
}

//노드가 10000개인것인가?
void DFS(int i, int j, int destroyNum) {

 // cout<<i<<" "<<j<<" "<<destroyNum<<" b : "<<board[i][j]<<endl;
  visited[i][j] = true;
  if(board[i][j]) {
  //  cout<<"++"<<endl;
    destroyNum++;
  }

  if(i == N-1 && j == M-1){
   // cout<<"FIND"<<endl;
    result = min(result, destroyNum);
    return;
  }
  for (int d = 0; d < 4; d++) {
    int ni = i + Di[d];
    int nj = j + Dj[d];
    if (ni < 0 || ni > N - 1 || nj < 0 || nj > M - 1 || visited[ni][nj]) continue;
    DFS(ni,nj,destroyNum);
    visited[ni][nj] = false;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  string in;
  for (int i = 0; i < M; i++) {
    cin>>in;
    for (int j = 0; j < N; j++) {
    //  cin >> board[i][j];
      board[i][j] = in[j] == '1' ? true : false;
    }
  }

  //cout<<"??";
  memset(visited, false, sizeof(visited));
  DFS(0,0,0);
  cout<<result;
  // from 0,0 to N-1, M-1;
  return 0;
}