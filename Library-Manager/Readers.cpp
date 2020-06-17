#include "Readers.h"

Readers::Readers() {
	cout << "Nhap ma doc gia: ";
	getline(cin, this->id);
	cout << "Nhap ten doc gia: ";
	getline(cin, this->name);
	cout << "Nhap so dien thoai lien lac: ";
	getline(cin, this->phone);
	cout << "Nhap dia chi: ";
	getline(cin, this->address);
}
Readers::Readers(string id, string n, string p, string a) {
	this->id = id;
	this->name = n;
	this->phone = p;
	this->address = a;
}

Readers::Readers(fstream& data) {
	getline(data, this->id);
	getline(data, this->name);
	getline(data, this->phone);
	getline(data, this->address);
}

void Readers::writeDataToFile(fstream& file) {
	file << this->id << "\n"
		<< this->name << "\n"
		<< this->phone << "\n"
		<< this->address << "\n";
}

void Readers::display() {
	cout << setw(8) << this->id << " |"
		<< setw(28) << this->name << " |"
		<< setw(14) << this->phone << " |"
		<< setw(40) << this->address << " |";
}

string Readers::getId() {
	return this->id;
}

string Readers::getName() {
	return this->name;
}

void Readers::edit() {
	string newData;
	cout << "Nhap thong tin moi cho doc gia, neu khong thay doi thi bo trong: " << endl;
	
	cout << "\tNhap ten doc gia: ";
	getline(cin, newData);
	if (newData != "") this->name = newData;

	cout << "\tNhap so dien thoai lien lac: ";
	getline(cin, newData);
	if (newData != "") this->phone = newData;

	cout << "\tNhap dia chi: ";
	getline(cin, newData);
	if (newData != "") this->address = newData;
}

Readers::~Readers() {

}