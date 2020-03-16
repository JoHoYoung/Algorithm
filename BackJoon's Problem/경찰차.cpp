#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

#define INF 987654321
#define MAX 1000000007
using namespace std;
using ll = long long;
using P = pair<int, int>;

int N, W;
vector<P> el;

int abs(int a) {
  if (a > 0) return a;
  return -a;
}

int dst(P A, P B) {
  return abs(A.first - B.first) + abs(A.second - B.second);
}

//1번 경찰차가 i번, 2번 경찰차가 j번 위치
int DP[1002][1002];

int max(int a, int b) {
  if (a < b) return b;
  return a;
}

int sol(int a, int b) {

  if (a >= W + 1 || b >= W + 1) return 0;
  int &result = DP[a][b];
  if (result != -1) return result;

  int cur = max(a, b);
  int l = sol(cur + 1, b) + dst(el[a], el[cur + 1]);
  int r = sol(a, cur + 1) + dst(el[b], el[cur + 1]);
  if (l < r) result = l;
  else result = r;
  return result = min(l, r);
}

void print(int a, int b) {
  int cur = max(a, b);
  if (cur == W + 1) return;
  int l = sol(cur + 1, b) + dst(el[a], el[cur + 1]);
  int r = sol(a, cur + 1) + dst(el[b], el[cur + 1]);
  if (l < r) {
    cout << "1\n";
    print(cur + 1, b);
  } else {
    cout << "2\n";
    print(a, cur + 1);
  }
}

//그 전의 행동은
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  cin >> W;
  memset(DP, -1, sizeof(DP));

  el.push_back({1, 1});
  el.push_back({N, N});
  for (int i = 0; i < W; i++) {
    int a, b;
    cin >> a >> b;
    el.push_back({a, b});
  }
  cout << sol(0, 1) << '\n';
  print(0, 1);
  return 0;
}

