#pragma once
#include "Book.h"
#include <map>

class BorrowManager {
private:
	map<string, int> unorderedbook;
public:
	void initialize_stock(const Book& book, int quantity);
	void borrowBook(string title);
	void returnBook(string title);
	void displayStock();
};