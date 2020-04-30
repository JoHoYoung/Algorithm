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

int N, M, A, B, K, G;

vector<int> route;
vector<P> gr[1001];

int mm[1001][1001];
int MM[1001][1001];
int cost[1001][1001];
int dst[1001];


void dijkstra() {
  for (int i = 0; i <= N; i++) dst[i] = INF;
  priority_queue<P> pq;
  pq.push({-K, A});
  dst[A] = K;
  while (!pq.empty()) {
    int curCost = -pq.top().first;
    int curNode = pq.top().second;
    pq.pop();
    for (int v = 0; v < gr[curNode].size(); v++) {
      int nNode = gr[curNode][v].first;
      int nCost = curCost + gr[curNode][v].second;
      int mC = mm[curNode][nNode];
      int MC = MM[curNode][nNode];
      if (nCost >= mC && curCost < MC && curCost >= mC) {
       // cout<<"FROM "<<curNode<<" TO "<<nNode<<" "<<curCost<<" "<<nCost<<endl;
       // cout<<mC<<" "<<MC<<endl;
        nCost += MC - curCost;
      }
      if (dst[nNode] > nCost) {
        dst[nNode] = nCost;
        pq.push({-nCost, nNode});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> A >> B >> K >> G;
  memset(mm, -1, sizeof(mm));
  memset(MM, -1, sizeof(MM));

  for (int i = 0; i < G; i++) {
    int tmp;
    cin >> tmp;
    route.push_back(tmp);
  }


  for (int i = 0; i < M; i++) {
    int U, V, L;
    cin >> U >> V >> L;
    gr[U].push_back({V, L});
    gr[V].push_back({U, L});
    cost[U][V] = L;
    cost[V][U] = L;
  }

  int upper = route[0];
  int curTime = 0;

  for (int i = 1; i < route.size(); i++) {
    mm[upper][route[i]] = curTime;
    mm[route[i]][upper] = curTime;

    MM[upper][route[i]] = curTime + cost[upper][route[i]];
    MM[route[i]][upper] = curTime + cost[upper][route[i]];
    curTime += cost[upper][route[i]];

    upper = route[i];
  }

  dijkstra();
//  for(int i=1;i<=N;i++){
//    cout<<dst[i]<<" ";
//  }
  cout << dst[B] - K;
  return 0;
}

