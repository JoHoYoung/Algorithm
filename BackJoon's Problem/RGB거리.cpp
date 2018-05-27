//문제 1149
//RGB거리에 사는 사람들은 집을 빨강, 초록, 파랑중에 하나로 칠하려고 한다.
//또한, 그들은 모든 이웃은 같은 색으로 칠할 수 없다는 규칙도 정했다.
//집 i의 이웃은 집 i - 1과 집 i + 1이다.처음 집과 마지막 집은 이웃이 아니다.
//
//각 집을 빨강으로 칠할 때 드는 비용, 초록으로 칠할 때 드는 비용,
//파랑으로 드는 비용이 주어질 때, 모든 집을 칠할 때 드는 비용의 
//최솟값을 구하는 프로그램을 작성하시오.

#include <iostream>
#include<algorithm>
using namespace std;

int MIN(int a, int b)
{
	if (a < b)
		return a;
	else return b;
}

int main()
{
	int HouseNum;
	cin >> HouseNum;

	int **arr;
	arr = new int*[HouseNum];
	for (int i = 0; i < HouseNum; i++)
		arr[i] = new int[3];

	for (int i = 0; i < HouseNum; i++)
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
		}

	for (int i = 0; i < HouseNum - 1; i++)
	{
		arr[i + 1][0] += MIN(arr[i][1], arr[i][2]);
		arr[i + 1][1] += MIN(arr[i][0], arr[i][2]);
		arr[i + 1][2] += MIN(arr[i][1], arr[i][0]);
	}
	cout << MIN(arr[HouseNum - 1][0], MIN(arr[HouseNum-1][1], arr[HouseNum-1][2]));

	system("pause");
	return 0;

}