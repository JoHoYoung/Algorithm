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
int W, H;
char board[100][100];
bool visited[100][100];
// 방향이 달라지면 거울 +1;
// 반대방향은 불가능
int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};
P S, E;

int re = INF;

int min(int a, int b) {
  if (a > b) return b;
  return a;
}
void print(){
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cout<<visited[i][j]<<" ";
    }
    cout<<endl;
  }
}
void dfs(int i, int j, int upperD, int numberOfMirror) {

  if(re<numberOfMirror) return;
  if (i == E.first && j == E.second) {
    re = min(re, numberOfMirror);
    return;
  }
  visited[i][j] = true;
  for (int d = 0; d < 4; d++) {
    int ni = i + Di[d];
    int nj = j + Dj[d];
    if (ni < 0 || ni > H - 1 || nj < 0 || nj > W - 1 || visited[ni][nj] || board[ni][nj] == '*') continue;
    if (d == upperD || upperD ==-1) dfs(ni, nj, d, numberOfMirror);
    else dfs(ni, nj, d, numberOfMirror + 1);
  }
  visited[i][j] = false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> W >> H;
  vector<P> el;
  memset(visited, false, sizeof(visited));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'C') el.push_back({i, j});
    }
  }
  S = el[0];
  E = el[1];

  dfs(S.first, S.second, -1, 0);

  cout << re;
  return 0;
}