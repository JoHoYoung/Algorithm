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

int N, K;

// 순간이동
int visited[200001];

vector<int> re;
typedef struct unit {
    int pos, depth;
};

void BFS() {
  queue<unit> Q;
  Q.push({N, 0});
  visited[N] = 0;
  while (!Q.empty()) {
    unit cur = Q.front();
    Q.pop();

    if (cur.pos == K) {
      //   cout<<cur.depth<<endl;
      re.push_back(cur.depth);
    }

    if (cur.pos + 1 <= 100000 && (visited[cur.pos + 1] == -1 || visited[cur.pos+1] >= cur.depth +1)) {
      visited[cur.pos + 1] = cur.depth + 1;
      Q.push({cur.pos + 1, cur.depth + 1});
    }

    if (cur.pos - 1 >= 0 && (visited[cur.pos - 1] == -1 || visited[cur.pos - 1] >= cur.depth+1)) {
      visited[cur.pos - 1] = cur.depth + 1;
      Q.push({cur.pos - 1, cur.depth + 1});
    }
    if (cur.pos * 2 <= 100000 && (visited[cur.pos * 2] == -1 || visited[cur.pos*2] >= cur.depth+1)) {
      visited[cur.pos * 2] = cur.depth + 1;
      Q.push({cur.pos * 2, cur.depth + 1});
    }

  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K;
  memset(visited, -1, sizeof(visited));
  BFS();
  sort(re.begin(), re.end());
  int ans = 1;
  int pv = re[0];
  for(int i=1;i<re.size();i++){
    if(pv != re[i]) break;
    ans ++;
  }
//  cout << "??";
  cout << visited[K] << "\n"<<ans;
  return 0;
}


