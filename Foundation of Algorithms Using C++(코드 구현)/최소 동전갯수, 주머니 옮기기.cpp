#include<iostream>
#include<math.h>
using namespace std;

// 1번 문제
int main()
{
	int Price;
	cin >> Price;			//전체 가격값 입력받는 부분
	int tempPrice;
	int tempPrice1;
	int tempPrice2;
	int tempPrice3;			//포문에서 각각의 단계에서 전 단계의 처리된 값들을 받아오기위한 변수

	int	Coin50 = 50;
	int Coin12 = 12;
	int Coin5 = 5;
	int Coin1 = 1;							//각각 코인의 값들

	int Coin50num = 0;
	int Coin12num = 0;
	int Coin5num = 0;
	int Coin1num = 0;							//각 값의 코인의 갯수들

	int TotalCoin = 0;									//총 코인의 갯수
	int Result[4];									//코인의 갯수가 제일 작은 것들의 각각 갯수를 저장할 결과 배열

	int min = 10000;							//비교를 위해 초기화
	if (Price <= 100)								//100원이하 금액 예외처리
	{
		for (int i = 0; Price - i * Coin50 >= 0; i++)					// 50원이 0개, 1개, 2개, 3개 인경우를 포문 안에서 수행.
		{
			tempPrice = Price;
			tempPrice -= i * Coin50;
			Coin50num = i;																	// 총가격에서 코인의 가치만큼 빼고 갯수저장

			for (int j = 0; tempPrice - j * Coin12 >= 0; j++)
			{
				tempPrice1 = tempPrice;
				tempPrice1 -= j * Coin12;
				Coin12num = j;																// 위의 과정 반복

				for (int k = 0; tempPrice1 - k * Coin5 >= 0; k++)
				{
					tempPrice2 = tempPrice1;
					tempPrice2 -= k * Coin5;
					Coin5num = k;																//위의 과정 반복

					for (int q = 0; tempPrice2 - q * Coin1 >= 0; q++)
					{
						tempPrice3 = tempPrice2;
						tempPrice3 -= q * Coin1;
						Coin1num = q;															//위의 과정 반복

						if (tempPrice3 == 0)
						{
							TotalCoin = Coin50num + Coin12num + Coin5num + Coin1num;
							if (min > TotalCoin)
							{
								min = TotalCoin;
								Result[0] = Coin50num;
								Result[1] = Coin12num;
								Result[2] = Coin5num;
								Result[3] = Coin1num;													//반복 수행하며 최솟값인경우 값들을 저장한다. 경우의 수들중에 제일 갯수가 작은것들이 결과 배열에 저장된다.
							}
						}

					}
				}

			}
		}
		cout << " 50원 동전 갯수 : " << Result[0] << endl;
		cout << "12원 동전 갯수 : " << Result[1] << endl;
		cout << "5원 동전 갯수 : " << Result[2] << endl;
		cout << "1원 동전 갯수 : " << Result[3] << endl;
		cout << "전체 동전 갯수 : " << min << endl;													//출력부분
	}
	else cout << " ERROR : 100원 이하의 금액만 입력할 수 있습니다. " << endl;       //100원 이상의 금액을 입력했을때 예외처리.
	system("pause");
	return 0;

}

/////////////////2번문제.	////////////////////////////////////////////
//int main()
//{
//	int NumPocket;					//총 포켓수
//	int Total = 0;					//공의 총 갯수
//	int pivot;						//같게하기위한 기준
//
//	cin >> NumPocket;
//
//	int *Pocket = new int[NumPocket];
//
//	for (int i = 0; i < NumPocket; i++)														// 사용자로부터 입력받는 부분.
//	{
//		cout << i + 1 << "번째 주머니에 들어 있는 공 개수 : ";
//		cin >> Pocket[i];
//		Total += Pocket[i];			//예외처리를 위한 공의 총 갯수 계산. 나누어 떨어지지 않으면 불가능.
//		cout << endl;
//	}
//	
//	if ((Total%NumPocket) != 0)																	// 예외처리부분
//		cout << "나눌 수 없습니다. ";
//	else
//	{	
//		pivot = Total / NumPocket;																// 다 같게 하려는 갯수 기준.
//		
//		for (int i = 0; i < NumPocket; i++)
//		{
//			if (Pocket[i] != pivot && Pocket[i] < pivot)									//기준 갯수보다 작을경우에만 공이 들어오므로
//			{
//				cout << "Pocket[" << i << "]로 이동 횟수 :" << abs(Pocket[i] - pivot)<<endl;			//기준 갯수와의 차이만큼 갯수가 들어오는것 출력.
//			}
//		}
//	}
//	system("pause");
//	return 0;
//}