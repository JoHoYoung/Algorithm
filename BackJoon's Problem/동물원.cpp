//���� 1309
//�� ���������� ���ڵ��� ��� �ִµ� ���ڵ��� �츮�� ���� ��, ���ηε� ���ηε� �پ� �ְ�
//��ġ�� ���� ����.�� ������ ���û�� ���ڵ��� ��ġ ���� ������ ��Ӹ��� �ΰ� �ִ�.
//
//������ ���û��� �Ӹ��� ������ �ʵ��� �츮�� 2 * N �迭�� ���ڸ� ��ġ�ϴ� ����� ���� 
//�� ���������� �˾Ƴ��� ���α׷��� �ۼ��� �ֵ��� ����.���ڸ� �� ������ ��ġ���� �ʴ� ��쵵
//�ϳ��� ����� ���� ģ�ٰ� �����Ѵ�.

#include<iostream>
using namespace std;

int DP[100003][3];

int Lion(int Space, int num)
{
	if (Space == 0)
	{
		DP[Space][num] = 1;
		return DP[Space][num];
	}
	if (DP[Space][num] != 0)
		return DP[Space][num];
	else {
		if (num == 0)
		DP[Space][num] = (Lion(Space-1,0) + Lion(Space-1,1)+ Lion(Space - 1, 2))%9901;
		else if (num == 1)
		DP[Space][num] = (Lion(Space - 1, 0) + Lion(Space - 1, 2))%9901;
		else if (num == 2)
		DP[Space][num] =( Lion(Space - 1, 0) + Lion(Space - 1, 1))%9901;
		}

	return DP[Space][num];
}

int main()
{
	int N;
	cin >> N;
	int result;
	memset(DP, 0, sizeof(DP));
	result = Lion(N-1, 0) + Lion(N-1, 1) + Lion(N-1, 2);
	cout << result%9901;

	system("pause");
	return 0;
}