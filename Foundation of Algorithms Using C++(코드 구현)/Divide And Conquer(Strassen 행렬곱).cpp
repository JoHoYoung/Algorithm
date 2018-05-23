#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

class Matrix
{
public:
		 int **arr;
		 int degree;

public :	
		Matrix(int n);
		Matrix  divMatrix(int n);
		Matrix operator+(Matrix &temp);
		Matrix operator-(Matrix &temp);

		void MergeMatrix(Matrix A1, Matrix A2, Matrix A3, Matrix A4);
		void PrintContent();
};

Matrix::Matrix(int n)
{
	degree = n;
	arr = new int*[n];

	for (int i = 0; i < n; i++)
		arr[i] = new int[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			arr[i][j] = rand() % 10;
}

Matrix Matrix::divMatrix(int n)
{
	Matrix A1(this->degree / 2);
	switch (n)
	{
	case 1:
		for (int i = 0; i < this->degree / 2; i++)
			for (int j = 0; j < this->degree / 2; j++)
				A1.arr[i][j] = this->arr[i][j];
		return A1;
		break;
	case 2:
		for (int i = 0; i < this->degree / 2; i++)
			for (int j = this->degree / 2; j < this->degree; j++)
				A1.arr[i][j - (this->degree / 2)] = this->arr[i][j];
		return A1;
		break;
	case 3:
		for (int i = this->degree / 2; i < this->degree; i++)
			for (int j = 0; j < this->degree / 2; j++)
				A1.arr[i - (this->degree / 2)][j] = this->arr[i][j];
		return A1;
		break;
	case 4:
		for (int i = this->degree / 2; i < this->degree; i++)
			for (int j = this->degree / 2; j < this->degree; j++)
				A1.arr[i - (this->degree / 2)][j - (this->degree / 2)] = this->arr[i][j];
		return A1;
		break;
	}
}

Matrix Matrix::operator+(Matrix &temp)
{
	Matrix Temp(this->degree);
	if (this->degree != temp.degree)
	{
		cout << "ERROR" << endl;
		exit(1);
	}
	else
	{
		for (int i = 0; i < this->degree; i++)
			for (int j = 0; j < this->degree; j++)
				Temp.arr[i][j] = this->arr[i][j] + temp.arr[i][j];
		return Temp;
	}
}

Matrix Matrix::operator-(Matrix &temp)
{
	Matrix Temp(this->degree);
	if (this->degree != temp.degree)
	{
		cout << "ERROR" << endl;
		exit(1);
	}
	else
	{
		for (int i = 0; i < this->degree; i++)
			for (int j = 0; j < this->degree; j++)
				Temp.arr[i][j] = this->arr[i][j] - temp.arr[i][j];
		return Temp;
	}
}

void Matrix::MergeMatrix(Matrix A1, Matrix A2, Matrix A3, Matrix A4)
{
	for (int i = 0; i < this->degree / 2; i++)
		for (int j = 0; j < this->degree / 2; j++)
			this->arr[i][j] = A1.arr[i][j];

	for (int i = 0; i < this->degree / 2; i++)
		for (int j = this->degree / 2; j < this->degree; j++)
			this->arr[i][j] = A2.arr[i][j - this->degree / 2];

	for (int i = this->degree / 2; i < this->degree; i++)
		for (int j = 0; j < this->degree / 2; j++)
			this->arr[i][j] = A3.arr[i - this->degree / 2][j];

	for (int i = this->degree / 2; i < this->degree; i++)
		for (int j = this->degree / 2; j < this->degree; j++)
			this->arr[i][j] = A4.arr[i - this->degree / 2][j - this->degree / 2];

}

void Matrix::PrintContent()
{
	for (int i = 0; i < degree; i++)
	{
		cout << '[' << " ";
		for (int j = 0; j < degree; j++)
			cout << arr[i][j] << " ";
		cout << ']' << " " << endl;
	}

}

void Strassen(int n, Matrix A, Matrix B, Matrix C)
{
	if (n >= 2) {
		if (n == 2)
		{
			for (int i = 0; i < 2; i++)
				for (int j = 0; j < 2; j++)
				{
					C.arr[i][j] = 0;
					for (int k = 0; k < 2; k++)
						C.arr[i][j] += A.arr[i][k] * B.arr[k][j]

				}
		}
		else {
			Matrix A1(n / 2), A2(n / 2), A3(n / 2), A4(n / 2), B1(n / 2), B2(n / 2), B3(n / 2), B4(n / 2);
			A1 = A.divMatrix(1);
			A2 = A.divMatrix(2);
			A3 = A.divMatrix(3);
			A4 = A.divMatrix(4);
			B1 = B.divMatrix(1);
			B2 = B.divMatrix(2);
			B3 = B.divMatrix(3);
			B4 = B.divMatrix(4);
			Matrix M1(n / 2);
			Matrix M2(n / 2);
			Matrix M3(n / 2);
			Matrix M4(n / 2);
			Matrix M5(n / 2);
			Matrix M6(n / 2);
			Matrix M7(n / 2);
			Strassen(n / 2, (A1 + A4), (B1 + B4), M1);
			Strassen(n / 2, (A3 + A4), B1, M2);
			Strassen(n / 2, A1, (B2 - B4), M3);
			Strassen(n / 2, A4, (B3 - B1), M4);
			Strassen(n / 2, (A1 + A2), B4, M5);
			Strassen(n / 2, (A3 - A1), (B1 + B2), M6);
			Strassen(n / 2, (A2 - A4), (B3 + B4), M7);
			Matrix TempMatrix1(n / 2);
			Matrix TempMatrix2(n / 2);
			Matrix TempMatrix3(n / 2);
			Matrix TempMatrix4(n / 2);
			TempMatrix1 = M1 + M4 - M5 + M7;
			TempMatrix2 = M3 + M5;
			TempMatrix3 = M2 + M4;
			TempMatrix4 = M1 + M3 - M2 + M6;
			C.MergeMatrix(TempMatrix1, TempMatrix2, TempMatrix3, TempMatrix4);
		}
	}
}

int main()
{
	Matrix A(8);
	Matrix B(8);
	Matrix C(8);
	Strassen(8, A, B, C);
	cout << "행렬 A " << endl;
	A.PrintContent();
	cout << "행렬 B " << endl;
	B.PrintContent();
	cout << "행렬 C " << endl;
	C.PrintContent();
	system("pause");
}