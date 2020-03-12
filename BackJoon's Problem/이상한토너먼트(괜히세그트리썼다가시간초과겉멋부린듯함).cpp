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

int N;

int board[501];
int tree[2004];
int DP[600][600];

int min(int a,int b){
  if(a>b) return b;
  return a;
}
int max(int a, int b) {
  if (a > b) return a;
  return b;
}

int maxTable[501][501];

void bulldMaxtable(){
  for(int d=0;d<N;d++){
    for(int i=1;i+d<=N;i++){
      if(d == 0){
        maxTable[i][i+d] = board[i];
        continue;
      }
      maxTable[i][i+d] = max(board[i], maxTable[i+1][i+d]);
    }
  }

//  for(int i=1;i<=N;i++){
//    for(int j=i;j<=N;j++){
//      if(i== j) {
//        maxTable[i][j] = board[i];
//        continue;
//      }
//      maxTable[i][j] = max(maxTable[i+1])
//    }
//  }
}
int query(int node, int start, int end, int l, int r) {
  if (end < l || start > r) return -1;
  if (start >= l && end <= r) return tree[node];
  int mid = (start + end) / 2;
  return max(query(node * 2, start, mid, l, r), query(node * 2 + 1, mid + 1, end, l, r));
}

int abs(int a) {
  if (a > 0) return a;
  return -a;
}

void update(int index, int value, int node, int l, int r) {
  if (index < l || index > r) return;
  //cout << "SET " << node << " to " << max(value, tree[node]) << endl;
  tree[node] = max(value, tree[node]);
  if (l != r) {
    int mid = (l + r) / 2;
    update(index, value, node * 2, l, mid);
    update(index, value, node * 2 + 1, mid + 1, r);
    // tree[node] = ((tree[node*2]%DIV) * (tree[node*2+1]%DIV))%DIV;
  }
}

void sol() {
  for (int d = 0; d < N; d++) {
    for (int i = 1; i + d <= N; i++) {
      if (d == 0) {
        DP[i][i + d] = 0;
        continue;
      }
      DP[i][i + d] = INF;
      for (int k = i; k + 1 <= i + d; k++) {
       // cout << "query result from " << i << " to k " << k << " " << query(1, 1, N, i, k) << " from " << k + 1 << " to "
        //     << i + d << " " << query(1, 1, N, k + 1, i + d) << endl;

       // cout<<"D : "<<d<<" k : "<<k<<" compare "<<DP[i][i + d]<<" "<<DP[i][k] + DP[k + 1][i + d] + abs(query(1, 1, N, i, k) - query(1, 1, N, k + 1, i + d));
      //  cout<<" from "<<i<<" to "<<i+d<<endl;
      //  cout<<"upper to dp "<<DP[i][k]<<" and "<<DP[k+1][i+d]<<" and query "<< query(1, 1, N, i, k)<<" - "<<query(1, 1, N, k + 1, i + d)<<endl;
   //     DP[i][i + d] = min(DP[i][i + d],
   //                        DP[i][k] + DP[k + 1][i + d] + abs(query(1, 1, N, i, k) - query(1, 1, N, k + 1, i + d)));
        DP[i][i + d] = min(DP[i][i + d],
                           DP[i][k] + DP[k + 1][i + d] + abs(maxTable[i][k] - maxTable[k+1][i+d]));
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  memset(DP, 0, sizeof(DP));
  memset(tree, 0, sizeof(tree));
  for (int i = 1; i <= N; i++) cin >> board[i];
 // for (int i = 1; i <= N; i++) update(i, board[i], 1, 1, N);

  bulldMaxtable();
  sol();
//  for (int i = 1; i <= N; i++) {
//    for (int j = i; j <= N; j++) {
//      cout << maxTable[i][j] << " ";
//    }
//    cout << endl;
//  }
//  cout << endl;
  cout << DP[1][N];
  return 0;
}