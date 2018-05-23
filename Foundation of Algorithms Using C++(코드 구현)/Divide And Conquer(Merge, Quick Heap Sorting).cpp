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
//  MergeSort : 절반으로 나눈다 -> 나눈 부분 각각을 Sorting한다. -> Sorting 된 부분을 합친다.																				  //
//  Merge : 합치기 위한 함수																																									  //
//  MergeSort : 절반으로 나눈다 -> 재귀적으로 부분을 계속 나누어서 Merge로 합침                                                                                             //
//  절반으로 나눠져 정렬된 두 부분을 합칠때 새로운 배열을 만들어 각각의 부분의 시작점을 할당하여 순서대로 새로운 배열에 저장                                 //
//  새로운 배열에 저장과정에서 한쪽 부분의 값들이 모두 새로운 배열에 할당되면, 다른쪽 부분의 남은 값들은 새로운 배열에 순차적으로 저장                    // 
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
//		*QuickSort : Pivot을 Sorting할 배열의 맨앞의 원소로 설정, Partition 함수를 사용하여 Sorting 되었을 때 Pivot이 들어갈 인덱스를 반환하여 그 인덱스를 기준//
//  으로 두 부분으로 나눔 ->  나눠진 두 부분의 각각 맨앞의 원소를 Pivot으로 설정 후 Partition함수를 사용하여 각각 Pivot이 들어갈 인덱스를 구하여 또다시  //
//  그 인덱스를 기준으로 절반으로 눠서 똑같은 과정 재귀적으로 실행																												  //
//		*Partition : 배열의 맨 앞부분을 Pivot, 비교를 시작할 위치를 head값으로 지정, temppivotdex 값 역시 head로 지정     												  //
//  -> i = head+1부터 for문을 사용하여 rear까지 arr[head+1]값과 pivot값을 비교 -> pivot값 보다  arr[i]값이 작을시, head값으로 지정하였던 ->                 //
//  temppivotdex값에 +1을 해주어 Swap. -> pivot보다 작은 값일경우 뒤로 가지않고 그 위치 유지( 앞에서 큰값을 만나지 않았을 경우만                           //
//  앞에서 pivot보다 큰 값을 만났을 경우 아무런 연산을 거치지 않고 지나치는데 이럴경우 그 큰숫자보다 한자리 앞에 temppivotdex값이 설정 되어있어      //
//  pivot보다 작은 값을 만났을 경우 지나친 큰 값과 작은 값이 Swap되는 작용이 일어남 Swap(arr[++temppivotdex], arr[i]) 코딩이 이러한 역할을 하게 함     //
//		큰값을 여러개 지나치고 나중에 작은값을 지나친 큰값의 수보다 적은 수 만날 경우 -> 큰값을 더 많이 지나쳤으므로 그 큰값들이 뒤로 가게되고, 작은값이 //
//  앞으로 온다 . 작은값뒤에는 큰값밖에 올 수 없다.
//		큰값을 여러개 지나치고 나중에 작은값을  지나친 큰값의 수보다 많이 만날 경우 -> 여러개 지난 큰값 갯수 만큼 큰값들이 뒤로 밀리고 뒤에 작은 값들이  //
//  위치하게 된다. ex) [10, 1(앞으로 온 작은값), 2(앞으로 온 작은값), 20, 30, 3, 4 ,5 ] 이 중간과정에서 temppivotdex는 큰값인 20 앞 즉 2(앞으로 온 작은값  //
//  에 머물러 있으므로 또 큰값을 그냥 지나치게 되고 그 후 큰값 개수만큼 큰 값들이 뒤로 가게 된다 .                                                                      //
//  [10, 1(앞으로 온 작은값), 2(앞으로 온 작은값), 3(앞으로 온 작은값), 4(앞으로 온 작은값)] , 20 , 30, 5 ] 여기서도 역시 temppivotdex는 20 앞 즉 4에        //
//  머무르게 되고 연산을 계속 반복하다보면 지나치는 큰값들의 수가 남아있는 작은값들의 수보다 작게되고 위의 그 경우를 반복하면 Sorting 이 완료된다. //
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
//  MinHeap, MaxHeap : 위의값 (부모노드)가 아랫값(자식노드) 보다 크거나 작은 이진트리 MinHeap : 부모노드가 더 작음 MaxHeap : 부모노드가 더 큼      //
//  이진트리 : 자식이 두개, 트리의 형태가 왼쪽부터 차례대로 되어 있는것
//  트리는 배열의 형태로 나타낸다 
//  부모노드의 인덱스가 K인 경우 자식노드 : 2K, 2K+1      &&   자식노드의 인덱스가 K인 경우 부모노드 : K/2
//  트리를 만들고 자식노드에서 부터 제일위의 노드까지 비교연산, 조건이 만족할경우 SWAP 하며 올라가는데 SWAP 했을경우 비교할 자식노드의 인덱스는 //
//  2/K로 바꾸고 부모노드의 값도 그에맞게 바꿔주어야 한다. 어떤경우가 생길지 모르니 연산은 조건을 만족할경우 제일위의 노드까지 비교, SWAP연산을 하게//
//  코딩을 해준다. 코딩은 부모노드 == 0 일때 까지 로 해주면 된다. 
//  Max, Min Heap을 만들어서 오름, 내림차순으로 Sorting 할 수 있다. 맨위의 노드값이 제일 크거나, 제일 작은 값이므로 맨위의 노드 값을 배열의 맨 마지막 값//
//  과 Swap을 해준다. 그렇다면 배열의 맨 마지막값에는 Sorting된 값이 들어가게 되므로 배열의 맨마지막 값은 다시 Heap을 구성할 필요가 없다. 맨위의 노드값을 배열의 맨 마지막 값//
//  과 Swap을 한 후의 Heap은 Max, 또는 Min Heap이 아니므로 다시 Heap을 만들어준다. 이때 배열의 맨마지막 값은 Sorting을 완료한 값이므로 그 값을 제외 //
//  하고 Heap을 만들어 준다.
//  이 과정을 계속 반복하면 Sorting이 완료된다.
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