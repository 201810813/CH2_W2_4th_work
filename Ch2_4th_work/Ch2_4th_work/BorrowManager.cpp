#include "BorrowManager.h"



void BorrowManager::initialize_stock(const Book& book, int quantity)
{
	unorderedbook.insert({ book.title, quantity});
}
void BorrowManager::borrowBook(string title) {
	if (unorderedbook.find(title) != unorderedbook.end()) {
		if (unorderedbook[title] > 0) {
			int select;
			cout << "책을 빌릴 수 있습니다 빌리시겠습니까? (1:yes, 2:no):\n재고: " << unorderedbook[title] << endl;
			cin >> select;
			if (select == 1) {
				cout << title << "책을 빌렸습니다 1주일 내로 반납해 주세요";
				unorderedbook[title]--;
				return;
			}
			else if (select == 2) {
				cout << "다음에 뵙겠습니다" << endl;
				return;
			}
		}
		else cout << "재고가 부족합니다 빌릴 수 없습니다.";
	}
	else cout << "해당 책이 없습니다.";
}

void BorrowManager::returnBook(string title)
{
	if (unorderedbook.find(title) != unorderedbook.end()) {
		if (unorderedbook[title] < 3) {
			cout << title << "책을 반납하겠습니다" << endl;
			unorderedbook[title]++;
		}
		else cout << "해당 책을 빌린적이 없습니다.";
	}
	else cout << "해당 책이 없습니다.";
}

void BorrowManager::displayStock()
{
	std::map<string, int>::iterator it = unorderedbook.begin();
	for (it; it != unorderedbook.end(); ++it) {
		std::cout << "제목: " << it->first << "\n" << " 남은 수량: " << it->second << std::endl;
	}
}