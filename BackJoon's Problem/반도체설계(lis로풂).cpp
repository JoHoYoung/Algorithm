#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

#define INF 987654321

using namespace std;
using ll = long long;
using P = pair<int, int>;

int N;

vector<int> el;
vector<int> lis;

int lowerbound(int target) {
  int l = 0;
  int r = lis.size() - 1;
  while (l < r) {
    int mid = (l + r) / 2;
    if (lis[mid] >= target) {
      r = mid ;
    } else {
      l = mid + 1;
    }
  }
  return r;
}

void sol(){
  for(int i=0;i<el.size();i++){
    if(lis.size() == 0 ){
      lis.push_back(el[i]);
      continue;
    }

    if(lis[lis.size()-1] < el[i]) lis.push_back(el[i]);
    else{
      int idx = lowerbound(el[i]);
      lis[idx] = el[i];
    }
  }
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
  sol();
  cout<<lis.size();
  return 0;
}