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
int N, M, X;
priority_queue<P> pq;

typedef struct eg {
    int e, cost;
};
vector<eg> gr[1001];

int dst[1001];

void dijkstra(P s) {

  for (int i = 1; i <= N; i++) dst[i] = INF;

  dst[s.second] = true;
  pq.push({-s.first, s.second});

  while (!pq.empty()) {
    P cur = pq.top();
    pq.pop();
    int curCost = -cur.first;
    int curE = cur.second;
    for (int i = 0; i < gr[curE].size(); i++) {
      int newE = gr[curE][i].e;
      int newC = curCost + gr[curE][i].cost;
      if (dst[newE] > newC) {
        dst[newE] = newC;
        pq.push({-newC, newE});
      }
    }
  }
}

int re[1001];
int re2[1001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> X;
  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    gr[a].push_back({b, c});
  }

  memset(re, false, sizeof(re));
  memset(re2, false, sizeof(re2));


  for (int i = 1; i <= N; i++) {
    if (i == X) continue;
    dijkstra({0, i});
    re[i] = dst[X];
  }

  dijkstra({0, X});

  for (int i = 1; i <= N; i++) {
    re[i] += dst[i];
  }
  sort(re + 1, re + N + 1);
  cout << re[N];
  return 0;
}