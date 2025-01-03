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
		getline(cin, chat);
		if (chat == "1") {
			cout << "å�� ������ �Է��ϼ���" << endl;
			cin >> title;
			cin.ignore();
			cout << "�۰��� �̸��� �Է��ϼ���" << endl;
			cin >> author;
			cin.ignore();
			BM.addBook(title, author);
			BRM.initialize_stock(*(BM.getBookByTitle("title")), 3);
			cout << title << "å�� ���忡 ��ϵǾ����ϴ�.";
		}
		else if (chat == "2") {
			cout << "å �������� ã��: 1\n �۰� �̸����� ã��: 2" << endl;
			cin >> chat;
			cin.ignore();
			if (chat == "1") {
				cout << "����: ";
				cin >> title;
				cin.ignore();
				cout << BM.getBookByTitle(title)->title << "å�� �ֽ��ϴ�." << endl;
			}
			else if (chat == "2") {
				cout << "�۰�: ";
				cin >> author;
				cin.ignore();
				cout << BM.getBookByTitle(author)->title << "�� �� å�� �ֽ��ϴ�." << endl;
			}
			else cout << "�߸� �Է��ϼ̽��ϴ�.";
		}
		else if (chat == "3") {
			cout << "�뿩 �Ͻ� å�� ������ �Է��� �ּ���\n:";
			cin >> title;
			BRM.borrowBook(title);
		}
		else if (chat == "4") {
			cout << "�ݳ��Ͻ� å�� ������ �Է��� �ּ���\n:";
			cin >> title;
			BRM.returnBook(title);
		}
	}
	return 0;
}