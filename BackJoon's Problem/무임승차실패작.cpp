#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>

#define MAXN 31
#define INF 987654321
#define MAX 1000000
#define MOD 1000000000

using namespace std;
using ll = long long;
using P = pair<int, int>;

int tc, n, m, S, E, s, p, y;

// 1Å³·Î´ç p¿ø
// °Å¸®ºñ·Ê ¹ú±Ý + y¿øÀÇ ¹ú±Ý

// ±â´ñ°ª
vector<int> gr[201];
float dst[201];

float cost[201][201];

float min(float a, float b) {
  return a > b ? b : a;
}

priority_queue<pair<float,int>> pq;

void initDst() {
  for (int i = 0; i <= n; i++) {
    dst[i] = -1;
  }
}
int trace[201];

void djkstra() {

  dst[S] = 0;
  pq.push({0, S});

  while (!pq.empty()) {
    int curNode = pq.top().second;
    float curCost = -pq.top().first;
    pq.pop();
    for (int v = 0; v < gr[curNode].size(); v++) {
      int nNode = gr[curNode][v];
      int nCost = curCost + cost[curNode][nNode];
      if (dst[nNode] <= nCost && dst[nNode] != -1) continue;
     // cout<<"Nnode "<<nNode<<" "<<nCost<<endl;
      trace[nNode] = curNode;
      dst[nNode] = nCost;
      pq.push({-nCost, nNode});
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> tc;
  while (tc--) {
    cin >> n >> m >> S >> E >> s >> p >> y;
    memset(trace, -1, sizeof(trace));
    for (int i = 0; i <= n; i++) gr[i].clear();
    initDst();
    for (int i = 0; i < m; i++) {
      int a, b;
      float c, d;
      cin >> a >> b >> c >> d;
      float costA = s + p * d;
      float costB = (c/100)*(y + p * d);
      //cout<<costA<<" "<<costB<<endl;
      cost[a][b] = min(costA, costB);
      gr[a].push_back(b);
    }
    djkstra();
//    cout<<"E "<<E<<endl;
//    for(int i=1;i<=n;i++){
//      cout<<dst[i]<<" ";
//    }
//    cout<<endl;
  //  cout.precision(1);
    cout << fixed;
    cout.precision(2);
    cout<<dst[E]<<"\n";
  }
  return 0;
}

