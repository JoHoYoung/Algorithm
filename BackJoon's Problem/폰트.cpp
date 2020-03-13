#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;
int N, K;

// ���տ��� K�� ������ �������� ������ �����

// param : (����� �ܾ� ����Ʈ, ����ܾ�)

vector<int> el;
int ans = 0;

void dfs(int trace, int depth) {
  if (depth == N) {
    if (trace == (1 << 26) - 1) ans++;
    return;
  }
  dfs(trace | el[depth], depth + 1);
  dfs(trace, depth + 1);
}


int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  string tmp;
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    int s = 0;
    int l = tmp.size();
    for (int j = 0; j < l; j++) {
      s |= (1 << (tmp[j] - 'a'));
    }
    el.push_back(s);
  }
  dfs(0, 0);
  cout << ans;
  return 0;
}