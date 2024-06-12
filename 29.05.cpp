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
		return NULL;
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


//struct Examinee
//{ 	
//	string id;
//	float maths, literature, physics, chemistry, biology, history, geography, civic_education, natural_science, social_science, foreign_language;
//};
//
//Examinee readExaminee(string line_info){
//	Examinee res;
//	
//	int pos;
//	while((pos = line_info.find(",,", 0)) != string::npos){
//		line_info.insert(pos + 1, "0");
//	}
//	while((pos = line_info.find(",", 0)) != string::npos){
//		line_info.replace(pos, 1, " ");
//	}
//	stringstream ss(line_info);
//	//cout << line_info << endl;
//	string name;	
//	ss >> res.id;
//	ss >> name;
//	ss >> res.maths;
//	ss >> res.literature;
//	ss >> res.physics;
//	ss >> res.chemistry;
//	ss >> res.biology;
//	ss >> res.history;
//	ss >> res.geography;
//	ss >> res.civic_education;
//	ss >> res.natural_science;
//	ss >> res.social_science;
//	ss >> res.foreign_language;
//	res.natural_science = res.physics + res.biology + res.chemistry;
//	res.social_science = res.history + res.civic_education + res.geography;
//	return res;
//}

//vector<Examinee> readExamineeList(string file_name){
//	ifstream ifs(file_name);
//	if(!ifs){
//		cout << "Khong mo duoc file";
//		exit(1);
//	}
//	vector<Examinee> list;
//	string read;
//	getline(ifs, read);
//	while(getline(ifs, read)){
//		list.push_back(readExaminee(read));
//	}
//	ifs.close();
//	return list;
//}

//ostream& operator<<(ostream& os, const Examinee &e){
//	float compulsory_score = e.maths + e.literature + e.foreign_language;
//	os << compulsory_score << " " << e.natural_science << " " << e.social_science;
//	return os;
//}

