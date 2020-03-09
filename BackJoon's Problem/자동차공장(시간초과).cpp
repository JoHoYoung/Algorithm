#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 987654321;
int N,M;
int S;

//상근이는 대장
// 상근이는 1번
// 나머지 : 2~N
// 자신 아래에 있는 부하들의 월급
vector<int> E[500001];

int money[500001];


void add(int e,int m){
  money[e] += m;
}

void action(int e,int m){
  for(int i=0;i<E[e].size();i++){
    add(E[e][i],m);
    action(E[e][i],m);
  }
}


int get(int e){
  return money[e];
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>N>>M;
  cin>>S;
  money[1] = S;

  for(int i=2;i<N+1;i++){
    int a,b;
    //i : 직원번호, a: 월급 b : 상사번호
    cin>>a>>b;
    E[b].push_back(i);
    money[i] = a;
  }
  vector<int> R;
  for(int i=0;i<M;i++){
    char p;
    int a,x;
    cin>>p;
    if(p == 'p'){
      cin >>a>>x;
      action(a, x);
    }else {
    //  cout<<p<<endl;
    //  cout<<"DO"<<endl;
      cin>>a;
      R.push_back(get(a));
    }
  }
  for(int i=0;i<R.size();i++){
    cout<<R[i]<<endl;
  }

  return 0;
}