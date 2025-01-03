#include "BookManager.h"

void BookManager::addBook(string title, string author) {
	Book* book = new Book(title, author);
	books.push_back(book);
}

void BookManager::displayAllBooks()
{
	for (int i = 0; i < books.size(); i++) {
		cout << "������ å\n" <<"-------------------- \n" << "å �̸�: " 
			<< books[i]->title << "�۰�: "<< books[i]->author << endl;
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
	cout << "ã���ô� å�� �����ϴ�.";
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


