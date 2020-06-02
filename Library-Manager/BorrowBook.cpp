#include "BorrowBook.h"

BorrowBook::BorrowBook() {
}

BorrowBook::BorrowBook(string iR, string iB, string bD, string aD) {
	this->idReaders = iR;
	this->idBook = iB;
	this->borrowDate = Date(bD);
	this->appointmentDate = Date(aD);
}

// Khởi tạo với dữ liệu đọc từ file
BorrowBook::BorrowBook(fstream& data) {
	string date;
	getline(data, this->idReaders);
	getline(data, this->idBook);
	getline(data, date);
	this->borrowDate = Date(date);
	getline(data, date);
	this->appointmentDate = Date(date);
}

// Ghi dữ liệu vào file
void BorrowBook::wrtieDataToFile(fstream& file) {
	file << this->idReaders << "\n"
		<< this->idBook << "\n"
		<< this->borrowDate << "\n"
		<< this->appointmentDate << "\n";
}

// Lấy mã độc giả
string BorrowBook::getIdReaders() {
	return this->idReaders;
}

// Lấy mã sách
string BorrowBook::getIdBook() {
	return this->idBook;
}

// Lấy ngày mượn
Date BorrowBook::getBorrowDate() {
	return this->borrowDate;
}

// Lấy ngày hẹn trả
Date BorrowBook::getAppointmentDate() {
	return this->appointmentDate;
}

BorrowBook::~BorrowBook() {

}