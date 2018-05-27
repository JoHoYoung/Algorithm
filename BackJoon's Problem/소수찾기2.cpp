//���� 2581
//
//�ڿ��� M�� N�� �־��� �� M�̻� N������ �ڿ��� �� �Ҽ���
//���� ��� ��� �̵� �Ҽ��� �հ� �ּҰ��� ã�� ���α׷��� �ۼ��Ͻÿ�.
//
//���� ��� M = 60, N = 100�� ��� 60�̻� 100������ �ڿ���
//�� �Ҽ��� 61, 67, 71, 73, 79, 83, 89, 97 �� 8���� �����Ƿ�, ��
//�� �Ҽ��� ���� 620�̰�, �ּҰ��� 61�� �ȴ�.

#include<iostream>
#include<algorithm>
#include<string.h>
#include<cstring>
using namespace std;

int main()
{
	int head, rear;
	int sum = 0;
	int min = INT_MAX;
	bool tt = false;

	cin >> head;
	cin >> rear;


	for (int i = head; i <= rear; i++)
	{
		if (i == 1)
			tt = true;

		for (int j = 2; j < i; j++)
		{
			if ((i % j) == 0)
			{
				tt = true;
				break;
			}
		}
		if (tt == false)
		{
			sum += i;

			if (i < min)
				min = i;
		}
		tt = false;
		
	}
	if (sum == 0)
		cout << "-1";
	else cout << sum << endl << min << endl;
	system("pause");
	return 0;
}