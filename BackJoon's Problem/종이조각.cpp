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

//왼쪽, 그리고 아랫족으로
int N, M;

int board[4][4];

vector<int> getArr(int bin) {
  vector<int> tmp;
  tmp.resize(N * M);
  for (int i = 0; i < N * M; i++) {
    tmp[i] = bin % 2;
    bin /= 2;
  }
  return tmp;
}

bool chk[4][4];

void build(vector<int> t) {
  int idx = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      chk[i][j] = t[idx++];
    }
  }
}

int sol() {
  int cnf = -1;
  for (int i = 0; i < (1 << N * M); i++) {
    vector<int> t = getArr(i);
    build(t);
    int sum = 0;
    // 가로찾기
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        // start point
        int tmp = 0;
        if (chk[i][j]) {
          while (1) {
            tmp *= 10;
            tmp += board[i][j++];
            if (!chk[i][j] || j >= M) break;
          }
        }
        sum += tmp;
      }
    }

    for (int j = 0; j < M; j++) {
      for (int i = 0; i < N; i++) {
        // start point
        int tmp = 0;
        if (!chk[i][j]) {
          while (1) {
            tmp *= 10;
            tmp += board[i++][j];
            if (chk[i][j] || i >= N) break;
          }
        }
        sum += tmp;
      }
    }
    cnf = max(cnf, sum);
  }
  return cnf;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      char a;
      cin >> a;
      board[i][j] = a - '0';
    }
  }
  cout<<sol();
  return 0;
}