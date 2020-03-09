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
int N, M;
int S;

//상근이는 대장
// 상근이는 1번
// 나머지 : 2~N
// 자신 아래에 있는 부하들의 월급
vector<int> E[500001];
char f;
int x, y;
int money[500001];
int s[2000000], e[2000000], seg[2000000], lazy[2000000];
int c = 0;

void dfs(int idx) {
  s[idx] = ++c;
  for (int i = 0; i < E[idx].size(); i++) {
    if (!s[idx])
      dfs(E[idx][i]);
  }
  e[idx] = c;
}

void u_lazy(int node, int l, int r) {
  if (!lazy[node]) return;
  seg[node] += lazy[node] * (r - l + 1);
  if (l != r) {
    lazy[node * 2] += lazy[node];
    lazy[node * 2 + 1] += lazy[node];
  }
  lazy[node] = 0;
}

int query(int node, int start, int end, int lo, int hi) {
  u_lazy(node, start, end);
  if (end < lo || hi < start) return 0;
  if (lo <= start && end <= hi) return seg[node];
  int mid = (start + end) / 2;
  return query(node * 2, start, mid, lo, hi) + query(node * 2 + 1, mid + 1, end, lo, hi);
}


int s_update(int lo, int hi, int val, int node, int x, int y) {
  u_lazy(node, x, y);
  if (y < lo || hi < x)
    return seg[node];
  if (lo <= x && y <= hi) {
    lazy[node] += val;
    u_lazy(node, x, y);
    return seg[node];
  }
  int mid = (x + y) >> 1;
  return seg[node] = s_update(lo, hi, val, node * 2, x, mid) + s_update(lo, hi, val, node * 2 + 1, mid + 1, y);
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  cin >> S;
  money[1] = S;

  memset(lazy, false, sizeof(lazy));
  memset(seg, false, sizeof(seg));
  for (int i = 2; i < N + 1; i++) {
    int a, b;
    //i : 직원번호, a: 월급 b : 상사번호
    cin >> a >> b;
    E[b].push_back(i);
    money[i] = a;
  }

  dfs(1);
  for (int i = 1; i <= N; i++) s_update(s[i], s[i], money[i], 1, 1, N);

  vector<int> R;
  for (int i = 0; i < M; i++) {
    char p;
    int x;
    cin >> p;
    if (p == 'p') {
      cin >> x >> y;
      if (s[x] == e[x])continue;
      s_update(s[x] + 1, e[x], y, 1, 1, N);
    } else {
      cin >> x;
      cout << query(1, 1, N, s[x], s[x]) << "\n";
    }
  }
  for (int i = 0; i < R.size(); i++) cout << R[i] << "\n";
  return 0;
}