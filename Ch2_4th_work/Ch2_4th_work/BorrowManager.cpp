#include "BorrowManager.h"



void BorrowManager::initialize_stock(const Book& book, int quantity)
{
	unorderedbook.insert({ book.title, quantity});
}
void BorrowManager::borrowBook(string title) {
	if (unorderedbook.find(title) != unorderedbook.end()) {
		if (unorderedbook[title] > 0) {
			int select;
			cout << "å�� ���� �� �ֽ��ϴ� �����ðڽ��ϱ�? (1:yes, 2:no):\n���: " << unorderedbook[title] << endl;
			cin >> select;
			if (select == 1) {
				cout << title << "å�� ���Ƚ��ϴ� 1���� ���� �ݳ��� �ּ���";
				unorderedbook[title]--;
				return;
			}
			else if (select == 2) {
				cout << "������ �˰ڽ��ϴ�" << endl;
				return;
			}
		}
		else cout << "��� �����մϴ� ���� �� �����ϴ�.";
	}
	else cout << "�ش� å�� �����ϴ�.";
}

void BorrowManager::returnBook(string title)
{
	if (unorderedbook.find(title) != unorderedbook.end()) {
		if (unorderedbook[title] < 3) {
			cout << title << "å�� �ݳ��ϰڽ��ϴ�" << endl;
			unorderedbook[title]++;
		}
		else cout << "�ش� å�� �������� �����ϴ�.";
	}
	else cout << "�ش� å�� �����ϴ�.";
}

void BorrowManager::displayStock()
{
	std::map<string, int>::iterator it = unorderedbook.begin();
	for (it; it != unorderedbook.end(); ++it) {
		std::cout << "����: " << it->first << "\n" << " ���� ����: " << it->second << std::endl;
	}
}