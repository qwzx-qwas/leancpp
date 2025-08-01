#include <iostream>
int main() {
    int currVal = 0, val = 0;
    if (std::cin >> currVal) {
        int cnt = 1;
        while (std::cin >> val) {
            if (val == currVal) {
                ++cnt;
            } else {
                std::cout << currVal << " occurs "
                            << cnt << " times" << std::endl;
                currVal = val;    // remember new value
                cnt = 1;          // reset counter
            }
        }
        std::cout << currVal << " occurs "
                    <<cnt << " times" << std::endl;
    }
    return 0;
}
