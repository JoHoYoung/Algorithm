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

string s;
int N;
int DP[2501][2501];
int min(int a, int b){
  if(a>b) return b;
  return a;
}
// 0
int isPaline(int l, int r) {
  if (l >= r) return 1;

  int &ref = DP[l][r];
  if(ref != -1) return ref;

  if(s[l] != s[r]) return ref = 0;

  return ref = isPaline(l+1, r-1);
}


int re[2500];
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string tmp;
  cin >> tmp;
  s.push_back('#');
  s += tmp;

  memset(DP, -1, sizeof(DP));
  N = s.size();

  re[0] = 0;
  for(int i=1;i<N;i++){
    re[i] = INF;
    for(int j=1;j<=i;j++){
      if(isPaline(j,i) == 1){
        re[i] = min(re[i], re[j-1]+1);
      }
    }
  }
  cout<<re[N-1];
  return 0;
}

