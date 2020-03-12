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
int n;
// 한노드에서 한노드로 가는 가장 긴 거리

vector<P> gr[10010];

bool visited[10002];
P dfs(int curDex, int cost){
  P re = {curDex, cost};
  visited[curDex] = true;
  for(int v =0;v<gr[curDex].size();v++){
    if(visited[gr[curDex][v].first]) continue;
    P p = dfs(gr[curDex][v].first, cost + gr[curDex][v].second);
    if(p.second > re.second) re = p;
  }
  visited[curDex] = false;
  return re;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i=0;i<n-1;i++){
    int a,b,c;
    cin>>a>>b>>c;
    gr[a].push_back({b,c});
    gr[b].push_back({a,c});
  }

  memset(visited, false, sizeof(visited));
  P a = dfs(1, 0);
  memset(visited, false, sizeof(visited));
  P re = dfs(a.first, 0);

  cout<<re.second;
  return 0;
}