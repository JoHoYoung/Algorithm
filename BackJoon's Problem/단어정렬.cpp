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

set<string> s;
vector<string> el;

bool cmp(string a, string b){
  if(a.size() == b.size()){
    for(int i= 0; i<a.size();i++){
      if(a[i] == b[i]) continue;
      return a[i] < b[i];
    }
  }else{
   return a.size() < b.size();
  }
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>N;

  for(int i=0;i<N;i++){
    string tmp;
    cin>>tmp;
    s.insert(tmp);
  }
  for(auto it = s.begin();it !=s.end();it++){
    el.push_back(*it);
  }
  sort(el.begin(), el.end(), cmp);
  for(int i=0;i<el.size();i++){
    cout<<el[i]<<'\n';
  }
  return 0;
}

