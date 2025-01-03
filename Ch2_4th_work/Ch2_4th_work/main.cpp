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
		cout << "메뉴를 선택하세요 \n1. 책 입력\n2. 검색\n3. 대여\n4. 반납\n(종료: -1)" << endl;
		cin >> chat;
		cin.ignore();
		if (chat == "1") {
			cout << "책의 제목을 입력하세요" << endl;
			getline(cin, title);
			cout << "작가의 이름을 입력하세요" << endl;
			getline(cin, author);
			BM.addBook(title, author);
			BRM.initialize_stock(*(BM.getBookByTitle(title)), 3);
			cout << title << "책이 매장에 등록되었습니다.";
		}
		else if (chat == "2") {
			cout << "책 제목으로 찾기: 1\n작가 이름으로 찾기: 2" << endl;
			cin >> chat;
			cin.ignore();
			if (chat == "1") {
				cout << "제목: ";
				getline(cin, title);
				cout << BM.getBookByTitle(title)->title << "책이 있습니다." << endl;
			}
			else if (chat == "2") {
				cout << "작가: ";
				getline(cin, author);
				cout << BM.getBookByAuthor(author)->author << "가 쓴 책이 있습니다." << endl;
			}
			else cout << "잘못 입력하셨습니다.";
		}
		else if (chat == "3") {
			cout << "대여 하실 책의 제목을 입력해 주세요\n:";
			getline(cin, title);
			BRM.borrowBook(title);
		}
		else if (chat == "4") {
			cout << "반납하실 책의 제목을 입력해 주세요\n:";
			getline(cin, title);
			BRM.returnBook(title);
		}
		else {
			cout << "잘못 입력하셨습니다." << endl;
		}
	}
	return 0;
}