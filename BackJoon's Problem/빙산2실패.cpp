#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>

#define MAXN 31
#define INF 98765432
#define MAX 1000000

using namespace std;
using ll = long long;
using P = pair<int, int>;

int N, M;

int board[301][301];

vector<P> pos[11];

int cumulSum[11];
bool visited[301][301];

int remain;
int Di[4] = {-1,0,1,0};
int Dj[4] = {0,1,0,-1};

bool BFS(int limit) {
  memset(visited, false, sizeof(visited));
  remain = 0;
  queue<P> Q;
  int ans = 0;
  for (int i = limit + 1; i <= 10; i++) {
    if (pos[i].size() != 0) {
    //  cout<<"AT "<<i<<" limit "<<limit<<endl;
      Q.push(pos[i][0]);
      visited[pos[i][0].first][pos[i][0].second] = true;
      remain = cumulSum[10] - cumulSum[i-1];
      break;
    }
  }
  if(remain == 0) return false;
  while(!Q.empty()){
    int curI = Q.front().first;
    int curJ = Q.front().second;
    Q.pop();
    ans++;
    for(int d=0;d<4;d++){
      int ni = curI + Di[d];
      int nj = curJ + Dj[d];
      if(ni < 0 || nj<0 || ni > N-1 || nj>M-1 || visited[ni][nj] || board[ni][nj] == 0 || board[ni][nj] <= limit) continue;
      visited[ni][nj] = true;
      Q.push({ni,nj});
    }
  }
 // cout<<"REMAIN : "<<remain<<" "<< ans<<endl;
  return ans != remain;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  memset(cumulSum, 0, sizeof(cumulSum));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
      pos[board[i][j]].push_back({i, j});
    }
  }
  for (int i = 1; i <= 10; i++) {
    cumulSum[i] = pos[i].size() + cumulSum[i - 1];
  }
  for(int i=0;i<=10;i++){
    if(BFS(i)){
      cout<<i;
      exit(0);
    }
  }
  cout<<0;
  return 0;
}

