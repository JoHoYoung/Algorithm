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

int N;
vector<int> el;
// 각조의 min, max 차이 합의 최대값
// 1명의 조로 구성하는 것은 별로임

int DP[1000];

int max(int a, int b) {
  if (a > b) return a;
  return b;
}

int min(int a, int b) {
  if (a > b) return b;
  return a;
}

int sol(int idx) {

  if(idx >= N) return 0;
  int &ref = DP[idx];
  if (ref != -1) return ref;

  ref = 0;

  int h = -1;
  int l = INF;

  for (int i = idx; i < N; i++) {


    h = max(el[i], h);

    l = min(el[i], l);

    ref = max(ref, (h - l) + sol(i + 1));
  }

  return ref;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(DP, -1, sizeof(DP));
  cin >> N;

  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    el.push_back(tmp);
  }

  cout<<sol(0);
  return 0;
}

