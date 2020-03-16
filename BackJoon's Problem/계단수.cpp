#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

#define INF 987654321
#define MAX 1000000000
using namespace std;
using ll = long long;
using P = pair<int, int>;

int N;

// 몇자리 수 , 끝자리 수
//int DP[100][10];
int DP[1 << 10][10][100];

// visited, cur
// 지금 몇번째 뎁스를 탐방 중인지
int sol(int trace, int s, int depth) {

  if (depth == N)  return trace == ((1<<10) -1) ? 1 : 0;
  int &ref = DP[trace][s][depth];
  if(ref != -1) return ref;

  ref = 0;
  int l = s - 1;
  int r = s + 1;

  if (l >= 0) ref += sol(trace | (1 << l), l, depth + 1)%MAX;
  if (r < 10) ref += sol(trace | (1 << r), r, depth + 1)%MAX;
  return ref = ref%MAX;
}

// N번째 계단수는 :
//  0으로 끝나는거 또는 9로 끝나는 거는 따로처리
//  0 으로 끝나는거는 그뒤에 1밖에 못옴
// 9 로 끝나는거도 뒤에 8밖에 못옴
// DP[N] => 2*DP[N-1]

// 어차피 모든 것은 0....9 에서 끝나기 마련임

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(DP, -1, sizeof(DP));
  cin >> N;
  int ans = 0;
  for (int i = 1; i < 10; i++) {
    ans += sol((1<<i), i, 1);
    ans %= MAX;
  }
  cout << ans;
  return 0;
}

