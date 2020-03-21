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

int N;
vector<int> el;

vector<int> gr[10010];
int DP[10010][2];
bool visited[10010];

int max(int a, int b) {
  if (a > b)return a;
  return b;
}

int sol(int node, int turn) {

  int &ref = DP[node][turn];
  if (ref != -1) return ref;
  visited[node] = true;

  if (turn == 1) ref = el[node];
  else ref = 0;

  for (int i = 0; i < gr[node].size(); i++) {
    if (visited[gr[node][i]]) continue;
    if (turn == 1) ref += sol(gr[node][i], 0);
    else {
      int l = sol(gr[node][i], 0);
      int r = sol(gr[node][i], 1);
      ref += max(l, r);
    }
  }
  visited[node] = false;
//  cout << "retrun " << ref << " at "<<node<<endl;
  return ref;
}

vector<int> vt;

int ff(int node, int turn) {
  visited[node] = true;
  if (turn) {
    vt.push_back(node);
    for (int i = 0; i < gr[node].size(); i++) {
      if (visited[gr[node][i]]) continue;
      ff(gr[node][i], 0);
    }
  } else {
    for (int i = 0; i < gr[node].size(); i++) {
      if (visited[gr[node][i]]) continue;
      if (DP[gr[node][i]][1] > DP[gr[node][i]][0]) {
        ff(gr[node][i], 1);
      } else {
        ff(gr[node][i], 0);
      }
    }
  }
  visited[node] = false;
}


// 인접간선이 없는 노드끼리의 집합
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  el.push_back(0);
  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    el.push_back(tmp);
  }

  memset(DP, -1, sizeof(DP));
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    gr[a].push_back(b);
    gr[b].push_back(a);
  }
  memset(visited, false, sizeof(visited));
  int l = sol(1, 0);

  memset(visited, false, sizeof(visited));
  int r = sol(1, 1);
  int ans = max(l, r);

  memset(visited, false, sizeof(visited));
  if (l > r)ff(1, 0);
  else ff(1, 1);

  sort(vt.begin(), vt.end());
  cout << ans << '\n';
  for (auto i : vt) cout << i << " ";
}

