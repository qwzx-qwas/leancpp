#ifndef SALES_DATA_H // 如果没有定义 SALES_DATA_H（第一次进来）
#define SALES_DATA_H // 定义 SALES_DATA_H
#include < string >
/*struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
//在类定义的后面加上分号
#endif // （不管有没有定义，我最后都得关门）*/

struct Sales_data {
    Sales_data() = default; // 默认构造函数
    Sales_data(const std::string &s) : bookNo(s) {} // 带参数的构造函数
    Sales_data(const std::string &s, unsigned n, double p) 
        : bookNo(s), units_sold(n), revenue(p * n) {}
    Sales_data(std::istream &);
    std::string isbn() const { return bookNo; } // 成员函数，返回书号
    Sales_data &combine(const Sales_data &); // 成员函数，合并数据
    double avg_price() const; // 成员函数，计算平均价格
    std::string bookNo; // 书号
    unsigned units_sold = 0; // 销售数量
    double revenue = 0.0; // 收入
};

#endif // SALES_DATA_H
