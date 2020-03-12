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

int N;

int board[500];
vector<P> el;

// 실력차 : 지루함의 정도
// 실력차가 최소가 되도록 대진표
bool visited[600];
int p[500];


int MM = -1;
int parent(int idx) {
  while (idx != p[idx]) idx = p[idx];
  return idx;
}

int LEFT_DEX(int idx) {1
  int s = idx;
  if (idx == 0) return -1;
  while(1){
    int p = parent(s);
    if(p != idx){
      return p;
    }
    s --;
    if(s < 0) break;
  }
  return -1;
}

int RIGHT_DEX(int idx) {
  int s = idx;
  if (idx == N - 1) return -1;
  while(1){
    int p = parent(s);
    if(p != idx){
      return p;
    }
    s ++;
    if(s > N-1) break;
  }
  return -1;
}


void s_union(int idx1, int idx2) {
  //cout<<"UNI"<<endl;
  idx1 = parent(idx1);
  idx2 = parent(idx2);
  if (board[idx1] >board[idx2]) p[idx2] = idx1;
  else p[idx1] = idx2;
}

priority_queue<P> Q;
int ans = 0;

void sol() {
  while (!Q.empty()) {
    P cur = Q.top();
    Q.pop();
 //   cout<<"Q ] "<<cur.first<<" "<<cur.second<<endl;
    cur.first *= -1;
    if(parent(cur.second)!= cur.second) continue;
    int leftIdx = LEFT_DEX(cur.second);
    int rightIdx = RIGHT_DEX(cur.second);
    int targetDex;
 //   cout<<leftIdx<<" "<<rightIdx<<endl;
    if (leftIdx == -1) {
      targetDex = rightIdx;
    } else if (rightIdx == -1) {
      targetDex = leftIdx;

    } else {
      if(board[leftIdx] > board[rightIdx]){
        targetDex = rightIdx;
      }else{
        targetDex = leftIdx;
      }
    }

  //  cout<<"TARGET DEX "<<targetDex<<endl;
    ans += board[targetDex] - board[cur.second];
//    cout<<"ADD "<<board[targetDex] - board[cur.second]<<endl;
    s_union(cur.second, targetDex);
   // cout<<"PUSh "<<-board[targetDex]<<" "<<targetDex<<endl;
    if(board[targetDex] == MM ) break;
    Q.push({-board[targetDex], targetDex});

  }
}

bool cmp(P A, P B) {
  return A.second < B.second;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> board[i];
    if(board[i]>MM){
      MM = board[i];
    }
    p[i] = i;
    Q.push({-board[i], i});
  }
  memset(visited, false, sizeof(visited));
  sol();
  cout << ans;
  return 0;
}