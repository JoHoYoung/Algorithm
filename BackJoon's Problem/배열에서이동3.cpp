#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>

#define MAXN 31
#define INF 987654321
#define MAX 1000000

using namespace std;
using ll = long long;
using P = pair<int, int>;

int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};

int N;
int board[101][101];

vector<int> el;

int min(int a, int b) {
  return a > b ? b : a;
}

bool visited[101][101];

void BFS(int l, int h) {
  if (board[0][0] < l || board[0][0] > h) return;
  visited[0][0] = true;
  queue<P> Q;
  Q.push({0, 0});
  while (!Q.empty()) {
    P cur = Q.front();
    Q.pop();

    for (int d = 0; d < 4; d++) {
      int ni = cur.first + Di[d];
      int nj = cur.second + Dj[d];
      if (ni < 0 || ni > N - 1 || nj < 0 || nj > N - 1 || visited[ni][nj] || board[ni][nj] < l ||
          board[ni][nj] > h)
        continue;
      visited[ni][nj] = true;
      Q.push({ni, nj});
    }
  }
}

int ans = INF;

set<int> s;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
      el.push_back(board[i][j]);
      s.insert(board[i][j]);
    }
  }
  auto l = s.begin();
  auto r = s.begin();
  while(r != s.end()){
    while(l != s.end()){

      memset(visited, false, sizeof(visited));
      BFS(*l, *r);
      if(visited[N-1][N-1]){
        ans = min((*r - *l),ans);
        l++;
      }else{
        break;
      }
    }
    r++;
  }

  cout << ans;
  return 0;
}

