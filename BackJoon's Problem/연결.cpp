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

int N, M;
bool visited[101][101];

P AS, AE, BS, BE;

vector<P> el;

int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};

typedef struct unit {
    int i, j, depth;
    vector<P> trace;
};

int ans = INF;

int min(int a, int b) {
  if (a > b) return b;
  return a;
}

void printvisited() {
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      cout << visited[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void initVisited(vector<P> Q2) {
  memset(visited, false, sizeof(visited));
  for (int i = 0; i < Q2.size(); i++) {
    visited[Q2[i].first][Q2[i].second] = true;
  }
  Q2.clear();
}

int BFS(P BS, P BE, P OS, P OE) {

  queue<unit> Q;
  vector<P> tr;

  if (visited[BS.first][BS.second]) return INF;

  tr.push_back({BS.first, BS.second});
  Q.push({BS.first, BS.second, 0, tr});
  visited[BS.first][BS.second] = true;

  while (!Q.empty()) {
    unit cur = Q.front();
    Q.pop();
    int curI = cur.i;
    int curJ = cur.j;
    int curD = cur.depth;
    if (curI == BE.first && curJ == BE.second) {
      initVisited(cur.trace);
      return curD;
    }
    for (int d = 0; d < 4; d++) {
      int ni = curI + Di[d];
      int nj = curJ + Dj[d];
      if (ni < 0 || ni > N || nj < 0 || nj > M || visited[ni][nj]) continue;

      if(ni == OS.first && nj == OS.second) continue;
      if(ni == OE.first && nj == OE.second) continue;

      visited[ni][nj] = true;
      vector<P> nTrace;
      nTrace.assign(cur.trace.begin(), cur.trace.end());
      nTrace.push_back({ni, nj});
      Q.push({ni, nj, curD + 1, nTrace});
    }
  }
  return INF;
}


int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;


  for (int i = 0; i < 4; i++) {
    int a, b;
    cin >> a >> b;
    el.push_back({a, b});
  }

  AS = el[0];
  AE = el[1];
  BS = el[2];
  BE = el[3];

  memset(visited, false, sizeof(visited));
  int b1 = BFS(AS, AE,BS,BE);
  int b2 = BFS(BS, BE,AS,AE);
  int ans1 = b1 == INF || b2 == INF ? INF : b1 + b2;

  memset(visited, false, sizeof(visited));
  int b3 = BFS(BS, BE,AS,AE);
  int b4 = BFS(AS, AE,BS,BE);
  int ans2 = b3 == INF || b4 == INF ? INF : b3 + b4;

 // cout << ans1 << " " << ans2 << endl;
  ans = min(ans1, ans2);
  if (ans == INF) cout << "IMPOSSIBLE\n";
  else cout << ans << '\n';

  return 0;
}

