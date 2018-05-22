#include<iostream>
#include<string>
using namespace std;

int NumofFamily(int H, int W)
{
	int sum = 0;
	if (W == 1)
		return 1;
	else if (H == 0)
		return W;
	else
	{
		for (int i = 1; i <= W; i++)
			sum += NumofFamily(H - 1, i);
	}
	return sum;

}

int main()
{
	int testcase, H, W;
	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		cin  >> H >> W;
		cout << NumofFamily(H, W);
	}system("pause");
}