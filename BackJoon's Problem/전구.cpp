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

int N, K;

vector<int> el;

// ������ 200��.
// ���� ������ 20����
//

// i��? ������ ������, �ȴ�����
// ������ 200����.. ����ø��� ���¸� �����ϱ�� ����ѵ�

//DP[i][j][k] : 1~j�� k�������� ����� ����� �ּڰ�
int DP[201][201];

int min(int a, int b) {
  if (a > b) return b;
  return a;
}

void sol() {

  for (int i = 1; i <= N; i++) {
    DP[i][i] = 0;
  }

  for (int d = 1; d < N; d++) {
    for (int i = 1; i + d <= N; i++) {
      DP[i][i + d] = INF;
      for (int p = i; p + 1 <= i + d; p++) {
        int l = DP[i][p];
        int r = DP[p + 1][i + d];
        int pivot = el[i] == el[p + 1] ? 0 : 1;
        DP[i][i + d] = min(DP[i][i+d], l + r + pivot);
      }
    }
  }

}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K;
  el.resize(N + 2);

  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    el[i + 1] = tmp;
  }
  sol();
 // cout<<DP[3][7];
  cout << DP[1][N];
  return 0;
}

