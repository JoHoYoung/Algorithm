//----------------------------------------------------------------Basic Setting ( library, SwapFunction ) --------------------------------------------------//
#include<iostream>
#include<cmath>
using namespace std;


void Swap(int &a, int &b)
{
	int temp;
	temp = b;
	b = a;
	a = temp;
}
//-----------------------------------------------------------------------MergeSort ( Ascending Power )------------------------------------------------------------------//
//  MergeSort : �������� ������ -> ���� �κ� ������ Sorting�Ѵ�. -> Sorting �� �κ��� ��ģ��.																				  //
//  Merge : ��ġ�� ���� �Լ�																																									  //
//  MergeSort : �������� ������ -> ��������� �κ��� ��� ����� Merge�� ��ħ                                                                                             //
//  �������� ������ ���ĵ� �� �κ��� ��ĥ�� ���ο� �迭�� ����� ������ �κ��� �������� �Ҵ��Ͽ� ������� ���ο� �迭�� ����                                 //
//  ���ο� �迭�� ����������� ���� �κ��� ������ ��� ���ο� �迭�� �Ҵ�Ǹ�, �ٸ��� �κ��� ���� ������ ���ο� �迭�� ���������� ����                    // 
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void Merge(int *arr, int start, int mid, int end)       // Function for Merge
{
	int INDEX = 0;
	int Ar1Index = start;
	int Ar2Index = mid + 1;
	int *temp = new int[end - start + 1];
	while (Ar1Index <= mid && Ar2Index <= end)
	{
		if (arr[Ar1Index] < arr[Ar2Index])
			temp[INDEX++] = arr[Ar1Index++];
		else temp[INDEX++] = arr[Ar2Index++];
	}

	if (Ar1Index > mid)
	{
		while (Ar2Index <= end)
			temp[INDEX++] = arr[Ar2Index++];
	}
	else
	{
		while (Ar1Index <= mid)
			temp[INDEX++] = arr[Ar1Index++];
	}

	for (int i = 0; i < INDEX; i++)           
		arr[start++] = temp[i];
}

void MergeSort(int *arr, int head, int rear)       // MergeSort Using Merge Function
{
	int midpoint = (head + rear) / 2;

	if (head < rear)
	{
		MergeSort(arr, head, midpoint);
		MergeSort(arr, midpoint + 1, rear);
		Merge(arr, head, midpoint, rear);
	}
}

//------------------------------------------------------------------------QuickSort ( Ascending Power )------------------------------------------------------------------//
//		*QuickSort : Pivot�� Sorting�� �迭�� �Ǿ��� ���ҷ� ����, Partition �Լ��� ����Ͽ� Sorting �Ǿ��� �� Pivot�� �� �ε����� ��ȯ�Ͽ� �� �ε����� ����//
//  ���� �� �κ����� ���� ->  ������ �� �κ��� ���� �Ǿ��� ���Ҹ� Pivot���� ���� �� Partition�Լ��� ����Ͽ� ���� Pivot�� �� �ε����� ���Ͽ� �Ǵٽ�  //
//  �� �ε����� �������� �������� ���� �Ȱ��� ���� ��������� ����																												  //
//		*Partition : �迭�� �� �պκ��� Pivot, �񱳸� ������ ��ġ�� head������ ����, temppivotdex �� ���� head�� ����     												  //
//  -> i = head+1���� for���� ����Ͽ� rear���� arr[head+1]���� pivot���� �� -> pivot�� ����  arr[i]���� ������, head������ �����Ͽ��� ->                 //
//  temppivotdex���� +1�� ���־� Swap. -> pivot���� ���� ���ϰ�� �ڷ� �����ʰ� �� ��ġ ����( �տ��� ū���� ������ �ʾ��� ��츸                           //
//  �տ��� pivot���� ū ���� ������ ��� �ƹ��� ������ ��ġ�� �ʰ� ����ġ�µ� �̷���� �� ū���ں��� ���ڸ� �տ� temppivotdex���� ���� �Ǿ��־�      //
//  pivot���� ���� ���� ������ ��� ����ģ ū ���� ���� ���� Swap�Ǵ� �ۿ��� �Ͼ Swap(arr[++temppivotdex], arr[i]) �ڵ��� �̷��� ������ �ϰ� ��     //
//		ū���� ������ ����ġ�� ���߿� �������� ����ģ ū���� ������ ���� �� ���� ��� -> ū���� �� ���� ���������Ƿ� �� ū������ �ڷ� ���Եǰ�, �������� //
//  ������ �´� . �������ڿ��� ū���ۿ� �� �� ����.
//		ū���� ������ ����ġ�� ���߿� ��������  ����ģ ū���� ������ ���� ���� ��� -> ������ ���� ū�� ���� ��ŭ ū������ �ڷ� �и��� �ڿ� ���� ������  //
//  ��ġ�ϰ� �ȴ�. ex) [10, 1(������ �� ������), 2(������ �� ������), 20, 30, 3, 4 ,5 ] �� �߰��������� temppivotdex�� ū���� 20 �� �� 2(������ �� ������  //
//  �� �ӹ��� �����Ƿ� �� ū���� �׳� ����ġ�� �ǰ� �� �� ū�� ������ŭ ū ������ �ڷ� ���� �ȴ� .                                                                      //
//  [10, 1(������ �� ������), 2(������ �� ������), 3(������ �� ������), 4(������ �� ������)] , 20 , 30, 5 ] ���⼭�� ���� temppivotdex�� 20 �� �� 4��        //
//  �ӹ����� �ǰ� ������ ��� �ݺ��ϴٺ��� ����ġ�� ū������ ���� �����ִ� ���������� ������ �۰Եǰ� ���� �� ��츦 �ݺ��ϸ� Sorting �� �Ϸ�ȴ�. //
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