//void writeScores(vector<Examinee> examinee_list, string out_file_name){
//	ofstream ofs(out_file_name);
//	if(!ofs){
//		cout << "Khong mo duoc file ghi";
//		exit(1);
//	}
//	ofs << "SBD BB KHTN KHXH" << endl;
//	for(int i = 0; i < examinee_list.size(); i++){
//		Examinee e = examinee_list[i];
//		float compulsory_score = e.maths + e.literature + e.foreign_language;
//		ofs << e.id << " " << compulsory_score << " " << e.natural_science << " " << e.social_science << endl;
//	}
//	ofs.close();
//}

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
//struct DNODE {
//	int key;
//	DNODE* pNext;
//	DNODE* pPrev;
//};
//struct DList {
//	DNODE* pHead;
//	DNODE* pTail;
//};
//DNODE* createNode(int data)
//{
//	DNODE* Node = new DNODE;
//	Node->key = data;
//	Node->pNext = NULL;
//	Node->pPrev = NULL;
//	return Node;
//}
//DList createList(DNODE* pNode)
//{
//	DList List;
//	List.pHead = pNode;
//	List.pTail = pNode;
//	return List;
//}
//void addHead(DList& L,int data)
//{
//	DNODE* Node = createNode(data);
//	if (L.pHead == NULL)
//	{
//		L.pHead = Node;
//		L.pTail = Node;
//	}
//	else 
//	{
//		Node->pNext = L.pHead;
//		L.pHead->pPrev = Node;
//		L.pHead = Node;
//	}
//}
//void addTail(DList & L,int data)
//{
//	DNODE *Node = createNode(data);
//	if (L.pTail==NULL)
//	{
//		L.pHead = Node;
//		L.pTail = Node;
//	}
//	else
//	{
//		L.pTail->pNext = Node;
//		Node->pPrev = L.pTail;
//		L.pTail = Node;
//	}
//}
//void printList(DList L)
//{
//	DNODE* current = L.pHead;
//	while (current!=NULL)
//	{
//		cout << current->key << "\t";
//		current = current->pNext;
//	}
//	cout << endl;
//	cout << endl;
//}
//void removeHead(DList &L)
//{
// 	if (L.pHead == NULL) return;
// 	if (L.pHead == L.pTail)
// 	{
// 		delete L.pHead;
//		 L.pHead = NULL;
//		 L.pTail = NULL;	
//		 return;
//	}
//	DNODE* tmp = L.pHead;
//	L.pHead = L.pHead -> pNext;
//	L.pHead->pPrev = NULL;
//	delete tmp;
//}
//void removeTail(DList &L)
//{
//	if(L.pTail == NULL) return;
//	if(L.pHead == L.pTail)
//	{
//		delete L.pTail;
//		L.pTail = NULL;
//		L.pHead = NULL;
//		return;
//	}
//	DNODE* tmp = L.pTail;
//	L.pTail = L.pTail -> pPrev;
//	L.pTail->pNext = NULL;
//	delete tmp;
//}
//void printDList(DList L)
//{
//	DNODE* tmp = L.pTail;
//	while(tmp != NULL)
//	{
//		cout << tmp -> key << endl;
//		tmp = tmp -> pPrev;
//	}
//}
//
//void removeBefore(DList &L, int val) {
//	if(L.pHead->pNext->key == val) removeHead(L);
//	else if(L.pHead == NULL) return;
//	else {
//		DNODE* cur = L.pHead;
//		while (cur->pNext != NULL && cur->key != val) {
//			cur = cur->pNext;
//		}
//		if(cur->key == val) {
//			DNODE* temp = cur->pPrev;
//			DNODE* prev = temp->pPrev;
//			cur->pPrev = prev;
//			prev->pNext = cur;
//			delete temp;
//		}
//		return;
//	}
//}
//
//void addBefore(DList &L, int data, int val) {
//	DNODE* newNode = createNode(data);
//	if(L.pHead->key == val) {
//		addHead(L, data);
//		return;
//	}
//	else if(L.pHead == NULL) return;
//	else {
//		DNODE* cur = L.pHead;
//		while(cur->pNext != NULL && cur->key != val ) {
//			cur = cur->pNext;
//		}
//		DNODE* prev = cur->pPrev;
//		cur->pPrev = newNode;
//		newNode->pNext = cur;
//		newNode->pPrev = prev;
//		prev->pNext = newNode;
//	}
//	return;
//}
//
//void removeAfter(DList& L, int val)
//{
//	DNODE* newNode = L.pHead;
//	DNODE* temp;
//	while (newNode != nullptr)
//	{
//		if(newNode->key == val)
//		{
//			if(newNode->pNext == NULL)
//			{
//				temp = newNode->pNext;
//				newNode->pNext = NULL;
//				delete temp;
//				L.pTail = newNode;
//				return;
//			}
//			temp = newNode -> pNext;
//			newNode->pNext = newNode->pNext->pNext;
//			(newNode -> pNext)->pPrev = newNode;
//			delete temp;
//			return;
//		}
//		newNode = newNode->pNext;
//	}
//}
//void addAfter(DList &L, int data, int val)
//{
//	DNODE* newNode = L.pHead;
//	DNODE* node = new DNODE();
//	node->key = data;
//	node->pNext = nullptr;
//	node->pPrev = nullptr;
//	DNODE* temp;
//	while (newNode != nullptr)
//	{
//		if(newNode->key == val)
//		{
//			if(newNode->pNext == NULL)
//			{
//				newNode->pNext = node;
//				node->pPrev = newNode;
//				L.pTail = node;
//			}			
//			temp = newNode -> pNext;
//			newNode->pNext = node;
//			node->pNext = temp;
//			temp->pPrev=node;
//			node->pPrev=newNode;
//			return;
//		}
//		newNode = newNode->pNext;
//	}
//}
//void addPos(DList &L, int data, int pos) {
//	if( pos < 0 ) return;
//	else if ( pos == 0 ) {
//		addHead(L, data);
//	}
//	else{
//		DNODE* newNode = createNode(data);
//		int cnt = 0;
//		DNODE* temp = L.pHead;
//		while (cnt < pos -1 && temp != NULL) {
//			cnt++;
//			temp = temp->pNext;
//		}
//		newNode->pNext = temp ->pNext;
//		newNode->pPrev = temp;
//		if(newNode->pNext != NULL) { 
//			temp->pNext = newNode;
//			newNode->pNext->pPrev = newNode;
//		}
//		else {
//			L.pTail= newNode;
//			temp->pNext = newNode;			
//		}
//	}
//}
//void removePos(DList &L, int pos) {
//	if (pos < 0 || L.pHead == NULL) return;
//	else if (pos == 0) {
//		removeHead(L);
//	}
//	else {
//		int cnt = 0;
//		DNODE* temp = L.pHead;
//		while (cnt < pos -1 && temp != NULL) {
//			cnt++;
//			temp= temp->pNext;
//		}
//		if (cnt != pos - 1 || temp == NULL ) return;
//		DNODE* toDelete= temp->pNext;
//		if (toDelete->pNext == NULL){
//			removeTail(L);
//		}
//		else {
//			temp->pNext = toDelete->pNext;
//			toDelete->pNext->pPrev = temp;
//			delete toDelete;
//		}
//	}
//}
//
//void removeDuplicate(DList &L) {
//	DNODE * current = L.pHead;
//	while (current->pNext != NULL) {
//		DNODE* after = current->pNext;
//		while (after->pNext != NULL) {
//			if (after->key == current->key) {
//				DNODE* temp = after->pNext;
//				after->pPrev->pNext = temp;
//				temp->pPrev = after->pPrev;
//				after = temp;
//			}
//			else {
//				after = after->pNext;
//			}
//		}
//		current = current->pNext;
//	}
//	
//	DNODE* temp = L.pHead;
//	while (1) {
//		if (temp->key == current->key) {
//			current->pPrev->pNext = NULL;
//			delete current;
//			break;
//		}
//		if (temp == NULL) {
//			break;
//		}
//		temp = temp->pNext;
//	}
//}
//bool removeElement(DList &L, int key) {
// 	DNODE* curr = L.pHead;
// 	bool flag = false;
// 	while (curr != NULL) {
// 		DNODE* temp = curr;
// 		flag = true;
// 		if (curr->key == key) {
// 			if (curr->pNext != NULL) {
// 				curr->pNext->pPrev = curr->pPrev;
//			 }
//			 else {
//			 	L.pTail = curr->pPrev;
//			 }
//			 if (curr->pPrev != NULL) {
//			 	curr->pPrev->pNext = curr->pNext;
//			 }
//			 else {
//			 	L.pHead = curr->pNext;
//			 }
//			 curr = curr->pNext;
//			 delete temp;			 
//		 }
//		 else {
//		 	curr = curr->pNext;
//		 }
//	 }
//	 return flag;
//}

