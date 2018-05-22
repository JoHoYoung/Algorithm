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
		cin >> W >> H >> N;

		room = (H%N) * 100 + H / N;
	}
	cout << room;
	system("pause");
}