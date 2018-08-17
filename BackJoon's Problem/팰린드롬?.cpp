//���� 10942 �Ӹ����?
//���� ȫ���̿� �Բ� �Ӹ���� ���̸� �غ����� �Ѵ�.
//
//����, ȫ���̴� �ڿ��� N���� ĥ�ǿ� ���´�. �� ����, ��쿡�� ������ �� M�� �Ѵ�.
//
//�� ������ �� ���� S�� E�� ��Ÿ�� �� ������, S��° ������ E��° ���� ���� �Ӹ������ �̷������ �����,
// ���� �� ������ ���� �Ӹ�����̴� �Ǵ� �ƴϴٸ� ���ؾ� �Ѵ�.
//
//���� ���, ȫ���̰� ĥ�ǿ� ���� ���� 1, 2, 1, 3, 1, 2, 1��� ����.
//
//S = 1, E = 3�� ��� 1, 2, 1�� �Ӹ�����̴�.
//S = 2, E = 5�� ��� 2, 1, 3, 1�� �Ӹ������ �ƴϴ�.
//S = 3, E = 3�� ��� 1�� �Ӹ�����̴�.
//S = 5, E = 7�� ��� 1, 2, 1�� �Ӹ�����̴�.
//�ڿ��� N���� ���� M���� ��� �־����� ��, ����� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

#include<iostream>
using namespace std;

int DP0[10001][1005]; //Ȧ������ ��� i��°�� pivot..�̰� �� ���̰� ...�ι�°�ΰ� �Ӹ�����ΰ�.
int DP1[10001][1005]; //¦������ ��� i��°, i+1��°�� pivot �̰�.. �ѱ��̰� �ι�°�ΰ� �Ӹ�����ΰ�.
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
        length=E-S+1; //���̰� Ȧ���� ���, ¦���� ���� ������ ����Ƚ���� Ȧ���ΰ�� (���� -1)/2
                     // ¦���ΰ�� ����Ƚ���� ����-2/2
                 if(length==1)
                {DP0[E][1]=true;
                 result[i+1]=true;
                }
        else if(length%2==1)                 // ���̰� Ȧ���� ���
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
        else{                           // ¦���� ���
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