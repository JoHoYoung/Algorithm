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

int N;
int board[21][21];

int **copyArr(int **board) {
  int **target;
  target = new int *[N];
  for (int i = 0; i < N; i++) {
    target[i] = new int[N];
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      target[i][j] = board[i][j];
    }
  }
  return target;
}

void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

int max(int a, int b) {
  return a > b ? a : b;
}

void printB(int **bd) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << bd[i][j] << " ";
    }
    cout << endl;
  }
}

int ans = -1;

bool simul(int dir, int **bd) {
  bool ismv = false;
  //위 오른쪽 아래 왼쪽 순
  bool visited[N][N];
  memset(visited, false, sizeof(visited));
  if (dir == 0) {
    for (int j = 0; j < N; j++) {
      for (int now = 0; now < N; now++) {
        int cblock = bd[now][j];
        if (cblock == 0) continue;

        for (int I = now - 1; I >= 0; I--) {
          int nblock = bd[I][j];
          if (nblock == 0) {
            ismv=true;
            bd[I][j] = cblock;
            bd[I + 1][j] = 0;
            continue;
          } else {
            if (nblock == cblock && !visited[I][j]) {
              ismv=true;
              bd[I][j] *= 2;
              visited[I][j] = true;
              ans = max(ans, bd[I][j]);
              bd[I + 1][j] = 0;
            } else {
              break;
            }
          }
        }

      }
    }

  } else if (dir == 1) {
    for (int i = 0; i < N; i++) {
      for (int now = N - 1; now >= 0; now--) {
        int cblock = bd[i][now];
        if (cblock == 0) continue;
        for (int I = now + 1; I < N; I++) {
          int nblock = bd[i][I];
          if (nblock == 0) {
            ismv=true;
            bd[i][I] = cblock;
            bd[i][I - 1] = 0;
            continue;
          } else {
            if (nblock == cblock && !visited[i][I]) {
              ismv=true;
              bd[i][I] *= 2;
              visited[i][I] = true;
              ans = max(ans, bd[i][I]);
              bd[i][I - 1] = 0;
            } else {
              break;
            }
          }
        }
      }
    }
  } else if (dir == 2) {

    for (int j = 0; j < N; j++) {
      for (int now = N - 1; now >= 0; now--) {
        int cblock = bd[now][j];
        if (cblock == 0) continue;
        for (int I = now + 1; I < N; I++) {
          int nblock = bd[I][j];
          if (nblock == 0) {
            ismv=true;
            bd[I][j] = cblock;
            bd[I - 1][j] = 0;
            continue;
          } else {
            if (nblock == cblock && !visited[I][j]) {
              ismv=true;
              bd[I][j] *= 2;
              visited[I][j] = true;
              ans = max(ans, bd[I][j]);
              bd[I - 1][j] = 0;
            } else {
              break;
            }
          }
        }
      }
    }

  } else if (dir == 3) {
    for (int i = 0; i < N; i++) {
      for (int now = 0; now < N; now++) {
        int cblock = bd[i][now];
        if (cblock == 0) continue;
        for (int I = now - 1; I >= 0; I--) {
          int nblock = bd[i][I];
          if (nblock == 0) {
            ismv=true;
            bd[i][I] = cblock;
            bd[i][I + 1] = 0;
            continue;
          } else {
            if (nblock == cblock && !visited[i][I]) {
              ismv=true;
              bd[i][I] *= 2;
              visited[i][I] = true;
              ans=max(ans, bd[i][I]);
              bd[i][I + 1] = 0;
            } else {
              break;
            }
          }
        }
      }
    }
  }
  return ismv;
}

void mv(int depth, int **board) {
  if (depth >= 5) {
    //printB(board);
    //cout<<endl;
    return;
  }
  //cout<<depth<<endl;
  for (int d = 0; d < 4; d++) {
    int **nbd = copyArr(board);
    //cout<<"DIR : "<<d<<endl;
    simul(d,nbd);
    mv(depth + 1, nbd);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
      ans = max(board[i][j], ans);
    }
  }
  int **target;
  target = new int *[N];
  for (int i = 0; i < N; i++) {
    target[i] = new int[N];
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      target[i][j] = board[i][j];
    }
  }
//  simul(1,target);
//  printB(target);
//  cout<<endl;
//  simul(2,target);
//  printB(target);
//  cout<<endl;
//  simul(1,target);
//  printB(target);
//  cout<<endl;
//  simul(2,target);
//  printB(target);
//  cout<<endl;
//  simul(3,target);
//  printB(target);
//  cout<<endl;
//  simul(2,target);
//  printB(target);
//  cout<<endl;
//  simul(3,target);
//  printB(target);
//  cout<<endl;
//  printB(target);
//  cout<<endl;


  mv(0, target);
  cout << ans;
  return 0;
}


