//���� 1699 ����
//� �ڿ��� N�� �׺��� �۰ų� ���� ���������� ������ ��Ÿ�� �� �ִ�.
//���� ��� 11=32+12+12(3�� ��)�̴�.
//�̷� ǥ������� ���� ������ �� �� �ִµ�, 11�� ��� 11=22+22+12+12+12(5�� ��)��
//�����ϴ�. �� ���,
// ������ ��ũ���׽��� ��11�� 3�� ���� ������ ������ ǥ���� �� �ִ�.����� ���Ѵ�.
//���� 11�� �׺��� ���� ���� ������ ������ ǥ���� �� �����Ƿ�,
//11�� �� �����ν� ǥ���� �� �ִ� ������ ���� �ּ� ������ 3�̴�.
//
//�־��� �ڿ��� N�� �̷��� ���������� ������ ǥ���� ����
//�� ���� �ּҰ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

#include<iostream>

using namespace std;
int DP[1000001];
int Largest(int n,int depth)
{
    int i=0;
    while(i*i<=n)
        i++;

    i-=1;
    return i-depth;
}

int main()
{
    int N;
    int count=0;

    DP[0]=0;
    DP[1]=1;
    DP[2]=2;
    int depth=0;
    for(int N=1;N<=300;N++){
    int min=100000;
    if((N-Largest(N,depth)*Largest(N,depth))==0)
        min = 1;
        else {
            min = 100000;

            int pivot = Largest(N, 0);
            for (int j = 0; j < pivot; j++) {
                int temp = N;
                count = 0;

                while (temp != 0) {
                    int k = Largest(temp, depth);
                    if (Largest(temp, depth) == (pivot))
                        k -= j;

                    if (Largest(temp, depth) >= pivot - j)
                        k = pivot - j;
                    temp -= k * k;
                    count++;
                }
                if (count < min && count != 0
                    min = count;
            }
        }
        cout<<"N�� "<<N<<"�϶�"<<min<<endl;
    }return 0;

}