#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

#define INF 987654321

using namespace std;
using ll = long long;

int T, K;
vector<int> el;
int DP[501][501];
// ºÎºÐÇÕ
int sum[501];

void accSum() {
  sum[0] = el[0];
  for (int i = 1; i < K; i++) {
    sum[i] = sum[i - 1] + el[i];
  }
}

int getAccsum(int from, int to){

  int l;
  if(from == 0) l = 0;
  else l = sum[from -1];

  return sum[to] - l;
}
void sol() {
  for (int d = 0; d < K; d++) {
    for (int i = 0; i + d < K; i++) {
      if (d == 0) {
        DP[i][i + d] = 0;
        continue;
      }
      DP[i][i + d] = INF;
      for (int k = 0; i + k < i + d; k++) {
        if (DP[i][i + d] > DP[i][i + k] + DP[i + k + 1][i + d] + getAccsum(i,i+d)) {
          DP[i][i + d] = DP[i][i + k] + DP[i + k + 1][i + d] + getAccsum(i,i+d);
        }
        //
      }
    }
  }
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  while (T--) {
    el.clear();
    memset(DP, 0, sizeof(DP));
    cin >> K;
    for (int i = 0; i < K; i++) {
      int tmp;
      cin >> tmp;
      el.push_back(tmp);
    }

    accSum();
    sol();
    cout << DP[0][K - 1]<<'\n';
  }
  return 0;
}