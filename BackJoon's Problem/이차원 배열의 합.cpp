//문제 2167 이차원 배열의 합
//2차원 배열이 주어졌을 때 (i, j) 위치부터 (x, y) 위치까지에 저장되어 있는 수들의 합을 구하는 프로그램을 작성하시오. 배열의 (i, j) 위치는 i행 j열을 나타낸다.


#include <iostream>
#include <algorithm>
using namespace std;


int arr[301][301];
int DP[301][301];

int main()
{
    int N,M;
    cin>>N;
    cin>>M;

    for(int i=0;i<N;i++) {
        for (int j = 0; j < M; j++) {

            cin >> arr[i][j];
            if (j == 0) {
                DP[i][j] = arr[i][j];
            } else {
                DP[i][j] = DP[i][j - 1] + arr[i][j];
            }

        }
    //    cout<<DP[2][0]<<endl;
    }

    int T;
    cin>>T;

    int *result = new int[T];
    int **test = new int*[T];
    for(int i=0;i<T;i++)
        test[i] =  new int[4];


    for(int i=0;i<T;i++)
    {
        cin>>test[i][0];
        cin>>test[i][1];
        cin>>test[i][2];
        cin>>test[i][3];

    }

    for(int k=0;k<T;k++)
    {
        int i,j,x,y;

        i = test[k][0];
        j = test[k][1];
        x = test[k][2];
        y = test[k][3];

        result[k] = 0;

        for(int c=i-1;c<=x-1;c++)
        {
           // cout<<"Times : "<<c<<endl;
            if(j==1)
            {
          //      cout<<"DP["<<y-1<<"]["<<c<<"] : "<<DP[y-1][c]<< " "<<endl;
                result[k] += DP[c][y-1];
            }else{
           result[k] += DP[c][y-1]-DP[c][j-2];

            }
        //    cout<<result[k];
        }


    }
    for(int i=0;i<T;i++)
        cout<<result[i]<<endl;
    return 0;
}