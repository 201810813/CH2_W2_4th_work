#include "BookManager.h"

void BookManager::addBook(string title, string author) {
	Book* book = new Book(title, author);
	books.push_back(book);
}

void BookManager::displayAllBooks()
{
	for (int i = 0; i < books.size(); i++) {
		cout << "소유한 책\n" <<"-------------------- \n" << "책 이름: " 
			<< books[i]->title << "작가: "<< books[i]->author << endl;
	}
}

Book* BookManager::getBookByTitle(string title)
{
	for (auto iter = books.begin(); iter != books.end(); ++iter) {
		if ((*iter)->title == title) {
			return *iter;
		}
	}
	return nullptr;
}

Book* BookManager::getBookByAuthor(string author)
{
	for (auto iter = books.begin(); iter != books.end(); ++iter) {
		if ((*iter)->author == author) {
			return *iter;
		}
	}
	cout << "찾으시는 책이 없습니다.";
	return nullptr;
}

BookManager::~BookManager()
{
	for (int i = 0; i < books.size(); ++i) {
		delete books[i];
	}
}

Book* BookManager::findBookByTitle(string title)
{
	for (auto iter = books.begin(); iter != books.end(); ++iter) {
		if ((*iter)->title == title) {
			return *iter;
		}
	}
	return nullptr;
}

Book* BookManager::findBookByAuthor(string author)
{
	for (auto iter = books.begin(); iter != books.end(); ++iter) {
		if ((*iter)->author == author) {
			return *iter;
		}
	}
	return nullptr;
}


