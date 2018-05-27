//문제 1475번
//다솜이는 은진이의 옆집에 새로 이사왔다.다
//솜이는 자기 방 번호를 예쁜 플라스틱 숫자로 문에 붙이려고 한다.
//
//다솜이의 옆집에서는 플라스틱 숫자를 한 세트로 판다
//.한 세트에는 0번부터 9번까지 숫자가 하나씩 들어있다.
//다솜이의 방 번호가 주어졌을 때, 필요한 세트의 개수의 최
//소값을 출력하시오. (6은 9를 뒤집어서 이용할 수 있고, 9는 6
//	을 뒤집어서 이용할 수 있다.)
//
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main()
{
	int TestNum;
	int W, H, N;
	int room;
	cin >> TestNum;
	for (int i = 0; i < TestNum; i++)
	{
		cin >> W >> H >> N;

		room = (H%N) * 100 + H / N;
	}
	cout << room;
	system("pause");
}