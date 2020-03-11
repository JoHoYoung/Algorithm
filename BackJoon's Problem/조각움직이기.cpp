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

int Di[4] = {-1, 0, 1, 0};
int Dj[4] = {0, 1, 0, -1};

char board[5][5];

vector<P> el;

int numOfBlock;
// 25개의 숫자로 좌표
// i : num / 5, j : num %4;
bool visited[25];
bool nBoard[5][5];

int nck = 0;
int nvisited[5][5];

void buildBoard(vector<int> arr) {
  nck = 0;
  memset(nvisited, false, sizeof(nvisited));
  memset(nBoard, false, sizeof(nBoard));
  for (int i = 0; i < arr.size(); i++) {
    int n = arr[i];
    nBoard[n / 5][n % 5] = true;
  }
}

void dfs(int i, int j) {
  nvisited[i][j] = true;
  nck++;
  for (int d = 0; d < 4; d++) {
    int ni = i + Di[d];
    int nj = j + Dj[d];
    if (ni < 0 || ni > 4 || nj < 0 || nj > 4 || nvisited[ni][nj] || !nBoard[ni][nj]) continue;
    dfs(ni, nj);
  }
}

vector<vector<int>> PERM;

int abs(int a) {
  if (a > 0) return a;
  return -a;
}
int min(int a,int b){
  if(a>b) return b;
  return a;
}

int getMvCnt(P a, P b) {
  return abs(a.first-b.first) + abs(a.second - b.second);
}


int getDst(vector<int> arr) {
  int re = INF;
  for (int i = 0; i < PERM.size(); i++) {
    int tmp = 0;
    for (int j = 0; j < PERM[i].size(); j++) {
      P A = el[j];
      int b = PERM[i][j];
      P B = {arr[b]/5, arr[b]%5};
      tmp += getMvCnt(A,B);
    }
    re = min(re, tmp);
  }
 return re;
}

void perm(int N, int n, int depth, vector<int> arr) {

  if (depth == n) {
    PERM.push_back(arr);
    return;
  }

  for (int i = 0; i < N; i++) {
    if (visited[i]) continue;
    vector<int> a;
    visited[i] = true;
    a.assign(arr.begin(), arr.end());
    a.push_back(i);
    perm(N, n, depth + 1, a);
    visited[i] = false;
  }
}

int ans = INF;
void comb(int N, int n, int idx, int depth, vector<int> &arr) {

  if (depth == n) {
    buildBoard(arr);
    // 다 이어져있는지 검사
    dfs(arr[0] / 5, arr[0] % 5);
    if (nck != numOfBlock) return;

    ans = min(ans, getDst(arr));
  }

  for (int i = idx; i < N; i++) {
    if (visited[i]) continue;
    arr.push_back(i);
    visited[i] = true;
    comb(N, n, i + 1, depth + 1, arr);
    visited[i] = false;
    arr.pop_back();
  }

}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> board[i][j];
      if (board[i][j] == '*') el.push_back({i, j});
    }
  }

  memset(visited, false, sizeof(visited));
  numOfBlock = el.size();
  vector<int> a;

  perm(numOfBlock, numOfBlock, 0, a);
  comb(25,numOfBlock,0,0,a);

  cout<<ans;
  return 0;
}