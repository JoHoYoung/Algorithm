#include <stdio.h>
#include<stdlib.h>

int SeqSearchCount = 0;
int BinSearchCount = 0;

int seqsearch(int arr[], int len, int key)
{
	int location = -1;

	for (int i = 0; i < len; i++)
	{

		SeqSearchCount++;
		if (key == arr[i])
		{
			location = i;

			return location;
		}

	}

	return location;
}

int BinSearch(int arr[], int key, int start, int end)
{
	int mid = (start + end) / 2;
	BinSearchCount++;

	if (key > arr[end - 1] || key<arr[start])
		return -1;

	if (key == arr[mid])
	{
		return mid;
	}

	if (start == end)
	{
		return -1;
	}
	else if (key > arr[mid])
	{
		BinSearch(arr, key, mid, end);
	}
	else if (key < arr[mid])
	{
		BinSearch(arr, key, start, mid);
	}

}
int main()
{
	int SeqSearchValue;
	int BinSearchValue;
	int input;
	int data[1000];
	for (int i = 0; i < 1000; i++) 
		data[i] = i + 1;
	printf("찾을 값을 입력하세요 => ");
	scanf_s("%d", &input);
	SeqSearchValue = seqsearch(data, 1000, input);
	BinSearchValue = BinSearch(data, input, 0, 1000);

	printf("찾으려고 하는 값은 배열 data의 %d번째에 있군요.\n", BinSearchValue + 1);
	printf("SeqSearch Count : %d \n", SeqSearchCount);
	printf("BinSearch Count : %d  \n", BinSearchCount);


	system("pause");
	return 0;
}