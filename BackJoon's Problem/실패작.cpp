#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int M, N,x,y,diff,tempdiff,solution;
	cin >> M >> N >> x >> y;

	diff = abs(M - N);
	if (abs(x - y) % diff != 0)
		return -1;

	tempdiff = abs(x - y);
	
	if (M < N)
	{
		
		solution = (tempdiff / diff) * M + x;
	}
	else if (M > N)
	{
		solution = (tempdiff / diff) * N + (y - 1);
	}

	cout << "ASA : " << (tempdiff / diff) * M+x << endl;
	cout << solution;
	system("pause");
}