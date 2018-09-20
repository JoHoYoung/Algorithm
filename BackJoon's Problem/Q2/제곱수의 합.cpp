//문제 1699 점프
//어떤 자연수 N은 그보다 작거나 같은 제곱수들의 합으로 나타낼 수 있다.
//예를 들어 11=32+12+12(3개 항)이다.
//이런 표현방법은 여러 가지가 될 수 있는데, 11의 경우 11=22+22+12+12+12(5개 항)도
//가능하다. 이 경우,
// 수학자 숌크라테스는 “11은 3개 항의 제곱수 합으로 표현할 수 있다.”라고 말한다.
//또한 11은 그보다 적은 항의 제곱수 합으로 표현할 수 없으므로,
//11을 그 합으로써 표현할 수 있는 제곱수 항의 최소 개수는 3이다.
//
//주어진 자연수 N을 이렇게 제곱수들의 합으로 표현할 때에
//그 항의 최소개수를 구하는 프로그램을 작성하시오.

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
        cout<<"N가 "<<N<<"일때"<<min<<endl;
    }return 0;

}