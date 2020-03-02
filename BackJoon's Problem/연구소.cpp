#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

#define MAXN 4000001

#define ll long long

using namespace std;
using P = pair<long, long>;
int N, M;

int board[100][100];

int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};

vector<P> W;
vector<P> V;
vector<P> Z;

vector<vector<int>> comb;

bool selected[100];

// N까지 k개를 뽑아라.
void combination(int idx, int N, int k, int depth, vector<int> &arr) {

  if (depth == k) {
    comb.push_back(arr);
    return;
  }

  for (int i = idx; i < N; i++) {
    if (selected[i]) continue;
    selected[i] = true;
    vector<int> temp;
    temp.assign(arr.begin(), arr.end());
    temp.push_back(i);
    combination(i, N, k, depth + 1, temp);
    selected[i] = false;
  }
}

queue<P> Q;
bool visited[100][100];

void bfs() {

  while (!Q.empty()) {
    P now = Q.front();
    Q.pop();
    for (int i = 0; i < 4; i++) {
      int nextI = now.first + Di[i];
      int nextJ = now.second + Dj[i];
      if (nextI < 0 || nextI > N - 1 || nextJ < 0 || nextJ > M - 1 || visited[nextI][nextJ] ||
          board[nextI][nextJ] == 1)
        continue;
      visited[nextI][nextJ] = true;
      Q.push({nextI, nextJ});
    }
  }
}

int countVisited() {
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (visited[i][j]) cnt++;
    }
  }
  return cnt;
}


int max(int a, int b) {
  if (a > b) return a;
  return b;
}

int result = 0;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
      if (board[i][j] == 1) {
        W.push_back({i, j});
      } else if (board[i][j] == 2) {
        V.push_back({i, j});
      } else {
        Z.push_back({i, j});
      }
    }
  }

  vector<int> a;
  memset(selected, false, sizeof(selected));

  combination(0, Z.size(), 3, 0, a);
  for (auto it = comb.begin(); it != comb.end(); it++) {
    for (auto it2 = (*it).begin(); it2 != (*it).end(); it2++) {
      P pos = Z[*it2];
      board[pos.first][pos.second] = 1;
    }

    memset(visited, false, sizeof(visited));

    // 탐색
    for (auto it = V.begin(); it != V.end(); it++) {
      visited[(*it).first][(*it).second] = true;
      Q.push(*it);
    }

    bfs();
    int visitedNumber = countVisited();
    int tempResult = N * M - visitedNumber - W.size() - 3;
    result = max(result, tempResult);
    // 원상복구
    for (auto it2 = (*it).begin(); it2 != (*it).end(); it2++) {
      P pos = Z[*it2];
      board[pos.first][pos.second] = 0;
    }
  }
  cout << result;
  return 0;
}