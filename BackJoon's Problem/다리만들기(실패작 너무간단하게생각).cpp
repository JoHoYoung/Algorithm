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

// �� ��� �Ʒ� ����
// 0, 1, 2 ,3
int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};

int N, M;

int board[11][11];

// ���� �� 100������
// ���δٸ� : 200
// ���δٸ� : 200;

// ������ �ٴٴ� X,
// �ٸ��� ���ο� ����
// �ٸ����̴� ������ 1�̻�

const int VERTICAL = 200;
const int HORIZON = 100;

bool visited[11][11];
bool bridgeVisited[2][11][11];
set<int> all;
int continentIdx = 1;

int mindst[100][100];
int travelBoard[2][11][11];
int travelDepth[2][11][11];

// ��� ���� �� ����ƴ���, Ư���ٸ��� �ϳ� ����� ���� �˻�
typedef struct travel {
    int i, j, dir;
};

vector<P> nonZero;
// ���ηθ� �� ���ų� ���ηθ� �� ������


// ���ϳ��� �̾ �� ����.

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
      // ����, �Ǵ� ���ηθ� �������ε�
      if (now.dir != -1 && d % 2 != now.dir) continue;
      int ni = now.i + Di[d];
      int nj = now.j + Dj[d];
      // out of index
      if (ni < 0 || ni > N - 1 || nj < 0 || nj > M - 1) continue;
      // ���� ��ΰ� ����� ���
      if (board[ni][nj] != 0) {
       // cout<<"HELLO"<<endl;
        if (visited[ni][nj]) continue;
        visited[ni][nj] = true;
        all.insert(board[ni][nj]);
        Q.push({ni, nj, -1});
        continue;
        // ������ΰ� �ٴ��ϰ��
      } else {
        // ���� ������� ����ϴ� ���
        if (now.dir == -1) {
          if (travelBoard[0][ni][nj] && !bridgeVisited[0][ni][nj]) {
            bridgeVisited[0][ni][nj] = true;
            Q.push({ni, nj, 0});
          }
          if (travelBoard[1][ni][nj] && !bridgeVisited[1][ni][nj]){
            bridgeVisited[1][ni][nj] = true;
            Q.push({ni, nj, 1});
          }
          // ���� �ٸ����� ����ϴ� ���
        } else {
          // �̹� ������ �ٸ��� ���
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


//0�� ����, 1�� ����
int min(int a, int b) {
  if (a > b) return b;
  return a;
}

typedef struct unit {
    int i, j, continent, dir, depth;
};
queue<unit> Q;
// �ٸ������� �̾����� �Ѵ�.

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
      // �ڱⰡ �̹� �湮�� ���� ���� ����, �ٴٰ� �ƴ� ������δ� ���� ����
      if (travelBoard[cur.dir][ni][nj] == cur.continent || board[ni][nj] != 0) continue;
      // ���� ��������, �ڱⰡ �湮�Ѱ��� �ƴϰ�, �ٸ��� ������
      // �ٸ��� �ִµ�, �� �ٸ���
      if (travelBoard[cur.dir][ni][nj] != 0) {
        // 1ĭ�� �ٸ��� ���� ����
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
        // �ٸ��� �����Ѵ�.
        // �� �ٸ��� ���������� ��� �湮�� �����ϸ� ������.
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