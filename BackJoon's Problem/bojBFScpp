#include <iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int input[5][5][5];
int maze[5][5][5];
int Plane[5][5][5];

bool visited[5][5][5];

// 상하좌우, 위 아래
int dir[6][3] = {{0,  -1, 0},
                 {0,  1,  0},
                 {0,  0,  1},
                 {0,  0,  -1},
                 {1,  0,  0},
                 {-1, 0,  0}};
struct Pos {
    int k;
    int i;
    int j;
    int move;
    int mode;
};

queue<Pos> Q;

int Min(int a, int b) {
  if (a == 0) {
    return b;
  }
  if (b == 0) {
    return a;
  }
  if (a > b) {
    return b;
  }
  return a;
}

// Start Point : 0,0,0
// End Point : 4,4,4
int result = 0;

void bfs() {
  while (!Q.empty()) {
    auto Next = Q.front();
    Q.pop();

    if (Next.k == 4 && Next.i == 4 && Next.j == 4 && maze[Next.k][Next.i][Next.j] == 1) {
      //cout<<"Result : "<<result<<"Next : "<<Next.move+1<<endl;
      result = Min(result, Next.move + 1);

      while (!Q.empty()) {
        Q.pop();
      }
      return;
    }

    for (int i = 0; i < 6; i++) {
      int nextK = Next.k + dir[i][0];
      int nextI = Next.i + dir[i][1];
      int nextJ = Next.j + dir[i][2];

      if (nextK < 0 || nextK > 4 || nextI < 0 || nextI > 4 || nextJ < 0 || nextJ > 4) {
        continue;
      }
      if (visited[nextK][nextI][nextJ]) continue;
      if (maze[nextK][nextI][nextJ] == 0) continue;

      if (maze[nextK][nextI][nextJ] == 1) {
        visited[nextK][nextI][nextJ] = true;
        Q.push(Pos{nextK, nextI, nextJ, Next.move + 1, Next.mode});
      }
    }
  }
}

void setPlane(int depth, int mode) {
  //cout<<"Depth : "<<depth<<" Mode: "<<mode<<endl;
  switch (mode) {
    case 0:
      for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
          Plane[depth][i][j] = input[depth][4 - j][i];
        }
      }
      break;
    case 1:
      for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
          Plane[depth][i][j] = input[depth][4 - i][4 - j];
        }
      }
      break;
    case 2:
      for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
          Plane[depth][i][j] = input[depth][j][4 - i];
        }
      }
      break;
    case 3:
      for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
          Plane[depth][i][j] = input[depth][i][j];
        }
      }
      break;
  }
}

void BuildMazeBfs() {
  vector<int> v(5);
  for (int i = 0; i < 5; i++) {
    v[i] = i;
  }
  do {
    memset(visited[0], false, sizeof(visited[0]));
    memset(visited[1], false, sizeof(visited[1]));
    memset(visited[2], false, sizeof(visited[2]));
    memset(visited[3], false, sizeof(visited[3]));
    memset(visited[4], false, sizeof(visited[4]));
    visited[0][0][0] = true;


    for(int k=0;k<5;k++){
      for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
          maze[v[k]][i][j] = Plane[k][i][j];
        }
      }
    }
    if(maze[0][0][0] == 1){
      Q.push(Pos{0, 0, 0, 0, 0});
      bfs();
    }
  } while (next_permutation(v.begin(), v.end()));

}

void dfs(int depth) {
  if (depth == 5) {
    BuildMazeBfs();
  } else {
    for (int i = 0; i < 4; i++) {
      setPlane(depth, i);
      dfs(depth + 1);
    }
  }
}


int main() {

  for (int k = 0; k < 5; k++) {
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        cin >> input[k][i][j];
      }
    }
  }

  dfs(0);
  cout << result-1;
  return 0;
}