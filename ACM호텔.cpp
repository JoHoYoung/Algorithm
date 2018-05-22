#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main()
{
	int TestNum;
	int W, H, N;
	int room;
	cin >> TestNum;
	for (int i = 0; i < TestNum; i++)
	{
		cin >> H >> W >> N;

		room = (N%H) * 100 + N / W+2;
		cout << room;
	}
	cout << room;
	system("pause");
}