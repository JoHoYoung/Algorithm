#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

#define MAXN 5000001
using namespace std;
using P = pair<int, int>;

int board[101];
bool visited[101];
bool check[101];
int N;

vector<vector<int>> COMB;

void comb(int start, int N, int C, int depth, vector<int> arr) {

  if (depth == C) {
    COMB.push_back(arr);
    return;
  }

  for (int i = start; i <= N; i++) {
    if (visited[i]) continue;

    visited[i] = true;
    vector<int> a;
    a.assign(arr.begin(), arr.end());
    a.push_back(i);
    comb(i, N, C, depth + 1, a);
    visited[i] = false;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> board[i];
  }

  memset(visited, false, sizeof(visited));
  vector<int> a;


  set<int> s;
  bool isFind;
  int number;
  for (number = N; number >= 1; number--) {
    cout << "Number : " << number << endl;
    COMB.clear();
    vector<int> a;

    s.clear();
    comb(1, N, number, 0, a);
    for (auto it = COMB.begin(); it != COMB.end(); it++) {
      memset(check, false, sizeof(check));
      isFind = true;
      for (auto it2 = (*it).begin(); it2 != (*it).end(); it2++) {
      //  cout<<"Idx : "<<*it2<<" value : "<<board[*it2]<<endl;
        check[board[*it2]] = true;
      }
      for (auto it2 = (*it).begin(); it2 != (*it).end(); it2++) {
        if (!check[*it2]) {
      //    cout<<"Idx : "<<*it2<<" value : "<<board[*it2]<<" is false"<<endl;
          isFind = false;
        }
      }
      if (isFind) break;
      cout<<endl;
    }
    if (isFind) {
      break;
    }
  }

  cout << number << "\n";
  for (int i = 1; i <=N; i++) {
    if(check[i] ){
      cout<<i<<"\n";
    }
  }
}
