#pragma once
#include <iostream>
#include <fstream>
#include "Date.h"

class BorrowBook
{
private:
	// Mã số người mượn
	string idReaders;
	// Mã số sách mượn
	string idBook;
	// Ngày mượn
	Date borrowDate = Date();
	//Ngày hẹn trả
	Date appointmentDate;
public:
	BorrowBook();
	BorrowBook(string iR, string iB, string bD, string aD);
	// Khởi tạo với dữ liệu đọc từ file
	BorrowBook(fstream &data);
	// Ghi dữ liệu vào file
	void wrtieDataToFile(fstream& file);
	// Lấy mã độc giả
	string getIdReaders();
	// Lấy mã sách
	string getIdBook();
	// Lấy ngày mượn
	Date getBorrowDate();
	// Lấy ngày hẹn trả
	Date getAppointmentDate();
	~BorrowBook();
};

