#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>

#define MAXN 31
#define INF 987654321
#define MAX 1000000

using namespace std;
using ll = long long;
using P = pair<int, int>;

typedef struct nodes {
    vector<pair<int, nodes*>> leaves;
    int end;
    int visit;

    nodes() {
      end = -1;
      visit = 0;
    }
};

nodes *root = new nodes();

int sv[30005];

void addToTries(string s, int idx) {

  nodes *now = root;
  int sum = 0;

  for (int i = 0; i < s.size(); i++) {
    nodes *next = nullptr;
    for(int j=0;j< (now ->leaves).size();j++){
      pair<int, nodes*> nNode = (now ->leaves)[j];
      if(nNode.first == s[i] - 'a'){
        next = nNode.second;
        break;
      }
    }
    if (!next) {
      next = new nodes();
      now -> leaves.push_back({s[i] - 'a', next});
    }
    now = next;
    now->visit++;
    sum += now->visit;
  }
  now->end = idx;
  sv[idx] = sum + 1 + idx;
}

int ans = 0;

void travel(int depth, string t, nodes *node) {


  if (depth == t.size() && (node->end) != -1) {
    ans = sv[node->end];
    return;
  }
  if (depth == t.size()) return;

  ans += node->visit;
  nodes *next = nullptr;

  for(int i=0;i< (node ->leaves).size();i++){
    pair<int, nodes*> nNode = (node ->leaves)[i];
    if(nNode.first == t[depth] - 'a'){
      next = nNode.second;
      break;
    }
  }
  if (!next) return;
  travel(depth + 1, t, next);
}

// 돌을 m개 제거
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;

  for (int q = 0; q < N; q++) {
    string s;
    cin >> s;
    addToTries(s, q);
  }

  int Q;
  cin >> Q;
  for (int q = 0; q < Q; q++) {
    string s;
    cin >> s;
    ans = 0;
    //  cout << "S " << s << endl;
    nodes* now = root;
    int i =0;
    for(i=0;i<s.size();i++){
      //  ans += now->visit;
      bool isFind = false;
      for(auto& leaf : now -> leaves){
        if(leaf.first == s[i] - 'a'){
          isFind = true;
          now = leaf.second;
          break;
        }
      }
      if(!isFind) break;
      ans += now->visit;
    }
    if(now -> end != -1 && i == s.size()){
      cout<<sv[now->end]<<'\n';
    }else{
      cout<<ans + N<<'\n';
    }

  }

}

//3 : 1 1 1
//3 : 1 1 1
//3 : 1 1 1
//4 : 1 1 1 1
//4 : 1 1 1 1
//4 : 1 1 1 1
//4 : 1 1 1 1
//4 : 1 1 1 1
// root : 8 , m + 8 ,a + 8, 5

//