int Partition(int *arr, int head, int rear)                      // Function for Partition 
{
	int pivot = arr[head];
	int temppivotdex = head;
	for (int i = head + 1; i <= rear; i++)
	{
		if (arr[i] <= pivot)
		{
			Swap(arr[++temppivotdex], arr[i]);
		}
	}
	Swap(arr[head], arr[temppivotdex]);
	return temppivotdex;
}

void QuickSort(int *arr, int head, int rear)     // QuickSort using partition
{
	int pivotdex;
	if (head < rear)
	{
		pivotdex = Partition(arr, head, rear);
		QuickSort(arr, head, pivotdex - 1);       
		QuickSort(arr, pivotdex + 1, rear);
	}
}
//-------------------------------------------------------HeapSort ( Ascending Power, Descending Power )-----------------------------------------------------------//
//  MinHeap, MaxHeap : ���ǰ� (�θ���)�� �Ʒ���(�ڽĳ��) ���� ũ�ų� ���� ����Ʈ�� MinHeap : �θ��尡 �� ���� MaxHeap : �θ��尡 �� ŭ      //
//  ����Ʈ�� : �ڽ��� �ΰ�, Ʈ���� ���°� ���ʺ��� ���ʴ�� �Ǿ� �ִ°�
//  Ʈ���� �迭�� ���·� ��Ÿ���� 
//  �θ����� �ε����� K�� ��� �ڽĳ�� : 2K, 2K+1      &&   �ڽĳ���� �ε����� K�� ��� �θ��� : K/2
//  Ʈ���� ����� �ڽĳ�忡�� ���� �������� ������ �񱳿���, ������ �����Ұ�� SWAP �ϸ� �ö󰡴µ� SWAP ������� ���� �ڽĳ���� �ε����� //
//  2/K�� �ٲٰ� �θ����� ���� �׿��°� �ٲ��־�� �Ѵ�. ���찡 ������ �𸣴� ������ ������ �����Ұ�� �������� ������ ��, SWAP������ �ϰ�//
//  �ڵ��� ���ش�. �ڵ��� �θ��� == 0 �϶� ���� �� ���ָ� �ȴ�. 
//  Max, Min Heap�� ���� ����, ������������ Sorting �� �� �ִ�. ������ ��尪�� ���� ũ�ų�, ���� ���� ���̹Ƿ� ������ ��� ���� �迭�� �� ������ ��//
//  �� Swap�� ���ش�. �׷��ٸ� �迭�� �� ������������ Sorting�� ���� ���� �ǹǷ� �迭�� �Ǹ����� ���� �ٽ� Heap�� ������ �ʿ䰡 ����. ������ ��尪�� �迭�� �� ������ ��//
//  �� Swap�� �� ���� Heap�� Max, �Ǵ� Min Heap�� �ƴϹǷ� �ٽ� Heap�� ������ش�. �̶� �迭�� �Ǹ����� ���� Sorting�� �Ϸ��� ���̹Ƿ� �� ���� ���� //
//  �ϰ� Heap�� ����� �ش�.
//  �� ������ ��� �ݺ��ϸ� Sorting�� �Ϸ�ȴ�.
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------//



//-----------------------------------------------------Ascending Power using MaxHeap--------------------------------------------------------------//

void MaxHeapBuild(int *arr, int head, int rear)                   // Function for MaxHeapBuilding
{
	for (int i = head + 1; i <= rear; i++)
	{
		int k = i;
		while (k != 0)
		{
			int root = (int)floor((k - 1) / 2);
			if (arr[root] < arr[k])
			{
				Swap(arr[root], arr[k]);
			}
			else {
				break;
			}
			k = root;
		}
	}
}

void AscendingHeapSort(int *arr, int head, int rear)            // AscendingHeapsort using Maxheap
{
	MaxHeapBuild(arr, head, rear);
	for (int i = rear; i >= 1; i--)
	{
		Swap(arr[0], arr[i]);
		MaxHeapBuild(arr, head, i - 1);
	}
}

///------------------------------------------------------------------Descending Power using Minheap------------------------------------------------------------//

void MinHeapBuild(int *arr, int head, int rear)                          // Function for building MinHeap
{
	for (int i = head + 1; i <= rear; i++)
	{
		int k = i;
		while (k != 0)
		{
			int root = (int)floor((k - 1) / 2);
			if (arr[root] > arr[k])
			{
				Swap(arr[root], arr[k]);
			}
			else { break; }
			k = root;
		}
	}
}

void DescendingHeapSort(int *arr, int head, int rear)                 // DescendingHeapSort using MinHeap
{
	MinHeapBuild(arr, head, rear);
	for (int i = rear; i >= 1; i--)
	{
		Swap(arr[0], arr[i]);
		MinHeapBuild(arr, head, i - 1);

	}
}

//------------------------------------ main ------------------------------------//

int main()
{
	int arr[10] = { 32,8,29,19,16,34,2,70,13,58 };
	DescendingHeapSort(arr, 0, 9);

	for (int i = 0; i < 10; i++)
		cout << arr[i] << endl;

	system("pause");

}