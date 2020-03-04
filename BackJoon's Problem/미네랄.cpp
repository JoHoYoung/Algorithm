#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

#define MAXN 1000000
using namespace std;
using P = pair<int, int>;
int N, M;

int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};
char board[101][101];
char visited[101][101];

int tc[101];

bool isFind = false;
vector<P> cluster;


void bfs(P startPos) {

  if (visited[startPos.first][startPos.second]) return;
  queue<P> Q;
  visited[startPos.first][startPos.second] = true;
  Q.push(startPos);
  cluster.push_back(startPos);
  while (!Q.empty()) {
    P cur = Q.front();
    Q.pop();
    if (cur.first == N - 1) {
      // cout<<"CHANGE"<<endl;
      isFind = true;
    }
    for (int d = 0; d < 4; d++) {
      int ni = cur.first + Di[d];
      int nj = cur.second + Dj[d];

      if (ni < 0 || ni > N - 1 || nj < 0 || nj > M - 1 || visited[ni][nj] || board[ni][nj] == '.') continue;
      visited[ni][nj] = true;
      cluster.push_back({ni, nj});
      Q.push({ni, nj});
    }
  }
}

// bfs를 돌고나면 가로범위, 밑 그 가로 인덱스에서 가장 낮은 친구의 위치가 나온다
int destroyMap(int seq) {
  if (seq % 2 == 0) {
    char *targetRow = board[tc[seq]];
    for (int j = 0; j < M; j++) {
      if (targetRow[j] == 'x') {
        targetRow[j] = '.';
        return j;
      }
    }
  } else {
    char *targetRow = board[tc[seq]];
    for (int j = M - 1; j >= 0; j--) {
      if (targetRow[j] == 'x') {
        targetRow[j] = '.';
        return j;
      }
    }
  }
  return -1;
}

// 같은 장소를 오는것은 단순하지 않다. 재방문하면 단순하지 않다.
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
    }
  }

  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> tc[i];
    tc[i] = N - tc[i];
  }

  for (int i = 0; i < T; i++) {
    int curi, curj;
    curi = tc[i];
    curj = destroyMap(i);

    if (curj == -1) continue;

    for (int d = 0; d < 4; d++) {
      // 초기화
      memset(visited, false, sizeof(visited));
      cluster.clear();
      isFind = false;

      //cout<<"INIT "<<endl;
      //초기화
      int ni = curi + Di[d];
      int nj = curj + Dj[d];
      if (ni < 0 || ni > N - 1 || nj < 0 || nj > M - 1) continue;
      if (board[ni][nj] != 'x') continue;
      bfs({ni, nj});
      if (isFind) continue;
      while (1) {
        bool down = true;
        for (int j = 0; j < cluster.size(); j++) {
          board[cluster[j].first][cluster[j].second] = '.';
        }
        for (int j = 0; j < cluster.size(); j++) {
          int y = cluster[j].first + 1;
          int x = cluster[j].second;
          if (y == N || board[y][x] == 'x') {
            down = false;
            break;
          }
        }
        for (int j = 0; j < cluster.size(); j++) {
          if (down) {
            cluster[j].first++;
          }
          board[cluster[j].first][cluster[j].second] = 'x';
        }

        if (!down) {
          break;
        }
      }
      break;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cout << board[i][j];
    }
    cout << "\n";
  }

  return 0;
}
