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

int n, m, ans;
int a[500][500];
const int b[19][4][2] = {
  { {0,0}, {0,1}, {1,0}, {1,1} }, // ¤±
  { {0,0}, {0,1}, {0,2}, {0,3} }, // ¤Ñ
  { {0,0}, {1,0}, {2,0}, {3,0} },
  { {0,0}, {0,1}, {0,2}, {1,0} }, // ¤¤
  { {0,2}, {1,0}, {1,1}, {1,2} },
  { {0,0}, {1,0}, {1,1}, {1,2} },
  { {0,0}, {0,1}, {0,2}, {1,2} },
  { {0,0}, {1,0}, {2,0}, {2,1} },
  { {0,0}, {0,1}, {1,1}, {2,1} },
  { {0,0}, {0,1}, {1,0}, {2,0} },
  { {0,1}, {1,1}, {2,0}, {2,1} },
  { {0,0}, {1,0}, {1,1}, {2,1} }, // Z
  { {0,1}, {1,0}, {1,1}, {2,0} },
  { {0,1}, {0,2}, {1,0}, {1,1} },
  { {0,0}, {0,1}, {1,1}, {1,2} },
  { {0,0}, {0,1}, {0,2}, {1,1} }, // ¤Ç
  { {0,1}, {1,0}, {1,1}, {1,2} },
  { {0,1}, {1,0}, {1,1}, {2,1} },
  { {0,0}, {1,0}, {1,1}, {2,0} }
};

void tetromino(int x, int y) {
  for (int i=0; i<19; i++) {
    int res = 0;
    for (int j=0; j<4; j++) {
      int nx = x + b[i][j][0];
      int ny = y + b[i][j][1];
      if (0 <= nx && nx < n && 0 <= ny && ny < m) {
        res += a[nx][ny];
      }
    }
    if (ans < res) ans = res;
  }
}

void solve() {
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      tetromino(i, j);
    }
  }
  printf("%d\n", ans);
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  solve();
  return 0;
}