//struct NODE {
//	int key;
//	NODE* pNext;
//};
//
//struct Stack {
//	NODE* top;
//	int count;
//};
//
//Stack* khoitao(int key) {
//	Stack* stack = new Stack;
//	stack->top = new NODE{key, nullptr};
//	stack->count = 1;
//	return stack;
//}
//
//void push(Stack* stack, int key) {
//	NODE* newNODE = new NODE{key, stack->top};
//	stack->top = newNODE;
//	stack->count++;
//}
//
//int pop(Stack* stack) {
//	if(stack->top == nullptr) {
//		cout << "Stack is empty";
//	}
//	NODE* tmp = stack->top;
//	int popedKey = tmp->key;
//	stack->top = stack->top->pNext;
//	delete tmp;
//	stack->count--;
//	return popedKey;
//}
//
//int countS(Stack* stack) {
//	return stack->count;
//}
//
//bool check(Stack* stack) {
//	return stack->top == nullptr;
//}
//
//void printS(Stack* stack) {
//	NODE* cur = stack->top;
//	while(cur != nullptr) {
//		cout << cur->key << "\t";
//		cur = cur->pNext;
//	}
//	cout << endl;
//}
//
//NODE* createNode1(int data)
//{
//	NODE *newnode = new NODE;
//	newnode -> key = data;
//	newnode -> pNext = NULL;
//	return newnode;
//}
//
//struct Queue{
//	NODE* head;
//};
//
//void initializeQueue(Queue &q,int data){
//	q.head = createNode1(data);
//}
//
//void enqueue(Queue &q, int data){
//	if(q.head == NULL){
//		initializeQueue(q, data);
//		return;
//	}
//	
//	NODE* p = createNode1(data);
//	p->pNext = q.head;
//	q.head = p;
//}
//
//int dequeue(Queue &q){
//	NODE* p = q.head;
//	while(p->pNext->pNext != NULL)
//		p = p->pNext;
//	
//	int ans = p->pNext->key;
//	delete p->pNext;
//	p->pNext = NULL;
//	return ans;
//}
//
//int countElement(Queue q){
//	if(q.head == NULL)
//		return 0;
//	
//	int cnt = 0;
//	NODE* p = q.head;
//	while(p != NULL){
//		cnt++;
//		p = p->pNext;
//	}
//	return cnt;
//}
//
//bool isEmpty(Queue q){
//	if(q.head == NULL)
//		return true;
//	return false;
//}
//
//void printQueue(Queue q){
//	NODE* p = q.head;
//	while(p != NULL){
//		cout << p->key << "\t";
//		p = p->pNext;
//	}
//	cout << endl;
//}

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

Examinee ***read3DExaminee(vector<Examinee> examinee_list, int p, int q, int r) {
	Examinee ***examineeMatrix = new Examinee**[p];
	for(int i = 0; i < p; ++i) {
		examineeMatrix[i] = new Examinee*[q];
		for(int j = 0; j < q; ++j) {
			examineeMatrix[i][j] = new Examinee[r];
			for(int k = 0; k < r; ++k) {
				examineeMatrix[i][j][k] = examinee_list[(q * r) * i + r * j + k];
			}
		}
	}
	
	return examineeMatrix;
}

