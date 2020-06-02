﻿#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "Book.h"
#include "Readers.h"
#include "BorrowBook.h"
class Library
{
private:
	vector<Book*> listBooks;
	vector<Readers*> listReaders;
	vector<BorrowBook*> listBorrowBooks;
public:
	Library();
	// Đọc dữ liệu các cuốn sách trong thư viện từ file
	void readDataBookFromFile();
	// Ghi dữ liệu các cuốn sách trong thư viện vào file
	void writeDataBookToFile();
	// Đọc thông tin các độc giả từ file
	void readDataReadersFromFile();
	// Ghi thông tin các độc giả vào file
	void writeDataReadersToFile();
	// Đọc thông tin các độc giả mượn sách từ file
	void readDataBorrowBookFromFile();
	// Ghi thông tin các độc giả mượn sách vào file
	void writeDataBorrowBookToFile();
	// Quản lý sách
	void bookManagement();
	// Quản lý độc giả
	void readersManagement();
	// Tìm chỉ số của sách theo mã số hoặc tên sách
	// mode: 'i' là tìm theo mã sách, 'n' tìm theo tên sách
	int findIndexBook(char mode, string data);
	// start là vị trí bắt đầu tìm kiếm
	int findIndexReaders(char mode, string data, unsigned int start);
	// Mượn sách
	void borrowBook();
	void menu();
};

