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
int n, m;

vector<int> E[1001];
vector<int> F[1001];

bool visited[1001];

void DFS(int cur) {
  visited[cur] = true;

  for (int i = 0; i < F[cur].size(); i++) {
    int nNode = F[cur][i];
    if (visited[nNode]) continue;
    DFS(nNode);
  }

  for (int i = 0; i < E[cur].size(); i++) {
    int nEnemy = E[cur][i];
    for (int j = 0; j < E[nEnemy].size(); j++) {
      int nNode = E[nEnemy][j];
      if (visited[nNode]) continue;
      DFS(nNode);
    }
  }
}

void printV(){
  for(int i=1;i<=n;i++){
    cout<<visited[i]<<" ";
  }
  cout<<endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  memset(visited, false, sizeof(visited));
  for (int i = 0; i < m; i++) {
    char a;
    int b, c;
    cin >> a >> b >> c;
    if (a == 'E') {
      E[b].push_back(c);
      E[c].push_back(b);
    } else {
      F[b].push_back(c);
      F[c].push_back(b);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (visited[i]) continue;
    DFS(i);
    ans++;
  }
  cout << ans;
  return 0;
}

