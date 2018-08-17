//문제 10942 팰린드롬?
//명우는 홍준이와 함께 팰린드롬 놀이를 해보려고 한다.
//
//먼저, 홍준이는 자연수 N개를 칠판에 적는다. 그 다음, 명우에게 질문을 총 M번 한다.
//
//각 질문은 두 정수 S와 E로 나타낼 수 있으며, S번째 수부터 E번째 까지 수가 팰린드롬을 이루는지를 물어보며,
// 명우는 각 질문에 대해 팰린드롬이다 또는 아니다를 말해야 한다.
//
//예를 들어, 홍준이가 칠판에 적은 수가 1, 2, 1, 3, 1, 2, 1라고 하자.
//
//S = 1, E = 3인 경우 1, 2, 1은 팰린드롬이다.
//S = 2, E = 5인 경우 2, 1, 3, 1은 팰린드롬이 아니다.
//S = 3, E = 3인 경우 1은 팰린드롬이다.
//S = 5, E = 7인 경우 1, 2, 1은 팰린드롬이다.
//자연수 N개와 질문 M개가 모두 주어졌을 때, 명우의 대답을 구하는 프로그램을 작성하시오.

#include<iostream>
using namespace std;

int DP0[10001][1005]; //홀수개인 경우 i번째가 pivot..이고 총 길이가 ...두번째인게 팰린드롬인가.
int DP1[10001][1005]; //짝수개인 경우 i번째, i+1번째가 pivot 이고.. 총길이가 두번째인게 팰린드롬인가.
int main()
{
    int N;
    cin>>N;
    int *Arr;
    Arr=new int[N+1];

    for(int i=1;i<=N;i++)
        cin>>Arr[i];

    int result[N+1];
    int test;
    cin>>test;
    bool is;


    int length;
    for(int i=0;i<test;i++) {
        result[i+1]=1;
        is=true;
        int S, E;
        cin >> S;
        cin >> E;
        length=E-S+1; //길이가 홀수인 경우, 짝수인 경우로 나누자 시행횟수는 홀수인경우 (길이 -1)/2
                     // 짝수인경우 시행횟수는 길이-2/2
                 if(length==1)
                {DP0[E][1]=true;
                 result[i+1]=true;
                }
        else if(length%2==1)                 // 길이가 홀수인 경우
        {
            int loop=(length-1)/2;
            int pivot = (S+E)/2;
            int nowlength=1;
            int idx=1;
            for(int k=1;k<=loop;k++)
            {
                if(DP0[pivot][nowlength]==true||nowlength==1)
                {
                    DP0[pivot][1]=true;
                    if(Arr[pivot-idx]==Arr[pivot+idx]) {
                        result[i + 1] = 1;
                        DP0[pivot][nowlength+2]=true;
                    }else {
                        result[i+1]=0;
                        DP0[pivot][nowlength+2]=false;
                        break;
                    }

                }
                else {result[i+1]=0;
                DP0[pivot][nowlength+2]=false;
                    break;
                }
                idx++;
                nowlength+=2;
            }
        }
        else{                           // 짝수인 경우
            int loop=(length-2)/2;
            int pivot=(S+E-1)/2;
            int nowlength=2;
            int idx=1;
            if(Arr[pivot]==Arr[pivot+1]) {
                DP1[pivot][2] = true;
                result[i+1]=1;
            }
            else result[i+1]=0;

            for(int k=1;k<=loop;k++)
            {
                if(DP1[pivot][nowlength]==true)
                {
                    if(Arr[pivot-idx]==Arr[pivot+1+idx]) {
                        result[i + 1] = 1;
                        DP1[pivot][nowlength+2]=true;
                    }else {
                        result[i+1]=0;
                        DP1[pivot][nowlength+2]=false;
                        break;
                    }

                }
                else {result[i+1]=0;
                DP1[pivot][nowlength+2]=false;
                    break;
                }
                idx++;
                nowlength+=2;
            }

        }

    }

    for(int i=1;i<=test;i++)
        cout<<result[i]<<endl;

    return 0;
}