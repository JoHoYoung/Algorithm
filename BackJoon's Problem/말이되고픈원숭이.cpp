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
int k, w, h;

bool board[200][200];
bool visited[200][200][32];


int hDi[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int hDj[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};

// 말의 움직임은 K번만 할 수 있다.
typedef struct unit {
    int i, j, d, hm;
};
queue<unit> Q;

int BFS() {

  Q.push({0, 0, 0, 0});
  visited[0][0][0] = 0;
  while (!Q.empty()) {
    unit cur = Q.front();
    Q.pop();

    int curI = cur.i;
    int curJ = cur.j;
    int curD = cur.d;
    int curHm = cur.hm;

     if (curI == h - 1 && curJ == w - 1) {
      return curD;
    }

    // 말처럼 움직이기
    if (curHm < k) {
      for (int d = 0; d < 8; d++) {
        int ni = curI + hDi[d];
        int nj = curJ + hDj[d];
        if (ni < 0 || ni > h - 1 || nj < 0 || nj > w - 1 || board[ni][nj] || visited[ni][nj][curHm + 1]) continue;
        visited[ni][nj][curHm + 1] = true;
        Q.push({ni, nj, curD + 1, curHm + 1});
      }
    }

    for (int d = 0; d < 4; d++) {
      int ni = curI + Di[d];
      int nj = curJ + Dj[d];
      if (ni < 0 || ni > h - 1 || nj < 0 || nj > w - 1 || board[ni][nj] || visited[ni][nj][curHm]) continue;
      visited[ni][nj][curHm] = true;
      Q.push({ni, nj, curD + 1, curHm});
    }
    // 그냥 움직이기
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> k >> w >> h;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> board[i][j];
    }
  }
  memset(visited, false, sizeof(visited));
  cout<<BFS()<<"\n";
  return 0;
}