#include "BookManager.h"
#include "Book.h"
#include "BorrowManager.h"
#include <iostream>

int main() {
	string chat;
	string title;
	string author;
	BookManager BM;
	BorrowManager BRM;
	while (chat != "-1") {
		cout << "�޴��� �����ϼ��� \n1. å �Է�\n2. �˻�\n3. �뿩\n4. �ݳ�\n(����: -1)" << endl;
		cin >> chat;
		cin.ignore();
		if (chat == "1") {
			cout << "å�� ������ �Է��ϼ���" << endl;
			getline(cin, title);
			cout << "�۰��� �̸��� �Է��ϼ���" << endl;
			getline(cin, author);
			BM.addBook(title, author);
			BRM.initialize_stock(*(BM.getBookByTitle(title)), 3);
			cout << title << "å�� ���忡 ��ϵǾ����ϴ�.";
		}
		else if (chat == "2") {
			cout << "å �������� ã��: 1\n�۰� �̸����� ã��: 2" << endl;
			cin >> chat;
			cin.ignore();
			if (chat == "1") {
				cout << "����: ";
				getline(cin, title);
				cout << BM.getBookByTitle(title)->title << "å�� �ֽ��ϴ�." << endl;
			}
			else if (chat == "2") {
				cout << "�۰�: ";
				getline(cin, author);
				cout << BM.getBookByAuthor(author)->author << "�� �� å�� �ֽ��ϴ�." << endl;
			}
			else cout << "�߸� �Է��ϼ̽��ϴ�.";
		}
		else if (chat == "3") {
			cout << "�뿩 �Ͻ� å�� ������ �Է��� �ּ���\n:";
			getline(cin, title);
			BRM.borrowBook(title);
		}
		else if (chat == "4") {
			cout << "�ݳ��Ͻ� å�� ������ �Է��� �ּ���\n:";
			getline(cin, title);
			BRM.returnBook(title);
		}
		else {
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
		}
	}
	return 0;
}