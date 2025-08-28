#include <iostream> 
#include <vector>

using namespace std;

class linearProbingHash {
private:
    vector<int> table;   //散列表
    int m;                  //散列表大小

    int hashFunc (int key) {
        return key % m;
    }



public:
    linearProbingHash (int size) : m(size), table(size, -1) {}

    void insert (int key) {
        int index = hashFunc(key);
        int start = index;
        while(table[index] != -1) {
            index = (index + 1) % m;
            if(index == start) {
                cout << "Hash table is full" <<endl;
                return;   // Hash table is full
            }
        }
        table[index] = key;
        return;
    }

    int search (int key) {
        int index = hashFunc(key);
        int start = index;
        while(table[index] != -1) {
            if(table[index] == key) {
                return index;
            }
            index = (index + 1) % m;
            if(index == start) {
                return -1;   // Hash table is full
            }
        }
        return -1;
    }

    void display () {
        for(int i = 0; i < m; i++) {
            if(table[i] != -1) {
                cout << "Index " << i << ": " << table[i] << endl;
            }
        }
    }



};
