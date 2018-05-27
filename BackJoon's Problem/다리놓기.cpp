//문제 1010
//
//재원이는 한 도시의 시장이 되었다.이 도시에는 도시를 동쪽과 서쪽
//으로 나누는 큰 강이 흐르고 있다.하지만 재원이는 다리가 없어
//서 시민들이 강을 건너는데 큰 불편을 겪고 있음을 알고 다리를
//짓기로 결심하였다.강 주변에서 다리를 짓기에 적합한 곳을 사이트
//라고 한다.재원이는 강 주변을 면밀히 조사해 본 결과 강의 서쪽에
//는 N개의 사이트가 있고 동쪽에는 M개의 사이트가 있다는 것을 알았다. (N ≤ M)
//
//재원이는 서쪽의 사이트와 동쪽의 사이트를 다리로 연결하려고 한
//다. (이때 한 사이트에는 최대 한 개의 다리만 연결될 수 있다.) 
//재원이는 다리를 최대한 많이 지으려고 하기 때문에 서쪽의 사이
//트 개수만큼(N개) 다리를 지으려고 한다.다리끼리는 서로 겹쳐질 
//수 없다고 할 때 다리를 지을 수 있는 경우의 수를 구하는 프로그램을 작성하라.

#include<iostream>
using namespace std;

int Brg[30][30];

void Bridge(int N, int M)
{
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			if (i == j)
				Brg[i][j] = 1;
			else if (i == 1)
			{	
				Brg[i][j] = j;
			}
			else
			{	
				Brg[i][j] = 0;
				for (int k = 1; j - k >= i - 1; k++)
					Brg[i][j] += Brg[i - 1][j - k];
			}

		}

	cout << Brg[N][M] << endl;
}

int main()
{
	int n;
	int **arr;
	cin >> n;
	arr = new int*[n];


	for (int i = 0; i < n; i++)
		arr[i] = new int[2];
	
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i][0];
		cin >> arr[i][1];
	}
	for (int i = 0; i < n; i++)
	{
		Bridge(arr[i][0], arr[i][1]);
	}
	system("pause");
	return 0;
}