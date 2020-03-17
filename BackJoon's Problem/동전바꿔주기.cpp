#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>

#define INF 987654321
#define MAX 1000000000
using namespace std;
using ll = long long;
using P = pair<int, int>;

int T, k;

//������ �Ἥ.. �ݾ�?
// �ݾ��� �޸������̼� ����
// ������ �� �����

vector<int> el;
int num[101];

// DP[i][j] i��° �����ܰ迡�� �ݾ� j�� ������Ű�� ��찡 ��� �ִ���.
int DP[101][10001];
//int DP[10001];


int sol(int cost, int idx) {

  if (cost > T) return 0;
  if (cost == T) {
    // cout << cost << endl;
    return 1;
  }
  if (idx >= el.size()) return 0;
  int &ref = DP[idx][cost];
  if(ref != -1) return ref;

  ref = 0;
  int coin = el[idx];
  for (int i = 0; i <= num[idx]; i++) {
    ref += sol(cost + i * coin, idx + 1);
  }
  return ref;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T >> k;

  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    el.push_back(a);
    num[i] = b;
  }
  memset(DP, -1, sizeof(DP));
  cout << sol(0, 0);
  return 0;
}

