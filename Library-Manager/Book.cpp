#include "Book.h"

Book::Book() {
    cout << "Nhap ma sach: ";
    getline(cin, this->id);
    cout << "Nhap ten sach: ";
    getline(cin, this->name);
    cout << "Nhap the loai sach: ";
    getline(cin, this->category);
    cout << "Nhap so trang: ";
    cin >> this->numOfPage;
    cin.ignore();
    cout << "Nhap ten tac gia: ";
    getline(cin, this->author);
    cout << "Nhap ten nha xuat ban ";
    getline(cin, this->publisher);
    cout << "Nhap thoi gian xuat ban (dd/mm/yyyy): ";
    string tmp;
    getline(cin, tmp);
    this->publishingTime = Date(tmp);
    cout << "Nhap so luong sach: ";
    cin >> this->numOfBook;
    cin.ignore();
}

Book::Book(string id, string cate, string auth, string pub, string pT, unsigned int nP, unsigned int nB, unsigned int nRBB = 0) {
    this->id = id;
    this->category = cate;
    this->author = auth;
    this->publisher = pub;
    this->publishingTime = pT;
    this->numOfPage = nP;
    this->numOfBook = nB;
    this->numOfReadersBorrowBook = nRBB;
}

Book::Book(fstream& data) {
    getline(data, this->id);
    getline(data, this->name);
    getline(data, this->category);
    data >> this->numOfPage;
    data.ignore();
    getline(data, this->author);
    getline(data, this->publisher);
    string time;
    getline(data, time);
    this->publishingTime = Date(time);
    data >> this->numOfBook;
    data.ignore();
    data >> this->numOfReadersBorrowBook;
    data.ignore();
}

void Book::display() {
    cout << setw(8) << this->id << " |"
        << setw(28) << this->name << " |"
        << setw(22) << this->category << " |"
        << setw(22) << this->author << " |"
        << setw(22) << this->publisher << " |"
        << setw(15) << this->publishingTime << " |"
        << setw(12) << this->numOfPage << " |"
        << setw(12) << (to_string(this->numOfBook - this->numOfReadersBorrowBook) + "/" + to_string(this->numOfBook)) << " |" << endl;
}

void Book::writeToFile(fstream& file) {
    file << this->id << "\n"
        << this->name << "\n"
        << this->category << "\n"
        << this->numOfPage << "\n"
        << this->author << "\n"
        << this->publisher << "\n"
        << this->publishingTime << "\n"
        << this->numOfBook << "\n"
        << this->numOfReadersBorrowBook << "\n";
}

string Book::getId() {
    return this->id;
}

string Book::getName() {
    return this->name;
}

unsigned int Book::getNumOfBookCur() {
    return this->numOfBook - this->numOfReadersBorrowBook;
}

void Book::changeReadersBorrowBook(char mode) {
    if (mode == 't') {
        this->numOfReadersBorrowBook = this->numOfReadersBorrowBook + 1;
    }
    else if (mode == 'g') {
        this->numOfReadersBorrowBook = this->numOfReadersBorrowBook - 1;
    }
}

Book::~Book() {}