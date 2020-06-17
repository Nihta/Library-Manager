#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Date.h"
using namespace std;

class Book {
private:
    // Mã số sách
    string id;
    // Tên sách
    string name;
    // Thể loại
    string category;
    // Tên tác giả
    string author;
    // Tên nhà xuất bản
    string publisher;
    // Thời gian xuất bản
    Date publishingTime;
    // Số trang
    unsigned int numOfPage = 0;
    // Số lượng sách
    unsigned int numOfBook = 0;
    // Số lượng người đang mượn
    unsigned int numOfReadersBorrowBook = 0;
public:
    Book();
    Book(string id, string cate, string auth, string pub, string pT, unsigned int nP, unsigned int nB, unsigned int nRBB);
    // Đọc dữ liệu từ file và khởi tạo đối tượng mới
    Book(fstream& data);
    // Ghi dữ liệu vào file
    void writeToFile(fstream& file);
    // Hiện thị thông tin sách
    void display();
    // Lấy mã sách
    string getId();
    // Lấy tên sách
    string getName();
    // Lấy số lượng sách hiện hiện tại
    unsigned int getNumOfBookCur();
    // mode: 't' tăng số lượng sách đang được mượn lên 1, 'g' giảm đi 1
    void changeReadersBorrowBook(char mode);
    // Sửa thông tin
    void edit();
    ~Book();
};