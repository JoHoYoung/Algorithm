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
int DP[5001][5001];

int min(int a, int b) {
  if (a > b) return b;
  return a;
}

int sol(int l, int r) {

  if (l > r) return 0;

  int &result = DP[l][r];
  if (result != -1) return result;

  if (el[l] == el[r]) result = sol(l + 1, r - 1);
  else result = min(1 + sol(l + 1, r), 1 + sol(l, r - 1));
  return result;
}


int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    el.push_back(tmp);
  }
  memset(DP, -1, sizeof(DP));

  cout<<sol(0, el.size()-1);
  return 0;
}

