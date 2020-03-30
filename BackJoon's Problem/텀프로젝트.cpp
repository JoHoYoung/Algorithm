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

int tc, N;

int Like[100001] = {0};
int startNode[100001] = {0};
int visited[100001] = {0};

int start;
int DFS(int cur, int cnt){
  if(visited[cur]){
    if(start != startNode[cur]) return 0;
    return cnt - visited[cur];
  }

  visited[cur] = cnt;
  startNode[cur] = start;
  return DFS(Like[cur], cnt+1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>tc;

  while(tc--){
    memset(Like, 0, sizeof(Like));
    memset(startNode, 0, sizeof(startNode));
    memset(visited, 0, sizeof(visited));

    cin >> N;
    for(int i=1;i<=N;i++){
      cin>>Like[i];
    }
    int ans = N;
    for(int i=1;i<=N;i++){
      if(visited[i]) continue;
      start = i;
      ans -= DFS(i, 0);
    }
    cout<<ans<<'\n';
  }

  return 0;
}

