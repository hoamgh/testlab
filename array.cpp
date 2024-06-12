#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;
void linearEquation(int a,int b);
void QuadraticEquation(int a, int b, int c);
bool isPrime(int n);
int sumDigits(int n);
int countPrime(int a, int b);
bool normalTriangle(float a,float b,float c);
bool rightTriangle(float a,float b,float c);
bool isoscelesTriangle(float a,float b,float c);
bool rightIsoscelesTriangle(float a,float b,float c);
bool equilateralTriangle(float a,float b,float c);
void inputArray(int A[], int n);
void printArray(int A[], int n);
int sumArray(int a[], int n);
bool isInscreasing(int A[], int n);
void input2DArray (int a[][10], int m, int n);
void output2DArray (int a[][10], int m, int n);
void Sum22DArray(int a[][10], int b[][10], int ans[][10], int m , int n);
void rotate2DArray(int A[][10], int &m , int &n);
void readFile();
int countNumbers(string s,string word);

void genRandom(int a[][22][22], int n, int m, int k);
void prt3D(int a[][22][22], int n, int m, int k);

int main(){
	//int n, a,b,c;
	/*cin >> a;
	cin >> b;
	cin >> c;
	cout<< a << "x + "<< b << " = 0\n"; 
	cout<< a << "x^2 + "<< b << "x + "<< c <<" = 0\n";
	//linearEquation(a,b);
	QuadraticEquation(a, b, c);*/
	//cin>>n;
	//if (isPrime(n)) cout << "La so nguyen to";
	//else cout << "Khong la so nguyen to";
//	int n;
//	cin >> n;
//	cout << sumDigits(n);
//	return 0;
//	int a=4,b=10;
//	cout << countPrime(a,b);
	/*float a,b,c;
	cout<<"Nhap:";
	cin>>a>>b>>c;
	if(normalTriangle(a,b,c))
	{
		cout<<"Normal triangle"<<endl;
	}
	if(rightTriangle(a,b,c))
	{
		cout<<"Right triangle"<<endl;
	}
	if(isoscelesTriangle(a,b,c))
	{
		cout<<"Isosceles triangle"<<endl;
	}
	if(rightIsoscelesTriangle(a,b,c))
	{
		cout<<"Right isosceles triangle"<<endl;
	}
	if(equilateralTriangle(a,b,c))
	{ 
	
		cout<<"Equilateral triangle"<<endl;;
	}
	*/
//	int a[5] = {1,2,3,4,5};
//	cout << "Sum of all elements: " << sumArray(a,5) << endl;
//	if (isInscreasing(a, 5)) {
//		cout << "array is increasing";
//	}
//	else {
//		cout << "not ";
//	}

//	srand(time(0));
//	int m = 5;
//	int n = 4;
//	int a[10][10];
//	input2DArray(a, m, n);
//	output2DArray(a, m, n);
//	rotate2DArray(a, m, n);
	//int b[10][10];
	//int ans[10][10];
//	int m = 3, n = 4;
	//input2DArray(a, m, n);
//	input2DArray(b, m, n);
//	output2DArray(a, m, n);
//	
//	Sum22DArray(a, b, ans, m, n);
//	
//	output2DArray(a, m, n);
//	
//	cout << endl;
//	
//	output2DArray(b, m, n);
//	
//	cout << endl;
//	
//	output2DArray(ans, m, n);]
	
	//readFile();
	ifstream ifs;
	ofstream ofs;
	ifs.open("input2.txt");
	ofs.open("output2.txt");
	string s;
	getline(ifs,s);
	string word;
	getline(ifs,word);
	ofs << countNumbers(s,word);
	ifs.close();
	ofs.close();
	
	//int a[22][22][22];
	//int n , m , k;
	//cin >> n >> m >> k;
	//genRandom(a, n, m, k);
	//prt3D(a, n , m , k);
	//return 0;
}

void linearEquation(int a, int b){
	int A[1000];
	int n = 5;
	inputArray(A, n);
	printArray(A, n);
	double x;
	if (a == 0)
		if (b == 0)
			cout << "Vo so nghiem";
		else cout << "Vo nghiem";
	else 
	{
		x = - b * 1.0 / a;
		cout << "x = " <<x;
	}
}
void QuadraticEquation(int a, int b, int c){
	if(a == 0){
		linearEquation(b,c);
	}
	else{
		double delta = b * b - 4 * a * c;
		if(delta < 0)cout << "VN";
		else if(delta == 0){
			double x = -b*1.0/2*a;
			cout << x;
		}
		else{
			double x1 = (-b - sqrt(delta)) * 1.0 / (2 * a);
			double x2 = (-b + sqrt(delta)) * 1.0 / (2 * a);
			cout << x1 << endl << x2;
		}
	}
}
bool isPrime (int n)
{
	int i;
	if (n <= 1) return false;
	for (i = 2 ; i < n ; i++)
	   if ( n % i== 0) return false;
	return true;
}
int countPrime (int a, int b)
{
	int count = 0;
	for ( int i = a + 1 ; i < b ; ++i)
	{
		if (isPrime(i))
		count++;
	}
	return count;
}
int sumDigits(int n){
	int sum = 0;
	if(n < 0){
		n = -n;
	}
	while (n > 0){
		sum += n % 10;
		n /= 10;
	}
	return sum;
	
}

