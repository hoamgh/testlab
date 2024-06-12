#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

struct Pokemon {
    string name = "";
    vector<string> types;
    vector<string> abilities;
    string tier = "";
    int hp;
    int attack;
    int defense;
    int specialAttack;
    int specialDefense;
    int speed;
    vector<string> nextEvolution;
    vector<string> moves;
};

struct Node {
    Pokemon data;
    Node* prev;
    Node* next;
};
struct List
{
    Node* head;
    Node* tail;
};
void addTail(List& list, Pokemon value) {
    Node* newNode = new Node{value, nullptr, nullptr};

        if (list.tail == nullptr) { // If the list is empty
            list.head = list.tail = newNode;
        } else {
            list.tail->next = newNode;
            newNode->prev = list.tail;
            list.tail = newNode;
        }
}
int stoint(string s)
{
    for(int i = 0; i < s.length(); ++i)
    {
        if(!isdigit(s[i])) 
        {
            s.erase(i,1);
            --i;
        }
    }
    int num = 0;
    for(int i = 0; i < s.length(); ++i)
    {
        num = num*10 + (s[i] - '0');
    }
    return num;
}
float stringToFloat(string str) {
    float result = 0.0f;
    int sign = 1;
    size_t i = 0;
    bool decimalPointEncountered = false;
    float decimalMultiplier = 0.1f;

    // Kiểm tra dấu
    if (str[i] == '-') {
        sign = -1;
        ++i;
    } else if (str[i] == '+') {
        ++i;
    }

    for (; i < str.length(); ++i) {
        if (str[i] == '.') {
            decimalPointEncountered = true;
            continue;
        }

        if (str[i] >= '0' && str[i] <= '9') {
            if (!decimalPointEncountered) {
                result = result * 10 + (str[i] - '0');
            } else {
                result += (str[i] - '0') * decimalMultiplier;
                decimalMultiplier *= 0.1f;
            }
        } else {
            // Nếu gặp ký tự không hợp lệ, trả về 0 hoặc có thể xử lý lỗi
            return 0.0f;
        }
    }

    return result * sign;
}

vector<string> multy(string s) {
    vector<string> mystring;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '\'' || s[i] == '[' || s[i] == ']' || s[i] == '\"') {
            s.erase(i, 1);
            --i;
        }
    }
    istringstream ss(s);
    string value;
    while (getline(ss, value, ';')) {
        if(value[0] == ' ') value.erase(0,1);
        mystring.push_back(value);
    }
    return mystring;
}

vector<Pokemon> readfile(string filename) {
    vector<Pokemon> myPo; //node* newNode = new node();
    Pokemon poke;
    ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Unable to open file" << std::endl;
        return myPo;
    }
    string line;
    getline(file, line); // Skip the header line
    while (getline(file, line)) {
        // istringstream ss(line);
        // getline(ss, poke.name, ',');
        // getline(ss, line, ',');
        // poke.types = multy(line);
        // getline(ss, line, ',');
        // poke.abilities = multy(line);
        // getline(ss, poke.tier, ',');
        //  ss >> poke.hp;
        //  ss.ignore();
        //  ss >> poke.attack;
        //  ss.ignore();
        //  ss >> poke.defense;
        //  ss.ignore();
        //  ss >> poke.specialAttack;
        //  ss.ignore();
        //  ss >> poke.specialDefense;
        //  ss.ignore();
        //  ss >> poke.speed;
        //  ss.ignore();
        //  getline(ss, line, ',');
        //  poke.nextEvolution = multy(line);
        //  getline(ss, line);
        //  poke.moves = multy(line);
        istringstream ss(line);

        getline(ss, poke.name, ',');
        getline(ss, line, ',');
        poke.types = multy(line);

        getline(ss, line, ',');
        poke.abilities = multy(line);

        getline(ss, poke.tier, ',');
        
        getline(ss, line, ',');
        poke.hp = stoi(line);

        getline(ss, line, ',');
        poke.attack = stoi(line);

        getline(ss, line, ',');
        poke.defense = stoi(line);

        getline(ss, line, ',');
        poke.specialAttack = stoi(line);

        getline(ss, line, ',');
        poke.specialDefense = stoi(line);

        getline(ss, line, ',');
        poke.speed = stoi(line);

        getline(ss, line, ',');
        poke.nextEvolution = multy(line);

        getline(ss, line);
        poke.moves = multy(line);
        myPo.push_back(poke);
    }
    file.close();
    return myPo;
}

