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

char board[13][8];

void resetBoard() {
  int col = 0;
  while (col < 6) {
    for (int i = 11; i >= 0; i--) {
      char block = board[i][col];
      int startPos = i + 1;
      if (block == '.') continue;
      while (1) {
        if (startPos > 12 || board[startPos][col] != '.') break;
        board[startPos - 1][col] = '.';
        board[startPos][col] = block;
        startPos++;
      }
    }
    col++;
  }
}

bool visited[13][8];

typedef struct unit {
    P pos;
    int depth;
};

int max(int a, int b) {
  if (a > b) return a;
  return b;
}

vector<P> toDelete;

void delBlock() {
  for (int i = 0; i < toDelete.size(); i++) {
    P p = toDelete[i];
    board[p.first][p.second] = '.';
  }
}

int BFS(P startPos) {
  // cout<<"BFS"<<endl;
  if (visited[startPos.first][startPos.second] || board[startPos.first][startPos.second] == '.') return 0;
  queue<unit> Q;
  visited[startPos.first][startPos.second] = true;
  Q.push({startPos, 1});
  int maxDepth = 0;
  while (!Q.empty()) {
    unit now = Q.front();
    P cur = now.pos;

    maxDepth = max(maxDepth, now.depth);
    Q.pop();
    for (int d = 0; d < 4; d++) {
      int ni = cur.first + Di[d];
      int nj = cur.second + Dj[d];

      if (ni < 0 || ni > 11 || nj < 0 || nj > 6 || visited[ni][nj] ||
          board[ni][nj] != board[cur.first][cur.second])
        continue;
      visited[ni][nj] = true;
      Q.push({{ni, nj}, now.depth + 1});
    }
  }
  cout << "RETURN " << maxDepth << endl;
  return maxDepth;
}

int num = 0;

void DFS(P cur, int depth) {

  if (visited[cur.first][cur.second] || board[cur.first][cur.second] == '.') return;
  visited[cur.first][cur.second] = true;
  toDelete.push_back(cur);
 // cout<<cur.first<<" "<<cur.second<<" depth "<<depth<<" "<<board[cur.first][cur.second]<<endl;
  num++;
  for (int d = 0; d < 4; d++) {
    int ni = cur.first + Di[d];
    int nj = cur.second + Dj[d];
    if (ni < 0 || ni > 11 || nj < 0 || nj > 6 || visited[ni][nj] ||
        board[ni][nj] != board[cur.first][cur.second])
      continue;
    DFS({ni, nj}, depth + 1);
  }
}

void print() {
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 6; j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 6; j++) {
      cin >> board[i][j];
    }
  }

  int cnt = 0;
  while (1) {
    bool isFind = false;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < 12; i++) {
      for (int j = 0; j < 6; j++) {
        toDelete.clear();
        DFS({i, j}, 1);
        if (toDelete.size() >= 4) {
      //    cout << "DELE " << toDelete.size() << endl;
          isFind = true;
          delBlock();
      //    cout << endl;
        }
      }
    }

    resetBoard();
   // print();
    if (!isFind) break;
    cnt++;
  }
  cout<<cnt;
  return 0;
}
