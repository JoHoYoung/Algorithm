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
int N, L;

int visited[100001];
vector<int> lineStationHas[100001];
vector<int> Line[100001];

int S, E;

void BFS() {
  queue<P> Q;
  Q.push({S,0});
  visited[S] = 0;
  while (!Q.empty()) {
    int cur = Q.front().first;
    int curCost = Q.front().second;
    Q.pop();
   // cout<<cur<<" cost "<<curCost<<endl;
    for (int l = 0; l < lineStationHas[cur].size(); l++) {
      vector<int> stations = Line[lineStationHas[cur][l]];
      for(int s=0;s<stations.size();s++){
        int nNode = stations[s];
        if(visited[nNode] != -1 && visited[nNode] <= curCost) continue;
        visited[nNode] = curCost;
        Q.push({nNode, curCost+1});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(visited, -1, sizeof(visited));
  cin >> N >> L;
  for (int i = 0; i < L; i++) {
    while (1) {
      int tmp;
      cin >> tmp;
      if (tmp == -1) break;
      Line[i].push_back(tmp);
      lineStationHas[tmp].push_back(i);
    }
  }
  cin >> S >> E;
  BFS();
  cout<<visited[E];
  return 0;
}

