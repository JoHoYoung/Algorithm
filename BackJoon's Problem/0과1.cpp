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

int T, N;
bool visited[20001];

P arr[20001];

void BFS() {
  queue<int> Q;
  Q.push(1);
  visited[1] = true;
  arr[1].first = -1;
  arr[1].second = 1;
  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();
    // 0추가
    int n1 = (cur * 10) % N;
    if (!visited[n1]) {
      arr[n1].first = cur;
      arr[n1].second = 0;
      if (n1 == 0) return;
      visited[n1] = true;
      Q.push(n1);
    }

    //1추가
    int n2 = (n1 + 1) % N;
    if (!visited[n2]) {
      arr[n2].first = cur;
      arr[n2].second = 1;
      if (n2 == 0) return;
      visited[n2] = true;
      Q.push(n2);
    }
  }
}

void trace(int num) {
  if (num == -1) return;
  trace(arr[num].first);
  cout << arr[num].second;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  while (T--) {
    memset(visited, false, sizeof(visited));
    cin >> N;
    BFS();
    trace(0);
    cout<<'\n';
  }

  return 0;
}

