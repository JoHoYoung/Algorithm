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
int visited[1000001];
int F, S, G, U, D;


void BFS(){
  queue<int> Q;
  Q.push(S);
  visited[S] = 0;

  while(!Q.empty()){
    int cur = Q.front();
    Q.pop();
    int nU = cur + U;
    int nD = cur - D;

    if(nU <= F && visited[nU] == -1){
      visited[nU] = visited[cur] + 1;
      Q.push(nU);
    }
    if(nD >= 1 && visited[nD] == -1){
      visited[nD] = visited[cur] + 1;
      Q.push(nD);
    }
  }

}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(visited, -1, sizeof(visited));

  cin >> F >> S >> G >> U >> D;
  BFS();
  if(visited[G] == -1) cout<<"use the stairs";
  else cout<<visited[G];
  return 0;
}

