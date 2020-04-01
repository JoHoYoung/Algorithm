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
#define MOD 1000000000

using namespace std;
using ll = long long;
using P = pair<int, int>;

int tc, N, M;

char board[1001][1001];
int DP[1001][1001];
bool visited[1001][1001];
int ans = -1;
int max(int a,int b){
  return a>b?a:b;
}
int Di[4] = {-1,0,1,0};
int Dj[4] = {0,1,0,-1};
int farI;
int farJ;

typedef struct unit{
    int i,j,d;

};

void bfs(int sI,int sJ){
  queue<unit> Q;
  Q.push({sI,sJ,0});
  visited[sI][sJ] = true;
  while(!Q.empty()){
    int curI = Q.front().i;
    int curJ = Q.front().j;
    int curD = Q.front().d;
  //  cout<<curI<<" "<<curJ<<" "<<curD<<endl;
    Q.pop();
    ans = max(ans, curD);
    for(int d=0;d<4;d++){
      int ni = curI + Di[d];
      int nj = curJ + Dj[d];
      if(ni < 0 || ni > N-1 || nj < 0 || nj > M-1 || visited[ni][nj] || board[ni][nj] == '#') continue;
      visited[ni][nj] = true;
      Q.push({ni,nj,curD+1});
      farI = ni;
      farJ = nj;
    }
  }
}
int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> tc;
  while (tc--) {
    cin>>M>>N;
    ans = -1;
    memset(visited, false, sizeof(visited));
    memset(DP, -1, sizeof(DP));
    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
        cin>>board[i][j];
      }
    }

    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
        if(visited[i][j] || board[i][j] == '#') continue;
        bfs(i,j);
        break;
      }
    }

    memset(visited,false, sizeof(visited));
    bfs(farI, farJ);
    cout<<"Maximum rope length is "<<ans<<".\n";
  }

  return 0;
}

