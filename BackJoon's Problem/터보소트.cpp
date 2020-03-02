#include <iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#define MAXN 300030
#define ll long long
using namespace std;
int N;
int board[100001];

void update(vector<int>& tree, int node, int dif){
  while(node <= MAXN){
    tree[node] += dif;
    node += ( node & -node);
  }
}

ll query(vector<int>& tree, int node){
  ll sum =  0;
  while(node > 0){
  //  cout<<node<<endl;
    sum += tree[node];
    node -= (node & -node);
  }
  return sum;
}


int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  vector<int> tree(MAXN+1, 0 );

  int leftest = 1000001;
  int rightest = MAXN;

  int temp;
  for(int i=1;i<=N;i++){
    cin >> temp;
    board[temp] = i;
    update(tree, i, 1);
  }

  vector<int> R;

  int left =1;
  int right = N;

  while(left < right){
    R.push_back(query(tree, board[left]-1));
    update(tree, board[left], -1);
    update(tree, leftest, 1);
    board[left++] = leftest ++;

    R.push_back(query(tree, 100001) - query(tree, board[right]));
    update(tree, board[right], -1);
    update(tree, rightest, 1);
    board[right--] = rightest --;

    if(left == right){
      R.push_back(query(tree, board[left]-1));
      update(tree, board[left], -1);
      update(tree, leftest, 1);
      board[left++] = leftest ++;
    }
  }

  for(auto it = R.begin(); it != R.end(); it++){
    cout<<*it<<"\n";
  }

  return 0;
}