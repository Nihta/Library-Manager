#include "Library.h"

Library::Library() {
	this->readDataBookFromFile();
	this->readDataReadersFromFile();
	this->readDataBorrowBookFromFile();
}

void Library::readDataBookFromFile() {
	fstream data("dataBooks.txt", ios::in);
	if (data.fail())
	{
		// Nếu mở file thất bại thì tạo một file mới
		fstream data("dataBooks.txt", ios::out);
		data << "0\n";
	}
	else
	{
		int numOfBook;
		data >> numOfBook;
		data.ignore();
		while (numOfBook--)
		{
			// Đọc thông tin sách, khởi tạo và đẩy vào vector 
			listBooks.push_back(new Book(data));
			// Bỏ qua dòng trống
			string blankLine;
			getline(data, blankLine);
		}
	}
	data.close();
}

void Library::writeDataBookToFile() {
	fstream file("dataBooks.txt", ios::out);
	file << this->listBooks.size() << "\n";
	for (auto book : this->listBooks) {
		book->writeToFile(file);
		file << "\n";
	}
	file.close();
}

int Library::findIndexBook(char mode, string data) {
	for (unsigned int i = 0; i < this->listBooks.size(); i++) {
		if ((mode == 'i' && this->listBooks[i]->getId() == data) ||
			(mode == 'n' && this->listBooks[i]->getName() == data)) {
			return i;
		}
	}
	return -1;
}

void Library::readDataReadersFromFile() {
	fstream data("dataReaders.txt", ios::in);
	if (data.fail())
	{
		// Nếu mở file thất bại thì tạo một file mới
		fstream data("dataReaders.txt", ios::out);
		data << "0\n";
	}
	else
	{
		int numOfReaders;
		data >> numOfReaders;
		data.ignore();
		while (numOfReaders--)
		{
			this->listReaders.push_back(new Readers(data));
			string blankLine;
			getline(data, blankLine);
		}
	}
	data.close();
}

void Library::writeDataReadersToFile() {
	fstream file("dataReaders.txt", ios::out);
	file << this->listReaders.size() << "\n";
	for (auto readers : this->listReaders) {
		readers->writeDataToFile(file);
		file << "\n";
	}
	file.close();
}

void Library::readDataBorrowBookFromFile() {
	fstream data("dataBorrowBook.txt", ios::in);
	if (data.fail())
	{
		// Nếu mở file thất bại thì tạo một file mới
		fstream data("dataBorrowBook.txt", ios::out);
		data << "0\n";
	}
	else
	{
		int num;
		data >> num;
		data.ignore();
		while (num--)
		{
			this->listBorrowBooks.push_back(new BorrowBook(data));
			string blankLine;
			getline(data, blankLine);
		}
	}
	data.close();
}

void Library::writeDataBorrowBookToFile() {
	fstream file("dataBorrowBook.txt", ios::out);
	file << this->listBorrowBooks.size() << "\n";
	for (auto BB : this->listBorrowBooks) {
		BB->wrtieDataToFile(file);
		file << "\n";
	}
	file.close();
}

int Library::findIndexReaders(char mode, string data, unsigned int start)
{
	for (unsigned int i = start; i < this->listReaders.size(); i++) {
		if ((mode == 'i' && this->listReaders[i]->getId() == data) ||
			(mode == 'n' && this->listReaders[i]->getName() == data)) {
			return i;
		}
	}
	return -1;
}

