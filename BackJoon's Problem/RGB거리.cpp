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