#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

#define INF 987654321
#define MAX_K 1000000000
using namespace std;
using ll = long long;
using P = pair<int, int>;

int comb[201][201];

int n, m, K;

void getcomb() {
  for (int i = 0; i <= (m + n); i++) {
    comb[i][0] = 1; //nC0
    comb[i][i] = 1; //nCn
  }

  //combination = nCr = n-1Cr-1 + n-1Cr
  for (int i = 2; i <= (n + m); i++) {
    for (int j = 1; j < i; j++) {
      comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
      if (comb[i][j] > MAX_K)
        comb[i][j] = MAX_K; //너무 커지지 않도록 조절
    }
  }
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> K;

  int totalS = n + m;
  // a를 몇개 맨앞으로 배치할지
  //
  getcomb();
  if(K > comb[n+m][m]) {
    cout<<-1<<'\n';
    return 0;
  }
  //cout<<comb[2][1]<<endl;
  string re;
  while(re.size() < totalS){
  //  cout<<re<<endl;
    if(comb[n+m-1][m] >= K){
      n--;
      re.push_back('a');
    }else{
      K -= comb[n+m-1][m];
      re.push_back('z');
      m--;
    }
  }
  cout<<re;
  return 0;
}