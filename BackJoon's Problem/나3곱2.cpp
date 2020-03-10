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

int N;

vector<ll> el;

vector<vector<ll>> PERM;
bool visited[100];


void perm(int N, int n, int depth, vector<ll> arr) {

  if (depth == n) {
    PERM.push_back(arr);
  }

  for (int i = 0; i < N; i++) {
    if (visited[i]) continue;
    if (depth >= 1) {
      ll upper = arr[depth - 1];
      ll cur = el[i];
      if (!(upper % 3 == 0 && upper / 3 == cur) && !(upper * 2 == cur)) continue;
    }
    visited[i] = true;
    vector<ll> a;
    a.assign(arr.begin(), arr.end());
    a.push_back(el[i]);
    perm(N, n, depth + 1, a);
    visited[i] = false;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  for (int i = 0; i < N; i++) {
    ll tmp;
    cin >> tmp;
    el.push_back(tmp);
  }
  memset(visited, false, sizeof(visited));
  vector<ll> a;
  perm(N, N, 0, a);

  for (int j = 0; j < PERM[0].size(); j++) {
    cout << PERM[0][j] << " ";
  }

  return 0;
}