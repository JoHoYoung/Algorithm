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

int N;
char board[3][3];


set<string> s;

// 세로 가로 대각
bool row() {
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == '.') continue;
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
  }
  return false;
}

bool col() {
  for (int i = 0; i < 3; i++) {
    if (board[0][i] == '.') continue;
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
  }
  return false;
}

bool diag() {

  if (board[0][0] != '.') {
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
  }
  if (board[0][2] != '.') {
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
  }
  return false;
}

bool isFind() {
  return row() || col() || diag();
}

string sol(string t) {
  auto iter = s.find(t);
  if (iter != s.end())return "valid";
  return "invalid";
}

bool visited[3][3];

void DFS(int nFill, bool cur) {

  if (nFill == 9 || isFind()) {
    string t;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        t.push_back(board[i][j]);
      }
    }

    s.insert(t);
    return;
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (visited[i][j]) continue;
      char nc;
      if (cur) nc = 'O';
      else nc = 'X';
      visited[i][j] = true;
      board[i][j] = nc;
      DFS(nFill + 1, !cur);
      board[i][j] = '.';
      visited[i][j] = false;
    }
  }
}

// 측정 할 수 없는 무게 중 최솟
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  vector<string> r;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = '.';
    }
  }
  DFS(0, false);
  while (1) {
    string in;
    cin >> in;
    if (in == "end") break;
    r.push_back(sol(in));
  }

 //cout << s.size();
  for (int i = 0; i < r.size(); i++) cout << r[i] << "\n";
  return 0;
}