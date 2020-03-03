#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

#define MAXN 5000001
using namespace std;
using P = pair<int, int>;
int N;

bool check[101];
bool visited[101];
bool cycle[101];
int board[101];

int cnt = 0;

bool dfs(int start, int idx) {
  if(visited[idx]) return false;
  visited[idx] = true;

  if(start == idx || dfs(start, board[idx])){
    cnt ++;
    cycle[idx] = true;
    return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  memset(check, false, sizeof(check));

  for(int i=1;i<=N;i++) cin>>board[i];

  for (int i = 1; i <= N; i++) {
    for(int j=1;j<=N;j++){
      visited[j] = cycle[j];
    }
    dfs(i, board[i]);
  }

  cout << cnt << endl;

  for (int i = 1; i <= N; i++)
    if (cycle[i]) //사이클 이루는 노드들 출력
      cout << i << " ";
  cout << endl;

  return 0;

}
