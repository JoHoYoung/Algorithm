#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 987654321;

int board[20][20];

//�����ֵ�, ������ġ
int visited[1 << 16][20];
string s;
int N, p;

int countSetBits(int n) {
  int count = 0;
  while (n) {
    count += n & 1;
    n >>= 1;
  }
  return count;
}

int min(int a, int b) {
  if (a > b) return b;
  return a;
}

int ans = INF;

void DFS(int trace, int cur) {
  // ��δ� ������
  cout << trace << " " << cur << " " << endl;
  if (countSetBits(trace) >= p) {
    ans = min(ans, visited[trace][cur]);
    return;
  }
  cout<<"FROM "<<cur<<endl;
  for (int v = 0; v < N; v++) {
    if (v == cur) continue;
    // �̹� ���� �����ҷδ� ���� ����
    if ((trace & (1<<v)) != 0) continue;
    int nTrace = trace | 1 << v;
    int nCost = visited[trace][cur] + board[cur][v];
    if (visited[nTrace][v] <= nCost && visited[nTrace][v] != -1) continue;
    visited[nTrace][v] = nCost;
    DFS(nTrace, v);
  }
}

// ��� P��.
// �������� Y������ ����
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  //cout<<countSetBits(7);
  cin >> N;

  for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> board[i][j];

  int initTrace = 0;
  vector<int> startPos;

  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'N') continue;
    initTrace = initTrace | 1 << i;
    startPos.push_back(i);
  }

  cin >> p;
  for (int i = 0; i < startPos.size(); i++) {
    memset(visited, -1, sizeof(visited));
    visited[initTrace][startPos[i]] = 0;
    DFS(initTrace, startPos[i]);
  }


  cout << ans;
  return 0;
}