#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <climits>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void gen2D(int **&a, int row, int col) {  
	srand(time(NULL));
	a = new int *[row];
	for (int i = 0; i < row; i++) {
		a[i] = new int [col];
	}
	for (int i = 0; i < row; i++) {
		for (int k = 0; k < col; k++) {
			a[i][k] = rand() % 10 + 1;
		}
	}
}

void print2D(int **a, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int k = 0; k < col; k++) {
			cout << a[i][k] << "\t";
		}
		cout << endl;
	}
}

void gen3d(int ***&a, int m, int n, int p) 
{
	a = new int**[m];
	for (int i = 0; i < m; i++)
	{
		a[i] = new int*[n];
		for (int j = 0; j < n; j++)
			a[i][j] = new int[p];
	}
	
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < p; k++)
				a[i][j][k] = rand() % 10 + 1;
}

void print3d(int ***a, int m, int n, int p)
{
	for (int i = 0; i < m; i++)
	{
		cout << "Floor " << i + 1 << endl;
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < p; k++)
				cout << a[i][j][k] << "\t";
			cout << endl; 
		}
		cout << endl << endl;
	}
}

int** findSubmatrix(int** a, int length, int width, int &lres, int &wres) {
	cin >> lres >> wres;
	
	if (lres < 0 || lres > length || wres < 0 || wres > width) {
		return nullptr;
	}
	
	int** result = new int*[lres];
	for (int i = 0; i < lres; i++) {
		result[i] = new int[wres];
	}
	
	int sumMax = INT_MIN;
	int rowIndex, colIndex;
	
	for (int i = 0; i < length - lres + 1; i++) {
		for (int j = 0; j < width - wres + 1; j++) {
			int sum = 0;
			for (int k = 0; k < lres; k++) {
				for (int l = 0; l < wres; l++) {
					sum += a[i + k][j + l];
				}
			}
			if (sum > sumMax) {
				sumMax = sum;
				rowIndex = i;
				colIndex = j;
			}
		}
	}
	
	for (int i = 0; i < lres; i++) {
		for (int j = 0; j < wres; j++) {
			result[i][j] = a[rowIndex + i][colIndex + j];
		}
	}
	
	return result;
}


struct Examinee
{ 	
	string id;
	float maths, literature, physics, chemistry, biology, history, geography, civic_education, natural_science, social_science, foreign_language;
};

Examinee readExaminee(string line_info){
	Examinee res;
	
	int pos;
	while((pos = line_info.find(",,", 0)) != string::npos){
		line_info.insert(pos + 1, "0");
	}
	while((pos = line_info.find(",", 0)) != string::npos){
		line_info.replace(pos, 1, " ");
	}
	stringstream ss(line_info);
	//cout << line_info << endl;
	string name;	
	ss >> res.id;
	ss >> name;
	ss >> res.maths;
	ss >> res.literature;
	ss >> res.physics;
	ss >> res.chemistry;
	ss >> res.biology;
	ss >> res.history;
	ss >> res.geography;
	ss >> res.civic_education;
	ss >> res.natural_science;
	ss >> res.social_science;
	ss >> res.foreign_language;
	res.natural_science = res.physics + res.biology + res.chemistry;
	res.social_science = res.history + res.civic_education + res.geography;
	return res;
}

vector<Examinee> readExamineeList(string file_name){
	ifstream ifs(file_name);
	if(!ifs){
		cout << "Khong mo duoc file";
		exit(1);
	}
	vector<Examinee> list;
	string read;
	getline(ifs, read);
	while(getline(ifs, read)){
		list.push_back(readExaminee(read));
	}
	ifs.close();
	return list;
}

//ostream& operator<<(ostream& os, const Examinee &e){
//	float compulsory_score = e.maths + e.literature + e.foreign_language;
//	os << compulsory_score << " " << e.natural_science << " " << e.social_science;
//	return os;
//}

void writeScores(vector<Examinee> examinee_list, string out_file_name){
	ofstream ofs(out_file_name);
	if(!ofs){
		cout << "Khong mo duoc file ghi";
		exit(1);
	}
	ofs << "SBD BB KHTN KHXH" << endl;
	for(int i = 0; i < examinee_list.size(); i++){
		Examinee e = examinee_list[i];
		float compulsory_score = e.maths + e.literature + e.foreign_language;
		ofs << e.id << " " << compulsory_score << " " << e.natural_science << " " << e.social_science << endl;
	}
	ofs.close();
}

