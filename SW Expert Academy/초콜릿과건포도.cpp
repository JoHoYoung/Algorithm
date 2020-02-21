#include <iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int tc;
int n, m;

int board[50][50];

int mapped[51][51][51][51];

int area[51][51];


void calArea() {
  area[0][0] = board[0][0];
  for(int i=1;i<n;i++){
    area[i][0] = area[i-1][0] + board[i][0];
  //  cout<<i<<" BOARD : "<<board[i][0]<<endl;
  }
  for(int j=1;j<m;j++){
    area[0][j] = area[0][j-1] + board[0][j];
  }

  for(int i=1;i<n;i++){
    for(int j=1;j<m;j++){
      area[i][j] = area[i-1][j] + area[i][j-1] - area[i-1][j-1] + board[i][j];
    }
  }
}
int getArea2(int rowStart, int rowEnd, int colStart, int colEnd) {
  int sum = 0;
  for(int i=rowStart; i<=rowEnd;i++){
    for(int j=colStart;j<=colEnd;j++){
      sum += board[i][j];
    }
  }
  return sum;
}
// 0 0 1 3
int getArea(int rowStart, int rowEnd, int colStart, int colEnd){
  if(rowStart == 0 && colStart == 0 ){
    return area[rowEnd][colEnd];
  }else if(rowStart == 0){
    return area[rowEnd][colEnd] - area[rowEnd][colStart-1];
  }else if(colStart == 0) {
    return area[rowEnd][colEnd] - area[rowStart-1][colEnd];
  }else{
  //  cout<<area[rowEnd][colEnd]<<" - "<<area[rowStart-1][colEnd] <<" - "<<  area[rowEnd][colStart-1]<<" + "<<area[rowStart-1][colStart-1]<<endl;
    return area[rowEnd][colEnd] - area[rowStart-1][colEnd] - area[rowEnd][colStart-1] + area[rowStart-1][colStart-1];
  }
}

int cnt  =0;
int sol(int rowStart, int rowEnd, int colStart, int colEnd) {

  int &result = mapped[rowStart][rowEnd][colStart][colEnd];

  if (rowStart == rowEnd && colStart == colEnd) {
    return 0;
  }
  if (result != -1) {
    return result;
  }
  result = 99999999;

  int sum = getArea(rowStart, rowEnd, colStart,colEnd);
  //cout<<rowStart<< " "<<rowEnd<< " "<<colStart<< " "<<colEnd<<endl;
  //cout<<"SUM "<<cnt++ <<" "<<sum<<endl;
  for (int rowPivot = 0; rowStart + rowPivot < rowEnd; rowPivot++) {
    result = min(result, sum + sol(rowStart, rowStart + rowPivot, colStart, colEnd) +
                         sol(rowStart + rowPivot + 1, rowEnd, colStart, colEnd));
  }
  for (int colPivot = 0; colStart + colPivot < colEnd; colPivot++) {
    result = min(result, sum + sol(rowStart, rowEnd, colStart, colStart + colPivot) +
                         sol(rowStart, rowEnd, colStart + colPivot + 1, colEnd));
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> tc;

  for (int t = 0; t < tc; t++) {
    cin >> n;
    cin >> m;

    memset(mapped, -1, sizeof(mapped));
    memset(area, 0, sizeof(area));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> board[i][j];
      }
    }
    calArea();
//    cout<<"ONE"<<endl;
//    cout<<getArea(0,0,1,3)<<endl;
////    cout<<getArea(0,0,0,1)<<endl;
////    cout<<getArea(0,1,0,0)<<endl;
////    cout<<getArea(1,2,2,3)<<endl;
//
//    cout<<"TWO"<<endl;
//    cout<<getArea2(0,0,1,3)<<endl;
////    cout<<getArea2(0,0,0,1)<<endl;
////    cout<<getArea2(0,1,0,0)<<endl;
////    cout<<getArea2(1,2,2,3)<<endl;
////    cout<<getArea()<<endl;
////    cout<<getArea()<<endl;

//    for(int i=0;i<n;i++){
//      for(int j=0;j<m;j++){
//        cout<<area[i][j]<<" ";
//      }
//      cout<<endl;
//    }

    int result = sol(0, n - 1, 0, m - 1);
    cout << "#" << t + 1 << " " << result << endl;
  }
  return 0;
}