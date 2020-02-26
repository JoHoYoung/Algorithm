#include <iostream>
#include<cstring>
#include<vector>
#include<set>

using namespace std;

int N, lo, hi;

int board[100][100];
int visited[100][100];
int dir[4][2] = {{-1, 0},
                 {1,  0},
                 {0,  -1},
                 {0,  1}};

int min(int a, int b) {
  if (a > b) {
    return b;
  }
  return a;
}

void dfs(int i, int j) {

  if (i < 0 || i >= N || j < 0 || j >= N || visited[i][j] || board[i][j] < lo || board[i][j] > hi) return;
  visited[i][j] = true;
  for (int d = 0; d < 4; d++) dfs(i + dir[d][0], j + dir[d][1]);
}

int result = 10000000;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);


  cin >> N;
  set<int> s;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
      s.insert(board[i][j]);
    }
  }

  set<int>::iterator l = s.begin(), r = s.begin();
  while(r != s.end()){
    while(l !=s.end()){
      memset(visited, 0, sizeof(visited));
      lo = *l;
      hi = *r;
      dfs(0, 0);

      if (!visited[N - 1][N - 1]) {
        break;
      }
      l++;
      result = min(result, hi - lo);
    }
    r++;
  }
  cout << result;
  return 0;
}
