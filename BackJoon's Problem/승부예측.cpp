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
map<string, int> m;

float result[4] = {0.};

int score[4] = {0, 0, 0, 0};

typedef struct versus{
    int a,b;
    float w,d,l;
};
versus V[6];


// 이기는 경우의 확률
void dfs(int depth, float p) {

  //cout<<depth<<endl;
  // 다돌았으면 정산 타임
  if(depth == 6){
    vector<P> re;
    for(int i=0;i<4;i++)
      re.push_back({score[i],i});

    sort(re.begin(), re.end());

    P A = re[3];
    P B = re[2];
    P C = re[1];
    P D = re[0];

    if(B.first != C.first) {
      result[A.second] += p;
      result[B.second] += p;
    }else if(A.first == B.first && C.first == D.first){
      result[A.second] += p/2.0f;
      result[B.second] += p/2.0f;
      result[C.second] += p/2.0f;
      result[D.second] += p/2.0f;
    }else if(A.first == B.first){
      result[A.second] += p*(2.0f/3.0f);
      result[B.second] += p*(2.0f/3.0f);
      result[C.second] += p*(2.0f/3.0f);
    }else if(C.first == D.first) {
      result[A.second] += p;
      result[B.second] += p * (1.0f / 3.0f);
      result[C.second] += p * (1.0f / 3.0f);
      result[D.second] += p * (1.0f / 3.0f);
    }else{
      result[A.second] += p;
      result[B.second] += p*(1.0f/2.0f);
      result[C.second] += p*(1.0f/2.0f);
    }
    return;
  }

  int a = V[depth].a;
  int b = V[depth].b;

  score[a] += 3;
  dfs(depth+1,p*V[depth].w);
  score[a] -= 3;

  score[a] += 1;
  score[b] += 1;
  dfs(depth+1, p*V[depth].d);
  score[a] -=1;
  score[b] -=1;

  score[b]+=3;
  dfs(depth+1, p*V[depth].l);
  score[b]-=3;


}
int main() {

  string s;
  for (int i = 0; i < 4; i++) {
    cin >> s;
    m.insert({s, i});
  }

  for (int i = 0; i < 6; i++) {
    string A, B;
    float w, d, l;
    int a, b;
    cin >> A >> B;

    a = m.find(A)->second;
    b = m.find(B)->second;
    cin >> w >> d >> l;

    V[i].a = a;
    V[i].b = b;
    V[i].w = w;
    V[i].l = l;
    V[i].d = d;
  }

  dfs(0, 1.0f);
  cout.precision(8);

  for(int i=0;i<4;i++){
    cout<<result[i]<<'\n';
  }
}