void Library::bookManagement() {
	string line = "+" + string(5, '-') + "--"
		+ string(8, '-') + "--"
		+ string(28, '-') + "--"
		+ string(22, '-') + "--"
		+ string(22, '-') + "--"
		+ string(22, '-') + "--"
		+ string(15, '-') + "--"
		+ string(12, '-') + "--"
		+ string(12, '-') + "-+" + "\n";
	string line2 = "|" + string(5, '-') + "-+"
		+ string(8, '-') + "-+"
		+ string(28, '-') + "-+"
		+ string(22, '-') + "-+"
		+ string(22, '-') + "-+"
		+ string(22, '-') + "-+"
		+ string(15, '-') + "-+"
		+ string(12, '-') + "-+"
		+ string(12, '-') + "-|" + "\n";
	bool isExit = false;
	while (!isExit)
	{
		system("cls");
		cout << "+------- Quan ly sach ------+\n"
			<<  "| 1. Tim sach               |\n"
			<<  "| 2. Them sach              |\n"
			<<  "| 3. Xoa sach               |\n"
			<<  "| 4. Sua thong tin sach     |\n"
			<<  "| 5. Hien thi toan bo sach  |\n"
			<<  "| 0. Quay lai               |\n"
			 << "+---------------------------+\n";

		int option;
		cin >> option;
		cin.ignore();
		system("cls");
		switch (option)
		{
		case 1: // Tìm sách
		{
			system("cls");
			cout << "+------ Chon cach tim kiem -----+\n"
				<<  "| 1. Tim theo ma sach           |\n"
				<<  "| 2. Tim theo ten sach          |\n"
				<<  "+-------------------------------+\n";

			int option;
			cin >> option;
			cin.ignore();
			system("cls");
			if (option == 1) {
				cout << "Nhap ma sach: ";
				string id;
				getline(cin, id);
				int index = this->findIndexBook('i', id);
				if (index == -1) {
					cout << "Khong tim thay!" << endl;
				}
				else
				{
					cout << line << "|" << setw(5) << "Stt" << " |" << setw(8) << "Ma so" << " |" << setw(28) << "Ten" << " |" << setw(22) << "The loai" << " |" << setw(22) << "Tac gia" << " |" << setw(22) << "Nha xuat ban" << " |" << setw(15) << "Nam Xuat ban" << " |" << setw(12) << "So trang" << " |" << setw(12) << "So luong" << " |" << "\n" << line2;
					cout << "|" << setw(5) << 1 << " |";
					this->listBooks[index]->display();
					cout << line;
				}
				getchar();
			}
			else if (option == 2) {
				cout << "Nhap ten sach: ";
				string name;
				getline(cin, name);
				int index = this->findIndexBook('n', name);
				if (index == -1) {
					cout << "Khong tim thay!" << endl;
				}
				else
				{
					cout << line << "|" << setw(5) << "Stt" << " |" << setw(8) << "Ma so" << " |" << setw(28) << "Ten" << " |" << setw(22) << "The loai" << " |" << setw(22) << "Tac gia" << " |" << setw(22) << "Nha xuat ban" << " |" << setw(15) << "Nam Xuat ban" << " |" << setw(12) << "So trang" << " |" << setw(12) << "So luong" << " |" << "\n" << line2;
					cout << "|" << setw(5) << 1 << " |";
					this->listBooks[index]->display();
					cout << line;
				}
				getchar();
			}
		}
		break;
		case 2: // Thêm sách
		{
			system("cls");
			this->listBooks.push_back(new Book());
			this->writeDataBookToFile();
			system("cls");
			cout << "Them thanh cong!" << endl;
			getchar();
		}
			break;
		case 3: // Xóa sách
		{
			cout << "Nhap ma so sach can xoa: ";
			string id;
			getline(cin, id);
			int index = this->findIndexBook('i', id);
			system("cls");
			if (index == -1) {
				cout << "Ma so sach khong dung!" << endl;
			}
			else {
				this->listBooks.erase(this->listBooks.begin() + index);
				this->writeDataBookToFile();
				cout << "Xoa thanh cong!" << endl;
			}
			getchar();
		}
		break;
		case 4: // Sửa thông tin sách
		{
			cout << "Nhap ma so sach can sua thong tin: ";
			string id;
			getline(cin, id);
			int index = this->findIndexBook('i', id);
			system("cls");
			if (index == -1) {
				cout << "Ma so sach khong dung!" << endl;
			}
			else {
				system("cls");
				this->listBooks[index]->edit();
				this->writeDataBookToFile();
				system("cls");
				cout << "Sua thanh cong!" << endl;
			}
			getchar();
		}
		break;
		case 5: // Hiện thị
		{
			system("cls");
			cout << line
				<< "|" << setw(5) << "Stt" << " |"
				<< setw(8) << "Ma so" << " |"
				<< setw(28) << "Ten" << " |"
				<< setw(22) << "The loai" << " |"
				<< setw(22) << "Tac gia" << " |"
				<< setw(22) << "Nha xuat ban" << " |"
				<< setw(15) << "Nam Xuat ban" << " |"
				<< setw(12) << "So trang" << " |"
				<< setw(12) << "So luong" << " |" << "\n"
				<< line2;
			for (unsigned int i = 0; i < this->listBooks.size(); i++) {
				cout << "|" << setw(5) << (i + 1) << " |";
				this->listBooks[i]->display();
			}
			cout << line;
		}
		getchar();
		break;
		case 0:
			isExit = true;
			break;
		}
	}
}

