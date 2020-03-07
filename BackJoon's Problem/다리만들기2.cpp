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

int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};

int N, M;
int board[11][11];
bool visited[11][11];

int dst[7][7];

vector<P> nonZero;
int continentIdx = 1;

int p[12];

int goUp(P s, int dst) {
  int curi = s.first;??
  int curj = s.second;
  int cnt = -1;
  while (1) {
    curi -= 1;
    cnt++;
    if (curi < 0 || curi > N - 1) return INF;
    if (board[curi][curj] == board[s.first][s.second]|| (board[curi][curj] != 0 &&board[curi][curj] != dst)) return INF;
    if (board[curi][curj] == dst) return cnt;
  }
}

int goDown(P s, int dst) {

  int curi = s.first;
  int curj = s.second;
  int cnt = -1;
  while (1) {
//    if(s.first == 0 && s.second == 2 && dst == 5){
//      cout<<curi<<" "<<curj<<endl;
//    }
    curi += 1;
    cnt++;
    if (curi < 0 || curi > N - 1) return INF;
    if (board[curi][curj] == board[s.first][s.second] || (board[curi][curj] != 0 &&board[curi][curj] != dst)) return INF;
    if (board[curi][curj] == dst) return cnt;
  }
}

int goLeft(P s, int dst) {
  int curi = s.first;
  int curj = s.second;
  int cnt = -1;
  while (1) {
    curj -= 1;
    cnt++;
    if (curj < 0 || curj > M - 1) return INF;
    if (board[curi][curj] == board[s.first][s.second]|| (board[curi][curj] != 0 &&board[curi][curj] != dst)) return INF;
    if (board[curi][curj] == dst) return cnt;
  }
}

int goRight(P s, int dst) {
  int curi = s.first;
  int curj = s.second;
  int cnt = -1;
  while (1) {
    curj += 1;
    cnt++;
    if (curj < 0 || curj > M - 1) return INF;
    if (board[curi][curj] == board[s.first][s.second] || (board[curi][curj] != 0 &&board[curi][curj] != dst)) return INF;
    if (board[curi][curj] == dst) return cnt;
  }
}


void getDst(int from, int to) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] == from) {
        P startDex = {i, j};
    //    cout<<"FROM "<<from<<" "<<"TO "<<to<<endl;
    //    cout<<"SEARCH AT "<<i<<" "<<j<<endl;
        int up = goUp(startDex, to);
        int down = goDown(startDex, to);
        int left = goLeft(startDex, to);
        int right = goRight(startDex, to);

       // cout<<"DOWN : "<<down<<endl;
        up = up == 1 ? INF : up;
        down = down == 1 ? INF : down;
        left = left == 1 ? INF : left;
        right = right == 1 ? INF : right;


        dst[from][to] = min(up, min(down, min(left, min(right, dst[from][to]))));
        dst[to][from] = dst[from][to];
      }
    }
  }
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

typedef struct eg {
    int start, end, cost;
};

vector<eg> edges;

bool cmp(eg a, eg b) {
  return a.cost < b.cost;
}

int find(int idx) {
  while (p[idx] != idx) idx = p[idx];
  return idx;
}

void Union(int a, int b) {
  a = find(a);
  b = find(b);
  if (a > b) p[a] = b;
  else p[b] = a;
}

vector<eg> MST;

bool kruskal() {
  for (int i = 1; i < continentIdx; i++) {
    p[i] = i;
  }
  int cnt = 0;
  for (int i = 0; i < edges.size(); i++) {
    eg e = edges[i];
    if (find(e.start) == find(e.end) || e.cost == 1) continue;
    Union(e.start, e.end);
    //  cout<<"ADD "<<e.start<<" "<<e.end<<" "<<e.cost<<endl;
    MST.push_back(e);
    cnt++;
  }
  return MST.size() == continentIdx - 2;
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

  memset(visited, false, sizeof(visited));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] != 0 && !visited[i][j]) {
        BFS({i, j});
        continentIdx++;
      }
    }
  }


  for (int i = 1; i < continentIdx; i++) {
    for (int j = 1; j < continentIdx; j++) {
      dst[i][j] = INF;
    }
  }
//  cout
  for (int i = 1; i < continentIdx; i++) {
    for (int j = i + 1; j < continentIdx; j++) {
      getDst(i, j);
    }
  }

  for (int i = 1; i < continentIdx; i++) {
    for (int j = i + 1; j < continentIdx; j++) {
      if (dst[i][j] != INF) edges.push_back({i, j, dst[i][j]});
    }
  }

  sort(edges.begin(), edges.end(), cmp);

  if (!kruskal()) {
    cout << -1;
  } else {
    int cnf = 0;
    for (int i = 0; i < MST.size(); i++) {
      cnf += MST[i].cost;
    }
    cout << cnf;
  }
return 0;
}