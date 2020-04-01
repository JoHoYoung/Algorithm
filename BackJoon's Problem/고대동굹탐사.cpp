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

int tc, N, E;

int value[20001];
bool visited[20001];
int DP[20001];
int trace[20001];

vector<P> gr[20001];

int dfs(int cur) {

  int &ref = DP[cur];
  if (ref != -1) return ref;
  ref = 0;

  visited[cur] = true;
  for (int v = 0; v < gr[cur].size(); v++) {
    int nNode = gr[cur][v].first;
    if (visited[nNode]) continue;

    int val = gr[cur][v].second + dfs(nNode);
    if (val > ref) {
      ref = val;
      trace[cur] = nNode;
    }
  }
  visited[cur] = false;
  return ref;
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> tc;
  while (tc--) {
    cin >> N >> E;
    for (int i = 1; i <= N; i++) gr[i].clear();
    memset(visited, false, sizeof(visited));
    memset(DP, -1, sizeof(DP));
    memset(trace, -1, sizeof(trace));

    for (int i = 1; i <= N; i++) cin >> value[i];

    for (int i = 0; i < E; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      int cost = -c + value[b];
      gr[a].push_back({b, cost});
    }

    int maxVal = value[1] + dfs(1);
    int visitNode = 1;
    int idx = 1;

    vector<int> route;
    route.push_back(1);

    while (trace[idx] != -1) {
      idx = trace[idx];
      visitNode += 1;
      route.push_back(idx);
    }

    cout << maxVal << " " << visitNode << '\n';
    for (int i = 0; i < route.size(); i++) {
      cout << route[i] << " ";
    }
    cout << endl;
  }

  return 0;
}

