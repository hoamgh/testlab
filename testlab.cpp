#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include<fstream>
#include<string.h>
#include<cstring>
#include<algorithm>
using namespace std;

struct pokemon {
	string Name;
	string T1,T2;

	vector<string> Abilities;
	string Tier;
	int HP;
	int Attack;
	int Defense;
	int SpecialAttack;
	int SpecialDefense;
	int Speed;
	vector<string> NextEvolution;
	vector<string> Moves;
};
int safe_stoi(const std::string &str) {
    if(str.empty() || ((!isdigit(str[0])) && (str[0] != '-') && (str[0] != '+'))) return 0;

    char * p;
    long converted = strtol(str.c_str(), &p, 10);
    if(*p != 0) return 0; // chuỗi không thể chuyển đổi hoàn toàn thành số nguyên

    if(converted < INT_MIN || converted > INT_MAX) return 0; // số nguyên nằm ngoài phạm vi của int

    return static_cast<int>(converted);
}
int stoi(const std::string& s) {
    int result = 0;
    bool is_negative = false;

    // Xử lý dấu âm
    if (!s.empty() && s[0] == '-') {
        is_negative = true;
        ++s.begin(); // Di chuyển con trỏ sang phải
    }

    // Chuyển đổi chuỗi thành số nguyên
    for (char c : s) {
        if (c < '0' || c > '9') {
            throw std::invalid_argument("Invalid input string");
        }
        result = result * 10 + (c - '0');
    }

    return is_negative ? -result : result;
}
string layChuoi(string temp){
    string a = ""; 
    for (int i = 0; i < temp.length(); i++) {
        if (isalpha(temp[i]) || temp[i] == ';' || ((temp[i] == ' ') && isalpha(temp[i - 1]) &&isalpha(temp[i + 1]))){
            a += temp[i];
        } 
    }
    return a;
}
pokemon readPokemon(string line_info) {
    pokemon res;
    stringstream ss(line_info);
    getline(ss, res.Name, ',');
    
    string temp;
    getline(ss, temp, ',');
    stringstream e(layChuoi(temp));
    getline(e,res.T1,';');
    getline(e,res.T2);
    getline(ss, temp, ',');
    stringstream b(layChuoi(temp));
    while (getline(b, temp, ';')) {
        res.Abilities.push_back(temp);
    }
    res.HP = safe_stoi(temp);
    getline(ss, temp, ',');
    res.Attack = safe_stoi(temp);
    getline(ss, temp, ',');
    res.Defense = safe_stoi(temp);
    getline(ss, temp, ',');
    res.SpecialAttack = safe_stoi(temp);
    getline(ss, temp, ',');
    res.SpecialDefense = safe_stoi(temp);
    getline(ss, temp, ',');
    res.Speed = safe_stoi(temp);
    getline(ss, temp, ',');
    stringstream f(layChuoi(temp));
    while (getline(f, temp, ';')) {
        res.NextEvolution.push_back(temp);
    }
    getline(ss, temp, '\n');
    stringstream c(layChuoi(temp));
    while (getline(c, temp, ';')) {
        res.Moves.push_back(temp);
    }
    return res;
}
pokemon *** readFile(string file_name,int m,int n, int p) {
    fstream fs(file_name);
    if(fs.is_open()){
        string line_ignore="";
        getline(fs,line_ignore);
        pokemon *** poke = new pokemon**[m];
        for(int i = 0; i < m ; i++ ){
            poke[i] = new pokemon *[n];
            for(int j = 0 ;j < n; j++){
                poke[i][j]= new pokemon [p];
            }
        }
        string line;
        pokemon temp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<p;k++){
                    int x = 0;
                    while(x==0&&!getline(fs, line).eof()){
                        line= "";
                        getline(fs,line);
                        temp=readPokemon(line);
                        
                            if(temp.T1=="Grass"||temp.T2=="Grass"){
                                x=1;
                                poke[i][j][k]= temp;
                            }
                        
                    }
                }
            }
        }
        fs.close();
        return poke;
    }
    
}
vector<pokemon> readVector  (string fileName,int m,int n,int p){
    fstream fs(fileName);
    vector<pokemon> res;
    string read;
    getline(fs,read);
    while (getline(fs,read))
    {   
        pokemon temp=readPokemon(read);
        if(temp.T1=="Grass"||temp.T2=="Grass"){
            res.push_back(temp);
        }
        
    }
    return res;
    

}
pokemon *** read3D(vector<pokemon> vectorPoke,int m,int n,int p){
        pokemon *** poke = new pokemon**[m];
        for(int i = 0; i < m ; i++ ){
            poke[i] = new pokemon *[n];
            for(int j = 0 ;j < n; j++){
                poke[i][j]= new pokemon [p];
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<p;k++){
                    poke[i][j][k]=vectorPoke[(n*p)*i+p*j+k];
                }
            }
        }
        return poke;
}
pokemon ** findSubMatrix(pokemon*** poke, int m, int n , int p, int&length, int& width){
    int max=INT_MIN;
    int rowIndex, colIndex,depthIndex;
    for(int i = 0;i < m ; i++){
        for(int j = 0 ; j < n - length + 1 ; j++)    {
            for(int k = 0 ; k < p - width + 1; k++){
                int sum = 0;
                for(int l = 0;l < length;l++){
                    for( int h = 0; h < width; h++){
                        sum+=poke[i][j+l][k+h].HP;
                    }
                }
                if(sum>max){
                    max=sum;
                    depthIndex=i;
                    rowIndex = j;
				    colIndex = k;
                }
            }
        }
    }
    pokemon** result = new pokemon*[length];
	for (int i = 0; i < length; i++) {
		result[i] = new pokemon[width];
	}
    for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			result[i][j] = poke[depthIndex][i+rowIndex][j+colIndex];

		}
    }
    return result;
}
struct DNode{
	pokemon base;
	DNode* prev;
	DNode* next;
};

