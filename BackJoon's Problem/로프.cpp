//���� 2217��
//N(1��N��100, 000)���� ������ �ִ�.
//�� ������ �̿��Ͽ� �̷� ���� ��ü�� ���ø� �� �ִ�.
//������ ������ �� ���⳪ ���̰� �ٸ��� ������ �� �� �ִ� 
//��ü�� �߷��� ���� �ٸ� ���� �ִ�.
//
//������ ���� ���� ������ ���ķ� �����ϸ� 
//������ ������ �ɸ��� �߷��� ���� �� �ִ�.k���� ������ 
//����Ͽ� �߷��� w�� ��ü�� ���ø� ��, ������ �������� 
//��� ���� w / k ��ŭ�� �߷��� �ɸ��� �ȴ�.
//
//�� �����鿡 ���� ������ �־����� ��, �� �������� �̿��Ͽ� 
//���ø� �� �ִ� ��ü�� �ִ� �߷��� ���س��� ���α׷���
//�ۼ��Ͻÿ�.��� ������ ����ؾ� �� �ʿ�� ������, 
//���Ƿ� �� ���� ������ ��� ����ص� �ȴ�.��, ������ ������ �� ������ �����Ѵ�.

#include <iostream>
#include<algorithm>
using namespace std;

int MAX(int a, int b)
{
	if (a < b)
		return b;
	else return a;
}

int main()
{
	int RopeSet[100010];
	int NumofRope;
	int MaxWeight;
	int currentSet=1;
	cin >> NumofRope;
	for (int i = 0; i < NumofRope; i++)
	cin >> RopeSet[i];

	sort(RopeSet, RopeSet + NumofRope);

	MaxWeight = RopeSet[NumofRope-1];


	MaxWeight = RopeSet[0];
	for (int i = 0; i < NumofRope; i++)
	{
		MaxWeight = MAX(MaxWeight, RopeSet[i] * (NumofRope - i));
	}
	cout << MaxWeight;
	system("pause");
	return 0;

}
/*for (int i = NumofRope - 1; i >= 1; i--)
{
if (MaxWeight<= RopeSet[i-1]*(currentSet+1))
{
MaxWeight = RopeSet[i - 1] * (currentSet + 1);
currentSet += 1;
}
}*/