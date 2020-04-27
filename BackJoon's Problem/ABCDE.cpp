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

using namespace std;
using ll = long long;
using P = pair<int, int>;

int N,M;

vector<int> gr[2001];

bool visited[2001];
bool DFS(int cur, int depth){

  visited[cur] = true;
  bool ans = false;

  if(depth >= 4) return true;

  for(int i=0;i<gr[cur].size();i++){
    int nF = gr[cur][i];
    if(visited[nF]) continue;
    ans |= DFS(nF, depth+1);
  }
  visited[cur] = false;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>N>>M;
  for(int i=0;i<M;i++){
    int a,b;
    cin>>a>>b;
    gr[a].push_back(b);
    gr[b].push_back(a);
  }
  for(int i=0;i<N;i++){
    if(DFS(i,0)){
      cout<<1;
      exit(0);
    }
  }
  cout<<0;
  return 0;
}


