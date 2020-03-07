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
int N, M;

typedef struct eg {
    int e, cost;
};
priority_queue<P> pq;

vector<eg> gr[1001];
int dst[1001];

void dijkstra() {

  while (!pq.empty()) {
    P cur = pq.top();
    pq.pop();

    int endNode = cur.second;
    int cost = -cur.first;
  //  cout<<gr[endNode].size()<<endl;
    for (int v = 0; v < gr[endNode].size(); v++) {
      int nDst = cost + gr[endNode][v].cost;
      int nextNode = gr[endNode][v].e;
      //cout << "NDST : " << nDst << endl;
      if (dst[nextNode] > nDst) {
        dst[nextNode] = nDst;
        pq.push({-nDst, nextNode});
      }
    }
  }
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    gr[a].push_back({b, c});
  }
  int s, e;
  cin >> s >> e;

  for (int i = 1; i <= N; i++) {
    dst[i] = INF;
  }

  pq.push({0, s});
  dijkstra();

//  for (int i = 1; i <= N; i++) {
//    cout << dst[i] << " ";
//  }

  cout << dst[e];
  return 0;
}