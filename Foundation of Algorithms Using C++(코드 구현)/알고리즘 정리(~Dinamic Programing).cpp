//BinSearch,피보나치,행렬곱,정렬,버블,인서트,셀렉션,머지,퀵,힙
//지수곱,하노이,파스칼,플로이드,플로이드패스
#include<iostream>
#include<cmath>
using namespace std;

void Swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int BinSearch(int *arr, int head, int rear,int key)
{
	int mid;

	while (1)
	{
		mid = (head + rear)/2;
		if (mid == head || mid == rear)
			return -1;
		if (arr[mid]==key)
			return mid;
		else if (arr[mid] > key)
			rear = mid;
		else if (arr[mid] < key)
			head = mid;		
	}
}

int Recfibonacci(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return Recfibonacci(n - 1) + Recfibonacci(n - 2);
}

int fibonacci(int n)
{
	int Fib[100];
	Fib[0] = 0;
	Fib[1] = 1;

	for (int i = 2; i <= n; i++)
		Fib[i] = Fib[i - 1] + Fib[i - 2];

	return Fib[n];
}
//
//void MatrixMulti(int arr, int brr, int *crr, int n)
//{
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//		{
//			crr[i][j] = 0;
//			for(int k=0;k<n;k++)
//			crr[i][j]+=arr[i][k]*arr[k][j]
//	}
//
//}

void BubbleSort(int *arr, int n)      //%%
{
	for(int i=n-2;i>=0;i--)
		for (int j = 0; j <=i; j++)
		{
			if (arr[j] > arr[j + 1])
				Swap(arr[j], arr[j + 1]);
		}
	
	for (int i = 0; i < n; i++)
		cout << arr[i]<<" ";
}

void InsertionSort(int *arr, int n)
{
	int key;
	int j;
	
	for (int i = 0; i < n-1; i++)
	{
		key = arr[i + 1];
		for (j = i; j >= 0; j--)
		{
			if (arr[j] > key)
			arr[j + 1] = arr[j];
			else break;                     //%% else break 중요.
		}
		arr[j + 1] = key;
	}
}

void SelectionSort(int *arr, int n)
{
	for (int i = n-1; i > 0; i--)
	{	
		int maxdex = 0;

		for (int j = 0; j <= i; j++)
		{
			if (arr[maxdex] < arr[j])
				maxdex = j;
		}
		Swap(arr[maxdex], arr[i]);

	}
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

}
int temp[100];

void Merge(int *arr, int head, int mid, int rear)
{
	int Arr1Idx = head;
	int Arr2Idx = mid + 1;
	int idx = 0;
	for (int i = 0; i <= rear; i++)
	{
		if (Arr1Idx > mid || Arr2Idx > rear)
			break;
		if (arr[Arr1Idx] > arr[Arr2Idx])
			temp[idx++] = arr[Arr2Idx++];
		else temp[idx++] = arr[Arr1Idx++];
	}
	if (Arr1Idx > mid)
	{
		for (int i = Arr2Idx; i <= rear; i++)
			temp[idx++] = arr[i];
	}
	else
	{
		for (int i = Arr1Idx; i <= mid; i++)
			temp[idx++] = arr[i];
	}

	for (int i = 0; i <idx; i++)
		arr[head++] = temp[i];
}

void MergeSort(int *arr, int head, int rear)
{
	int mid = (head + rear) / 2;

	if (head<rear)                                    //%% 엥간하면 와일문을 쓰자. 그리고 이부분 틀림.
	{
		MergeSort(arr, head, mid);
		MergeSort(arr, mid + 1, rear);
		Merge(arr, head, mid, rear);
	}
}

int Partition(int *arr, int head, int rear) //다시공부.
{
	int pivot = arr[rear];
	int tempdex = head;
	for (int i = head; i < rear; i++)
	{
		if (arr[i] <= pivot)
			Swap(arr[i], arr[tempdex++]);

	}
	Swap(arr[tempdex], arr[rear]);
	return tempdex;
}

int Partition(int *arr, int head, int rear)
{
	int pivot = arr[rear];
	int tempdex = 0;
	for(int i=head;i<rear;i++)
	{
		if(arr[i]<=pivot)
			swap(arr[i],arr[tempdex++])
	}
	swap(arr[i],arr[tempdex])
		return tempdex
}

