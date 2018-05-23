#include<iostream>

using namespace std;



void MatrixMulti(int n, const int Arr1[3][3], const int Arr2[3][3], int Arr3[3][3])
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			Arr3[i][j] = 0;
			for(int k=0;k<n;k++)
			Arr3[i][j] += Arr1[i][k] * Arr2[k][j];
		}
}

int main()
{
	const int a[3][3] = { {1,2,3},{4, 5, 6}, {7, 8, 9} };
	const int b[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int c[3][3];

	MatrixMulti(3, a, b, c);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cout << c[i][j] << endl;
	system("pause");

}
//--------------------------------------피보나치----------------------------------------------
//#include<iostream>
//
//using namespace std;
//
//
//
//int Fibonacci(int n)
//{
//	int f[500];
//	int INDEX = 0;
//	f[0] = 0;
//	f[1] = 1;
//
//	for (int i = 2; i <= n; i++)
//	{
//		f[i] = f[i - 1] + f[i - 2];
//	}
//
//	return f[n];
//}
//
//int main()
//{
//
//	cout << Fibonacci(46);
//	system("pause");
//-----------------------------------피보나치 재귀-----------------------------------------
//#include<iostream>
//using namespace std;
//
//int fib(int n)
//{
//	if (n == 0)
//		return 0;
//	else if (n == 1)
//		return 1;
//	else return fib(n - 1) + fib(n - 2);
//
//}
//}
//------------------------------------------Sort--------------------------------------------------
//#include<iostream>
//using namespace std;
//
//void ExchangeSort(int n, int arr[])
//{
//	int temp;
//	for (int i = 0; i < n; i++)
//		for (int j = i + 1; j < n; j++)
//		{
//			if (arr[i]>arr[j])
//			{
//				temp = arr[i];
//				arr[i] = arr[j];
//				arr[j] = temp;
//			}
//		}
//
//}
//
//int main()
//{
//	int arr[8] = { 10,14,2,30,5,8,1,19 };
//
//	ExchangeSort(8, arr);
//
//
//	for (int i = 0; i < 8; i++)
//		cout << arr[i] << " ";
//	system("pause");
//}