#include <iostream>
#include<cstring>
#include<vector>
#include<set>

using namespace std;

int N;

char board[51][51];
int height[51][51];
bool visited[51][51];
int comm[2500];

int lo, hi;

int dir[8][2] = {{-1, -1},
                 {-1, 0},
                 {-1, 1},
                 {0,  1},
                 {0,  -1},
                 {1,  1},
                 {1,  0},
                 {1,  -1}};

struct pos {
    int i, j;
};

vector<pos> dist;

int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

int min(int a, int b) {
  if (a > b) {
    return b;
  }
  return a;
}

bool visitedAll() {
  for (int i = 0; i < dist.size(); i++) {
    pos now = dist.at(i);
    if (!visited[now.i][now.j]) {
      return false;
    }
  }
  return true;
}

int result = 10000000;
//
//void dfs(int i, int j) {
//
//  for (int d = 0; d < 8; d++) {
//    int nextI = i + dir[d][0];
//    int nextJ = j + dir[d][1];
//    if (nextI < 0 || nextI >= N || nextJ < 0 || nextJ >= N || visited[nextI][nextJ] || height[nextI][nextJ] < lo ||
//        height[nextI][nextJ] > hi) {
//      continue;
//    }
//    visited[nextI][nextJ] = true;
//    dfs(nextI, nextJ);
//  }
//}

void print(int N) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << visited[i][j] << " ";
    }
    cout << endl;
  }
}

void dfs(int i, int j) {
  for (int d = 0; d < 8; d++) {
    int nextI = i + dir[d][0];
    int nextJ = j + dir[d][1];
    if (nextI < 0 || nextI >= N || nextJ < 0 || nextJ >= N || visited[nextI][nextJ] || height[nextI][nextJ] < lo ||
        height[nextI][nextJ] > hi) {
      continue;
    }
    visited[nextI][nextJ] = true;
    dfs(nextI, nextJ);
  }
}

//void dfs(int i, int j) {
//  if (i < 0 || i >= N || j < 0 || j >= N || visited[i][j] || height[i][j] < lo || height[i][j] > hi) return;
//  visited[i][j] = true;
//  for (int d = 0; d < 8; d++) {
////    int nextI = i + dir[d][0];
////    int nextJ = j + dir[d][1];
//    dfs(i + dir[d][0], j + dir[d][1]);
//  }
//}
//
//void dfs(int i, int j) {
//  if (i < 0 || j < 0 || i >= N || j >= N || visited[i][j] || height[i][j] < lo || height[i][j] > hi)return;
//  visited[i][j] = 1;
//  for (int d = 0; d < 8; ++d)dfs(i + dir[d][0], j + dir[d][1]);
//}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  pos start;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'K') {
        dist.push_back(pos{i, j});
      }
      if (board[i][j] == 'P') {
        start = pos{i, j};
      }
    }
  }

  set<int> dif;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> height[i][j];
      dif.insert(height[i][j]);
    }
  }

  set<int>::iterator l = dif.begin(), r = dif.begin();
//
  while (r != dif.end()) {
    while (l != dif.end()) {

      lo = (*l);
      hi = (*r);
      memset(visited, 0, sizeof(visited));
      dfs(start.i, start.j);
      if (!visitedAll()) {
        break;
      }
      result = min(result, hi - lo);
      ++l;
    }
    ++r;
  }

//  for (auto it = dif.begin(); it != dif.end(); it++) {
//    for (auto it2 = dif.begin(); it2 != dif.end(); it2++) {
//      lo = (*it2);
//      hi = (*it);
//      cout<<lo<<" "<<hi<<endl;
//      memset(visited, 0, sizeof(visited));
//      dfs(start.i, start.j);
//      if (!visitedAll()) {
//        break;
//      }
//      result = min(result, hi - lo);
//    }
//  }

  cout << result;
  return 0;
}
