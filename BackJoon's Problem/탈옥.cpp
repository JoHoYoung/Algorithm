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

int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};
int tc, h, c;
int board[103][103];

int visited[3][103][103];

// 문을 여는 최소 갯수
vector<P> C;
vector<P> doors;
P CA;
P CB;
typedef struct unit {
    int i, j, depth;
};

void BFS(P S, int idx) {
  queue<unit> Q;
  Q.push({S.first, S.second, 0});
  visited[idx][S.first][S.second] = 0;

  while (!Q.empty()) {
    unit cur = Q.front();
    Q.pop();
    int curI = cur.i;
    int curJ = cur.j;
    int curD = cur.depth;
    for (int d = 0; d < 4; d++) {
      int ni = curI + Di[d];
      int nj = curJ + Dj[d];
      int nD = curD;
      if (ni < 0 || ni > h + 1 || nj < 0 || nj > c + 1 || board[ni][nj] == '*') continue;
      if (board[ni][nj] == '#') nD += 1;

      if (visited[idx][ni][nj] != -1 && visited[idx][ni][nj] <= nD) continue;
      visited[idx][ni][nj] = nD;
      Q.push({ni, nj, nD});
    }
  }
}

int min(int a, int b) {
  return a > b ? b : a;
}

int getAns() {
  int ans = INF;

  for (int i = 0; i <= h + 1; i++) {
    for (int j = 0; j <= c + 1; j++) {
      if(visited[0][i][j] == -1 || visited[1][i][j] == -1 || visited[2][i][j] == -1) continue;
      int tmp = visited[0][i][j] + visited[1][i][j] + visited[2][i][j];
      if(board[i][j] == '#') tmp-=2;
   //   cout<<"TMP : "<<tmp<<" at "<<i<<" "<<j<<endl;
      ans = min(ans, tmp);
    }
  }
  return ans;
}


int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> tc;
  while (tc--) {
    C.clear();
    doors.clear();
    cin >> h >> c;
    memset(board, 0, sizeof(board));
    memset(visited, -1, sizeof(visited));
    for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= c; j++) {
        char tp;
        cin >> tp;
        board[i][j] = tp;
        if (board[i][j] == '$') C.push_back({i, j});
        if (board[i][j] == '#') doors.push_back({i, j});
      }
    }

    CA = C[0];
    CB = C[1];

    BFS({0, 0}, 0);
    BFS(CA, 1);
    BFS(CB, 2);
    cout<<getAns()<<'\n';
  }

  return 0;
}

