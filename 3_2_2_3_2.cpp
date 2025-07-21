#include <iostream>
#include <string>

using std::cout ;
using std::endl;
using std::cin;
using std::string;
using std::getline;
/*
int main() {
    string line;
    cout << "Enter a line of text (type 'quit' to exit): ";
    while (getline(cin, line)) {
        if (line == "quit" || line == "exit") {
            break;  // 退出循环
        }
        cout << "You entered: " << line << endl;
        cout << "Enter next line (type 'quit' to exit): ";
}            
*/

int main() {
    string word;
    cout << "Enter words (type 'quit' to exit): ";
    while (cin >> word) {
        if (word == "quit" || word == "exit") {
            break;  // 退出循环
        }
        cout << "You entered word: " << word << endl;   
        cout << "Enter next word (type 'quit' to exit): ";
    }
    return 0;
}
