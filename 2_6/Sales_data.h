#ifndef SALES_DATA_H // 如果没有定义 SALES_DATA_H（第一次进来）
#define SALES_DATA_H // 定义 SALES_DATA_H
#include < string >

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
//在类定义的后面加上分号
#endif // （不管有没有定义，我最后都得关门）
