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


int n, d, c;
int tc;
vector<P> gr[10001];
int dst[10001];

void dijkstra(int s) {
  for (int i = 0; i <= n; i++) dst[i] = INF;
  dst[s] = 0;
  priority_queue<P> pq;
  pq.push({0, s});
  while (!pq.empty()) {
    int curCost = -pq.top().first;
    int curNode = pq.top().second;
    pq.pop();
    for (int v = 0; v < gr[curNode].size(); v++) {
      int nCost = gr[curNode][v].second + curCost;
      int nNode = gr[curNode][v].first;
      if (dst[nNode] > nCost) {
        dst[nNode] = nCost;
        pq.push({-nCost, nNode});
      }
    }
  }
}

int max(int a, int b) {
  return a > b ? a : b;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> tc;
  while (tc--) {
    for (int i = 0; i <= n; i++) gr[i].clear();
    cin >> n >> d >> c;
    for (int i = 0; i < d; i++) {
      int a, b, s;
      cin >> a >> b >> s;
      gr[b].push_back({a, s});
    }
    dijkstra(c);
    int cnt = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++){
      if(dst[i] == INF) continue;
      cnt ++;
      ans = max(ans, dst[i]);
    }
    cout<<cnt<<" "<<ans<<"\n";
  }

  return 0;
}

