#include<iostream>
#include<math.h>
using namespace std;

// 1�� ����
int main()
{
	int Price;
	cin >> Price;			//��ü ���ݰ� �Է¹޴� �κ�
	int tempPrice;
	int tempPrice1;
	int tempPrice2;
	int tempPrice3;			//�������� ������ �ܰ迡�� �� �ܰ��� ó���� ������ �޾ƿ������� ����

	int	Coin50 = 50;
	int Coin12 = 12;
	int Coin5 = 5;
	int Coin1 = 1;							//���� ������ ����

	int Coin50num = 0;
	int Coin12num = 0;
	int Coin5num = 0;
	int Coin1num = 0;							//�� ���� ������ ������

	int TotalCoin = 0;									//�� ������ ����
	int Result[4];									//������ ������ ���� ���� �͵��� ���� ������ ������ ��� �迭

	int min = 10000;							//�񱳸� ���� �ʱ�ȭ
	if (Price <= 100)								//100������ �ݾ� ����ó��
	{
		for (int i = 0; Price - i * Coin50 >= 0; i++)					// 50���� 0��, 1��, 2��, 3�� �ΰ�츦 ���� �ȿ��� ����.
		{
			tempPrice = Price;
			tempPrice -= i * Coin50;
			Coin50num = i;																	// �Ѱ��ݿ��� ������ ��ġ��ŭ ���� ��������

			for (int j = 0; tempPrice - j * Coin12 >= 0; j++)
			{
				tempPrice1 = tempPrice;
				tempPrice1 -= j * Coin12;
				Coin12num = j;																// ���� ���� �ݺ�

				for (int k = 0; tempPrice1 - k * Coin5 >= 0; k++)
				{
					tempPrice2 = tempPrice1;
					tempPrice2 -= k * Coin5;
					Coin5num = k;																//���� ���� �ݺ�

					for (int q = 0; tempPrice2 - q * Coin1 >= 0; q++)
					{
						tempPrice3 = tempPrice2;
						tempPrice3 -= q * Coin1;
						Coin1num = q;															//���� ���� �ݺ�

						if (tempPrice3 == 0)
						{
							TotalCoin = Coin50num + Coin12num + Coin5num + Coin1num;
							if (min > TotalCoin)
							{
								min = TotalCoin;
								Result[0] = Coin50num;
								Result[1] = Coin12num;
								Result[2] = Coin5num;
								Result[3] = Coin1num;													//�ݺ� �����ϸ� �ּڰ��ΰ�� ������ �����Ѵ�. ����� �����߿� ���� ������ �����͵��� ��� �迭�� ����ȴ�.
							}
						}

					}
				}

			}
		}
		cout << " 50�� ���� ���� : " << Result[0] << endl;
		cout << "12�� ���� ���� : " << Result[1] << endl;
		cout << "5�� ���� ���� : " << Result[2] << endl;
		cout << "1�� ���� ���� : " << Result[3] << endl;
		cout << "��ü ���� ���� : " << min << endl;													//��ºκ�
	}
	else cout << " ERROR : 100�� ������ �ݾ׸� �Է��� �� �ֽ��ϴ�. " << endl;       //100�� �̻��� �ݾ��� �Է������� ����ó��.
	system("pause");
	return 0;

}

/////////////////2������.	////////////////////////////////////////////
//int main()
//{
//	int NumPocket;					//�� ���ϼ�
//	int Total = 0;					//���� �� ����
//	int pivot;						//�����ϱ����� ����
//
//	cin >> NumPocket;
//
//	int *Pocket = new int[NumPocket];
//
//	for (int i = 0; i < NumPocket; i++)														// ����ڷκ��� �Է¹޴� �κ�.
//	{
//		cout << i + 1 << "��° �ָӴϿ� ��� �ִ� �� ���� : ";
//		cin >> Pocket[i];
//		Total += Pocket[i];			//����ó���� ���� ���� �� ���� ���. ������ �������� ������ �Ұ���.
//		cout << endl;
//	}
//	
//	if ((Total%NumPocket) != 0)																	// ����ó���κ�
//		cout << "���� �� �����ϴ�. ";
//	else
//	{	
//		pivot = Total / NumPocket;																// �� ���� �Ϸ��� ���� ����.
//		
//		for (int i = 0; i < NumPocket; i++)
//		{
//			if (Pocket[i] != pivot && Pocket[i] < pivot)									//���� �������� ������쿡�� ���� �����Ƿ�
//			{
//				cout << "Pocket[" << i << "]�� �̵� Ƚ�� :" << abs(Pocket[i] - pivot)<<endl;			//���� �������� ���̸�ŭ ������ �����°� ���.
//			}
//		}
//	}
//	system("pause");
//	return 0;
//}