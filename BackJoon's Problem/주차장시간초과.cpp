#include <iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;
using P = pair<int, int>;

int R, C;

char board[50][50];
int lo, hi;

bool parkSelected[100];
bool carSelected[100];
int dst[100][100];
bool visited[100][100];

int numberOfCar;
int numberOfPark;
int result = 49 * 49;

int max(int a, int b) {
  if (a > b) return a;
  return b;
}

int min(int a, int b) {
  if (a > b) return b;
  return a;
}


struct unit {
    int i, j, depth;
};

vector<P> CAR;
vector<P> PARK;

int Di[4] = {-1,
             0,
             1,
             0};

int Dj[4] = {0,
             1,
             0,
             -1};

// 어떤 시작점에서, 어떤 주차지역까지 거리.
queue<unit> Q;

bool getParkingLot(int carIdx, int parkIdx, int limit) {
  if (dst[carIdx][parkIdx] > limit || dst[carIdx][parkIdx] == -1) {
    return false;
  }
  return true;
}

bool isFind = false;

void matchDfs(int limit, int depth) {

  if (isFind) {
    return;
  }

  if (depth == numberOfCar) {
    isFind = true;
    return;
  }
  for (int j = 0; j < numberOfPark; j++) {
    if (getParkingLot(depth, j, limit) && !parkSelected[j] && !isFind) {
      parkSelected[j] = true;
      matchDfs(limit, depth + 1);
      parkSelected[j] = false;
    }
  }
}
//void matchDfs2(int depth) {
//
//  if (isFind) {
//    return;
//  }
//
//  if (depth == numberOfCar) {
//    isFind = true;
//    return;
//  }
//  for (int j = 0; j < numberOfPark; j++) {
//    if (getParkingLot(depth, j, limit) && !parkSelected[j] && !isFind) {
//      parkSelected[j] = true;
//      matchDfs(limit, depth + 1);
//      parkSelected[j] = false;
//    }
//  }
//}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> R >> C;

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'C') {
        CAR.push_back({i, j});
      }
      if (board[i][j] == 'P') {
        PARK.push_back({i, j});
      }
    }
  }

  numberOfCar = CAR.size();
  numberOfPark = PARK.size();
  // 차없는 경우 예외처리
  if (CAR.empty()) {
    cout << 0;
    return 0;
  }

  if (numberOfCar > numberOfPark) {
    cout << -1;
    return 0;
  }

  set<int> s;
  int dstMax = 0;
  for (int i = 0; i < numberOfCar; i++) {
    for (int j = 0; j < numberOfPark; j++) {
      while (!Q.empty()) {
        Q.pop();
      }
      bool find = false;
      memset(visited, 0, sizeof(visited));
      //cout<<"START : "<<CAR[i].first<<" "<<CAR[i].second<<endl;
      //cout<<"END : "<<PARK[j].first<<" "<<PARK[j].second<<endl;
      visited[CAR[i].first][CAR[i].second] = true;
      Q.push(unit{CAR[i].first, CAR[i].second, 0});
      while (!Q.empty()) {
        unit now = Q.front();
        Q.pop();
        if (now.i == PARK[j].first && now.j == PARK[j].second) {
          while (!Q.empty()) {
            Q.pop();
          }
          find = true;
          dst[i][j] = now.depth;
          break;
        }
        for (int d = 0; d < 4; d++) {
          int nextI = now.i + Di[d];
          int nextJ = now.j + Dj[d];
          if (nextI < 0 || nextI >= R || nextJ < 0 || nextJ >= C || visited[nextI][nextJ] ||
              board[nextI][nextJ] == 'X') {
            continue;
          } else {
            visited[nextI][nextJ] = true;
            Q.push(unit{nextI, nextJ, now.depth + 1});
          }
        }
      }
      if (!find) {
        dst[i][j] = -1;
      }
      dstMax = max(dst[i][j], dstMax);
      if( dst[i][j] != -1){
        s.insert(dst[i][j]);
      }
    }
  }
//
//  set<int>::iterator l = s.begin(), r = s.begin();
  bool isResult = false;
//  while(r != s.end()){
//    while(l !=s.end()){
//      lo = *r;
//      hi = *l;
//      isFind = false;
//      memset(parkSelected, 0, sizeof(parkSelected));
//      memset(carSelected, 0, sizeof(carSelected));
//      matchDfs2(0);
//      // 찾으면 lo증가
//      if(isFind){
//        isResult = true;
//        result = min(result, lo);
//        ++r;
//        break;
//      }
//    }
//    // 못찾으면 hi증가
//    ++l;
//  }

  set<int>::iterator l = s.begin(), r = s.begin();
  int left = 0;
  int right = 100;
  while (l != s.end() && !isFind) {
    //  cout << left << " " << right << endl;
    isFind = false;
    memset(parkSelected, 0, sizeof(parkSelected));
    memset(carSelected, 0, sizeof(carSelected));
    int mid = (left + right) / 2;
    matchDfs(*l, 0);
    if (isFind) {
      //   cout << "TRUE" << endl;
      isResult = true;
      right = mid - 1;
      result = min(result, *l);
    } else {
      left = mid + 1;
      ++l;
    }
  }

  if (result == 0 || !isResult) {
    cout << -1;
    return 0;
  }

  cout << result << "\n";
  return 0;
}
//3 13
//.C.P...P.X..P
//XXC......X..P
//XX.....C.....

