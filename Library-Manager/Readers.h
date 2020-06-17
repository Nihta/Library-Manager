#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
class Readers
{
private:
	// Mã độc giả
	string id;
	// Tên độc giả
	string name;
	// Số điện thoại độc giả
	string phone;
	// Đỉa chỉ độc giả
	string address;
public:
	Readers();
	Readers(string id, string n, string p, string a);
	// Khởi tạo đối tượng mới với dữ liệu đọc được từ file
	Readers(fstream& data);
	// Ghi dữ liệu vào file
	void writeDataToFile(fstream& file);
	// Hiện thị thông tin độc giả
	void display();
	// Lấy tên độc giả
	string getName();
	// Lấy tên độc giả
	string getId();
	// Sửa thông tin độc giả
	void edit();
	~Readers();
};

