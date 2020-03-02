#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;
using P = pair<long, long>;

int R, C;

int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};

char board[21][21];

bool check['Z' - 'A' + 1];

bool visited[21][21];

int max(int a, int b) {
  if (a > b) return a;
  return b;
}

int result = 0;

void dfs(int i, int j, int depth){

  for (int d = 0; d < 4; d++) {
    int ni = i + Di[d];
    int nj = j + Dj[d];
    if (ni < 0 || ni > R - 1 || nj < 0 || nj > C - 1 || check[board[ni][nj] - 'A'] || visited[ni][nj])
      continue;
    visited[ni][nj] = true;
    check[board[ni][nj] - 'A'] = true;
    dfs(ni,nj,depth+1);
    check[board[ni][nj] - 'A'] = false;
    visited[ni][nj] = false;
  }
  result = max(result, depth);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> R >> C;

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> board[i][j];
    }
  }

  memset(visited, false, sizeof(visited));
  memset(check, false, sizeof(check));

  check[board[0][0] - 'A']= true;
  visited[0][0] = 1;
  dfs(0,0,1);
  cout << result;
  return 0;
}
