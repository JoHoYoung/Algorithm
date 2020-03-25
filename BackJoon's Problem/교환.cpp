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


string s;
int N, K;
int DP[1000001][11];

// 스왑
// 0 으로 시작 할 수 는 없다
// M : N의 자릿수

int dfs(string n, int depth) {

  if (depth == K) return stoi(n);

  int &ref = DP[stoi(n)][depth];
  if (ref != -1) return ref;

  ref = -1;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      swap(n[i], n[j]);
      if (n[0] == '0') {
        swap(n[i], n[j]);
        continue;
      }
      ref = max(ref, dfs(n, depth + 1));
      swap(n[i], n[j]);
    }
  }
  return ref;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(DP, -1, sizeof(DP));
  cin >> s >> K;
  N = s.size();
  cout<<dfs(s, 0);
  return 0;
}