void printExaminee(Examinee x)
{
    cout << x.id << " " << x.maths << " " << x.literature << " " << x.physics << " "
        << x.chemistry << " " << x.biology << " " << x.history << " " << x.geography
        << " " << x.civic_education << " " << x.natural_science << " " << x.social_science <<" " << x.foreign_language << endl;
}

struct DNODE_FILE {
	Examinee key;
	DNODE_FILE* pNext;
	DNODE_FILE* pPrev;
};
struct DList {
	DNODE_FILE* pHead;
	DNODE_FILE* pTail;
};
DNODE_FILE* createNode(Examinee data)
{
	DNODE_FILE* Node = new DNODE_FILE;
	Node->key = data ;
	Node->pNext = NULL;
	Node->pPrev = NULL;
	return Node;
}
DList createList(DNODE_FILE* pNode)
{
	DList List;
	List.pHead = pNode;
	List.pTail = pNode;
	return List;
}
void addHead(DList& L, Examinee data)
{
	DNODE_FILE* Node = createNode(data);
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
void addTail(DList & L,Examinee data)
{
	DNODE_FILE *Node = createNode(data);
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

void printDListBW(DList L)
{
	DNODE_FILE* tmp = L.pTail;
	while(tmp != NULL)
	{
		printExaminee(tmp->key);
	}
}

void printDListFW(DList L)
{
    DNODE_FILE* tmp = L.pHead;
	while(tmp != NULL)
	{
		printExaminee(tmp->key);
		tmp = tmp->pNext;
	}
}

DList addtoDList(string filename)
{
    DList L{0,0};
    vector <Examinee> list = readExamineeList(filename);
    int size = list.size();
    for(int i = 0 ; i < size ; i++)
    {
        addTail(L , list[i]);
    }
    return L;
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
//	DList myList= createList(createNode(1));
//	int data, val;
//	cin >> data >> val;
//	addHead(myList,2);
//	addHead(myList,3);
//	addTail(myList,4);
//	addTail(myList,5);
//	printList(myList);
//	cout << endl;
//	removeHead(myList);
//	printList(myList);	
//	cout << endl;
//	printDList(myList);
//	cout << endl;
//	removeTail(myList);
//	printList(myList);
//	int a[10] = {1, 2, 3, 2, 5, 1, 1, 2, 3, 5};
//	DList L;
//	L.pHead = NULL;
//	L.pTail = NULL;
////	int data, val; cin >> data >>  val;
//	for(int i = 0 ; i < 10; ++i) {
//		addTail(L, a[i]);
//	}
//	printList(L);
//	removeBefore(L, val);
//	addBefore(L, data, val);
//	removeAfter(L,7);
//	addAfter(L, 11, 7);
//	addPos(L, 11, 2);
//	removePos(L, 5);

	//removeDuplicate(L);
//	removeElement(L, 1);
//	printList(L);
//	Stack* stack = khoitao(1);
//	push(stack, 2);
//	push(stack, 3);
//	push(stack, 4);
//	push(stack, 5);
//	printS(stack);
//	pop(stack);
//	pop(stack);
//	
//	pop(stack);
//	printS(stack);
//	cout << countS(stack);
//	pop(stack);
//	pop(stack);
//	if(check(stack)) {
//		cout << "Stack is empty";
//	}
	
//	Queue q;
//	initializeQueue(q, 1);
//	enqueue(q, 2);
//	enqueue(q,3);
//	enqueue(q,4);
//	enqueue(q,5);
//	printQueue(q);
//	cout << countElement(q) << endl;
//	
//	while(!isEmpty(q)){
//		cout << dequeue(q) << endl;
//		printQueue(q);
//	}
//	
//	if(isEmpty(q))
//		cout <<"Queue is empty" << endl;

//	int p, q, r;
//	cin >> p >> q >> r;
//	vector<Examinee> vect;
//	vect = readExamineeList("D:\\data.txt");
//	Examinee ***examineeList = read3DExaminee(vect, p, q, r);
//	for(int i = 0; i < p; ++i) {
//		for(int j = 0; j < q; ++j) {
//			for(int k = 0; k < r; ++k) {
//				cout << examineeList[i][j][k].id << ' ';
//			}
//			cout << endl;
//		}
//		cout << endl << endl;
//	}
	string filename = "D:\\data.txt";
	DList L = addtoDList(filename);
	printDListFW(L);
	return 0;
}