List readFileList(string filename)
{
    List L = {nullptr, nullptr};
    Pokemon poke;
    ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Unable to open file" << std::endl;
        return L;
    }
    string line;
    getline(file, line); // Skip the header line
    while (getline(file, line)) {
        istringstream ss(line);

        getline(ss, poke.name, ',');

        getline(ss, line, ',');
        poke.types = multy(line);

        getline(ss, line, ',');
        poke.abilities = multy(line);

        getline(ss, poke.tier, ',');

        ss >> poke.hp;
        ss.ignore();

        ss >> poke.attack;
        ss.ignore();

        ss >> poke.defense;
        ss.ignore();

        ss >> poke.specialAttack;
        ss.ignore();

        ss >> poke.specialDefense;
        ss.ignore();

        ss >> poke.speed;
        ss.ignore();

        getline(ss, line, ',');
        poke.nextEvolution = multy(line);

        getline(ss, line);
        poke.moves = multy(line);

        addTail(L,poke);
    }
    file.close();
    return L;
}
void removeWeakPokemons(List& list, int threshold) {
    Node* current = list.head;
    while (current != nullptr) {
        if (current->data.attack < threshold) {
            Node* toDelete = current;
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                list.head = current->next;
            }
            if (current->next) {
                current->next->prev = current->prev;
            } else {
                list.tail = current->prev;
            }
            current = current->next;
            delete toDelete;
        } else {
            current = current->next;
        }
    }
}
void printList(List& list) {
    Node* temp = list.head;
    int i = 0;
    while (temp != nullptr && i < 10) {
        cout << "Pokemon Name: " << temp->data.name << endl;
        cout << "Types: ";
        for (const auto& type : temp->data.types) {
            cout << type << " ";
        }
        cout << endl;
        cout << "Abilities: ";
        for (const auto& ability : temp->data.abilities) {
            cout << ability << " ";
        }
        cout << endl;
        cout << "Tier: " << temp->data.tier << endl;
        cout << "HP: " << temp->data.hp << endl;
        cout << "Attack: " << temp->data.attack << endl;
        cout << "Defense: " << temp->data.defense << endl;
        cout << "Special Attack: " << temp->data.specialAttack << endl;
        cout << "Special Defense: " << temp->data.specialDefense << endl;
        cout << "Speed: " << temp->data.speed << endl;
        cout << "Next Evolutions: ";
        for (const auto& evo : temp->data.nextEvolution) {
            cout << evo << ", ";
        }
        cout << endl;
        cout << "Moves: ";
        for (const auto& move : temp->data.moves) {
            cout << move << ", ";
        }
        cout << endl << "---------------------" << endl;
        temp = temp->next;
        ++i;
    }
}
vector<vector<vector<Pokemon>>> create3D(List L, int m, int n, int p)
{
    vector<vector<vector<Pokemon>>> vec(m, vector<vector<Pokemon>>(n, vector<Pokemon>(p)));
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            for(int k = 0; k < p; ++k)
            {
                vec[i][j][k] = L.head->data;
                L.head = L.head->next;
            }
        }
    }
    return vec;
}
void print3D(vector<vector<vector<Pokemon>>> poke, int m, int n, int p)
{
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            for(int k = 0; k < p; ++k)
            {
                cout << poke[i][j][k].name << endl;
            }
        }
    }
}
int main() {
    string filename = "pokemon_temp.csv";
    List pokemonList = readFileList(filename);
    //printList(pokemonList);
    vector<vector<vector<Pokemon>>> pikachu = create3D(pokemonList, 3, 4, 5);
    print3D(pikachu, 3,4,5);
    return 0;
    //printList(myPokemon);
    //cout << myPokemon.head->data.name;
    // for (int i = 0; i < 10 && i < myPokemon.size(); ++i) {
    //     cout << "Name: " << myPokemon[i].name << endl;
    //     cout << "Types: ";
    //     for (const auto& type : myPokemon[i].types) {
    //         cout << type << " ";
    //     }
    //     cout << endl;

    //     cout << "Abilities: ";
    //     for (const auto& ability : myPokemon[i].abilities) {
    //         cout << ability << " ";
    //     }
    //     cout << endl;

    //     cout << "Tier: " << myPokemon[i].tier << endl;
    //     cout << "HP: " << myPokemon[i].hp << endl;
    //     cout << "Attack: " << myPokemon[i].attack << endl;
    //     cout << "Defense: " << myPokemon[i].defense << endl;
    //     cout << "Special Attack: " << myPokemon[i].specialAttack << endl;
    //     cout << "Special Defense: " << myPokemon[i].specialDefense << endl;
    //     cout << "Speed: " << myPokemon[i].speed << endl;

    //     cout << "Next Evolution: ";
    //     for (const auto& evolution : myPokemon[i].nextEvolution) {
    //         cout << evolution << " ";
    //     }
    //     cout << endl;

    //     cout << "Moves: ";
    //     for (const auto& move : myPokemon[i].moves) {
    //         cout << move << " ";
    //     }
    //     cout << endl;

    //     cout << "----------------------" << endl;
    // }
}
