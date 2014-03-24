//============================================================================
// Name        : ReserveList
// Author      : Scott Dreyer
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <list>
#include <vector>
/*
 * For this problem I created a book class that will take a string for a title and an
 * integer for book thickness.  I used a list to store all of the books on the shelf
 * and a vector to temporarily store the books that are checked out.
 *
 */
using namespace std;

class Book {
private:
	string title;
	int bookLength;

public:
	Book(string name, int size) {
		bookLength = size;
		title = name;
	}
	int getBookLength() const {
		return bookLength;
	}
	string getTitle() const {
		return title;
	}

	bool operator ==(const Book& other) {
		if(this->getTitle()==other.getTitle()&&this->getBookLength()
				==other.getBookLength()){
			return true;
		}else
			return false;
	}

};

class BookShelf {
public:
	std::list<Book> shelf;
	int shelfSpace;
	vector<Book> out;

	BookShelf(int space){
		shelfSpace = space;
		shelf.empty();
		out.empty();
	}

	void add(Book currentBook) {
		//Book myBook = Book(bookName, bookThickness);
		if (shelfSpace < currentBook.getBookLength()) {
			int temp = shelf.back().getBookLength();
			shelfSpace += temp;
			shelf.pop_back();
			add(currentBook);

		} else {
			shelf.push_front(currentBook);
			shelfSpace -= currentBook.getBookLength();
		}

	}

	void bookReturn(string str){
		for(auto i=out.begin();i!=out.end();++i){
			if(str==i->getTitle()){
				Book myBook = Book(i->getTitle(),i->getBookLength());
				add(myBook);
				out.erase(i);
				break;
			}
		}
	}

	void checkout(string str) {
		for(auto it=shelf.begin();it!=shelf.end();it++){
			if(str==it->getTitle()){
				shelfSpace+=it->getBookLength();
				Book myBook = Book(it->getTitle(),it->getBookLength());
				shelf.erase(it);
				out.push_back(myBook);
				break;
			}
		}

	}

	void printOut() {
		for (auto it = shelf.begin(); it != shelf.end(); ++it) {
			Book &currentBook = (*it);
			cout << setw(35) << left;
			cout << currentBook.getTitle();
			cout << right << currentBook.getBookLength() << endl;
		}
		cout << "AVAILABLE SHELF SPACE:" << shelfSpace << endl;
		cout << "" << endl;
	}

};

int main(int argc, const char * argv[]) {
	ifstream input(argv[1]);
	int availableSpace;
	int thickness;
	string command, title,space;

	input >> availableSpace;
	BookShelf reserved = (availableSpace);

	while (input >> command) {
        input >> std::ws;

		if (command == "ADD") {
			getline(input, title);
			auto pos = title.find_last_of(' ');
			thickness = atoi(title.substr(pos, title.size()).c_str());
			title = title.substr(0, pos);
			int x=0;
			for(int i=title.length()-1;i>0;i--){
				if(title.at(i)==' '){
					x++;
				}else{
					title= title.substr(0,title.length()-x);
					break;
				}
			}
			Book myBook = Book(title, thickness);
			reserved.add(myBook);


		} else if (command == "CHECKOUT") {
			getline(input, title);
			reserved.checkout(title);

		} else if (command == "RETURN") {
			getline(input, title);
			reserved.bookReturn(title);

		} else {
			reserved.printOut();
		}
	}
	cout << "End of program by Scott Dreyer." << endl;
	return 0;
}
