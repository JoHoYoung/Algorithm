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

int N, M;

bool chk[10001];
bool visited[10001];
bool overflowed[10001];

int DP[100001];

vector<int> gr[10001];
vector<int> nGr[10001];

bool DFS(int cur) {

  int &can = DP[cur];
  if (can != -1) return can;

  can = false;
  if (cur == 2) {
    chk[cur] = true;
    can = true;
  }
  for (int i = 0; i < gr[cur].size(); i++) {
    can |= DFS(gr[cur][i]);
  }
  if (can) chk[cur] = true;
  return can;
}

ll dst[10001];
ll result[10001];
bool isCycle = false;

void sol() {
  queue<int> Q;

  for (int i = 1; i <= N; i++) {
    if (!chk[i] || dst[i] != 0) continue;
    Q.push(i);
    result[i] = 1;
    visited[i] = true;
  }

  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();
    for (int i = 0; i < nGr[cur].size(); i++) {
      int nNode = nGr[cur][i];
      if (dst[nNode] == 0) continue;
      result[nNode] += result[cur];
      if (result[nNode] >= MOD || overflowed[cur]) overflowed[nNode] = true;
      result[nNode] %= MOD;
      dst[nNode]--;
      if (dst[nNode] == 0) {
        visited[nNode] = true;
        Q.push({nNode});
      }
    }
  }

}

void resetGr() {

  for (int i = 1; i <= N; i++) {
    if (!chk[i]) continue;
    for (int j = 0; j < gr[i].size(); j++) {
      if (!chk[gr[i][j]]) continue;
      nGr[i].push_back(gr[i][j]);
      dst[gr[i][j]]++;

    }
  }
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;

  memset(visited, false, sizeof(visited));
  memset(chk, false, sizeof(chk));
  memset(DP, -1, sizeof(DP));
  memset(dst, 0, sizeof(dst));
  memset(result, 0, sizeof(result));

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    gr[a].push_back(b);
  }

  DFS(1);

  if (!chk[1]) {
    cout << 0;
    exit(0);
  }

  resetGr();

  sol();
  for (int i = 1; i <= N; i++) {
    if(dst[i] != 0 ){
      isCycle = true;
      break;
    }
  }

  if (isCycle) {
    cout << "inf";
    exit(0);
  }

  string r = to_string(result[2]);
  if (overflowed[2]) {
    for (int i = 0; i < 9 - r.size(); i++) {
      cout << "0";
    }
  }

  cout << r;
  return 0;
}

