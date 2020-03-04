#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

#define MAXN 1000000
#define WIN 2
#define DRAW 1
#define LOOSE 0

using namespace std;
using P = pair<int, int>;
int N, K;

int Di[4] = {0, -1, 0, 1};
int Dj[4] = {1, 0, -1, 0};

vector<int> MV;
bool board[300][300];

void DO() {
  vector<int> temp;
  for (int i = 0; i < MV.size(); i++) {
    int newMove = (MV[i] + 1) % 4;
    temp.push_back(newMove);
  }
  for (int i = temp.size() - 1; i >= 0; i--) {
    MV.push_back(temp[i]);
  }
}

void print() {
  for (int i = 0; i < MV.size(); i++) {
    cout << MV[i] << " ";
  }
  cout << endl;
}

vector<P> pos;

void printPos() {
  for (auto it = pos.begin(); it != pos.end(); it++) {
    cout << (*it).first << " " << (*it).second << endl;
  }
}

void getPos(P startPos) {
  int curi = startPos.first;
  int curj = startPos.second;
  for (int i = 0; i < MV.size(); i++) {
    int d = MV[i];
    int ni = curi + Di[d];
    int nj = curj + Dj[d];
    pos.push_back({ni, nj});
    curi = ni;
    curj = nj;
  }
}

P A, B, C, D;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  int x, y, d, g;
  for (int i = 0; i < N; i++) {
    MV.clear();
    cin >> x >> y >> d >> g;
    MV.push_back(d);
    pos.push_back({y, x});
    for (int i = 0; i < g; i++) {
      DO();
    }
    getPos({y, x});
  }
  //printPos();
  memset(board, false, sizeof(board));

  for (auto it = pos.begin(); it != pos.end(); it++) {
    board[(*it).first][(*it).second] = true;
  }

  A = {0, 0};
  B = {0, 1};
  C = {1, 0};
  D = {1, 1};

  int cnt = 0;
  for(int i=0;i<190;i++){
    for(int j=0;j<190;j++){
    //  cout<<i<<" "<<j<<endl;
      A.first = i;
      A.second = j;

      B.first = A.first;
      B.second = A.second + 1;

      C.first = A.first + 1;
      C.second = A.second;

      D.first = A.first + 1;
      D.second = A.second + 1;

      if(board[A.first][A.second] && board[B.first][B.second]
      && board[C.first][C.second]&& board[D.first][D.second]) cnt++;
    }
  }

  cout<<cnt;
  return 0;
}
