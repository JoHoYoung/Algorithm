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

using namespace std;
using ll = long long;
using P = pair<int, int>;

int N, M;
int S, E;

int visited[10001];
vector<P> gr[10001];

void BFS(int tg) {

  queue<int> Q;
  Q.push(S);
  visited[S] = true;
  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();

    for (int i = 0; i < gr[cur].size(); i++) {
      P nC = gr[cur][i];
      if (nC.second < tg || visited[nC.first]) continue;
      visited[nC.first] = true;
      Q.push(nC.first);
    }
  }
}

int ans = 0;
int max(int a,int b){
  return a>b ? a:b;
}
int main() {
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    gr[a].push_back({b, c});
    gr[b].push_back({a, c});
  }
  cin >> S >> E;
  S;
  E;
  int l = 0;
  int r = 1000000000;
  while (l <= r) {
    memset(visited, false, sizeof(visited));
    int mid = (l + r) / 2;
    BFS(mid);
    if (!visited[E]) {
      r = mid - 1;
    } else {
      ans = max(ans, mid);
      l = mid + 1;
    }
  }
  cout << ans;
  return 0;
}

