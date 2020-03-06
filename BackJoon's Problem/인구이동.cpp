#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;
using P = pair<int, int>;
const int INF = 987654321;

int N, L, R;
int board[101][101];

int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};

bool visited[101][101];

vector<P> pos[50000];

int abs(int a) {
  if (a < 0) return -a;
  return a;
}

void dfs(int i, int j, int depth, int no) {

  if (visited[i][j]) return;
  //cout<<i<<" "<<j<<" "<<depth<<endl;
  int curN = board[i][j];
  visited[i][j] = true;
  pos[no].push_back({i, j});
  for (int d = 0; d < 4; d++) {
    int ni = i + Di[d];
    int nj = j + Dj[d];
    if (ni < 0 || ni > N - 1 || nj < 0 || nj > N - 1 || visited[ni][nj]) continue;
    int dif = abs(curN - board[ni][nj]);
    if (dif < L || dif > R) continue;
    dfs(ni, nj, depth + 1, no);
  }
}

void sumAnddivide(vector<P> p) {
  int sum = 0;
  for (int i = 0; i < p.size(); i++) {
    sum += board[p[i].first][p[i].second];
  }
  for (int i = 0; i < p.size(); i++) {
    board[p[i].first][p[i].second] = sum / p.size();
  }
}

int mvCount = 0;
bool isFind = false;

void mv() {
  for (int i = 0; i < 2500; i++) {
    if (pos[i].size() <= 1) continue;
    sumAnddivide(pos[i]);
    isFind = true;
  }

  for (int i = 0; i < 2500; i++) {
    pos[i].clear();
  }
}

void print() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0); //cin 실행속도 향상
  cin >> N >> L >> R;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }

  while (1) {
    int no = 0;
    isFind = false;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (visited[i][j]) continue;
        dfs(i, j, 0, no++);
      }
    }

    mv();
    if (!isFind) break;
    mvCount++;
  }
  cout << mvCount;
  return 0;
}