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

vector<string> nums;

int nSize = nums.size();
int visited[10000];

void getN() {
  int arr[10000];
  for (int i = 0; i < 10000; i++) arr[i] = i;

  for (int i = 2; i < 10000; i++)
    for (int j = 2; j < 10000; j++)
      if (i != arr[j] && arr[j] % i == 0) arr[j] = 0;


  for (int i = 1000; i < 10000; i++) {
    if (arr[i] == 0) continue;
    nums.push_back(to_string(i));

  }
}

int tc;
string S, D;

bool can(string s, string d) {
  int cnt = 0;
  for (int i = 0; i < 4; i++) {
    if (s[i] == d[i]) continue;
    cnt++;
  }
  return cnt == 1;
}

void BFS() {
  queue<string> Q;
  visited[stoi(S)] = 0;
  Q.push(S);
  while (!Q.empty()) {
    string cur = Q.front();
    Q.pop();
    for (int i = 0; i < nums.size(); i++) {
      if (visited[stoi(nums[i])] != -1)continue;
      if (!can(cur, nums[i])) continue;
      visited[stoi(nums[i])] = visited[stoi(cur)] + 1;
      Q.push(nums[i]);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  getN();
  cin >> tc;
  while (tc--) {
    memset(visited, -1, sizeof(visited));
    cin >> S >> D;
    BFS();
    cout << visited[stoi(D)] << '\n';
  }
  return 0;
}

