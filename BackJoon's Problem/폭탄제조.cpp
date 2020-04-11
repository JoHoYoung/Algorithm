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

int X[100], Y[100], Sm[100], Pm[100], Sv[100], Pv[100];

int min(int a, int b) {
  return a > b ? b : a;
}

int max(int a, int b) {
  return a > b ? a : b;
}

bool sol(int mid) {
  int cst = 0;
  for (int i = 0; i < N; i++) {
    int c = mid * X[i] - Y[i];
    int L = c / Sm[i] + (c % Sm[i] ? 1 : 0);
    int m = INF;
    for (int j = 0; j <= L; j++) {
      int rm = c - Sm[i] * j;
      if (rm < 0) m = min(m, j * Pm[i]);
      else m = min(m, j * Pm[i] + (rm / Sv[i] + (rm % Sv[i] ? 1 : 0)) * Pv[i]);
    }
    cst += m;
  }
  return cst > M;
}

int ans = -1;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i] >> Sm[i] >> Pm[i] >> Sv[i] >> Pv[i];
  }
  int l = 0;
  int r = M;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (sol(mid)) r = mid - 1;
    else {
      l = mid + 1;
      ans = max(ans, mid);
    }
  }
  cout << ans;
  return 0;
}


