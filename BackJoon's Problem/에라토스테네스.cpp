//���� 2960��
//
//�����佺�׳׽��� ü�� N���� �۰ų� ���� ��� �Ҽ��� ã�� ������ �˰����̴�.
//
//�� �˰����� ������ ����.
//
//2���� N���� ��� ������ ���´�.
//���� ������ ���� ���� �� ���� ���� ���� ã�´�.�̰��� P��� �ϰ�, �� ���� �Ҽ��̴�.
//P�� �����, ���� ������ ���� P�� ����� ũ�� ������� �����.
//���� ��� ���ڸ� ������ �ʾҴٸ�, �ٽ� 2�� �ܰ�� ����.
//N, K�� �־����� ��, K��° ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

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

	cin >> head >> rear;


	for (int i = head; i <= rear; i++)
	{
		for (int j = 2; j*j <= i; j++)
		{
			if ((i%j) == 0)
			{
				tt = true;
				break;
			}
		}
		if (tt == false)
			cout << i<<endl;
		else tt = false;
	}

	system("pause");
	return 0;
}