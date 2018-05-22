#include <iostream>
using namespace std;

int F[1000000];

int min(int n1, int n2)
{
	if (n1 < n2)
		return n1;
	else return n2;
}

int main()
{
	int n; cin >> n;
	F[1] = 0;
	for (int i = 2; i <= n; i++) {
		F[i] = i;
		if (i % 3 == 0) {
			F[i] = min(F[i], F[i / 3] + 1);
		}
		if (i % 2 == 0) {
			F[i] = min(F[i], F[i / 2] + 1);
		}
		F[i] = min(F[i], F[i - 1] + 1);
	}
	cout << F[n];
	system("pause");
	return 0;

}