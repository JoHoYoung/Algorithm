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

int N;
int l, r;

vector<int> el;

// ���� ��ĭ��, ������ ��ĭ�� ���� �ʴ´�.
// ���ʹ����� Ÿ���� ���� -> ������ ������
// �����ʹ����� Ÿ���� ������ -> �������� ������
// Ÿ���� ��� : �Ѵ� �غ�
int min(int a, int b) {
  if (a > b) return b;
  return a;
}

int DP[21][21][21];

int sol(int l, int r, int idx) {

  int &ref = DP[l][r][idx];

  if (ref != -1) return ref;
  if (idx == el.size()) return 0;

  if (el[idx] <= l) {
    ref = l - el[idx] + sol(el[idx], r, idx + 1);
  } else if (el[idx] >= r) {
    ref = el[idx] - r + sol(l, el[idx], idx + 1);
  } else {
    ref = min(r - el[idx] + sol(l, el[idx], idx + 1), el[idx] - l + sol(el[idx], r, idx + 1));
  }

  return ref;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  cin >> l >> r;

  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int tmp;
    cin >> tmp;
    el.push_back(tmp);
  }
  memset(DP, -1, sizeof(DP));
  cout << sol(l, r, 0);
  return 0;
}