struct DList{
	DNode* head;
	DNode* tail;
};

DNode* makeNode(pokemon a){
	DNode* newNode = new DNode;
	newNode->base = a;
	newNode->prev = newNode->next = NULL;
	return newNode;
}

bool areEqual(const pokemon& p1, const pokemon& p2) {
    if (p1.Name != p2.Name ||
        p1.T1 != p2.T1 ||
        p1.T2 != p2.T2 ||
        p1.Tier != p2.Tier ||
        p1.HP != p2.HP ||
        p1.Attack != p2.Attack ||
        p1.Defense != p2.Defense ||
        p1.SpecialAttack != p2.SpecialAttack ||
        p1.SpecialDefense != p2.SpecialDefense ||
        p1.Speed != p2.Speed) {
        return false;
    }

    if (p1.Abilities.size() != p2.Abilities.size() ||
        !std::equal(p1.Abilities.begin(), p1.Abilities.end(), p2.Abilities.begin())) {
        return false;
    }

    if (p1.NextEvolution.size() != p2.NextEvolution.size() ||
        !std::equal(p1.NextEvolution.begin(), p1.NextEvolution.end(), p2.NextEvolution.begin())) {
        return false;
    }

    if (p1.Moves.size() != p2.Moves.size() ||
        !std::equal(p1.Moves.begin(), p1.Moves.end(), p2.Moves.begin())) {
        return false;
    }

    return true;
}
void addTail(DList& list, DNode* newNode){
	if(list.head == NULL){
		list.head = list.tail = newNode;
		return;
	}
	list.tail->next = newNode;
	newNode->prev = list.tail;
	list.tail = newNode;
}
void addHead(DList& list, DNode* newNode){
    if(list.head == NULL){
        list.head = list.tail = newNode;
    } else {
        newNode->next = list.head;
        list.head->prev = newNode;
        list.head = newNode;
    }
}

DList buildDL(vector<pokemon> list){
	DList res{0, 0};
	//res.head = res.tail = NULL;
	for(int i = 0; i < list.size(); i++){
		DNode* newNode = makeNode(list[i]);
		addTail(res, newNode);
	}
	return res;
}
void printDList(DList s){
	for(DNode* cur = s.head; cur != NULL; cur = cur->next){
            cout<<cur->base.Name<<endl;
	}
}

void delDLL(DList& a){
    if(a.head == NULL){
        return;
    }
    DNode* tmp;
    while(a.head != NULL){
        tmp = a.head->next;
        delete a.head;
        a.head = tmp;
    }
}
void removeHead(DList &L)
{
	if (L.head == NULL) return;
	if (L.head == L.tail)
	{
		delete L.head;
		 L.head = NULL;
		 L.tail = NULL;	
		 return;
	}
	DNode* tmp = L.head;
	L.head = L.head -> next;
	L.head->prev = NULL;
	delete tmp;
}
void removeTail(DList &L)
{
	if(L.head == NULL) return;
	if(L.head == L.tail)
	{
		delete L.head;
		L.tail = NULL;
		L.head = NULL;
		return;
	}
	DNode* tmp = L.tail;
	L.tail = L.tail -> prev;
	L.tail->next = NULL;
	delete tmp;
}


void removeBefore(DList &L, pokemon val) {
	if(areEqual(L.head->next->base,val)) removeHead(L);
	else if(L.head == NULL) return;
	else {
		DNode* cur = L.head;
		while (cur->next != NULL && !areEqual(cur->base,val)) {
			cur = cur->next;
		}
		if(areEqual(cur->base,val)) {
			DNode* temp = cur->prev;
			DNode* prev = temp->prev;
			cur->prev = prev;
			prev->prev = cur;
			delete temp;
		}
		return;
	}
}

