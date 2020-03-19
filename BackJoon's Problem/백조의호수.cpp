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

int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};

vector<P> S;
P startP;
P endP;
char board[1501][1501];

typedef struct unit {
    int i, j, depth;
};

queue<unit> Q;
int visited[1501][1501];
bool travelVisited[1501][1501];

int min(int a,int b){
  if(a>b) return b;
  return a;
}

int maxCost = 0;

bool travel(int limit) {
  queue<P> Q;
  Q.push(startP);

  travelVisited[startP.first][startP.second] = true;

  while (!Q.empty()) {
    P cur = Q.front();
    Q.pop();

    int curI = cur.first;
    int curJ = cur.second;

    if (curI == endP.first && curJ == endP.second) return true;
    for (int d = 0; d < 4; d++) {
      int ni = curI + Di[d];
      int nj = curJ + Dj[d];
      if (ni < 0 || ni > R - 1 || nj < 0 || nj > C - 1) continue;
      if (visited[ni][nj] > limit) continue;

      if (travelVisited[ni][nj]) continue;

      travelVisited[ni][nj] = true;
      Q.push({ni, nj});
    }
  }
  return false;
}

void bfs() {
  while (!Q.empty()) {
    unit cur = Q.front();
    Q.pop();
    int curI = cur.i;
    int curJ = cur.j;
    int curD = cur.depth;

    for (int d = 0; d < 4; d++) {
      int ni = curI + Di[d];
      int nj = curJ + Dj[d];
      if (ni < 0 || ni > R - 1 || nj < 0 || nj > C - 1) continue;
      if (board[ni][nj] == '.' || board[ni][nj] == 'L') {
        visited[ni][nj] = 0;
        continue;
      }

      if (visited[ni][nj] != -1) continue;
      visited[ni][nj] = curD + 1;
      maxCost = max(visited[ni][nj], maxCost);
      Q.push({ni, nj, curD + 1});
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> R >> C;

  memset(visited, -1, sizeof(visited));
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'L') {
        Q.push({i,j,0});
        S.push_back({i, j});
      }
      if (board[i][j] == '.') Q.push({i, j, 0});
    }
  }
  bfs();
  startP = S[0];
  endP = S[1];

  int result = INF;
  int l = 0;
  int r = maxCost;

  while (l <= r) {
    int mid = (l + r) / 2;
    memset(travelVisited, false, sizeof(travelVisited));
    while(!Q.empty()) Q.pop();
    if (travel(mid)) {
      result = min(result, mid);
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  cout << result;
  return 0;
}

