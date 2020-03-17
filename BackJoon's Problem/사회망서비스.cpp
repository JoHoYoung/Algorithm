#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

#define INF 987654321
#define MAX 1000000000
using namespace std;
using ll = long long;
using P = pair<int, int>;

int N;

vector<int> gr[1000001];

int DP[1000001][2];
// 내가 아니면, 자식은 얼리어답터
// DP[][0] : 난 아님
// DP[][1] : 내가 얼리어답터

int min(int a, int b) {
  if (a > b) return b;
  return a;
}

// 각 단계에서 자기 자식의 자식의 갯수를 리턴.
// 즉 지금이 0이면 자기 자식의 갯수를 올려줌
// 자기가 꺼져있으면 자식은 무조건 켜야하지만
// 자기가 켜져있으면 자식을 켜도될수도있음
bool visited[1000001];
int dfs(int cur, int pivot) {

  visited[cur] = true;
  // 자식의 갯수를 저장?
  //cout << cur << " " << pivot << endl;
  int &ref = DP[cur][pivot];

  if (ref != -1) return ref;

  ref = 0;
  for (int i = 0; i < gr[cur].size(); i++) {
    if(visited[gr[cur][i]]) continue;
    int tmp = dfs(gr[cur][i], 1);
    if (pivot == 1) tmp = min(tmp, dfs(gr[cur][i], 0));
    ref += tmp;
  }
  visited[cur] = false;
  return ref = ref+pivot;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    gr[a].push_back(b);
    gr[b].push_back(a);
  }

  memset(DP, -1, sizeof(DP));
  cout << min(dfs(1, 0), dfs(1, 1));
  return 0;
}

