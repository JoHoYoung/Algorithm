#include <iostream>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

int tc;
int n, m;

int board[50][50];

int DP[50][50];

int finalResult[50];

int rowSum[50];

int min(int a, int b) {
  if (a < b) {
    return a;
  }
  return b;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> tc;

  // 자르기로 결정한 순간 다 줘야함
  // 한조각이 되는것은 안줘도
  for (int t = 0; t < tc; t++) {
    cin >> n;
    cin >> m;
    for (int i = 0; i < n; i++){
      rowSum[i] = 0;
      for (int j = 0; j < m; j++) {
        cin >> board[i][j];
        rowSum[i] += board[i][j];
      }
      cout<<"Row Sum : "<<rowSum[i]<<endl;
    }
    // 32 + 14 + 15 = 32 + 29 =
    for (int i = 0; i < n; i++) {
      // one row;
      int *target = board[i];
      for (int windowSize = 1; windowSize <= m; windowSize++) {
        for (int startDex = 0; startDex + windowSize -1 < m; startDex++) {
          if (windowSize == 1) {
            DP[startDex][startDex + windowSize - 1] = target[startDex];
            //       cout<<target[startDex]<<endl;
          } else {
            for (int pivot = 1; pivot < windowSize; pivot++) {
              DP[startDex][startDex + windowSize - 1] = min(DP[startDex][startDex + windowSize -1],
                                                            DP[startDex][startDex + pivot -1] +
                                                            DP[startDex + pivot][startDex + windowSize-1]);
            }
          }
        }
      }
      //   cout<<DP[0][m-1]<<endl;
      finalResult[i] = DP[0][m-1];
    }

    for (int i = 0; i < n; i++) {
      // one row;
      int *target = board[i];
      for (int windowSize = 1; windowSize <= m; windowSize++) {
        for (int startDex = 0; startDex + windowSize -1 < m; startDex++) {
          DP[startDex][startDex + windowSize - 1] = 99999999;
          //      cout<<"Window Size " <<windowSize << endl;
          if (windowSize == 1) {
            DP[startDex][startDex + windowSize - 1] = 0;
            // cout<<target[startDex]<<endl;
          } else {

            int sum = 0;
            for(int q = startDex; q<startDex+windowSize; q++){
              sum += target[q];
            }
            //    cout<<"SUM : "<<sum<<endl;
            for (int pivot = 1; pivot < windowSize; pivot++) {

              DP[startDex][startDex + windowSize - 1] = min(DP[startDex][startDex + windowSize -1],
                                                            DP[startDex][startDex + pivot -1] +
                                                            DP[startDex + pivot][startDex + windowSize-1] +sum);
            }
            //      cout<<"Start Dex : "<<startDex<<" End Dex : "<<startDex + windowSize - 1 <<" " <<DP[startDex][startDex + windowSize - 1]<<endl;
          }
        }
      }
      // cout<<endl;
      // cout<<DP[0][m-1]<<endl<<endl;
      finalResult[i] = DP[0][m-1];
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
      int *target = finalResult;
      for (int windowSize = 1; windowSize <= n; windowSize++) {
        for (int startDex = 0; startDex + windowSize -1 < n; startDex++) {
          DP[startDex][startDex + windowSize - 1] = 99999999;
          if (windowSize == 1) {
            DP[startDex][startDex + windowSize - 1] = target[startDex];
          } else {

            int sum = 0;
            for(int q = startDex; q<startDex+windowSize; q++){
              sum += rowSum[q];
            }
            for (int pivot = 1; pivot < windowSize; pivot++) {
              DP[startDex][startDex + windowSize - 1] = min(DP[startDex][startDex + windowSize -1],
                                                            DP[startDex][startDex + pivot -1] +
                                                            DP[startDex + pivot][startDex + windowSize-1] + sum);
            }
          }
        }
      }
      result = DP[0][n-1];
    }
    cout<<"#"<<t+1<<" "<<result<<endl;
  }
  return 0;
}