void addBefore(DList &L, pokemon data, pokemon val) {
	DNode* newNode = makeNode(data);
	if(areEqual(L.head->base,val)) {
		addHead(L, makeNode(data));
		return;
	}
	else if(L.head == NULL) return;
	else {
		DNode* cur = L.head;
		while(cur->next != NULL && areEqual(cur->base ,val) ) {
			cur = cur->next;
		}
		DNode* prev = cur->prev;
		cur->prev = newNode;
		newNode->next = cur;
		newNode->prev = prev;
		prev->prev = newNode;
	}
	return;
}


void addAfter(DList &L, pokemon data, pokemon val)
{
	DNode* newNode = L.head;
	DNode* node = new DNode();
	node->base = data;
	node->next = nullptr;
	node->prev = nullptr;
	DNode* temp;
	while (newNode != nullptr)
	{
		if(areEqual(newNode->base,val))
		{
			if(newNode->next == NULL)
			{
				newNode->next = node;
				node->prev = newNode;
				L.tail = node;
			}			
			temp = newNode -> next;
			newNode->next = node;
			node->next = temp;
			temp->prev=node;
			node->prev=newNode;
			return;
		}
		newNode = newNode->next;
	}
}
void addPos(DList &L, pokemon data, int pos) {
	if( pos < 0 ) return;
	else if ( pos == 0 ) {
		addHead(L, makeNode(data));
	}
	else{
		DNode* newNode = makeNode(data);
		int cnt = 0;
		DNode* temp = L.head;
		while (cnt < pos -1 && temp != NULL) {
			cnt++;
			temp = temp->next;
		}
		newNode->next = temp ->next;
		newNode->prev = temp;
		if(newNode->next != NULL) { 
			temp->next = newNode;
			newNode->next->prev = newNode;
		}
		else {
			L.tail= newNode;
			temp->next = newNode;			
		}
	}
}
void removePos(DList &L, int pos) {
	if (pos < 0 || L.head == NULL) return;
	else if (pos == 0) {
		removeHead(L);
	}
	else {
		int cnt = 0;
		DNode* temp = L.head;
		while (cnt < pos -1 && temp != NULL) {
			cnt++;
			temp= temp->next;
		}
		if (cnt != pos - 1 || temp == NULL ) return;
		DNode* toDelete= temp->next;
		if (toDelete->next == NULL){
			removeTail(L);
		}
		else {
			temp->next = toDelete->next;
			toDelete->next->prev = temp;
			delete toDelete;
		}
	}
}

void removeDuplicate(DList &L) {
	DNode * current = L.head;
	while (current->next != NULL) {
		DNode* after = current->next;
		while (after->next != NULL) {
			if (areEqual(after->base ,current->base)) {
				DNode* temp = after->next;
				after->prev->next = temp;
				temp->prev = after->prev;
				after = temp;
			}
			else {
				after = after->next;
			}
		}
		current = current->next;
	}
	
	DNode* temp = L.head;
	while (1) {
		if (areEqual(temp->base , current->base)) {
			current->prev->next = NULL;
			delete current;
			break;
		}
		if (temp == NULL) {
			break;
		}
		temp = temp->next;
	}
}
bool removeElement(DList &L, pokemon key) {
	DNode* curr = L.head;
	bool flag = false;
	while (curr != NULL) {
		DNode* temp = curr;
		flag = true;
		if (areEqual(curr->base , key)) {
			if (curr->next != NULL) {
				curr->next->next = curr->next;
			 }
			 else {
			 	L.tail = curr->next;
			 }
			 if (curr->prev != NULL) {
			 	curr->prev->next = curr->next;
			 }
			 else {
			 	L.head = curr->next;
			 }
			 curr = curr->next;
			 delete temp;			 
		 }
		 else {
		 	curr = curr->next;
		 }
	 }
	 return flag;
}

int main()
{
    // pokemon *** poke = new pokemon**[3];
    //     for(int i = 0; i < 3 ; i++ ){
    //         poke[i] = new pokemon *[3];
    //         for(int j = 0 ;j < 3; j++){
    //             poke[i][j]= new pokemon [3];
    //         }
    //     }
    // vector<pokemon> vectorPoke;
    // string filename="pokemon.txt";
    // vectorPoke=readVector(filename,3,3,3);
    // poke= read3D(vectorPoke,3,3,3);
    // for(int i = 0 ; i < 3; i++){
    //     for(int j = 0 ; j < 3;j++){
    //         for(int k=0; k< 3 ;k++){
    //             cout<<"a"<<i<<j<<k;
                
    //             cout<<poke[i][j][k].T1<< " "<<poke[i][j][k].T2<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     cout<<endl;
    // }
    vector<pokemon> vectorPoke;
    string filename="pokemon.txt";
    vectorPoke=readVector(filename,3,3,3);
    DList s;
    s=buildDL(vectorPoke);
	printDList(s);
	removePos(s,0);
    cout<<endl;
    printDList(s);
    return 0;
    
}
