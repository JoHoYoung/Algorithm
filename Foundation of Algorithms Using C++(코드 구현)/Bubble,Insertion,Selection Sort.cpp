#include<iostream>

using namespace std;


void SelectionSort(int* arr, int num)
{
	int temp;
	for (int i = num - 1; i >= 0; i--)
	{
		int maxdex = 0;
		for (int j = 0; j <= i; j++)
		{
			if (arr[maxdex] < arr[j])
				maxdex = j;
		}
		temp = arr[i];
		arr[i] = arr[maxdex];
		arr[maxdex] = temp;

	}
}

void BubbleSort(int *arr, int num)
{
	int temp;
	bool issorted = true;
	for (int i = 0; i < num - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			issorted = false;
		break;
	}
	if (!issorted)
	{
		for (int i = num - 2; i >= 0; i--)
		{
			for (int j = 0; j <= i; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
}

void InsertionSort(int *arr, int num)
{
	int key;
	int j;
	for (int i = 0; i < num - 1; i++)
	{
		key = arr[i + 1];

		for (j = i; j >= 0; j--)
		{
			if (arr[j] > key)
			{
				arr[j + 1] = arr[j];
			}
			else {

				break;
			}
		}
		arr[j + 1] = key;
	}

}



int main()
{
	int arr[10] = { 29,18,3,6,40,28,30,45,10,39 };
	BubbleSort(arr, 10);
	for (int i = 0; i < 10; i++)
		cout << arr[i] << endl;

	system("pause");

}