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

int n, m;
int dst[201];
int mark[201][201];

vector<P> gr[201];

//typedef struct unit {
//    int cost, node, parent;
//};

using unit = pair<int, pair<int,int>>;
void dijkstra(int s) {
  for (int i = 0; i <= n; i++) dst[i] = INF;
  dst[s] = 0;
  priority_queue<unit> pq;
  pq.push({0, {s, s}});
  while (!pq.empty()) {
    unit cur = pq.top();
    pq.pop();
    int curCost = -cur.first;
    int curNode = cur.second.first;
    int curParent = cur.second.second;
    for (int v = 0; v < gr[curNode].size(); v++) {
      int nCost = curCost + gr[curNode][v].second;
      int nNode = gr[curNode][v].first;
      int nParent = curParent;
      if(nParent == s) nParent = nNode;
      if(dst[nNode] > nCost){
        mark[s][nNode] = nParent;
        dst[nNode] = nCost;
        pq.push({-nCost,{nNode, nParent}});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    gr[a].push_back({b, c});
    gr[b].push_back({a, c});
  }

  for(int i=1;i<=n;i++) dijkstra(i);

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(i != j) cout<<mark[i][j]<<" ";
      else cout<<"- ";
    }
    cout<<endl;
  }
  return 0;
}

