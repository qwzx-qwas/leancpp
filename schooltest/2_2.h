#include <algorithm>
#include <stdexcept>

const int MaxSize = 1000;
//低位在前
struct bigInt {
    int digit[MaxSize];  // 数字数组
    int last;   //最后一位的下标
};

//时间复杂度为O(n)
int cmp(bigInt a, bigInt b) {
    if (a.last != b.last) {
        return (a.last > b.last) ? 1 : -1;
    }
    for ( int i = a.last; i >= 0; --i ) {
        if (a.digit[i] != b.digit[i]) {
            return (a.digit[i] > b.digit[i]) ? 1 : -1;
        }
    }
    return 0;
}

bigInt add(bigInt a, bigInt b) {
    bigInt c;
    c.last = 0;
    int carry = 0;  //进位
    int n = std::max(a.last, b.last) + 1;
    for (int i = 0; i <= n ;i++) {
        int sum = carry;
        if( i <= a.last ) sum += a.digit[i];
        if( i <= b.last ) sum += b.digit[i];
        c.digit[i] = sum % 10;
        carry = sum / 10;
    }
    c.last = (carry > 0) ? n : n - 1;
    return c;
}

bigInt sub(bigInt a, bigInt b) {
    bigInt c;
    c.last = 0;
    int borrow = 0;  //借位
    for (int i = 0; i <= a.last; i++) {
        int diff = a.digit[i] - borrow;
        if (i <= b.last) diff -= b.digit[i];
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        c.digit[c.last++] = diff;
    }
    // 去除前导零
    while (c.last > 1 && c.digit[c.last - 1] == 0) {
        c.last--;
    }
    return c;
}

bigInt mul(bigInt a, bigInt b) {
    bigInt c;
    c.last = 0;
    for (int i = 0; i <= a.last; i++) {
        int carry = 0;
        for (int j = 0; j <= b.last; j++) {
            int product = a.digit[i] * b.digit[j] + carry;
            if (i + j < MaxSize) {
                c.digit[i + j] += product % 10;
                carry = product / 10;
                if (c.digit[i + j] >= 10) {
                    c.digit[i + j] -= 10;
                    carry++;
                }
            }
        }
        if (carry > 0 && i + b.last < MaxSize) {
            c.digit[i + b.last] += carry;
        }
    }
    c.last = a.last + b.last;
    // 去除前导零
    while (c.last > 1 && c.digit[c.last - 1] == 0) {
        c.last--;
    }
    return c;
}

bigInt div(bigInt a, bigInt b) {
    bigInt c;
    c.last = 0;
    if (b.last == 0 && b.digit[0] == 0) {
        throw std::invalid_argument("Division by zero");
    }
    
    bigInt remainder = { {0}, 0 };
    for (int i = a.last; i >= 0; --i) {
        remainder.digit[remainder.last++] = a.digit[i];
        while (cmp(remainder, b) >= 0) {
            remainder = sub(remainder, b);
            c.digit[c.last++]++;
        }
    }
    
    // 去除前导零
    while (c.last > 1 && c.digit[c.last - 1] == 0) {
        c.last--;
    }
    
    return c;
}
