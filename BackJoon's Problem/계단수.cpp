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

// ���ڸ� �� , ���ڸ� ��
//int DP[100][10];
int DP[1 << 10][10][100];

// visited, cur
// ���� ���° ������ Ž�� ������
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

// N��° ��ܼ��� :
//  0���� �����°� �Ǵ� 9�� ������ �Ŵ� ����ó��
//  0 ���� �����°Ŵ� �׵ڿ� 1�ۿ� ����
// 9 �� �����°ŵ� �ڿ� 8�ۿ� ����
// DP[N] => 2*DP[N-1]

// ������ ��� ���� 0....9 ���� ������ ������

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

