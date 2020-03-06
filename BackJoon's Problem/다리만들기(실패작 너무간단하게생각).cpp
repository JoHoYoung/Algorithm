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

// 위 어른쪽 아래 왼쪽
// 0, 1, 2 ,3
int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};

int N, M;

int board[11][11];

// 점은 총 100개정도
// 가로다리 : 200
// 세로다리 : 200;

// 인접한 바다는 X,
// 다리는 세로와 가로
// 다리길이는 무조건 1이상

const int VERTICAL = 200;
const int HORIZON = 100;

bool visited[11][11];
bool bridgeVisited[2][11][11];
set<int> all;
int continentIdx = 1;

int mindst[100][100];
int travelBoard[2][11][11];
int travelDepth[2][11][11];

// 모든 섬이 다 연결됐는지, 특정다리가 하나 생기는 순간 검사
typedef struct travel {
    int i, j, dir;
};

vector<P> nonZero;
// 세로로만 쭉 가거나 가로로만 쭉 가야함


// 점하나만 이어서 다 돌림.

bool isAllconnected() {
  memset(visited, false, sizeof(visited));
  memset(bridgeVisited, false, sizeof(bridgeVisited));
  queue<travel> Q;
  P s = nonZero[0];
  Q.push({s.first, s.second, -1});
  //cout<<s.first<<" "<<s.second<<endl;
  visited[s.first][s.second] = true;

  while (!Q.empty()) {
    travel now = Q.front();
    Q.pop();
    for (int d = 0; d < 4; d++) {
      // 가로, 또는 세로로만 가는중인데
      if (now.dir != -1 && d % 2 != now.dir) continue;
      int ni = now.i + Di[d];
      int nj = now.j + Dj[d];
      // out of index
      if (ni < 0 || ni > N - 1 || nj < 0 || nj > M - 1) continue;
      // 다음 경로가 대륙인 경우
      if (board[ni][nj] != 0) {
       // cout<<"HELLO"<<endl;
        if (visited[ni][nj]) continue;
        visited[ni][nj] = true;
        all.insert(board[ni][nj]);
        Q.push({ni, nj, -1});
        continue;
        // 다음경로가 바다일경우
      } else {
        // 지금 대륙에서 출발하는 경우
        if (now.dir == -1) {
          if (travelBoard[0][ni][nj] && !bridgeVisited[0][ni][nj]) {
            bridgeVisited[0][ni][nj] = true;
            Q.push({ni, nj, 0});
          }
          if (travelBoard[1][ni][nj] && !bridgeVisited[1][ni][nj]){
            bridgeVisited[1][ni][nj] = true;
            Q.push({ni, nj, 1});
          }
          // 지금 다리에서 출발하는 경우
        } else {
          // 이미 지나온 다리일 경우
          if (!travelBoard[now.dir][ni][ni] || bridgeVisited[now.dir][ni][nj]) continue;
          bridgeVisited[now.dir][ni][nj] = true;
          Q.push({ni, nj, now.dir});
        }
      }
    }
  }
  cout<<all.size()<<endl;
  return all.size() == continentIdx - 1;
}

void BFS(P start) {
  queue<P> Q;
  Q.push(start);
  visited[start.first][start.second] = true;

  while (!Q.empty()) {
    P now = Q.front();
    Q.pop();
    board[now.first][now.second] = continentIdx;
    for (int d = 0; d < 4; d++) {
      int ni = now.first + Di[d];
      int nj = now.second + Dj[d];
      if (ni < 0 || ni > N - 1 || nj < 0 || nj > M - 1 || visited[ni][nj] || board[ni][nj] != 1) continue;
      visited[ni][nj] = true;
      Q.push({ni, nj});
    }
  }
}

void print(int arr[][11]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}


//0을 세로, 1을 가로
int min(int a, int b) {
  if (a > b) return b;
  return a;
}

typedef struct unit {
    int i, j, continent, dir, depth;
};
queue<unit> Q;
// 다리끼리만 이어져야 한다.

