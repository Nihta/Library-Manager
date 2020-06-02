#include <iostream>
#include <sstream>
#include <ctime>
using namespace std;
#pragma once

class Date
{
private:
    int day = 1;
    int month = 1;
    int year = 1;

public:
    // Lấy mốc thời gian hiện tại
    Date();
    // Khởi tạo từ string
    Date(string d);
    // Xuất định dạng string
    string toString();
    // Nhập dạng dd/mm/yyyy
    friend istream& operator>>(istream& is, Date& D);
    // In định dạng dạng dd/mm/yyyy
    friend ostream& operator<<(ostream& os, const Date& D);
    ~Date();
};