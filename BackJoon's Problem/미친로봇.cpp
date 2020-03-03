#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

#define MAXN 1000000
using namespace std;
using P = pair<int, int>;
int N;

// 동 서 남 북
int Di[4] = {0, 0, 1, -1};
int Dj[4] = {1, -1, 0, 0};

double board[4];
bool visited[31][31];
int world[31][31];

float all = 0;
float re = 0;
vector<int> DIR;

// 총 백개의 디렉션;
double dfs(int i, int j, int depth) {


  if(depth == N ) return 1.0f;
  double ret = 0.0f;

  for (int d = 0; d <4; d++) {
    int ni = i + Di[d];
    int nj = j + Dj[d];
    if(visited[ni][nj]) continue;
    visited[ni][nj] = true;
    ret += board[d] * dfs(ni, nj, depth + 1);
    visited[ni][nj] = false;
  }
  return ret;
}

// 같은 장소를 오는것은 단순하지 않다. 재방문하면 단순하지 않다.
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  P S = {15, 15};

  for (int i = 0; i < 4; i++) {
    cin >> board[i];
    board[i] = board[i] / 100.0;
  }

  //cout << endl << DIR.size() << endl;
  memset(visited, false, sizeof(visited));
  visited[S.first][S.second] = true;
  cout.precision(10);
  cout << dfs(S.first, S.second, 0);

//  cout << all<<endl;
//  cout<<re<<endl;
  return 0;

}
