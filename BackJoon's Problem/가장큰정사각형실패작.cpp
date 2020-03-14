#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

#define INF 987654321

using namespace std;
using ll = long long;
using P = pair<int, int>;

int N, M;
bool board[1001][1001];
// 정사각형 판단 : 왼쪽 아래
// 특정.. N개 특정 정 사각형이 갖고있는게..
// 아래, 위 점검
// 맨마지막 끝점 점검

//특정 정사각형의 왼쪽 위점이 시작이고, 그가 가지고 있는 정사각형 크기
int DP[1001][1001];

int abs(int a) {
  if (a > 0) return a;
  return -a;
}

int max(int a, int b) {
  if (a > b) return a;
  return b;
}

int min(int a, int b) {
  if (a > b) return b;
  return a;
}

int thisPointHasN(int i, int j) {

  if (i == N - 1 || j == M - 1) return -1;
  int curL = DP[i][j];
  int down = DP[i + 1][j];
  int right = DP[i][j + 1];

  int remainL = i + down;
  int remainR = i + right;
  int remainU = j + right;
  int remainD = j + down;

  int candidateLen = min(down, right) + 1;

  if (board[i + candidateLen - 1][j + candidateLen - 1] != 1 || candidateLen == curL) {
    return -1;
  }

  return candidateLen;
}


queue<P> Q;

void printDP() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cout << DP[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int slen = 0;

int sol() {
  while (!Q.empty()) {
    P cur = Q.front();
    Q.pop();

    int nLen = thisPointHasN(cur.first, cur.second);
    if (nLen != -1) {
      DP[cur.first][cur.second] = nLen;
      slen = nLen;
      Q.push(cur);
    }
  }
  return slen;
}

int isFind = true;

int sol2() {
  while(isFind){
    isFind = false;
    for (int i = N - 1; i >= 0; i--) {
      for (int j = N - 1; j >= 0; j--) {
        if (DP[i][j] == 0) continue;
        int nLen = thisPointHasN(i,j);
      //  cout<<"N len : "<<nLen<<endl;
        if(nLen != -1){
          isFind = true;
          slen = max(slen,nLen);
          DP[i][j] = nLen;
        }
      }
    }
  }
  return slen;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;

  memset(DP, 0, sizeof(DP));
  memset(board, false, sizeof(board));

  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < M; j++) {
      board[i][j] = s[j] - '0';
      if (board[i][j]) {
        slen = 1;
        Q.push({i, j});
        DP[i][j] = 1;
      }
    }
  }

  printDP();
  int ans = sol2();
  printDP();
  cout << ans * ans<<'\n';
  return 0;
}