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

int N, L, R, X;

vector<int> el;

// гую╨ L <= s && s >= R
vector<vector<int>> COMB;
bool visited[20];

bool sumation(vector<int> arr) {
  int sum = 0;
  for (int i = 0; i < arr.size(); i++) {
    sum += el[arr[i]];
    if (sum > R) return false;
  }
  return sum >= L;
}

void comb(int N, int n, int idx, int depth, vector<int> arr) {

  if (depth == n) {
    sort(arr.begin(), arr.end());
    if (el[arr[arr.size() - 1]] - el[arr[0]] < X) return;
    COMB.push_back(arr);
    return;
  }

  for (int i = idx; i < N; i++) {
    if (visited[i]) continue;
    vector<int> a;
    visited[i] = true;
    a.assign(arr.begin(), arr.end());
    a.push_back(i);
    comb(N, n, i + 1, depth + 1, a);
    visited[i] = false;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> L >> R >> X;

  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    el.push_back(tmp);
  }

  sort(el.begin(), el.end());
  for (int i = 2; i <= N; i++) {
    memset(visited, false, sizeof(visited));
    vector<int> a;
    comb(N, i, 0, 0, a);
  }

  int cnt = 0;
  for (int i = 0; i < COMB.size(); i++) {
    if (sumation(COMB[i])) cnt++;
  }

  cout << cnt;
  return 0;
}