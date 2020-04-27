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

int X, N, L;

vector<int> el;
vector<string> re;

// 10000000
// 10^8
int main() {

  while (cin >> X) {
    bool isFind = false;
    X = X*10000000;
    el.clear();
    cin >> N;
    for (int i = 0; i < N; i++) {
      int l;
      cin >> l;
      el.push_back(l);
    }
    sort(el.begin(), el.end());
    int l = 0;
    int r = el.size() - 1;
    while (l < r) {
      if(el[l] + el[r] > X){
        r --;
      }else if(el[l] + el[r] < X){
        l++;
      }else{
        string s;
        cout<<"yes "<<to_string(el[l])<<" "<<to_string(el[r]) << '\n';
        isFind = true;
        break;
      }
    }
    if(!isFind) cout<<"danger\n";
  }
  return 0;
}

