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
int n, k, s;
int board[401][2];

vector<int> B[401];
bool visited[401];

bool dfs(int idx, int end){

  if(idx == end) return true;
 vector<int> myNodes = B[idx];
  for(auto it = myNodes.begin(); it != myNodes.end(); it++){
    if(visited[*it]) continue;
    visited[*it] = true;
    if(dfs(*it, end)) return true;
    visited[*it] = false;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;

  for (int i = 0; i < k; i++) {
    cin >> board[i][0] >> board[i][1];
    B[board[i][0]].push_back(board[i][1]);
  }

  cin >> s;
  int start, end;

  vector<int> R;
  for (int i = 0; i < s; i++) {
    cin >> start >> end;
    int ans = 0;

    memset(visited, false, sizeof(visited));
    if(dfs(start, end)) ans = -1;

    memset(visited, false, sizeof(visited));
    if(dfs(end, start)) ans = 1;

    R.push_back(ans);
  }

  for(auto it = R.begin(); it != R.end(); it++) cout<<*it<<"\n";
  return 0;

}