void QuickSort(int *arr, int head, int rear)
{
	if (head < rear)
	{
		int pivvotPoint = Partition(arr, head, rear);

		QuickSort(arr, head, pivvotPoint - 1);
		QuickSort(arr, pivvotPoint + 1, rear);
	}
}

void heapify(int *arr, int n)
{
	int root;
	for (int i = 2; i <=n; i++)
	{
		int k = i;
		while (k != 1)
		{
			root = (int)floor(k / 2);

			if (arr[root] > arr[k])
			{
				Swap(arr[root], arr[k]);
			}
			else {
				break;                                //%% 엘스 -> 브레이크 구문 중요.
			}
			k = root;
		}
	}
}

void BuildHeap(int *arr, int n)
{
	heapify(arr, n);

}
void HeapSort(int* arr,int n)
{
	BuildHeap(arr, n);
	for (int i = n; i > 0; i--)
	{
		Swap(arr[1], arr[i]);
		heapify(arr, i - 1);

	}

}

void heapSort(int S[], int n)
{
	buildHeap(S, n);
	for (int i = n; i > 0; --i)
	{
		swap(S[0], S[i]);
		heapify(S, 0, i - 1);
	}
}

void buildHeap(int S[], int n)
{
	for (int i = n / 2; i >= 0; --i)
		heapify(S, i, n);
}

void heapify(int S[], int k, int n)
{
	int left, right;
	left = 2 * k + 1; right = 2 * k + 2;
	int smaller;
	if (right <= n)
	{
		if (S[left] < S[right]) smaller = left;
		else smaller = right;
	}
	else if (left <= n) smaller = left;
	else return;

	if (S[smaller] < S[k])
	{
		swap(S[k], S[smaller]);
		heapify(S, smaller, n);
	}
}

//void Floyd()
//{
//
//	for(k=0;i<n;k++)
//		for(int i=0;i<n;i++)
//			for (int j = 0; j < n; j++)
//			{
//				if (D[i][j] > D[i][k] + D[k][j])
//				{
//					D[i][j] = D[i][k] + D[k][j];
//					Path[i][j] = k;
//				}
//			}
//
//}
//path(int s, int d)
//{
//	if (Path[s][d] == NULL)
//		cout << s << "-->" << d << endl;
//	else
//	{
//		path(s, Path[s][d]);
//		path(Path[s][d], d);
//
//	}
//}
int bin(int n, int k)
{
	if (n == k || k == 0 || n == 0)
		return 1;
	else
		return bin(n - 1, k - 1) + bin(n - 1, k);

}
void bin2(int n, int k)
{
	int **arr;
	arr = new int*[n + 1];
	for (int i = 0; i <= n; i++)
		arr[i] = new int[k + 1];

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n&&j<=i; j++)
		{
			if (i == j || i == 0 || j == 0)
				arr[i][j] = 1;
			else
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}

}

void bin3(int n, int k)
{
	int *arr;
	arr = new int[n + 1];
	int temp;
	int temp2 = 1;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < n; j ++ )
		{
			if (i == j || i == 0 || j == 0)
				arr[i] = 1;
			else
			{
				temp = arr[i][j];
				arr[i][j] += temp2;

			}
			temp2 = temp;
		}
		return arr[k];
	}
}/* 시간복잡도는 j가 0부터 k-1까지일 때는 1번.........k번.
k부터 n까지는 k+1번 즉 k(k+1)/2 +(n-k+1)(k+1)*/
void main()
{
	int Binarr[10] = { 1,3,4,5,8,11,13,18,19,23 };
	int Sortarr[10] = { 7,1,29,13,22,10,2,3,40,30 };
	int Heaparr[10]= { -1,1,29,13,22,10,2,3,40,30 };
	HeapSort(Heaparr,9);
	for (int i = 1; i < 10; i++)
		cout << Heaparr[i] << " ";
	//cout<<BinSearch(Binarr, 0, 9,15);
	system("pause");

}



int Exponential(int base, int exponent)
{
	if (exponent == 1)
		return base;
	else if (exponent % 2)
		return Exponential(base*base, exponent / 2)*base;
	else
		return Exponential(base*base, exponent / 2);
}

