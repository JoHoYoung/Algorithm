//���� 1193��
//�̿� ���� ������ �м����� 1
/// 1 -> 1 / 2 -> 2 / 1 -> 3 / 1 -> 2 / 2->�� �� ���� ������ 
//���ʴ�� 1��, 2��, 3��, 4��, 5��, �� �м���� ����.
//
//X�� �־����� ��, X��° �м��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.


#include<iostream>
using namesapce std;

int spacefact(int n)
{
	int k = n / 2;
	k += 1;
	
	if (k == 0)
		return 0;
	if (k == 1)
		return 1;
	else {
		return spacefact(n - 2) + spacefact(n - 1);
	}
}

int main()
{
	int num1;
	int num2;
	int interval;

	cin >> num1;
	cin >> num2;
	interval = num1 - num2;

	for (int i = 0; i < 100; i++)
	{
		if (spacefact(i) < interval&&spacefact(i + 1) <= interval)
			cout << i;
    }
	system("pause");
}