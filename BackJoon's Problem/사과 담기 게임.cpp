//���� 2828
//����̴� �����ǿ��� �ٱ��ϸ� �ű�� ������ ������ �Ѵ�.
//��ũ���� Nĭ���� �������� �ִ�.��ũ���� �Ʒ��ʿ��� Mĭ��
//�����ϴ� �ٱ��ϰ� �ִ�. (M<N) �÷��̾�� ������ �ϴ� �߿�
//	�ٱ��ϸ� �����̳� ���������� �̵��� �� �ִ�.������, �ٱ�
//	�ϴ� ��ũ���� ��踦 �Ѿ�� �ȵȴ�.���� ó���� �ٱ��ϴ�
//	���� Mĭ�� �����ϰ� �ִ�.
//
//��ũ���� ������ ��� ���� ���� ��������.�� ����� Nĭ�� �� 
//ĭ�� ��ܿ��� �������� �����ϸ�, ��ũ���� �ٴڿ� ���������� 
//�������� ��������.�� ����� �ٴڿ� ��� ���, �ٸ� ����� �������� �����Ѵ�.
//
//�ٱ��ϰ� ����� �������� ĭ�� �����ϰ� �ִٸ�, �ٱ��ϴ� �� 
//����� �ٴڿ� ���� ��, ����� ���� �� �ִ�.����̴� ����� 
//��� �������� �Ѵ�.�� ��, �ٱ����� �̵� �Ÿ��� �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
#include<iostream>
using namespace std;

struct Bucket
{
	int head;
	int rear;
};

int main()
{
	int N, M;
	cin >> N;
	cin >> M;

	int result=0;

	Bucket Buck;
	Buck.head = 1;
	Buck.rear = M;

	int Apple;
	cin >> Apple;

	int *seq = new int[Apple];

	for (int i = 0; i < Apple; i++)
		cin >> seq[i];

	for (int i = 0; i < Apple; i++)
	{
		if (seq[i] > Buck.rear)
		{
			int temp = seq[i] - Buck.rear;
			result += seq[i] - Buck.rear;
			Buck.rear += temp;
			Buck.head += temp;
			if (Buck.rear > N)
			{
				result -= Buck.rear - N;
				Buck.head = N-M+1;
				Buck.rear = N;
			}
		}
		else if (seq[i] < Buck.head)
		{
			int temp = Buck.head - seq[i];
			result += Buck.head - seq[i];
			Buck.rear -= temp;
			Buck.head -= temp;

			if (Buck.head < 1)
			{
				result -= 1 - Buck.head;
				Buck.head = 1;
				Buck.rear = M;
			}
		}

	}
	cout << result;
	
	system("pause");
	return 0;
}