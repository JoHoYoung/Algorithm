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

int n, d, c, a, b, s;

typedef struct eg {
    int e, cost;
};
vector<eg> gr[10001];
priority_queue<P> pq;
int dst[10001];

void initDst() {
  for (int i = 1; i <= n; i++) {
    dst[i] = INF;
  }
}

void dijkstra() {
  while (!pq.empty()) {
    P cur = pq.top();
    pq.pop();
    int curNode = cur.second;
    int curCost = -cur.first;

    for (int v = 0; v < gr[curNode].size(); v++) {
      int nNode = gr[curNode][v].e;
      int nCost = curCost + gr[curNode][v].cost;

      if (dst[nNode] > nCost) {
        dst[nNode] = nCost;
        pq.push({-nCost, nNode});
      }
    }
  }
}

int max(int a, int b) {
  if (a > b) return a;
  return b;
}

P getResult() {
  int mx = -1;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (dst[i] == INF) continue;
    mx = max(mx, dst[i]);
    cnt++;
  }
  return {cnt, mx};
}

int tc;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>tc;

  while (tc != 0) {
    cin >> n >> d >> c;
    for(int i=1;i<=n;i++){
      gr[i].clear();
    }
    for (int i = 0; i < d; i++) {
      cin >> a >> b >> s;
      gr[b].push_back({a, s});
    }
    initDst();
    pq.push({0, c});
    dst[c] = 0;
    dijkstra();
    P R = getResult();
    cout << R.first << " " << R.second<<"\n";
    tc--;
  }

  return 0;
}