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

int S;

// 복사, 붙여넣기

typedef struct unit {
    int curNum, copyNum, depth;
};
int ans = INF;

int min(int a, int b) {
  return a > b ? b : a;
}

int visited[1001][1001];

void BFS() {

  queue<unit> Q;
  Q.push({1, 0, 0});
  visited[1][0] = 0;
  while (!Q.empty()) {
    int curNum = Q.front().curNum;
    int copyNum = Q.front().copyNum;
    int curD = Q.front().depth;
    Q.pop();
 //   cout << curNum << " " << copyNum << " " << curD << endl;
    if (curNum == S) {
      ans = curD;
      return;
    }
    // 클립보드에 복사한게 있으면
    if (copyNum != 0 && curNum + copyNum <= 1000 && visited[curNum + copyNum][copyNum] == -1) {
      visited[curNum + copyNum][copyNum] = curD + 1;
      Q.push({curNum + copyNum, copyNum, curD + 1});
    }
    // 클립보드에 저장

    if (visited[curNum][curNum] == -1) {
      Q.push({curNum, curNum, curD + 1});
      visited[curNum][curNum] = curD + 1;
    }
    //삭제
    if (curNum - 1 >= 0 && visited[curNum - 1][copyNum] == -1) {
      Q.push({curNum - 1, copyNum, curD + 1});
      visited[curNum - 1][copyNum] = curD + 1;
    }

  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> S;
  memset(visited, -1, sizeof(visited));
  BFS();
  cout << ans;
  return 0;
}


