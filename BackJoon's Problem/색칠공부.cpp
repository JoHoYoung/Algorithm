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
#define MOD 1000000007

using namespace std;
using ll = long long;
using P = pair<int, int>;

int N;
long K;
int start = 0;
ll DP[1000001] = {0};
int F[1000001] = {0};
int visited[1000001] = {0};
int startPoint[1000001] = {0};

int DFS(int cur, int cnt){
  if(visited[cur]){
    if(startPoint[cur] != start) return 0;

    return cnt - visited[cur];
  }

  visited[cur] = cnt;
  startPoint[cur] = start;

  return DFS(F[cur], cnt+1);
}

int dfs(int current,int cnt,int start_point){

  if(visited[current]){

    //기존 사이클과 다른 정점 방문 시 (사이클 x)
    if(startPoint[current]!=start_point)
      return 0;

    return cnt-visited[current];
  }

  visited[current]=cnt;
  startPoint[current]=start_point;
  return dfs(F[current],cnt+1, start_point);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K;
  DP[0]=1;
  DP[1]=K;
  DP[2]=(K*(K-1))%MOD;
  DP[3]=(K*(K-1)*(K-2))%MOD;

  for(int i=4;i<=N;i++){

    //1번째와 i-2가 같은색일 때 + 1번째와 i-2가 다른색일 때
    DP[i]=DP[i-2]*(K-1)+DP[i-1]*(K-2);
    DP[i]%=MOD;
  }
  for (int i = 1; i <= N; i++) cin >> F[i];

  ll ans = 1;
  int sNode = N;

  for(int i=1; i<=N;i++){
    if(visited[i]) continue;
    start = i;
    int cycled = DFS(i,1);
    sNode -= cycled;
    ans *= DP[cycled];
    ans %= MOD;
  }

  for(int i=1;i<=sNode;i++){
    ans *= (K-1);
    ans %= MOD;
  }
  cout<<ans;

  return 0;
}

