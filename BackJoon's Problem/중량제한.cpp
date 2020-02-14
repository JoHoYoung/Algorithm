#include <iostream>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;
int N, M, A, B;

int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}
struct Point{
    int dst;
    int cost;
};
int MAX_WEIGHT = 1000000010;
vector<Point> info[10010];
bool visited[10010];

bool bfs(int pivot){
  queue<int> Q;
  Q.push(A);
  visited[A] = true;

  while(!Q.empty()){
    int now = Q.front();
    Q.pop();

    for(auto it = info[now].begin(); it!=info[now].end(); it++){
      int next = (*it).dst;
      int nextCost = (*it).cost;

      if(!visited[next]){
        if(nextCost < pivot){
          continue;
        } else{
          Q.push(next);
          visited[next] = true;
        }
      }
    }
  }
  return visited[B];
}

int result = 0;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N;
  cin >> M;

  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    info[a].push_back(Point{b, c});
    info[b].push_back(Point{a, c});
  }

  cin >> A;
  cin >> B;

  int left = 0;
  int right = MAX_WEIGHT;
  int mid;

  while(left<=right){

    mid = (left + right)/2;
    fill(visited,visited+N+1,false);
    if(bfs(mid)){
      result = mid;
      left = mid + 1;
    }else{
      right = mid - 1;
    }
  }

  cout<<result;
  return 0;
}