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

int N, M, H;

bool board[12][32];
vector<vector<int>> COMB;
vector<P> pos;

bool visited[300];

int min(int a, int b){
  if(a>b) return b;
  return a;
}

bool canAddHere(int i, int j) {

  bool left;
  bool right;

  if (i == 1) left = true;
  else left = !board[i - 1][j];

  if (i == N - 1) right = true;
  else right = !board[i + 1][j];

  return left && right;
}

void comb(int N, int n, int depth, int idx, vector<int> arr) {
  if (depth == n) {
    COMB.push_back(arr);
    return;
  }

  for (int i = idx; i < N; i++) {
    if (visited[i]) continue;
    vector<int> a;
    visited[i] = true;
    a.assign(arr.begin(), arr.end());
    a.push_back(i);
    comb(N, n, depth + 1, i + 1, a);
    visited[i] = false;
  }
}

bool posHasLineAt(int i, int j) {
  if (i <= 0 || i >= N) return false;
  return board[i][j];
}

bool travel(int startI, int startJ) {
  int curI = startI;
  int curJ = startJ;

  while (1) {
    if (curJ > H) break;
    bool leftHasLine = posHasLineAt(curI - 1, curJ);
    bool rightHasLine = posHasLineAt(curI, curJ);
    if (leftHasLine) {
      curI--;
      curJ++;
      continue;
    }else if (rightHasLine) {
      curI++;
      curJ++;
      continue;
    }else{
      curJ++;
    }
  }
  return startI == curI;
}

bool setLadder(vector<int> arr){
  for (int i = 0; i < arr.size(); i++) {
    P cur = pos[arr[i]];
    if (!canAddHere(cur.first, cur.second)) return false;
    board[cur.first][cur.second] = true;
  }
  return true;
}

void destroyLadder(vector<int> arr){
  for (int i = 0; i < arr.size(); i++) {
    P cur = pos[arr[i]];
    board[cur.first][cur.second] = false;
  }
}

int result = INF;
int main(void) {

  ios_base::sync_with_stdio(0);
  cin.tie(0); //cin 실행속도 향상
  cin >> N >> M >> H;

  memset(board, false, sizeof(board));
  for (int i = 0; i < M; i++) {
    int a, b;
    cin>>a>>b;
    board[b][a] = true;
  }

  for (int i = 1; i <= N-1; i++) {
    for (int j = 1; j <= H; j++) {
      if (!board[i][j]) pos.push_back({i, j});
    }
  }

  vector<int> a;
  COMB.push_back(a);
  for (int i = 1; i <= 3; i++) {
    memset(visited, false, sizeof(visited));
    vector<int> a;
    comb(pos.size(), i, 0, 0, a);
  }

  for (int i = 0; i < COMB.size(); i++) {
    bool isFind = true;
    if(result < COMB.size()) break;
    if(!setLadder(COMB[i])) {
      destroyLadder(COMB[i]);
      continue;
    }
    for (int i = 1; i <= N; i++) {
      if (!travel(i, 1)){
        isFind = false;
        break;
      }
    }
    destroyLadder(COMB[i]);
    if(!isFind) continue;
    result = min(result, COMB[i].size());
  }

  if(result != INF) cout<<result;
  else cout<<-1;

  return 0;

}