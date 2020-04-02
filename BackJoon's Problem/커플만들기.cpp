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

vector<int> m;
vector<int> f;

// DP[작은쪽][큰쪽]
int DP[1001][1001];

int min(int a, int b) {
  return a > b ? b : a;
}

int abs(int a) {
  return a < 0 ? -a : a;
}

// DP[i][j] = DP[i-1][j-1] + abs(r[j] - l[i])
void sol(vector<int> &s, vector<int> &r) {

  int slen = s.size();
  int rlen = r.size();
  for (int i = 1; i < slen; i++) {
    for (int j = 1; j < rlen; j++) {
      DP[i][j] = DP[i-1][j-1] + abs(s[i] - r[j]);
      if(j > i) DP[i][j] = min(DP[i][j], DP[i][j-1]);
      if(i > j) DP[i][j] = min(DP[i][j], DP[i-1][j]);
    }
  }

}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;

  m.push_back(0);
  f.push_back(0);

  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    m.push_back(tmp);
  }

  for (int i = 0; i < M; i++) {
    int tmp;
    cin >> tmp;
    f.push_back(tmp);
  }

  sort(m.begin(), m.end());
  sort(f.begin(), f.end());
  memset(DP, 0 ,sizeof(DP));
  sol(f,m);

  cout<<DP[f.size()-1][m.size()-1];
}

