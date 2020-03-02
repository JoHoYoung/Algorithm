#include <iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

#define MAXN 4000001

#define ll long long
using namespace std;
int N;

bool prime[4000001];

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  int start = 1;

  memset(prime, 1, sizeof(prime));
  prime[0] = false;
  prime[1] = false;

  while (start < MAXN) {
    start++;
    if (!prime[start]) continue;
    int pivot = 2;
    while (start * pivot < MAXN) {
      if (!prime[start * pivot]) {
        pivot++;
        continue;
      }
      prime[start * pivot] = false;
      pivot++;
    }
  }
  vector<int> s;
  for (int i = 1; i <= N; i++) {
    if (prime[i]) s.push_back(i);
  }
  int cnt = 0;
  int l = 0;
  int r = 0;
  int target = 2;
  while (l <= r && r < s.size()) {
    //   cout<<l<<" "<<r<<" "<<target<<endl;
    if (target > N) {
      target -= s[l];
      l++;
    } else if (target < N) {
      target += s[++r];
    } else {
      target += s[++r];
      cnt++;
    }
  }

  cout << cnt;
  return 0;
}