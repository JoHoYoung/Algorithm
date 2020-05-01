#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>

#define MAXN 31
#define INF 98765432
#define MAX 1000000

using namespace std;
using ll = long long;
using P = pair<int, int>;

int A, B, N, M;

// ºÏ µ¿ ³² ¼­
int Di[4] = {1, 0, -1, 0};
int Dj[4] = {0, 1, 0, -1};

typedef struct unit {
    P pos;
    int dir;
};

vector<unit> Robots;

int board[101][101];

int DIR(char d) {
  if (d == 'N') return 0;
  if (d == 'E') return 1;
  if (d == 'S') return 2;
  if (d == 'W') return 3;
}

void mv(int no, char cmd) {
  if (cmd == 'L') {
    Robots[no].dir = Robots[no].dir - 1 < 0 ? 3 : Robots[no].dir - 1;
  } else if (cmd == 'R') {
    Robots[no].dir = (Robots[no].dir + 1) % 4;
  } else if (cmd == 'F') {
    int ni = Robots[no].pos.first + Di[Robots[no].dir];
    int nj = Robots[no].pos.second + Dj[Robots[no].dir];
    if (ni <= 0 || ni > B || nj <= 0 || nj > A) {
      cout << "Robot " << no << " crashes into the wall";
      exit(0);
    }
    if (board[ni][nj] != 0) {
      cout << "Robot " << no << " crashes into robot " << board[ni][nj];
      exit(0);
    }
    board[Robots[no].pos.first][Robots[no].pos.second] = 0;
    board[ni][nj] = no;
    Robots[no].pos.first = ni;
    Robots[no].pos.second = nj;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> A >> B >> N >> M;
  memset(board, 0, sizeof(board));
  int no = 1;
  Robots.push_back({{-1,-1},-1});
  for (int i = 0; i < N; i++) {
    int x, y;
    char d;
    cin >> x >> y >> d;
    Robots.push_back({{y, x}, DIR(d)});
    board[y][x] = no++;
  }


  for (int i = 0; i < M; i++) {
    int no;
    char cmd;
    int loop;
    cin >> no >> cmd >> loop;
    while (loop--) mv(no, cmd);
  }
  cout << "OK";
  return 0;
}


