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

int N, M;

int board[301][301];

vector<P> pos[11];

int cumulSum[11];
bool visited[301][301];

int remain;
int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};

int nZero(P s) {
  int ans = 0;
  for (int d = 0; d < 4; d++) {
    int ni = s.first + Di[d];
    int nj = s.second + Dj[d];
    if (board[ni][nj] == 0) ans++;
  }
  return ans;
}

int nonZero;

void timepss() {
  memset(visited, false, sizeof(visited));
  nonZero = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      board[i][j] -= nZero({i, j});
      board[i][j] = board[i][j] < 0 ? 0 : board[i][j];
      if (board[i][j] != 0) nonZero++;
    }
  }
}

void print() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}

int BFS() {
  memset(visited, false, sizeof(visited));
  queue<P> Q;
  bool fi = false;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] == 0) continue;
      Q.push({i, j});
      visited[i][j] = true;
      fi = true;
      break;
    }
    if (fi) break;
  }
  int ans = 0;
  while (!Q.empty()) {
    int curI = Q.front().first;
    int curJ = Q.front().second;
    Q.pop();
    ans++;
    for (int d = 0; d < 4; d++) {
      int ni = curI + Di[d];
      int nj = curJ + Dj[d];
      if (visited[ni][nj] || board[ni][nj] == 0) continue;
      visited[ni][nj] = true;
      Q.push({ni, nj});
    }
  }
  //cout<<"RETURN "<<ans<<endl;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  nonZero = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
      if (board[i][j] != 0) nonZero++;
    }
  }

  int time = 0;
  while (nonZero != 0) {
    //cout<<"NONZ "<<nonZero<<endl;
    print();
    cout << endl;
    if (BFS() != nonZero) {
      cout << time;
      exit(0);
    }
    timepss();
    time++;
  }
  cout << 0;
  return 0;
}

