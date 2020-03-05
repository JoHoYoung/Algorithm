#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

#define MAXN 99999999

using namespace std;
using P = pair<int, int>;
int N, M;

int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};
int result = MAXN;
bool **board;

bool visited[20];
vector<vector<int>> PERM;
vector<vector<int>> COMB;

void comb(int N, int n, int depth, int idx, vector<int> arr) {
  if (depth == n) {
    COMB.push_back(arr);
    return;
  }
  for (int i = idx; i <= N; i++) {
    if (visited[i]) continue;
    visited[i] = true;
    vector<int> a;
    a.assign(arr.begin(), arr.end());
    a.push_back(i);
    comb(N, n, depth + 1, i + 1, a);
    visited[i] = false;
  }
}

void perm(int N, int n, int depth, vector<int> arr) {
  if (depth == n) {
    PERM.push_back(arr);
    return;
  }

  for (int i = 0; i <= N; i++) {
    if (visited[i]) continue;
    visited[i] = true;
    vector<int> a;
    a.assign(arr.begin(), arr.end());
    a.push_back(i);
    perm(N, n, depth + 1, a);
    visited[i] = false;
  }
}

void press(P pos, bool **board) {
  board[pos.first][pos.second] = !board[pos.first][pos.second];
  for (int d = 0; d < 4; d++) {
    int ni = pos.first + Di[d];
    int nj = pos.second + Dj[d];
    if (ni < 0 || ni > N - 1 || nj < 0 || nj > N - 1) continue;
    board[ni][nj] = !board[ni][nj];
  }
}

bool **copyBoard(bool **target) {
  bool **temp = new bool *[20];

  for (int i = 0; i < N; i++) {
    temp[i] = new bool[20];
    for (int j = 0; j < N; j++) {
      temp[i][j] = target[i][j];
    }
  }
  return temp;
}

bool sol(bool **board, int &cnt) {

  for (int h = 0; h < N - 1; h++) {
    for (int j = 0; j < N; j++) {
      if (board[h][j]) {
        press({h + 1, j}, board);
        cnt++;
      }
    }
  }

  for (int j = 0; j < N; j++) if (board[N - 1][j]) return false;
  return true;
}


void print(bool **board) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}

int min(int a, int b) {
  if (a > b) return b;
  return a;
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  board = new bool *[20];

  for (int i = 0; i < N; i++) {
    board[i] = new bool[20];
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }


  vector<int> a;
  COMB.push_back(a);
  for (int i = 1; i <= N; i++) {
    vector<int> a;
    comb(N - 1, i, 0, 0, a);
  }

  for (int i = 0; i < COMB.size(); i++) {
    bool **newArr = copyBoard(board);
    int cnt = 0;
    for (int j = 0; j < COMB[i].size(); j++) {
      press({0, COMB[i][j]}, newArr);
      cnt++;
    }
    if (sol(newArr, cnt)) result = min(result, cnt);
  }

  if (result == MAXN) cout << -1;
  else cout << result;

  return 0;
}
