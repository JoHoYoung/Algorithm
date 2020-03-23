#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>

#define INF 987654321
#define MAX 1000000
using namespace std;
using ll = long long;
using P = pair<int, int>;

int R, C;
char board[26][26];

P S;
P E;

vector<P> el;

bool visited[26][26][4];

vector<int> Di[8];
vector<int> Dj[8];

int DI[4] = {-1, 0, 1, 0};
int DJ[4] = {0, 1, 0, -1};

int nextDir(int d, char c) {
  if (d == 0) {
    if (c == 124) return 0;
    if (c == '+') return 0;
    if (c == '1') return 1;
    if (c == '4') return 3;
  } else if (d == 1) {
    if (c == '-') return 1;
    if (c == '+') return 1;
    if (c == '3') return 0;
    if (c == '4') return 2;
  } else if (d == 2) {
    if (c == 124) return 2;
    if (c == '+') return 2;
    if (c == '2') return 1;
    if (c == '3') return 3;
  } else if (d == 3) {
    if (c == '-') return 3;
    if (c == '+') return 3;
    if (c == '1') return 2;
    if (c == '2') return 0;
  }
  return -1;
}

int pipeSize;

typedef struct unit {
    int i, j, d, depth;
};

bool BFS() {
  queue<unit> Q;
  Q.push({S.first, S.second, 0, 0});
  Q.push({S.first, S.second, 1, 0});
  Q.push({S.first, S.second, 2, 0});
  Q.push({S.first, S.second, 3, 0});

  visited[S.first][S.second][0] = true;
  visited[S.first][S.second][1] = true;
  visited[S.first][S.second][2] = true;
  visited[S.first][S.second][3] = true;
  bool isFind = false;
  set<pair<int, P>> travel;
  while (!Q.empty()) {
    unit cur = Q.front();
    Q.pop();
    int curI = cur.i;
    int curJ = cur.j;
    int curD = cur.d;
    int ni = curI + DI[curD];
    int nj = curJ + DJ[curD];


    if (ni < 0 || ni > R - 1 || nj < 0 || nj > C - 1 || board[ni][nj] == '.') continue;
    if (ni == E.first && nj == E.second) {
      isFind = cur.depth == pipeSize;
    }

    int nc = board[ni][nj];
    int nd = nextDir(curD, nc);
    if (nd == -1) continue;
    int ndepth = cur.depth + 1;

    for (int i = 0; i < 4; i++) {
      if (visited[ni][nj][i]) {
        ndepth -= 1;
        break;
      }
    }
    visited[ni][nj][nd] = true;
    Q.push({ni, nj, nd, ndepth});

  }
  return isFind;
}

void setDir() {

  Di[0].push_back(-1);
  Di[0].push_back(1);

  Dj[0].push_back(0);
  Dj[0].push_back(0);


  Di[1].push_back(0);
  Di[1].push_back(0);

  Dj[1].push_back(-1);
  Dj[1].push_back(1);

  Di[2].push_back(-1);
  Di[2].push_back(0);
  Di[2].push_back(1);
  Di[2].push_back(0);

  Dj[2].push_back(0);
  Dj[2].push_back(1);
  Dj[2].push_back(0);
  Dj[2].push_back(-1);

  Di[3].push_back(1);
  Di[3].push_back(0);

  Dj[3].push_back(0);
  Dj[3].push_back(1);

  Di[4].push_back(-1);
  Di[4].push_back(0);

  Dj[4].push_back(0);
  Dj[4].push_back(1);

  Di[5].push_back(-1);
  Di[5].push_back(0);

  Dj[5].push_back(0);
  Dj[5].push_back(-1);

  Di[6].push_back(0);
  Di[6].push_back(1);

  Dj[6].push_back(-1);
  Dj[6].push_back(0);
}

char pipes[7] = {124, '-', '+', '1', '2', '3', '4'};

// 인접간선이 없는 노드끼리의 집합
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> R >> C;

  setDir();

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'M') S = {i, j};
      if (board[i][j] == 'Z') E = {i, j};
      if (board[i][j] == '.') el.push_back({i, j});
    }
  }

  pipeSize = R * C - 2 - el.size() + 1;

  for (int i = 0; i < el.size(); i++) {
    for (int p = 0; p < 7; p++) {
      memset(visited, false, sizeof(visited));
      board[el[i].first][el[i].second] = pipes[p];
      if (BFS()) {
        cout << el[i].first + 1 << " " << el[i].second + 1 << " " << pipes[p] << '\n';
        exit(0);
      }
      board[el[i].first][el[i].second] = '.';
    }
  }

}

