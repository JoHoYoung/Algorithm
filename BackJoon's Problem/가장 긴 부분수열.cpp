#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int N;
	cin >> N;
	
	int *arr, *count;
	arr = new int[N];
	count = new int[N];
	
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];												// �Է¹迭 �޴� �κ�
		count[i] = 0;												// count�迭 �ʱ�ȭ �ϴºκ�
	}
	
	int tempsum = 0;
	
	for (int i = N - 1; i >= 0; i--)
	{	
		int tempcount = -10000;								// ���� ū count�� �����ϱ����� �ʱ�ȭ

		for (int j = i+1; j < N; j++)							// ���� i ���� �ڿ��� ��
		{
			if (arr[j] < arr[i]&&count[j]>tempcount)		// �ڿ��Ű� ���غ��� �۰�, count���� ũ�� 
			{
				tempsum = count[j];							// �Ͻ������� ����ū�� ���� // ���� ������ ���� ū�� �����
				tempcount = count[j];							// ���� ū count �����ϱ� ���� �񱳴��(tempī��Ʈ �ʱ�ȭ)
			}
		}
		if (tempcount != -10000)								// -10000�� �ƴ϶�°� �񱳴�󺸴� ������ �ϳ��� �ִٴ� �ǹ�
		count[i] += tempsum+1;								//	���ϱ� 1		// 10000�̸� ó���� �ʱ�ȭ�ߴ� 0�� ���µ�
	}																					// �񱳴�� i���� ������ �ϳ��� �����ϱ� 0�� ���°� ����
	int max = -10000;
	for (int i = 0; i < N; i++)									// ������� count�� �߿� ����ū�� �����ϱ�����
	{
		if (count[i] > max)
			max = count[i];
	}
	cout << max+1;											//������ �����ϴϱ� +1 �ؼ� ���
	system("pause");
	return 0;
}