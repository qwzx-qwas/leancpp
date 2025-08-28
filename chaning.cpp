#include <iostream>
#include <list>
#include <vector>

using namespace std;

class chaningHash {
private:
    vector<list<int>> table;   //散列表
    int m;                  //散列表大小

    int hashFunc (int key) {
        return key % m;
    }

public:
    chaningHash (int size) : m(size), table(size) {}

    void insert (int key) {
        int index = hashFunc(key);
        table[index].push_back(key);
    }
    
    bool search (int key) {
        int index = hashFunc(key);
        for (auto &e: table[index] ){
            if(e == key) {
                return true;
            }
        }
        return false;
    }

    void display () {
        for(int i = 0; i < m; i++) {
            if(!table[i].empty()) {
                cout << "Index " << i << ": ";
                for(auto &e: table[i]) {
                    cout << e << " -> ";
                }
                cout << "nullptr" << endl;
            }
        }
    }

};
