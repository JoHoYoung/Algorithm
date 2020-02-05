#include <iostream>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;
// '/' -> 위로가고있으면 왼쪽 아래로 가고있으면 오른쪽
// '\' -> 위로가고있으면 왼쪽 아래로 가고 있으면 오른쪽

// 위 아래 오른쪽 왼쪽
int dir[4][2] = {{-1, 0},
                 {1,  0},
                 {0,  1},
                 {0,  -1}};

struct Unit {
    int i;
    int j;
    int dir;
    int cnt;

};
struct Pos {
    int i;
    int j;
};

char board[51][51];
int visited[4][51][51];

vector<Pos> door;
int allMirrorNumber;
Pos start;
Pos dst;

int N;
queue<Unit> Q;

int result = 50;

int min(int a, int b) {
  if (a > b) {
    return b;
  }
  return a;
}

void simulate() {

  while (!Q.empty()) {
    Unit cur= Q.front();
    Q.pop();

    char pos = board[cur.i][cur.j];

    int nextI = cur.i + dir[cur.dir][0];
    int nextJ = cur.j + dir[cur.dir][1];

    if (nextI < N && nextI >= 0 && nextJ < N && nextJ >= 0 && board[nextI][nextJ] != '*' ) {
      if(visited[cur.dir][nextI][nextJ] > cur.cnt){
        visited[cur.dir][nextI][nextJ] = cur.cnt;
        Q.push(Unit{nextI, nextJ, cur.dir, cur.cnt});
      }
    }

    switch (cur.dir) {
      case 0 :
        if (pos == '!') {
          int nextdir[2] = {2,3};
          for(int i=0;i<2;i++){
            int nextI = cur.i + dir[nextdir[i]][0];
            int nextJ = cur.j + dir[nextdir[i]][1];
            if (nextI >= N || nextI < 0 || nextJ >= N || nextJ < 0 || board[nextI][nextJ] == '*') {
              continue;
            }
            if(visited[nextdir[i]][nextI][nextJ] > cur.cnt + 1){
              Q.push(Unit{nextI, nextJ, nextdir[i], cur.cnt + 1});
              visited[nextdir[i]][nextI][nextJ] = cur.cnt + 1;
            }
          }
        }
        break;
      case 1 :
        if (pos == '!') {
          int nextdir[2] = {2,3};
          for(int i=0;i<2;i++){
            int nextI = cur.i + dir[nextdir[i]][0];
            int nextJ = cur.j + dir[nextdir[i]][1];
            if (nextI >= N || nextI < 0 || nextJ >= N || nextJ < 0 || board[nextI][nextJ] == '*') {
              continue;
            }
            if(visited[nextdir[i]][nextI][nextJ] > cur.cnt + 1){
              Q.push(Unit{nextI, nextJ, nextdir[i], cur.cnt + 1});
              visited[nextdir[i]][nextI][nextJ] = cur.cnt + 1;
            }
          }

        }
        break;
      case 2 :
        if (pos == '!') {
          int nextdir[2] = {0,1};
          for(int i=0;i<2;i++){
            int nextI = cur.i + dir[nextdir[i]][0];
            int nextJ = cur.j + dir[nextdir[i]][1];
            if (nextI >= N || nextI < 0 || nextJ >= N || nextJ < 0 || board[nextI][nextJ] == '*') {
              continue;
            }
            if(visited[nextdir[i]][nextI][nextJ] > cur.cnt + 1){
              Q.push(Unit{nextI, nextJ, nextdir[i], cur.cnt + 1});
              visited[nextdir[i]][nextI][nextJ] = cur.cnt + 1;
            }
          }
        }
        break;
      case 3 :
        if (pos == '!') {
          int nextdir[2] = {0,1};
          for(int i=0;i<2;i++){
            int nextI = cur.i + dir[nextdir[i]][0];
            int nextJ = cur.j + dir[nextdir[i]][1];
            if (nextI >= N || nextI < 0 || nextJ >= N || nextJ < 0 || board[nextI][nextJ] == '*' ) {
              continue;
            }
            if(visited[nextdir[i]][nextI][nextJ] > cur.cnt + 1){
              Q.push(Unit{nextI, nextJ, nextdir[i], cur.cnt + 1});
              visited[nextdir[i]][nextI][nextJ] = cur.cnt + 1;
            }
          }
        }
        break;
    }
  }
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N;

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 51; j++) {
      for (int k = 0; k < 51; k++) {
        visited[i][j][k] = 100000;
      }
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      char a;
      cin >> a;
      if (a == '#') {
        door.push_back(Pos{i, j});
      }
      board[i][j] = a;
    }
  }

  start = door.at(0);
  dst = door.at(1);

  for (int i = 0; i < 4; i++) {
    Q.push(Unit{start.i, start.j, i, 0});
  }

  simulate();
    for(int i=0;i<4;i++){

    for(int j=0;j<N;j++){
      for(int k =0 ;k<N;k++){
        cout<<visited[i][j][k]<<" ";
      }
      cout<<endl;
    }
    cout<<endl<<endl;
  }
  cout << min(visited[3][dst.i][dst.j],min(visited[2][dst.i][dst.j],min(visited[1][dst.i][dst.j],visited[0][dst.i][dst.j])));

  return 0;
}