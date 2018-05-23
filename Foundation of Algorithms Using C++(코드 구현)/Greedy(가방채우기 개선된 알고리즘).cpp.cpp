#include<iostream>
using namespace std;

int Max(int a, int b)
{
	if (a > b)
		return a;
	else return b;
}

int knap(int ItemNum, int Storage, int **P, int **Info)
{
	if (ItemNum == 0 || Storage == 0)
	{
		P[ItemNum][Storage] = 0;
	}
	else {

		if (Info[ItemNum][0] <= Storage)
		{
			P[ItemNum][Storage] = Max(knap(ItemNum - 1, Storage, P, Info), Info[ItemNum][1] + knap(ItemNum - 1, Storage - Info[ItemNum][0], P, Info));
				//cout << "P[" << ItemNum << "][" << Storage << "]" << " = " << P[ItemNum][Storage] << endl;
		}
		else {
			P[ItemNum][Storage] = knap(ItemNum - 1, Storage, P, Info);
			//cout << "ITEMNUM이 " << ItemNum << "일때 엘스 들어감" << endl;
		}
	}

	return P[ItemNum][Storage];
}

int main()
{
	int Storage;
	int NumofItem;
	int **P;
	cout << "가방 용량 입력 : ";
	cin >> Storage;

	cout << "아이템 갯수 입력" << endl;
	cin >> NumofItem;

	P = new int*[NumofItem + 1];

	for (int i = 0; i <= NumofItem; i++)
		P[i] = new int[Storage + 1];

	int **Info;
	Info = new int*[NumofItem + 1];

	for (int i = 0; i <= NumofItem; i++)		// Info[0]은 무게, Info[1]은 값어치
		Info[i] = new int[2];

	cout << "아이템 무게, 값어치 입력" << endl;
	for (int i = 1; i <= NumofItem; i++)
	{
		cin >> Info[i][0];
		cin >> Info[i][1];
	}
	cout << "최대 값어치 : " << knap(NumofItem, Storage, P, Info);

	system("pause");
	return 0;
}