void Library::readersManagement() {
	bool isExit = false;
	while (!isExit) {
		string line = "+" + string(104, '-') + "+\n";
		string line2 = "|" + string(5, '-') + "-+"
			+ string(8, '-') + "-+"
			+ string(28, '-') + "-+"
			+ string(14, '-') + "-+"
			+ string(40, '-') + "-|" + "\n";
		system("cls");
		cout << "+-------- Quan ly doc gia --------+\n"
			<<  "| 1. Tim doc gia                  |\n"
			<<  "| 2. Them doc gia                 |\n"
			<<  "| 3. Xoa doc gia                  |\n"
			<<  "| 4. Sua thong tin doc gia        |\n"
			<<  "| 5. Hien thi toan bo doc gia     |\n"
			<<  "| 0. Quay lai                     |\n" 
			<<  "+---------------------------------+\n";
		int option;
		cin >> option;
		cin.ignore();
		system("cls");
		switch (option)
		{
		case 1: // Tìm độc giả
		{
			cout << "+------ Chon cach tim kiem -----+\n"
				<<  "| 1. Tim theo ma doc gia        |\n"
				<<  "| 2. Tim theo ten doc gia       |\n"
				<<  "+-------------------------------+\n";

			int option;
			cin >> option;
			cin.ignore();
			system("cls");
			if (option == 1) {
				cout << "Nhap ma doc gia: ";
				string id;
				getline(cin, id);
				int index = this->findIndexReaders('i', id, 0);
				if (index == -1) {
					cout << "Khong tim thay!" << endl;
				}
				else
				{
					cout << line
						<< "|" << setw(5) << "Stt" << " |"
						<< setw(8) << "Ma so" << " |"
						<< setw(28) << "Ten doc gia" << " |"
						<< setw(14) << "Dien thoai" << " |"
						<< setw(40) << "Dia chi" << " |\n"
						<< line2;
						cout << "|" << setw(5) << 1 << " |";
						this->listReaders[index]->display();
						cout << "\n" << line;
				}
				getchar();
			}
			else if (option == 2) {
				cout << "Nhap ten doc gia: ";
				string name;
				getline(cin, name);
				int index = this->findIndexReaders('n', name, 0);
				if (index == -1) {
					cout << "Khong tim thay!" << endl;
				}
				else
				{
					int i = 1;
					cout << line
						<< "|" << setw(5) << "Stt" << " |"
						<< setw(8) << "Ma so" << " |"
						<< setw(28) << "Ten doc gia" << " |"
						<< setw(14) << "Dien thoai" << " |"
						<< setw(40) << "Dia chi" << " |\n"
						<< line2;
					cout << "|" << setw(5) << 1 << " |";
					this->listReaders[index]->display();
					cout << "\n";
					while (index != -1)
					{
						index = this->findIndexReaders('n', name, index + 1);
						if (index != -1) {
							cout << "|" << setw(5) << ++i << " |";
							this->listReaders[index]->display();
							cout << "\n";
						}
					}
					cout << line;
				}
				getchar();
			}
		}
		break;
		case 2: // Thêm độc giả
		{
			this->listReaders.push_back(new Readers());
			this->writeDataReadersToFile();
			system("cls");
			cout << "Them doc gia thanh cong!" << endl;
			getchar();
		}
		break;
		case 3: // Xóa độc giả
		{
			cout << "Nhap ma so doc gia can xoa: ";
			string id;
			getline(cin, id);
			int index = this->findIndexReaders('i', id, 0);
			system("cls");
			if (index == -1) {
				cout << "Ma so doc gia khong dung!" << endl;
			}
			else {
				this->listReaders.erase(this->listReaders.begin() + index);
				this->writeDataReadersToFile();
				cout << "Xoa thanh cong!" << endl;
			}
			getchar();
		}
		break;
		case 4: // Sửa thông tin độc giả
		{
			cout << "Nhap ma so doc gia can sua thong tin: ";
			string id;
			getline(cin, id);
			int index = this->findIndexReaders('i', id, 0);
			system("cls");
			if (index == -1) {
				cout << "Ma doc gia khong dung!" << endl;
			}
			else {
				this->listReaders[index]->edit();
				this->writeDataReadersToFile();
				system("cls");
				cout << "Sua thanh cong!" << endl;
			}
			getchar();
		}
		break;
		case 5: // Hiện thị danh sách các độc giả
		{
			system("cls");
			cout << line
				<< "|" << setw(5) << "Stt" << " |"
				<< setw(8) << "Ma so" << " |"
				<< setw(28) << "Ten doc gia" << " |"
				<< setw(14) << "Dien thoai" << " |"
				<< setw(40) << "Dia chi" << " |\n"
				<< line2;
			for (unsigned int i = 0; i < this->listReaders.size(); i++) {
				cout << "|" << setw(5) << (i + 1) << " |";
				this->listReaders[i]->display();
				cout << "\n";
			}
			cout << line;
		}
		getchar();
		break;
		case 0:
			isExit = true;
			break;
		}
	}
}

