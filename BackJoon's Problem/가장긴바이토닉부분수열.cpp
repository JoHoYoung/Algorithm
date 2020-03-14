#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;

int N;

vector<int> el;
int DP[1003];
int DP2[1003];

int max(int a, int b) {
  if (a > b) return a;
  return b;
}

void sol() {
  int re = -1;
  for (int i = 1; i <= N; i++) {
    DP[i] = 0;
    for (int j = 1; j < i; j++) {
      if (el[j] >= el[i]) continue;
      DP[i] = max(DP[i], DP[j] + 1);
    }
  }

  for (int i = N; i >= 1; i--) {
    DP2[i] = 0;
    for (int j = N; j > i; j--) {
      if (el[j] >= el[i]) continue;
      DP2[i] = max(DP2[i], DP2[j] + 1);
    }
  }

  for (int i = 1; i <= N; i++) {
    re = max(re, DP[i] + DP2[i]);
  }
  cout << re +1;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  memset(DP,0,sizeof(DP));
  memset(DP2, 0, sizeof(DP2));
  el.push_back(98765643123);
  for (int i = 0; i < N; i++) {
    int tp;
    cin >> tp;
    el.push_back(tp);
  }
  el.push_back(-1);

  sol();
//  for(int i=1;i<=N;i++){
//    cout<<DP[i]<<" ";
//  }
//  cout<<endl;
//  for(int i=1;i<=N;i++){
//    cout<<DP2[i]<<" ";
//  }
  return 0;
}