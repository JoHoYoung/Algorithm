#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>

#define MAXN 31
#define INF 987654321
#define MAX 1000000

using namespace std;
using ll = long long;
using P = pair<int, int>;

int N, M, x, y, k;
int board[21][21];

int store[6] = {0, 0, 0, 0, 0, 0};
int dice[6] = {0, 0, 0, 0, 0, 0};
// return floor
int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};

void save() {
  for (int i = 0; i < 6; i++) {
    store[i] = dice[i];
  }
}

void mv(int dir) {
  if (dir == 0) {
    dice[0] = store[3];
    dice[1] = store[0];
    dice[2] = store[1];
    dice[3] = store[2];
  } else if (dir == 2) {
    dice[0] = store[1];
    dice[1] = store[2];
    dice[2] = store[3];
    dice[3] = store[0];
  } else if (dir == 1) {
    dice[0] = store[4];
    dice[4] = store[2];
    dice[2] = store[5];
    dice[5] = store[0];
  } else if (dir == 3) {
    dice[0] = store[5];
    dice[5] = store[2];
    dice[2] = store[4];
    dice[4] = store[0];
  }
}

int dir(int d) {
  switch (d) {
    case 1:
      return 1;
    case 2:
      return 3;
    case 3 :
      return 0;
    case 4 :
      return 2;
  }
}

void print() {
  for (int i = 0; i < 6; i++) {
    cout << dice[i] << " ";
  }
  cout << endl;
}

// ³² ³² ³² µ¿ ºÏ ºÏ ºÏ ¼­
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> x >> y >> k;
  vector<int> re;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
    }
  }

  for (int i = 0; i < k; i++) {
    int cmd;
    cin >> cmd;
    int d = dir(cmd);
    int nx = x + Di[d];
    int ny = y + Dj[d];
    //  cout<<nx<<" "<<ny<<endl;
    if (nx < 0 || nx > N - 1 || ny < 0 || ny > M - 1) continue;
    x = nx;
    y = ny;
    mv(d);
    if (board[x][y] == 0) board[x][y] = dice[0];
    else if (board[0] != 0) {
      dice[0] = board[x][y];
      board[x][y] = 0;
    }
    // print();
    save();
    cout << dice[2] << "\n";
  }

  return 0;
}


