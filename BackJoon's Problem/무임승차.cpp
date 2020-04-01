#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>

#define MAXN 31
#define INF 987654321.0
#define MAX 1000000
#define MOD 1000000000

using namespace std;
using ll = long long;
using P = pair<int, int>;

int tc, n, m, S, E, s, p, y;

// 1Å³·Î´ç p¿ø
// °Å¸®ºñ·Ê ¹ú±Ý + y¿øÀÇ ¹ú±Ý

vector<int> gr[201];
double dst[201];
double len[201][201];
double prop[201][201];

double DP[201][2];
double min(double a, double b) {
  return a > b ? b : a;
}

priority_queue<pair<double,int>> pq;

void initDst() {
  for (int i = 0; i <= n; i++) {
    dst[i] = INF;
    DP[i][0] = INF;
    DP[i][1] = INF;

  }
}

void djkstra() {
  dst[S] = 0;

  DP[S][0] = s;
  DP[S][1] = 0;

  pq.push({0., S});
  while (!pq.empty()) {
    int curNode = pq.top().second;
    //cout<<"curNode "<<curNode<<endl;
    pq.pop();
    for (int v = 0; v < gr[curNode].size(); v++) {
      int nNode = gr[curNode][v];
      int nLen = len[curNode][nNode];
      int nProp = prop[curNode][nNode];

      DP[nNode][0] = min(DP[nNode][0], min(DP[curNode][0] + nLen*p, DP[curNode][1] + s + nLen*p));
      DP[nNode][1] = min(DP[nNode][1], min(DP[curNode][0], DP[curNode][1]) + (y+nLen*p)*(nProp/100.));
      double nCost = min(DP[nNode][0], DP[nNode][1]);

      //cout<<"n Node : "<<nNode<<" nCost "<<nCost<<" re : "<<dst[nNode]<<endl;
      if(dst[nNode] <= nCost) continue;
      //cout<<"push "<<endl;
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
    for (int i = 0; i <= n; i++) gr[i].clear();
    initDst();
    for (int i = 0; i < m; i++) {
      int a, b;
      double c, d;
      cin >> a >> b >> c >> d;

      len[a][b] = d;
      len[b][a] = d;

      prop[a][b] = c;
      prop[b][a] = c;

      gr[a].push_back(b);
      gr[b].push_back(a);
    }
    djkstra();
    cout << fixed;
    cout.precision(2);
  //  printf("%.2f\n", dst[E]);
    cout<<dst[E]<<"\n";
  }
  return 0;
}

