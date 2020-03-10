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

int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};
//���� : a,f

int N, M;
char board[50][50];
// ���� �� �� ���� ���� �� �ּڰ�
// Ż���ϴµ� �ɸ��� �̵�Ƚ���� �ּڰ�
// �ϴ� �Ծ�� �ϴ� ����
int visited[51][51][1 << 7];

typedef struct unit {
    int i, j, depth, key;
};

int bfs(P S) {
  queue<unit> Q;
  Q.push({S.first, S.second, 0, 0});
  visited[S.first][S.second][0] = true;
  while (!Q.empty()) {
    unit cur = Q.front();
    Q.pop();
    int curI = cur.i;
    int curJ = cur.j;
    int key = cur.key;
    //cout<<curI<<" "<<curJ<<" "<<key<<endl;
    if (board[curI][curJ] == '1') return cur.depth;
    for (int d = 0; d < 4; d++) {
      int ni = curI + Di[d];
      int nj = curJ + Dj[d];
      if (ni < 0 || ni > N - 1 || nj < 0 || nj > M - 1 || board[ni][nj] == '#') continue;
      char nc = board[ni][nj];
      //���踦 �������
      if ('a' <= nc && nc <= 'f') {
        int nk = key | (1 << (nc - 'a'));
        if (visited[ni][nj][nk]) continue;
        visited[ni][nj][nk] = true;
        Q.push({ni, nj, cur.depth + 1, nk});
        // ���� �������
        // ���谡 �ִ��� �˻�.
      } else if ('A' <= nc && nc <= 'F') {
        // ���谡������ ,
        if (!(key & (1 << (nc - 'A'))) || visited[ni][nj][key]) continue;
        // ���谡 ������
        visited[ni][nj][key] = true;
        Q.push({ni, nj, cur.depth + 1, key});
      } else {
        if (visited[ni][nj][key]) continue;
        visited[ni][nj][key] = true;
        Q.push({ni, nj, cur.depth + 1, key});
      }
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  P S;
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
      if (board[i][j] == '0') S = {i, j};
    }
  }

  memset(visited, false, sizeof(visited));
  cout << bfs(S);

  return 0;
}