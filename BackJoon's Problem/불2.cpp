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

int t, w, h;

char board[1000][1000];

int visited[1000][1000];

int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};

// 작은 칸으로만 이동할 수 있다.
typedef struct unit {
    int i, j, d;
};

int ans;
queue<unit> Q;

void BFS() {
 // Q.push({S.first, S.second, 0});
 // visited[S.first][S.second] = 0;
  while (!Q.empty()) {
    unit cur = Q.front();
    Q.pop();
    int curI = cur.i;
    int curJ = cur.j;
    int curD = cur.d;

    for (int d = 0; d < 4; d++) {
      int ni = curI + Di[d];
      int nj = curJ + Dj[d];
      if (ni < 0 || ni > h - 1 || nj < 0 || nj > w - 1 || board[ni][nj] == '#') continue;
      if (visited[ni][nj] <= curD + 1 && visited[ni][nj] != -1) continue;
      visited[ni][nj] = curD + 1;
      Q.push({ni, nj, curD + 1});
    }
  }
}

void BFSUser(P S) {
  Q.push({S.first, S.second, 0});
  visited[S.first][S.second] = 0;
  while (!Q.empty()) {
    unit cur = Q.front();
    Q.pop();
    int curI = cur.i;
    int curJ = cur.j;
    int curD = cur.d;

    if (curI == 0 || curI == h - 1 || curJ == 0 || curJ == w - 1) {
      ans = curD;
      return;
    }
//    cout << curI << " " << curJ << endl;
    for (int d = 0; d < 4; d++) {
      int ni = curI + Di[d];
      int nj = curJ + Dj[d];
      if (ni < 0 || ni > h - 1 || nj < 0 || nj > w - 1 || board[ni][nj] == '#') continue;
      if (visited[ni][nj] <= curD + 1 && visited[ni][nj] != -1) continue;
      visited[ni][nj] = curD + 1;
      Q.push({ni, nj, curD + 1});
    }
  }
}

vector<P> F;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;

  while (t > 0) {

    ans = INF;
    cin >> w >> h;
    F.clear();
    P S;
    memset(visited, -1, sizeof(visited));
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> board[i][j];
        if (board[i][j] == '*') F.push_back({i, j});
        if (board[i][j] == '@') S = {i, j};
      }
    }

    for (int i = 0; i < F.size(); i++) {
      Q.push({F[i].first, F[i].second, 0});
      visited[F[i].first][F[i].second] = 0;
    }

    BFS();
//    for (int i = 0; i < h; i++) {
//      for (int j = 0; j < w; j++) {
//        cout << visited[i][j] << " ";
//      }
//      cout << endl;
//    }
    BFSUser(S);
    if (ans == INF) cout << "IMPOSSIBLE\n";
    else cout << ans + 1 << "\n";
    t--;
  }
  return 0;
}