void Library::borrowBook() {
	string iR, iB, bD, aD;
	int indexBook;
	while (true)
	{
		// Nhập sai thì yêu cầu nhập lại hoặc nhập 0 để thoát
		cout << "Nhap ma doc gia (0 de thoat): ";
		getline(cin, iR);
		if (iR == "0") {
			return;
		}
		// Nếu nhập đúng thì tiếp tục
		if (this->findIndexReaders('i', iR, 0) != -1) {
			break;
		}
	}
	while (true)
	{
		// Nhập sai thì yêu cầu nhập lại hoặc nhập 0 để thoát
		cout << "Nhap ma sach can muon (0 de thoat): ";
		getline(cin, iB);
		if (iB == "0") {
			return;
		}
		// Nếu nhập đúng thì tiếp tục
		indexBook = this->findIndexBook('i', iB);
		if (indexBook != -1) {
			break;
		}
	}
	// Kiểm tra xem còn sách này nữa không
	if (this->listBooks[indexBook]->getNumOfBookCur() == 0) {
		cout << "Xin loi! Sach nay hien tai khong con cuon nao." << endl;
	}
	else {
		bD = Date().toString();
		cout << "Nhap ngay hen tra: ";
		getline(cin, aD);
		this->listBorrowBooks.push_back(new BorrowBook(iR, iB, bD, aD));
		this->writeDataBorrowBookToFile();
		this->listBooks[indexBook]->changeReadersBorrowBook('t');
		this->writeDataBookToFile();
		cout << "Thanh cong!" << endl;
	}
}

void Library::menu() {
	bool exit = false;
	while (!exit)
	{
		system("cls");
		cout << "+-------- Quan ly thu vien -------+\n"
			 << "| 1. Muon sach                    |\n"
			 << "| 2. Tra sach                     |\n"
			 << "| 3. Danh sach nguoi muon sach    |\n"
			 << "| 4. Quan ly sach                 |\n"
			 << "| 5. Quan ly doc gia              |\n"
		     << "| 0. Thoat                        |\n"
			 << "+---------------------------------+\n";

		int option;
		cin >> option;
		cin.ignore();

		system("cls");
		switch (option)
		{
		case 1:
			this->borrowBook();
			getchar();
			break;
		case 2:
		{
			cout << "Nhap ma doc gia tra sach: ";
			string iR;
			getline(cin, iR);
			cout << "Nhap ma sach muon tra: ";
			string iB;
			getline(cin, iB);
				
			bool status = false;
			for (unsigned int i = 0; i < this->listBorrowBooks.size(); i++) {
				if (this->listBorrowBooks[i]->getIdBook() == iB && this->listBorrowBooks[i]->getIdReaders() == iR) {
					this->listBorrowBooks.erase(this->listBorrowBooks.begin() + i);
					this->listBooks[this->findIndexBook('i', iB)]->changeReadersBorrowBook('g');
					this->writeDataBorrowBookToFile();
					this->writeDataBookToFile();
					status = true;
				}
			}

			if (status) {
				cout << "Tra sach thanh cong!" << endl;
			}
			else {
				cout << "Tra sach that bai!" << endl;
			}
			getchar();
		}
			break;
		case 3:
		{
			if (this->listBorrowBooks.size() == 0) {
				cout << "Khong co doc gia dong muon sach!" << endl;
			}
			else
			{
				string line = "+" + string(128, '-') + "+\n";
				cout << line << "|" << setw(5) << "Stt" << " |"
					<< setw(14) << "Ma doc gia" << " |"
					<< setw(28) << "Ten doc gia" << " |"
					<< setw(14) << "Ma so sach" << " |"
					<< setw(28) << "Ten sach" << " |"
					<< setw(12) << "Ngay muon" << " |"
					<< setw(14) << "Ngay hen tra" << " |\n"
					<< line;
				for (unsigned int i = 0; i < this->listBorrowBooks.size(); i++) {
					BorrowBook* bB = this->listBorrowBooks[i];
					string iR = bB->getIdReaders();
					string nameR = this->listReaders[this->findIndexReaders('i', iR, 0)]->getName();
					string iB = bB->getIdBook();
					string nameB = this->listBooks[this->findIndexBook('i', iB)]->getName();
					cout << "|" << setw(5) << (i + 1) << " |"
						<< setw(14) << bB->getIdReaders() << " |"
						<< setw(28) << nameR << " |"
						<< setw(14) << bB->getIdBook() << " |"
						<< setw(28) << nameB << " |"
						<< setw(12) << bB->getBorrowDate() << " |"
						<< setw(14) << bB->getAppointmentDate() << " |"
						<< endl;
				}
				cout << line;
			}
		}
		getchar();
		break;
		case 4:
			this->bookManagement();
			break;
		case 5:
			this->readersManagement();
			break;
		case 0:
			exit = true;
			break;
		}
	}
}