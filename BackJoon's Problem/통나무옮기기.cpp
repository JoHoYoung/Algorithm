#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>

#define INF 987654321
#define MAX 1000000
using namespace std;
using ll = long long;
using P = pair<int, int>;

int N, M;
char board[51][51];
int visited[51][51][2];

// p : 0가로, p : 1 세로
bool canTurn(int centerI, int centerJ, int p) {
  if (p == 0) {
    if (centerI == 0 || centerI == N - 1) return false;
    return (board[centerI - 1][centerJ - 1] != '1' && board[centerI - 1][centerJ] != '1' &&
            board[centerI - 1][centerJ + 1] != '1') &&
           (board[centerI + 1][centerJ - 1] != '1' && board[centerI + 1][centerJ] != '1' &&
            board[centerI + 1][centerJ + 1] != '1');
  } else {
    if (centerJ == 0 || centerJ == N - 1) return false;
    return (board[centerI - 1][centerJ - 1] != '1' && board[centerI][centerJ - 1] != '1' &&
            board[centerI + 1][centerJ - 1] != '1') &&
           (board[centerI - 1][centerJ + 1] != '1' && board[centerI][centerJ + 1] != '1' &&
            board[centerI + 1][centerJ + 1] != '1');
  }
}

bool canGoLeft(int centerI, int centerJ, int p) {
 // cout<<"CANGO WITH "<<centerI<<" "<<centerJ<<" "<<p<<endl;
  if (p == 0) {
    if (centerJ - 1 <= 0) return false;
    if (board[centerI][centerJ - 2] == '1')return false;
    return true;
  } else {
    if (centerJ - 1 < 0) return false;
    return (board[centerI - 1][centerJ - 1] != '1' && board[centerI][centerJ - 1] != '1' &&
            board[centerI + 1][centerJ - 1] != '1');
  }
}

bool canGoRight(int centerI, int centerJ, int p) {
  if (p == 0) {
    if (centerJ + 1 >= N - 1) return false;
    if (board[centerI][centerJ + 2] == '1')return false;
    return true;
  } else {
    if (centerJ + 1 > N - 1) return false;
    return (board[centerI - 1][centerJ + 1] != '1' && board[centerI][centerJ + 1] != '1' &&
            board[centerI + 1][centerJ + 1] != '1');
  }
}

bool canGoUP(int centerI, int centerJ, int p) {
  if (p == 1) {
    if (centerI - 1 <= 0) return false;
    if (board[centerI - 2][centerJ] == '1')return false;
    return true;
  } else {
    if (centerI - 1 < 0) return false;
    return (board[centerI - 1][centerJ - 1] != '1' && board[centerI - 1][centerJ] != '1' &&
            board[centerI - 1][centerJ + 1] != '1');
  }
}

bool canGoDown(int centerI, int centerJ, int p) {
  if (p == 1) {
    if (centerI + 1 >= N - 1) return false;
    if (board[centerI + 2][centerJ] == '1')return false;
    return true;
  } else {
    if (centerI + 1 > N - 1) return false;
    return (board[centerI + 1][centerJ - 1] != '1' && board[centerI + 1][centerJ] != '1' &&
            board[centerI + 1][centerJ + 1] != '1');
  }
}

typedef struct Unit {
    int i, j, d, p;
};
vector<P> E;
vector<P> B;
Unit St;
Unit Ed;
int ans = INF;

int min(int a, int b) {
  if (a > b) return b;
  return a;
}

void BFS() {
  queue<Unit> Q;
  Q.push(St);
  visited[St.i][St.j][St.p] = St.d;

  while (!Q.empty()) {
    Unit cur = Q.front();
    Q.pop();
    int curI = cur.i;
    int curJ = cur.j;
    int curD = cur.d;
    int curP = cur.p;
   // cout << curI << " " << curJ << " " << curP <<" d "<<curD <<endl;
    if (curI == Ed.i && curJ == Ed.j && curP == Ed.p) {
      ans = min(ans, curD);
      continue;
    }

    if (canTurn(curI, curJ, curP) && (visited[curI][curJ][(curP + 1) % 2] == -1 ||
                                      visited[curI][curJ][(curP + 1) % 2] > curD + 1)) {
      visited[curI][curJ][(curP + 1) % 2] = curD + 1;
      Q.push({curI, curJ, curD + 1, (curP + 1) % 2});
    }

    if (canGoUP(curI, curJ, curP) &&
        (visited[curI - 1][curJ][curP] == -1 || visited[curI - 1][curJ][curP] > curD + 1)) {
      visited[curI - 1][curJ][curP] = curD + 1;
      Q.push({curI - 1, curJ, curD + 1, curP});
    }

    if (canGoDown(curI, curJ, curP) && (visited[curI + 1][curJ][curP] == -1 ||
                                        visited[curI + 1][curJ][curP] > curD + 1)) {
      visited[curI + 1][curJ][curP] = curD + 1;
      Q.push({curI + 1, curJ, curD + 1, curP});
    }
    if (canGoLeft(curI, curJ, curP) && (visited[curI][curJ - 1][curP] == -1 ||
                                        visited[curI][curJ - 1][curP] > curD + 1)) {
    //  cout<<"COMPARE "<<visited[curI][curJ - 1][curP]<<" with "<<curD+1<<endl;
      visited[curI][curJ - 1][curP] = curD + 1;
   //   cout<<"GO L "<<curI<<" "<<curJ-1<<endl;
      Q.push({curI, curJ - 1, curD + 1, curP});
    }

    if (canGoRight(curI, curJ, curP) && (visited[curI][curJ + 1][curP] == -1 ||
                                         visited[curI][curJ + 1][curP] > curD + 1)) {
      visited[curI][curJ + 1][curP] = curD + 1;
      Q.push({curI, curJ + 1, curD + 1, curP});
    }
  }

}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(visited, -1, sizeof(visited));
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'E') E.push_back({i, j});
      if (board[i][j] == 'B') B.push_back({i, j});
    }
  }
  if (B[0].second + 1 == B[1].second) {
    St.i = B[1].first;
    St.j = B[1].second;
    St.d = 0;
    St.p = 0;
  } else {
    St.i = B[1].first;
    St.j = B[1].second;
    St.d = 0;
    St.p = 1;
  }

  if (E[0].second + 1 == E[1].second) {
    Ed.i = E[1].first;
    Ed.j = E[1].second;
    Ed.p = 0;
  } else {
    Ed.i = E[1].first;
    Ed.j = E[1].second;
    Ed.p = 1;
  }
  BFS();

  if(ans == INF) cout<<0;
  else cout << ans;
  return 0;
}