/*struct NODE 
{
	int key;
	NODE* pNext;
};

struct List
{
    NODE* pHead;
    NODE* pTail;
};

NODE* createNode(int data)
{
	NODE *newnode = new NODE;
	newnode -> key = data;
	newnode -> pNext = NULL;
	return newnode;
}

List createList(NODE* pNode)
{
	List L;
	L.pHead = pNode;
	L.pTail = pNode;
	return L;
}

void addHead(List &L, int data)
{
	NODE *newnode = createNode(data);
	if (L.pHead == NULL)
	{
		L.pHead = newnode;
		L.pTail = newnode;
	}
	else
	{
		newnode -> pNext = L.pHead;
		L.pHead = newnode;
	}
}

void addTail(List &L, int data)
{
	NODE *newnode = createNode(data);
	NODE *curnode = L.pTail;
	if (L.pHead == NULL)
	{
		L.pHead = newnode;
		L.pTail = newnode;
	}
	else
	{
		L.pTail -> pNext = newnode;
		L.pTail = newnode;
	}
}

void printList(List L)
{
	NODE *curnode = L.pHead;
	while (curnode != NULL)
	{
		cout << curnode -> key <<"->";
		curnode = curnode -> pNext;
		if (curnode == NULL)
		{
			cout<<"NULL";
		}
	}
}

void addPos(List &L, int data, int pos) {
	NODE* curNode = L.pHead;
	int i = 0;
	while (curNode && i < pos - 1) {
		i++;
		curNode = curNode->pNext;
	}
	
	if (!curNode) return;
	if (curNode == L.pHead && pos == 0) {
		addHead(L, data);
		return;
	}
	if (curNode->pNext == L.pTail && pos != 1) {
		addTail(L, data);
		return;
	}
	NODE* tmp = createNode(data);
	tmp->pNext = curNode->pNext;
	curNode->pNext = tmp;
}

void removePos(List &L, int pos) {
	NODE* curNode = L.pHead;
	int i = 0;
	while (curNode && i < pos - 1) {
		i++;
		curNode = curNode->pNext;
	}
	
	if (!curNode || curNode == L.pTail) return;
	if (curNode == L.pHead && pos == 0) {
		L.pHead = L.pHead->pNext;
		curNode->pNext = nullptr;
		delete curNode;
		return;
	}
	if (curNode->pNext == L.pTail) {
		L.pTail = curNode;
	}
	NODE* tmp = curNode->pNext;
	curNode->pNext = tmp->pNext;
	tmp->pNext = nullptr;
	delete tmp;
}
*/
struct DNODE {
	int key;
	DNODE* pNext;
	DNODE* pPrev;
};
struct DList {
	DNODE* pHead;
	DNODE* pTail;
};
DNODE* createNode(int data)
{
	DNODE* Node = new DNODE;
	Node->key = data;
	Node->pNext = NULL;
	Node->pPrev = NULL;
	return Node;
}
DList createList(DNODE* pNode)
{
	DList List;
	List.pHead = pNode;
	List.pTail = pNode;
	return List;
}
void addHead(DList& L,int data)
{
	DNODE* Node = createNode(data);
	if (L.pHead == NULL)
	{
		L.pHead = Node;
		L.pTail = Node;
	}
	else 
	{
		Node->pNext = L.pHead;
		L.pHead->pPrev = Node;
		L.pHead = Node;
	}
}
void addTail(DList & L,int data)
{
	DNODE *Node = createNode(data);
	if (L.pTail==NULL)
	{
		L.pHead = Node;
		L.pTail = Node;
	}
	else
	{
		L.pTail->pNext = Node;
		Node->pPrev = L.pTail;
		L.pTail = Node;
	}
}
void printList(DList L)
{
	DNODE* current = L.pHead;
	while (current!=NULL)
	{
		cout << current->key<<endl;
		current=current->pNext;
	}
}
void removeHead(DList &L)
{
 	if (L.pHead == NULL) return;
 	if (L.pHead == L.pTail)
 	{
 		delete L.pHead;
		 L.pHead = NULL;
		 L.pTail = NULL;	
		 return;
	}
	DNODE* tmp = L.pHead;
	L.pHead = L.pHead -> pNext;
	L.pHead->pPrev = NULL;
	delete tmp;
}
void removeTail(DList &L)
{
	if(L.pTail == NULL) return;
	if(L.pHead == L.pTail)
	{
		delete L.pTail;
		L.pTail = NULL;
		L.pHead = NULL;
		return;
	}
	DNODE* tmp = L.pTail;
	L.pTail = L.pTail -> pPrev;
	L.pTail->pNext = NULL;
	delete tmp;
}
void printDList(DList L)
{
	DNODE* tmp = L.pTail;
	while(tmp != NULL)
	{
		cout << tmp -> key << endl;
		tmp = tmp -> pPrev;
	}
}
int main() {

	
	//srand(time(NULL));
//	int ***a;
//	int m = 5, n = 5, p = 5;
//	gen3d(a, m, n, p);
//	print3d(a, m, n, p);
//	
//	int **a;
//	int row = 4, col = 4;
//	gen2D(a, row, col);
//	print2D(a, row, col);
//	int lres, wres;
//	int **result = findSubmatrix(a, row, col, lres, wres);
//	print2D(result, lres, wres);	
	//string file_name = "D:\data.txt";
	//string file_out_name = "D:\output.txt";
	//vector<Examinee> list = readExamineeList(file_name);
	//writeScores(list, file_out_name);
///	string a = "BD1200001,,4.0,5.0,,,,4.25,7.0,7.75,,,2.0,N1,BinhDinh";
//	Examinee b = readExaminee(a);
//	cout << b.id << " " << b.maths;*/

	/*NODE *curnode  = createNode(1);
	cout<<curnode -> key;
	
	List L = createList(curnode);
	addHead(L, 2);
	addTail(L, 3);
	printList(L);
	*/
/*	NODE *node = createNode(1);
	List L = createList(node);
	addPos(L,2,0);
	addPos(L,3,1);
	addPos(L,4, 10);
	
	printList(L);
	cout << endl;
	removePos(L, 0);
	removePos(L, 10);
	printList(L);*/
	DList myList= createList(createNode(1));
	addHead(myList,2);
	addHead(myList,3);
	addTail(myList,4);
	addTail(myList,5);
	printList(myList);
	cout << endl;
	removeHead(myList);
	printList(myList);	
	cout << endl;
	printDList(myList);
	cout << endl;
	removeTail(myList);
	printList(myList);
	return 0;
}




