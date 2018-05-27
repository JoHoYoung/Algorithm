//���� 2262
//����ÿ����� �ų� n���� ������� �� ���� ũ����Ʈ��� ������ ��ʸ�Ʈ ��ȸ�� ġ����.
//�� ������ Ư���� �Ƿ¸��� ���и� �¿��ϱ� ������, �ƹ��� �Ƿ��� ������� ����� ������
//ġ���� ��ŷ�� ���� ����� �ݵ�� �̱�� �ȴ�.���� ����ÿ����� ������ ��������ϰ� 
//����� ���ؼ�, �������� ���� �� ������� �� ���տ� ���ϴ� �������� ��ŷ ���̸� ����ϰ�
//������� �Ѵ�.
//
//��ʸ�Ʈ�� ���� ������ �̹� ��÷�� �� ������� �������� ��ġ�ϰ�, ���ʿ��� ��������
//������ ��߳��� �ʵ��� ������ ���Ѵ�.���� �������� ���Ƿ� ���� �� ������, ��ʸ�Ʈ�� 
//�������� �� �ȴ�.����, �� ���տ� ���ϴ� �� ������ ��ŷ�� ������ ���� �ּҰ� �ǵ��� �Ϸ� �Ѵ�.
//
//���� ��� ��÷ ����� ���ʷ� ��ŷ 1, 6, 2, 5, 3, 4���� �������̾��� ���� ��ʸ�Ʈ �� ���� ���� �ִ�.
//<A>�� ���� �� ������(1 6), (2 5), (3 4), (1 2), (1 3)���� ��ŷ ������ ���� 5 + 3 + 1 + 1 + 2 = 12
//�� �ȴ�.�ݸ鿡 <B>�� 11��, <C>�� 10�� �ȴ�.
//
//��ʸ�Ʈ ��÷ ����� �־����� ��, �� ���տ� ���ϴ� 
//�� ������ ��ŷ ������ �� ���� �ּҰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

#include<iostream>
using namespace std;
#define abs(a,b) (a>b ? (a-b):(b-a))
#define min(a,b) (a>b ? b:a)
int w[500][500];
int save[500][500];

int HF(int head, int rear, int *arr)
{
	int result = 1000000;

	if (save[head][rear] && save[head][rear] != -1)
	{
		return save[head][rear];
	}

	if (head == rear)
	{
		save[head][rear] = 0;
		return 0;
	}

	if (head == rear - 1)
	{
		save[head][rear] = abs(arr[head], arr[rear]);
		return abs(arr[head], arr[rear]);
	}

	for (int i = 0; head + i < rear; i++)
	{
		result = min(result, abs(w[head][head + i], w[head + i + 1][rear]) + HF(head, head + i, arr) + HF(head + i + 1, rear, arr));
	}

	save[head][rear] = result;
	return save[head][rear];
}

int main()
{
	int Num;
	cin >> Num;
	int **D;
	int *arr;
	arr = new int[Num];

	for (int i = 0; i <= Num; i++)
		for (int j = 0; j <= Num; j++)
			save[i][j] = -1;

	for (int i = 0; i < Num; i++)
		cin >> arr[i];

	///////////////////////////////////////// �Էºκ� �� , �˰��� �κ�/////////////////////////////////////////////////
	for (int i = 0; i < Num; i++)
	{
		w[i][i] = arr[i];
		for (int j = i + 1; j < Num; j++)
		{
			w[i][j] = min(w[i][j - 1], arr[j]);

		}
	}

	cout << HF(0, Num - 1, arr);
	system("pause");
	return 0;
}