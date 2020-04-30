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

int N, E;

//int min(int a, int b) {
//  return a > b ? b : a;
//}

vector<P> gr[1000];
int dst[801];
int v1, v2;

int min(int a, int b) {
  return a > b ? b : a;
}

int dijkstra(int s, int e) {

  for (int i = 0; i <= N; i++) dst[i] = INF;

  priority_queue<P> pq;
  dst[s] = 0;
  pq.push({0, s});
  while (!pq.empty()) {
    P cur = pq.top();
    pq.pop();

    int curCost = -cur.first;
    int curNode = cur.second;

    for (int v = 0; v < gr[curNode].size(); v++) {
      int nNode = gr[curNode][v].first;
      int nCost = curCost + gr[curNode][v].second;
      if (dst[nNode] >= nCost) {
        dst[nNode] = nCost;
        pq.push({-nCost, nNode});
      }
    }
  }
  //cout<<"RETURN "<<dst[e]<<'\n';
  return dst[e];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> E;
  for (int i = 0; i < E; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    gr[a].push_back({b, c});
    gr[b].push_back({a, c});
  }
  cin >> v1 >> v2;

  int d1 = dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, N);
  int d2 = dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, N);
  int ans = min(d1, d2);
  if (ans >= INF) cout << -1;
  else cout << ans;
  return 0;
}

