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

int V, E, K;
int dst[20001];


struct eg {
    int s, e, cost;
};

priority_queue<P> pq;
vector<eg> gr[20001];

void djkstra() {
  while (!pq.empty()) {
    P cur = pq.top();
    pq.pop();
    for (int v = 0; v < gr[cur.second].size(); v++) {
      int nDst = -cur.first + gr[cur.second][v].cost;
      if (dst[gr[cur.second][v].e] >= nDst) {
        dst[gr[cur.second][v].e] = nDst;
        pq.push({-nDst, gr[cur.second][v].e});
      }
    }
  }
}


int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> V >> E;
  cin >> K;
  for (int i = 0; i < E; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    gr[a].push_back({a, b, c});
  }
  for (int i = 1; i <= V; i++) {
    dst[i] = INF;
  }
  // 첫번째가 가중치, 두번째가 점
  pq.push({0, K});
  dst[K] = 0;
  djkstra();

  for (int i = 1; i <= V; i++) {
    if (dst[i] == INF) cout << "INF\n";
    else cout << dst[i] << "\n";
  }

  return 0;
}