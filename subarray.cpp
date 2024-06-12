#include <iostream>
#include <new>
#include <cstdlib>
#include <ctime>
using namespace std;
int*** findSubMatrixTotal(int **a, int m , int n, int p, int q, int& d1, int& d2, int& d3, int number );
int** generate2DMatrix(int &a, int &b);
void print2DMatrix(int **A, int a, int b);
void print3DMatrix(int ***A, int a, int b, int c);
int main()
{
	srand(time(0));
	int a, b;
	int **A = generate2DMatrix(a, b);
	print2DMatrix(A, a, b);
	int d1, d2, d3;
	int*** B = findSubMatrixTotal(A, a, b, 3, 3, d1, d2, d3, 50);
	print3DMatrix(B, d1, d2, d3);

}
int** generate2DMatrix(int &a, int &b)
{
	cout << "input a, b: ";
	cin >> a >> b;
	int **A = new int*[a];
	for (int i = 0; i < a; i++)
	{
		A[i] = new int[b];
		for (int j = 0; j < b; j++)
		{
			A[i][j] = rand() % 20;
		}
	}
	return A;
}
void print2DMatrix(int **A, int a, int b)
{
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			cout << A[i][j] << "\t"; 
		}
		cout << endl;
	}
	cout << endl;
}
void print3DMatrix(int ***A, int a, int b, int c)
{
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			for (int k = 0; k < c; k++)
			{
				cout << A[i][j][k] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}
	cout << endl;
}
int*** findSubMatrixTotal(int **a, int m , int n, int p, int q, int &d1, int &d2, int &d3, int number){
	
	int sum;
	int count = 0;
	for (int i = 0; i <= m - p; i++){
		for (int j = 0; j <= n - q; j++){
			sum = 0;
			for (int k = 0 ; k < p; k++){
				for (int l = 0;l < q; l++){
					sum += a[k + i][l + j];	
				}
			}
			if ( sum >= number){
				count++;
			}
		}
	}
	d1 = count;
	d2 = p;
	d3 = q;
	int*** b= new int** [d1];
	for (int i = 0; i < d1; i++){
		 b[i] = new int* [d2];
		 for(int j = 0; j < d2; j++){
		 	b[i][j] = new int [d3];
		}
	}
	int temp = count ;
	for (int i = 0; i <= m - p; i++){
		for (int j = 0; j <= n - q; j++){
			sum = 0;
			for (int k = 0 ; k < p; k++){
				for (int l = 0;l < q; l++){
					sum += a[k + i][l + j];	
				}
			}
			if (sum >= number){
				for (int k = 0 ; k < p ; k++){
					for(int l =0 ; l < q; l++){
						b[count - temp][k][l] = a[k + i][l + j];
					}
				}
				temp--;
			}
		}
	}
	return b;
	
}

