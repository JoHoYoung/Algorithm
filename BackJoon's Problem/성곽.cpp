#include <iostream>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;


// [0 ,0 ,0 ,0]
// ³² µ¿ ºÏ ¼­
//
int dir[4][2] = {{1,  0},
                 {0,  1},
                 {-1, 0},
                 {0,  -1}};

int n, m;
int board[50][50];
int no = 0;
bool visited[50][50];

int _width[2501];

int *intToBinary(int l) {

  int *arr = new int[4];
  int pivot = 8;

  for (int i = 0; i < 4; i++) {
    if (l >= pivot) {
      arr[i] = 1;
    } else {
      arr[i] = 0;
    }
    l = l % pivot;
    pivot /= 2;
  }
  return arr;
}

struct Room{
  int no;
};

Room rooms[50][50];

struct Unit {
    int depth;
    int i, j;
};

queue<Unit> Q;

bool init() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!visited[i][j]) {
        visited[i][j] = true;
        rooms[i][j] = Room{no};
        Q.push(Unit{1, i, j});
        return true;
      }
    }
  }
  return false;
}

void initVisited() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      visited[i][j] = false;
    }
  }
}

int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> m;
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
    }
  }

  initVisited();

  int roomCount = 0;
  int maxWidth = 0;
  int width = 0;

  while (init()) {

    roomCount++;

    width = 0;

    while (!Q.empty()) {

      Unit now = Q.front();
      Q.pop();

      width++;
      int *info = intToBinary(board[now.i][now.j]);

      for (int i = 0; i < 4; i++) {
        if (info[i] == 0) {
          int nextI = now.i + dir[i][0];
          int nextJ = now.j + dir[i][1];
          if (!visited[nextI][nextJ] && nextI >= 0 && nextI < n && nextJ >= 0 && nextJ < m) {
            visited[nextI][nextJ] = true;
            rooms[nextI][nextJ] = Room{no};
            Q.push(Unit{now.depth + 1, nextI, nextJ});
          }
        }

      }
    }
    _width[no++] = width;
    maxWidth = max(maxWidth, width);

  }

  int result = 0;

  for(int i=0;i<n;i++){
    for(int j=0;j<m-1;j++){
      if(rooms[i][j].no != rooms[i][j+1].no){
        result = max(result, _width[rooms[i][j].no] + _width[rooms[i][j+1].no]);
      }
    }
  }

  for(int j=0;j<m;j++){
    for(int i=0;i<n-1;i++){
      if(rooms[i][j].no != rooms[i+1][j].no){
        result = max(result, _width[rooms[i][j].no] + _width[rooms[i+1][j].no]);
      }
    }
  }


  cout << roomCount << endl;
  cout << maxWidth << endl;
  cout << result;
  return 0;
}