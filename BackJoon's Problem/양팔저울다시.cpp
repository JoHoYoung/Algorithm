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

int N, M;

vector<int> e;
vector<int> t;
vector<char> re;

bool arr[30][40001];
int abs(int a){
  if(a>0) return a;
  return -a;
}
void sol() {
  arr[0][0] = true;
  arr[0][e[0]] = true;
  for(int i=1;i<N;i++){
    for(int j=0;j<40001;j++){
      if(!arr[i-1][j]) continue;
      arr[i][j] = true;
      int l = j - e[i];
      int r = j + e[i];
      arr[i][abs(l)] = true;
      if(r <= 40000) arr[i][r] = true;
    }
  }
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(arr, false, sizeof(arr));
  cin >> N;
  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    e.push_back(tmp);
  }

  cin >> M;
  for (int i = 0; i < M; i++) {
    int tmp;
    cin >> tmp;
    t.push_back(tmp);
  }

  sol();
  for(int i=0;i<M;i++){
    if(arr[N-1][t[i]]) re.push_back('Y');
    else re.push_back('N');
  }
  for(int i=0;i<re.size();i++){
    cout<<re[i]<<" ";
  }

  return 0;
}

