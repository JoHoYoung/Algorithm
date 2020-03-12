#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 987654321;

int t, h, w;

char board[100][100];
bool visited[100][100];

vector<P> doorPos[27];
vector<P> suspend[27];

queue<P> Q;

int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};


void getKey(char key) {

  vector<P> doors = doorPos[key - 'a'];
  for (int i = 0; i < doors.size(); i++) {
    board[doors[i].first][doors[i].second] = '.';
  }

  vector<P> suspended = suspend[key - 'a'];
  for (int i = 0; i < suspended.size(); i++) {

    visited[suspended[i].first][suspended[i].second] = true;
    board[suspended[i].first][suspended[i].second] = '.';
    Q.push({suspended[i]});

  }
  suspend[key - 'a'].clear();
}


int ans = 0;

bool enQside() {
  bool cont = false;
  for (int i = 0; i < h; i++) {
    if (!visited[i][0]) {
      if (board[i][0] == '.') {
        visited[i][0] = true;
        cont = true;
        Q.push({i, 0});
      } else if (board[i][0] == '$') {
        ans++;
        board[i][0] = '.';
        visited[i][0] = true;
        cont = true;
        Q.push({i, 0});
      } else if (board[i][0] >= 'a' && board[i][0] <= 'z') {
        getKey(board[i][0]);
        board[i][0] = '.';
        visited[i][0] = true;
        cont = true;
        Q.push({i, 0});
      } else if(board[i][0]>='A' && board[i][0] <= 'A'){
        suspend[board[i][0] - 'A'].push_back({i,0});
      }
    }

    if (!visited[i][w - 1]) {
      if (board[i][w - 1] == '.') {
        visited[i][w - 1] = true;
        cont = true;
        Q.push({i, w - 1});
      } else if (board[i][w - 1] == '$') {
        ans++;
        board[i][w - 1] = '.';
        visited[i][w - 1] = true;
        cont = true;
        Q.push({i, w - 1});
      } else if (board[i][w - 1] >= 'a' && board[i][w - 1] <= 'z') {
        getKey(board[i][w - 1]);
        board[i][w - 1] = '.';
        visited[i][w - 1] = true;
        cont = true;
        Q.push({i, w - 1});
      } else if(board[i][w-1]>='A' && board[i][w-1] <= 'A'){
        suspend[board[i][w-1] - 'A'].push_back({i,w-1});
      }
    }
  }

  for (int j = 0; j < w; j++) {
    if (!visited[0][j]) {
      if (board[0][j] == '.') {
        Q.push({0, j});
        cont = true;
        visited[0][j] = true;
        Q.push({0, j});
      } else if (board[0][j] == '$') {
        ans++;
        board[0][j] = '.';
        visited[0][j] = true;
        cont = true;
        Q.push({0, j});
      } else if (board[0][j] >= 'a' && board[0][j] <= 'z') {
     //   cout<<"HERE"<<endl;
        getKey(board[0][j] );
        board[0][j] = '.';
        visited[0][j] = true;
        cont = true;
        Q.push({0, j});
      }else if(board[0][j]>='A' && board[0][j] <= 'A'){
        suspend[board[0][j] - 'A'].push_back({0,j});
      }
    }
    if (!visited[h - 1][j]) {
      if (board[h - 1][j] == '.') {
        visited[h - 1][j] = true;
        cont = true;
        Q.push({h - 1, j});
      } else if (board[h-1][j] == '$') {
        ans++;
        board[h-1][j] = '.';
        visited[h-1][j] = true;
        cont = true;
        Q.push({h-1, j});
      } else if (board[h-1][j] >= 'a' && board[h-1][j] <= 'z') {
        getKey(board[h-1][j]);
        board[h-1][j] = '.';
        visited[h-1][j] = true;
        cont = true;
        Q.push({h-1, j});
      } else if(board[h-1][j]>='A' && board[h-1][j] <= 'A'){
        suspend[board[h-1][j] - 'A'].push_back({h-1,j});
      }
    }
  }
  return cont;
}

void BFS() {
  while (!Q.empty()) {
    P cur = Q.front();
    int curI = cur.first;
    int curJ = cur.second;
  //  cout<<curI<<" "<<curJ<<endl;
    Q.pop();
    for (int d = 0; d < 4; d++) {
      int ni = curI + Di[d];
      int nj = curJ + Dj[d];
      if (ni < 0 || ni > h - 1 || nj < 0 || nj > w - 1 || visited[ni][nj] || board[ni][nj] == '*') continue;
      // 문을 만났을 경우
      if (board[ni][nj] >= 'A' && board[ni][nj] <= 'Z') {
        suspend[board[ni][nj] - 'A'].push_back({ni, nj});
        continue;
      }
      //열쇠를 만났을경우
      if (board[ni][nj] >= 'a' && board[ni][nj] <= 'z') {
        getKey(board[ni][nj]);
        visited[ni][nj] = true;
        board[ni][nj] = '.';
        Q.push({ni, nj});
        continue;
      }
      // 문서를 만났을경우
      if (board[ni][nj] == '$') {
        board[ni][nj] = '.';
        ans++;
      }
      // 문서도, 문도, 열쇠도 벽도 아닐경우
      visited[ni][nj] = true;
      Q.push({ni, nj});
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> h >> w;
    string keys;
    ans = 0;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < 27; i++) {
      doorPos[i].clear();
      suspend[i].clear();
    }

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> board[i][j];
        if (board[i][j] >= 'A' && board[i][j] <= 'Z') {
          doorPos[board[i][j] - 'A'].push_back({i, j});
        }
      }
    }
    cin >> keys;
   if (keys == "0") keys = "";
    for (int i = 0; i < keys.size(); i++) {
      getKey(keys[i]);
    }
   // cout<<"HERE>?";
    while (enQside()) {
    //  cout<<"??"<<endl;
      BFS();
    }
    cout << ans<<'\n';
  }

  return 0;
}