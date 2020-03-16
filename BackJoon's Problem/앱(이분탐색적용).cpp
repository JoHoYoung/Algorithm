#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

#define INF 987654321
#define MAX_K 1000000000
using namespace std;
using ll = long long;
using P = pair<int, int>;

int N, M;
vector<int> b, c;
vector<P> el;

int DP[100][10000];

int max(int a, int b) {
  if (a > b) return a;
  return b;
}

//특정 코스트로 확보할 수 있는 최대 메모리
// 메모이제이션 하는 완탐.인데.. 이것이 디피엿군
int sol(int idx, int cost) {

  if (idx > N - 1) return 0;
  int &result = DP[idx][cost];
  if (result != -1) return result;

  // 나를 선택안하고,
  result = sol(idx + 1, cost);

  // 선택하고 , 사실상 완탐인데..
  if (c[idx] <= cost) {
    result = max(result, max(idx + 1, b[idx] + sol(idx + 1, cost - c[idx])));
  }

  return result;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  int tmp;
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    b.push_back(tmp);
  }
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    c.push_back(tmp);
  }
  memset(DP, -1, sizeof(DP));
  int l = 0;
  int r = 10000;
  while (l < r) {
    int mid = (l + r) / 2;
    if (sol(0, mid) >= M) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout<<l;
  return 0;
}