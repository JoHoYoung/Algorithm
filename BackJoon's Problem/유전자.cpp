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

int DP[500][500];
int N;
string s;

int max(int a, int b) {
  if (a > b) return a;
  return b;
}

void sol() {

  for (int i = 0; i < N; i++) {
    DP[i][i] = 0;
  }

  for (int d = 1; d < N; d++) {
    for (int i = 0; i + d < N; i++) {

      DP[i][i+d] = 0;
      for (int k = i ; k + 1 <= i + d; k++) {
        DP[i][i+d] = max(DP[i][i+d], DP[i][k] + DP[k + 1][i + d]);
      }

      if ((s[i] == 'a' && s[i + d] == 't') || (s[i] == 'g' && s[i + d] == 'c'))
        DP[i][i+d] = max(DP[i][i+d], DP[i+1][i+d-1]+2);
    }
  }

}


// 인접간선이 없는 노드끼리의 집합
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> s;
  N = s.size();
  sol();
  cout << DP[0][N - 1];
}