bool normalTriangle(float a, float b, float c)
{
	if(a+b>c && b+c>a && c+a>b) return true;
	else return false;
}

bool rightTriangle(float a, float b, float c)
{
	if(normalTriangle(a,b,c))
	{
		if(a*a==b*b+c*c || b*b==a*a+c*c || c*c==a*a+b*b) return true;
		else return false;
	}
	else return false;
}

bool isoscelesTriangle(float a, float b, float c)
{
	if(normalTriangle(a,b,c))
	{
		if(a==b || b==c || c==a) return true;
		else return false;
	}
	else return false;
}

bool rightIsoscelesTriangle(float a, float b, float c)
{
	if(normalTriangle(a,b,c))
	{
		if(a*a==b*b+c*c && b==c) return true;
		else if(b*b==a*a+c*c && a==c) return true;
		else if(c*c==a*a+b*b && a==b) return true;
		else return false;
	}
	else return false;
}

bool equilateralTriangle(float a, float b, float c)
{
	if(normalTriangle(a,b,c))
	{
		if(a==b && b==c && c==a) return true;
		else return false;
	}
	else return false;
}

void inputArray(int A[], int n){
	for(int i = 0; i < n; i++){
		A[i] = rand() % 90 + 10 ;
	}
}

void printArray(int A[], int n){
	for(int i = 0; i < n; i++){
		cout << A[i] << " ";
	}
}
int sumArray(int a[], int n){
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i];
	return sum;
}

bool isInscreasing(int A[], int n) {
	if (A[0] <= A[1]){
		for (int i = 2; i < n; ++i) {
			if (A[i] < A[i - 1]){
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}
	
}

void input2DArray (int a[][10], int m, int n){
	for (int i = 0; i < m; i++){
		for (int k = 0; k < n; k++){
			a[i][k] = rand() % 100;
		}
	}
}
void output2DArray (int a[][10], int m, int n){
	for (int i = 0; i < m; i++){
		for (int k = 0; k < n; k++){
			cout << a[i][k] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Sum22DArray(int a[][10], int b[][10], int ans[][10], int m , int n){
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			ans[i][j] = a[i][j] + b[i][j];
		}
	}
}

void rotate2DArray(int A[][10], int& m , int& n) {
	int rotate[n][m];
	
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			rotate[j][m - 1 - i] = A[i][j];
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			A[i][j] = rotate[i][j];
		}
	}
	
	swap(m, n);
}
void readFile()
{
	ifstream ifs;
	ofstream ofs;
	ifs.open("input1.txt");
	ofs.open("output1.txt");
	
	int n;
	ifs >> n;
	
	double a, b;
	char c;
	for (int i = 1; i <= n; i++)
	{
		ifs >> a;
		ifs >> c;
		ifs >> b;
		if (c == '*')
			ofs << a * b;
		else if (c == '/')
			ofs << a / b;
		else if (c == '+')
			ofs << a + b;
		else if (c == '-')
			ofs << a - b;
		ofs << endl;
	}
	ifs.close();
	ofs.close();
}
int countNumbers (string s, string word)
{
	int dem = 0;
	int i = 0;
	while (s[i] != " " &&  word[i] != " ")
	{
		int j = i + 1;
		while ( s[j] != " " && s[j])
	}
}

void genRandom(int a[][22][22], int n, int m, int k ){
	srand(time(NULL));
	for ( int i = 0; i < n; i++ ){
		for ( int j = 0; j < m; j++){
			for ( int t = 0; t < k; t++)
				a[i][j][k] = 10+  rand() % ( 99 - 10 + 1);
		}
	}
}

void prt3D(int a[][22][22], int n, int m, int k ){
	for ( int i = 0; i < n; i++ ){
		cout << "TABLE " << i + 1 << ": \n";
		for ( int j = 0; j < m; j++){
			for ( int t = 0; t < k; t++)
				cout << a[i][j][k] << ' ';
			cout << '\n';
		}
		cout << '\n';
	}
}
