#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

int APower(int N, int p)
{
	if (p == 0)
		return 1;
	if (p == 1)
		return N;
	if (p % 2 == 0)
	{
		return APower(N, p / 2)*APower(N, p / 2);
	}
	else {
		return APower(N, (p - 1) / 2)*APower(N, (p - 1) / 2)*N;
	}
}

void hanoi(int n,int start,int destination,int node)
{
	if (n == 1)
		cout << start << " ---> " << destination << endl;
	else
	{
		hanoi(n - 1, start, node, destination);
		cout<< start << " ---> " << destination << endl;
		hanoi(n - 1, node, destination, start);
	}
}

																

int main()
{
	hanoi(5, 1, 3, 2);
	system("pause");
}