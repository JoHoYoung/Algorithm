#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>

#define INF 987654321
#define MAX 1000000
using namespace std;
using ll = long long;
using P = pair<int, int>;

int N, K, M;

set<int> gr[100001];

int dst[100001];

void initDst() {
  for (int i = 0; i <= N; i++) {
    dst[i] = INF;
  }
}

priority_queue<P> pq;

void Dijkstra() {
  pq.push({0, 1});
  dst[1] = 0;

  while (!pq.empty()) {

    int curCost = -pq.top().first;
    int curNode = pq.top().second;
    pq.pop();
    //cout<<"Cur cost "<<curCost<<" curNode "<<curNode<<endl;
    for (auto it = gr[curNode].begin(); it != gr[curNode].end(); it++) {
      int nextNode = (*it);
      int nCost = curCost + 1;
      if (dst[nextNode] <= nCost) continue;
      //cout<<"SET "<<endl;
      dst[nextNode] = nCost;
      pq.push({-nCost, nextNode});
    }
  }

}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
//  cout<<dst[1];
  cin >> N >> K >> M;
  initDst();
  vector<int> input;
  for (int i = 0; i < M; i++) {
    input.clear();
    for (int t = 0; t < K; t++) {
      int tmp;
      cin >> tmp;
      input.push_back(tmp);
    }

    for (int t = 0; t < input.size(); t++) {
      for (int p = 0; p < input.size(); p++) {
        if (t == p) continue;
        gr[input[t]].insert(input[p]);
      }
    }
  }

  Dijkstra();
  if(dst[N] == INF) cout<<-1;
  else cout<<dst[N]+1;
  return 0;
}

