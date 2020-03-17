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

int N, K;

//지각 두번이상, 결석 세번연속 :
//지각 두번이상, 결석 세번연속
// 특정 일에서, 지각 몇번으로, 개근을 받을 수 있는 경우를 메모
int DP[1001][2][1<<2];

// trace는 현재까지 연속 결석
int sol(int day, int num, int trace) {

  // 2회이상 지각
  if(num == 2) return 0;
  // 3연 결석
  if(trace == ((1<<3)-1)) return 0;
  if(day == N) return 1;

  int &ref = DP[day][num][trace];
  if(ref != -1) return ref;

  ref = 0;
  trace = (trace<<1);

  // 내일 지각
  ref += sol(day + 1, num + 1, 0);
  // 내일 결석
  ref += sol(day + 1, num, trace | 1);
  // 내일 출근
  ref += sol(day + 1, num, 0);
  ref %= MAX;
  return ref;

}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  memset(DP, -1, sizeof(DP));
  cout<<sol(0,0,0);
  return 0;
}

