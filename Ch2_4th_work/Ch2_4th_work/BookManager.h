#pragma once
#include <vector>
#include "Book.h"
class BookManager {
public:
	void addBook(string title, string author);
	void displayAllBooks();
	Book* getBookByTitle(string title);
	Book* getBookByAuthor(string author);
	~BookManager();
private:
	Book* findBookByTitle(string title);
	Book* findBookByAuthor(string author);
	
private:
	vector<Book*> books;
};