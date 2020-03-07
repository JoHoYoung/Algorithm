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
vector<eg> gr[1001];
priority_queue<P> pq;

vector<int> trace[1001];
int dst[1001];

void initDst() {
  for (int i = 1; i <= N; i++) {
    dst[i] = INF;
  }
}

void dijkstra() {
  pq.push({0, 1});
  dst[1] = 0;
  while (!pq.empty()) {
    P cur = pq.top();
    pq.pop();
    int curCost = -cur.first;
    int curNode = cur.second;

    for (int v = 0; v < gr[curNode].size(); v++) {
      int nNode = gr[curNode][v].e;
      int nCost = curCost + gr[curNode][v].cost;
      if (dst[nNode] > nCost) {
        dst[nNode] = nCost;
        pq.push({-nCost, nNode});
        trace[nNode].clear();
        trace[nNode].push_back(curNode);
        //    cout << "TRACE " << nNode << " val " << curNode << endl;
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
    gr[b].push_back({a, c});
  }

  initDst();

  pq.push({0, 1});
  dijkstra();
  queue<int> Q;

//  for (int i = 1; i <= N; i++) {
//    cout << dst[i] << " ";
//  }

  // cout<<endl;
  // Q.push(4);
//  while(!Q.empty()){
//    int cur = Q.front();
//    Q.pop();
//    vector<int> target = trace[cur];
//    // cout<<target.size();
//    for(int i=0;i<target.size();i++){
//      cout<<cur<<" "<<target[i]<<endl;
//      Q.push(target[i]);
//    }
//  }
  //cout << trace[2].size() << endl;
  int cnf = 0;
  for (int i = 1; i <= N; i++) {
    cnf+= trace[i].size();
  }
  cout<<cnf<<endl;
  for (int i = 1; i <= N; i++) {

    for (int j = 0; j < trace[i].size(); j++) {
      cout << i << " " << trace[i][j] << endl;
    }
  }

  return 0;
}