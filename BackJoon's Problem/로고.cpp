#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 987654321;

bool visited[1001];

typedef struct S {
    int l, d, r, u;
};

vector<S> el;
int N;

bool check_box(int a, int b) {
  S A = el[a];
  S B = el[b];
  //if(u)
  return (A.r < B.l || A.u < B.d || A.l > B.r || A.d > B.u || A.l > B.l && A.r < B.r && A.u < B.u && A.d > B.d);
  // return (lw[a] < fx[b] || ly[a] < fy[b] || fx[a] > fx[b] && lx[a] < lx[b] && fy[a] > fy[b] && ly[a] < ly[b]);
}

void buildS(int x1, int y1, int x2, int y2) {
  el.push_back({x1, y1, x2, y2});
}


void travel(int idx) {
  visited[idx] = true;
  for (int i = 0; i < el.size(); i++) {
    if (visited[i]) continue;
    if (!check_box(idx, i) && !check_box(i, idx)) {
      travel(i);
    }
  }
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  el.push_back({0, 0, 0, 0});

  for (int i = 0; i < N; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    buildS(x1, y1, x2, y2);
  }

  memset(visited, false, sizeof(visited));
  int cnt = 0;

  for (int i = 0; i < el.size(); i++) {
    if (visited[i]) continue;
    cnt++;
    travel(i);
  }
  cout << cnt - 1;
  return 0;
}