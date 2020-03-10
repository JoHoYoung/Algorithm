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

vector<int> el;

// ?차수열
// 1을 더하거나 1을빼기
int min(int a, int b) {
  if (a > b) return b;
  return a;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    el.push_back(tmp);
  }

  int ans = INF;
  for (int d1 = -1; d1 <= 1; d1++) {
    for (int d2 = -1; d2 <= 1; d2++) {
      int cnt = 0;
      if (d1 != 0) cnt++;
      if (d2 != 0) cnt++;

      int curF = el[0] + d1;
      int curS = el[1] + d2;

      int dif = curS - curF;

      int pivot = curS;
      bool find = true;
      for (int i = 2; i < N; i++) {
        pivot += dif;
        if (el[i] == pivot) {
          continue;
        }
        if (el[i] + 1 == pivot || el[i] - 1 == pivot) {
          cnt++;
          continue;
        }
        find = false;
        break;
      }
      if (find) {
        ans = min(ans, cnt);
      }
    }
  }

  if (ans == INF) cout << -1;
  else cout << ans;
  return 0;
}