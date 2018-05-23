#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	char Equation[1000];
	cin >> Equation;
	int NumofMinus = 0;
	int leng = strlen(Equation);  // leng은 문자열갯수, 배열 최종인덱스+1 

	for (int i = 0; i < leng; i++)
		if (Equation[i] == '-')
			NumofMinus++;

	int  *Midterm;
	Midterm = new int[NumofMinus + 1];
	for (int i = 0; i <= NumofMinus; i++)
		Midterm[i] = 0;

	int Middex = 0;
	int tempdex = 0;
	char temp[1000];
	int n;

	for (int i = 0; i <= leng; i++)
	{
		if (Equation[i] == '-')
		{
			temp[tempdex] = '\n';
			n = atoi(temp);
			//cout << "   n = " << n << endl;
			tempdex = 0;
			Midterm[Middex] += n;
			Middex++;
		}
		else if (Equation[i] == '+' || Equation[i] == NULL)
		{
			temp[tempdex] = '\n';
			n = atoi(temp);
			//cout << "   n = " << n << endl;
			tempdex = 0;
			Midterm[Middex] += n;

		}
		else {
			temp[tempdex++] = Equation[i];
		}
	}
	int result = Midterm[0];
	for (int i = 1; i <= NumofMinus; i++)
	{
		//cout << "Midtem[" << i << "]" << " = " << Midterm[i] << endl;
		result -= Midterm[i];
	}
	cout << result;
	system("pause");
}