bool travel() {
  for (int i = 0; i < nonZero.size(); i++) {
    P p = nonZero[i];
    Q.push({p.first, p.second, board[p.first][p.second], 0, 1});
    Q.push({p.first, p.second, board[p.first][p.second], 1, 1});
  }
 // cout<<Q.size()<<endl;
  while (!Q.empty()) {
    unit cur = Q.front();
    Q.pop();
    //cout<<cur.depth<<endl;
    for (int d = 0; d < 4; d++) {
      if (d % 2 != cur.dir) continue;
      int ni = cur.i + Di[d];
      int nj = cur.j + Dj[d];
      // outOFIndex
      if (ni < 0 || ni > N - 1 || nj < 0 || nj > M - 1) continue;
      // 자기가 이미 방문한 곳은 가지 않음, 바다가 아닌 대륙으로는 가지 않음
      if (travelBoard[cur.dir][ni][nj] == cur.continent || board[ni][nj] != 0) continue;
      // 다음 포지션이, 자기가 방문한것이 아니고, 다리가 있으면
      // 다리가 있는데, 그 다리는
      if (travelBoard[cur.dir][ni][nj] != 0) {
        // 1칸인 다리면 잇지 않음
        if(travelDepth[cur.dir][ni][nj] == 1 && cur.depth == 1) continue;
       // cout<<"FIND"<<endl;
       if(mindst[cur.continent][travelBoard[cur.dir][ni][nj]] == 0){
         cout<<"SET "<<cur.continent<<" "<<travelBoard[cur.dir][ni][nj]<<" to "<< travelDepth[cur.dir][ni][nj] + cur.depth+1<<endl;
         mindst[cur.continent][travelBoard[cur.dir][ni][nj]] = travelDepth[cur.dir][ni][nj] + cur.depth;
       }else{
         mindst[cur.continent][travelBoard[cur.dir][ni][nj]] = min(mindst[cur.continent][travelBoard[cur.dir][ni][nj]],
                                                                   travelDepth[cur.dir][ni][nj] + cur.depth);
       }

        mindst[travelBoard[cur.dir][ni][nj]][cur.continent] = mindst[cur.continent][travelBoard[cur.dir][ni][nj]];
        // 다리를 연결한다.
        // 이 다리를 연결했을때 모두 방문이 가능하면 끝내자.
        if (isAllconnected()) return true;
        continue;
      }
    //  cout<<"ELSE "<<cur.dir<<" "<<ni<<" "<<nj<<endl;
      travelBoard[cur.dir][ni][nj] = cur.continent;
      travelDepth[cur.dir][ni][nj] = cur.depth;
      Q.push({ni, nj, cur.continent, cur.dir, cur.depth + 1});
    }
  }
  return false;
}

int countAllBridge() {
  int cnt = 0;
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      cnt += mindst[i][j];
    }
  }
  return cnt;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
      if (board[i][j] != 0) nonZero.push_back({i, j});
    }
  }

  for(int i=0;i<100;i++) {
    for (int j = 0; j < 100; j++) {
      mindst[i][j] = 0;
    }
  }



  memset(visited, false, sizeof(visited));
  memset(travelBoard, false, sizeof(travelBoard));
  memset(travelDepth, false, sizeof(travelDepth));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] != 0 && !visited[i][j]) {
        BFS({i, j});
        continentIdx++;
      }
    }
  }

  if (!travel()) cout << -1<<endl;
  else cout << countAllBridge()<<endl;
  for(int i=1;i<5;i++) {
    for (int j = 1; j < 5; j++) {
      cout<< mindst[i][j] <<" ";
    }
    cout<<endl;
  }
  cout<<endl;
  print(travelDepth[0]);
  cout<<endl;
  print(travelDepth[1]);
  cout<<endl;
  print(travelBoard[0]);
  cout<<endl;
  print(travelBoard[1]);
  cout<<endl;
  //print(board);
  return 0;
}