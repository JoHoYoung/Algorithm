#include <iostream>
#include<vector>
#include<deque>
#include <utility>
#include<cstring>
#include<queue>
using namespace std;

struct Pos {
    int i;
    int j;
    int num;
};

queue<Pos> Aqueue;
queue<Pos> seqStones;

int map[23][23];
bool visited[23][23];

int N, M;

pair<bool, int> bfs() {
  int cnt = 0;
  bool flag = true;
  while (!seqStones.empty()) {
    Pos next = seqStones.front();
//    if(next.i > N+1 || next.i < 0 || next.j > M+1 || next.j < 0){
//      continue;
//    }
    seqStones.pop();

    cnt++;

    if (next.i + 1 <= N + 1) {
      if (map[next.i + 1][next.j] == 2 && !visited[next.i + 1][next.j]) {
        visited[next.i + 1][next.j] = true;
        seqStones.push(Pos{next.i + 1, next.j, 0});
      } else if (map[next.i + 1][next.j] == 0) {
        flag = false;
      }
    }

    if (next.i - 1 >= 0) {
      if (map[next.i - 1][next.j] == 2 && !visited[next.i - 1][next.j]) {
        visited[next.i - 1][next.j] = true;
        seqStones.push(Pos{next.i - 1, next.j, 0});
      } else if (map[next.i - 1][next.j] == 0) {
        flag = false;
      }
    }

    if (next.j - 1 >= 0) {
      if (map[next.i][next.j - 1] == 2 && !visited[next.i][next.j - 1]) {
        visited[next.i][next.j - 1] = true;
        seqStones.push(Pos{next.i, next.j - 1, 0});
      } else if (map[next.i][next.j - 1] == 0) {
        flag = false;
      }
    }

    if (next.j + 1 <= M + 1) {
      if (map[next.i][next.j + 1] == 2 && !visited[next.i][next.j + 1]) {
        visited[next.i][next.j + 1] = true;
        seqStones.push(Pos{next.i, next.j + 1, 0});
      } else if (map[next.i][next.j + 1] == 0) {
        flag = false;
      }
    }
  }
  return make_pair(cnt, flag);
}

int result = 0;

int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

void innerStons() {
  int cc = 0;
  for (int i = 0; i < N + 2; i++) {
    for (int j = 0; j < M + 2; j++) {
      memset(visited, false, sizeof(visited));
      if (map[i][j] == 2 && !visited[i][j]) {
//        seqStones.clear();
        seqStones.push(Pos{i, j, 0});
        visited[i][j]=true;
        auto temp = bfs();
        //   cout<<temp.first<<" "<<temp.second<<" "<<endl;
        if (temp.second) {
          cc += temp.first;
        }
      }
    }
  }
  result = max(result, cc);
}

int main() {

  cin >> N;
  cin >> M;

  for (int i = 0; i < M + 2; i++) {
    map[0][i] = 1;
    map[N + 1][i] = 1;
  }

  for (int i = 0; i < N + 2; i++) {
    map[i][0] = 1;
    map[i][M + 1] = 1;
  }

  for (int i = 1; i < N + 1; i++) {
    for (int j = 1; j < M + 1; j++) {
      cin >> map[i][j];
    }
  }

  for (int i = 1; i < N + 1; i++) {
    for (int j = 1; j < M + 1; j++) {
      if (map[i][j] == 0) {
        if(map[i][j+1] == 2 ||map[i][j-1] == 2 ||map[i-1][j] == 2 ||map[i+1][j] == 2 )
        Aqueue.push(Pos{i, j, 1});
      }
    }
  }

  while (!Aqueue.empty()) {
    Pos next = Aqueue.front();
    Aqueue.pop();

    map[next.i][next.j] = 1;

    for (int i = next.i; i < N + 1; i++) {
      for (int j = 1; j < M + 1; j++) {
        if(i==next.i && j<=next.j) continue;
        if (i == next.i && j == next.j) {
          continue;
        }
        if (map[i][j] == 0) {
          map[i][j] = 1;
          innerStons();
          map[i][j] = 0;
        }
      }
    }
    map[next.i][next.j] = 0;
  }
  cout << result;
  return 0;
}