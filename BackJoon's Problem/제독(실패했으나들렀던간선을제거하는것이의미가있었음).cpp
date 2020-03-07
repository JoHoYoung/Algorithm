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
int v, e;

int graph[1001][1001];
int dst[1001];

void initGrp() {
  for (int i = 1; i <= v; i++) {
    for (int j = 1; j <= v; j++) {
      graph[i][j] = INF;
    }
  }
}

void initDst() {
  for (int i = 1; i <= v; i++) dst[i] = INF;
}

// 특정 점에 오기위해 방문한 노드들, 인덱스 : 목적지, 원소들 : 중간 친구들

vector<int> midNode[1001];
priority_queue<P> pq;

void dijkstra() {
  pq.push({0, 1});
  dst[1] = 0;
  while (!pq.empty()) {
    P cur = pq.top();
    pq.pop();
    int curNode = cur.second;
    int curCost = -cur.first;

    for (int nextNode = 1; nextNode <= v; nextNode++) {
      if (graph[curNode][nextNode] == INF) continue;
      int nCost = curCost + graph[curNode][nextNode];
      if (dst[nextNode] > nCost) {
        dst[nextNode] = nCost;
        pq.push({-nCost, nextNode});
        midNode[nextNode].clear();
        midNode[nextNode].push_back(curNode);
      }
    }
  }
}

void delWithBFS(int D) {
  queue<int> Q;
  Q.push(D);
  //cur에 도착하기까지, 방문햇던 점들 삭제하는 작업.
  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();

    for (int i = 0; i < midNode[cur].size(); i++) {
      cout<<"DEL "<<midNode[cur][i]<<" TO "<<cur<<" Upper Cost "<< graph[midNode[cur][i]][cur]<<endl;
      graph[midNode[cur][i]][cur] = INF;
      Q.push(midNode[cur][i]);
    }
    midNode[cur].clear();
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> v >> e;

  initGrp();
  for (int i = 0; i < e; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a][b] = c;
  }

  int cnt = 0;
  initDst();
  dijkstra();
  for(int i=1;i<=v;i++){
    cout<<dst[i]<<" ";
  }
  cout<<endl;
  cnt += dst[v];

  delWithBFS(v);
  initDst();
  dijkstra();
  for(int i=1;i<=v;i++){
    cout<<dst[i]<<" ";
  }
  cout<<endl;
  cnt += dst[v];
  cout << cnt;
  return 0;
}