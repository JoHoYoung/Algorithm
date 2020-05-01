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


int tc;
int V, E;

bool visited[20001];

vector<int> gr[20001];

int re = 0;
int _Try = 0;

void dfs(int s) {
  visited[s] = true;
  re++;
  for (int i = 0; i < gr[s].size(); i++) {
    if (visited[gr[s][i]]) continue;
    dfs(gr[s][i]);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> tc;
  while (tc--) {
    cin >> V >> E;
    re = 0;
    _Try = 0;
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= V; i++) gr[i].clear();
    for (int i = 0; i < E; i++) {
      int a, b;
      cin >> a >> b;
      gr[a].push_back(b);
      gr[b].push_back(a);
    }

    for (int i = 1; i <= V; i++) {
      if (visited[i]) continue;
      _Try++;
      if (_Try >= 3) break;
      dfs(i);
    }
    cout<<re<<" "<<_Try<<'\n';
    if (re == V && _Try == 2) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}

