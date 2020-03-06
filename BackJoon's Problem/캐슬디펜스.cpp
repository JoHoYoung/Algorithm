#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;
using P = pair<int, int>;
const int INF = 987654321;

int N, M, D;

int abs(int a){
  if(a<0) return -a;
  return a;
}

int dst(P S, P D) {
  return abs(S.first - D.first) + abs(S.second - D.second);
}

int max(int a,int b){
  if(a>b) return a;
  return b;
}
int min(int a, int b){
  if(a>b) return b;
  return a;
}
int turn = 0;
int archerRow;

vector<int> monsters[15];
vector<int> archer;

bool archerChecked[100];
bool monsterChecked[100][100];

int ROW(int target) {
  if (target - turn > N - 1) return -1;
  return (target - turn) % N;
}

int kill = 0;

void simul() {
  //1≈œ¥Á
  vector<P> monsterToDelete;
  // ROW∏¶ ≈ΩπÊ

  for (int a = 0; a < archer.size(); a++) {
    int curDst = INF;
    int curPos = INF;
    int delRow = INF;
    P curArcherPos = {archerRow, archer[a]};
    for (int i = N - 1; i >= 0; i--) {
      int row = ROW(i);
    if (row < 0) continue;
      if (archerRow - i > D) break;
      vector<int> monster = monsters[row];
      for (int m = 0; m < monster.size(); m++) {
        if (monsterChecked[row][monster[m]]) continue;
        P curMonsterPos = {i, monster[m]};
        int newDst = dst(curArcherPos, curMonsterPos);
    //    cout<<"NEW DST "<<newDst<<endl;
        if (newDst > D) continue;
        if (curDst > newDst) {

          archerChecked[archer[a]] = true;
          curDst = newDst;
          delRow = row;
          curPos = monster[m];
        } else if (curDst == newDst){
          if(monster[m] < curPos){
            delRow = row;
            curPos = monster[m];
          }
        }
      }
    }

    if (curPos != INF) {
      monsterToDelete.push_back({delRow, curPos});
    }
  }

  for (int i = 0; i < monsterToDelete.size(); i++) {
    P p = monsterToDelete[i];
    if(monsterChecked[p.first][p.second]) continue;
    monsterChecked[p.first][p.second] = true;
    kill++;
  }
  monsterToDelete.clear();

}

vector<vector<int>> COMB;
bool visited[100];

void comb(int N, int n, int idx, int depth, vector<int> arr) {
  if (depth == n) {
    COMB.push_back(arr);
    return;
  }
  for (int i = idx; i < N; i++) {
    if (visited[i]) continue;
    vector<int> a;
    a.assign(arr.begin(), arr.end());
    a.push_back(i);
    visited[i] = true;
    comb(N, n, i + 1, depth + 1, a);
    visited[i] = false;
  }
}

int result = 0;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> D;
  archerRow = N;

  int temp;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> temp;
      if (temp != 0) monsters[i].push_back(j);
    }
  }

  vector<int> a;
  comb(M, 3, 0, 0, a);
  for (int i = 0; i < COMB.size(); i++) {
    memset(monsterChecked, false, sizeof(monsterChecked));
    archer = COMB[i];
    turn = 0;
    kill = 0;
   while(turn < N){
      memset(archerChecked, false, sizeof(archerChecked));
      simul();
      turn ++;
    }
    result = max(result, kill);
  }

  cout<<result;
  return 0;
}