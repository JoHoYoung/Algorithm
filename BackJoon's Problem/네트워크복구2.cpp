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

int N, M;
int dst[1001];
int trace[1001];

vector<P> gr[1001];

void dijkstra() {
  for (int i = 0; i <= N; i++) dst[i] = INF;
  priority_queue<P> pq;
  pq.push({0, 1});
  dst[1] = 0;
  while (!pq.empty()) {

    int curNode = pq.top().second;
    int curCost = -pq.top().first;
    pq.pop();
    for (int v = 0; v < gr[curNode].size(); v++) {
      int nNode = gr[curNode][v].first;
      int nCost = gr[curNode][v].second + curCost;
      if(dst[nNode] > nCost){
        trace[nNode] = curNode;
        dst[nNode] = nCost;
        pq.push({-nCost, nNode});
      }
    }
  }

}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  memset(trace, -1, sizeof(trace));
  for (int i = 0; i < M; i++) {
    int A, B, C;
    cin >> A >> B >> C;
    gr[A].push_back({B, C});
    gr[B].push_back({A, C});
  }
  dijkstra();
  int cnf = 0;
  for(int i=1;i<=N;i++) cnf += trace[i] == -1 ? 0 : 1;
  cout<<cnf<<'\n';
  for(int i=1;i<=N;i++){
    if(trace[i] != -1){
      cout<<i<<" "<<trace[i]<<"\n";
    }
  }
  return 0;
}

