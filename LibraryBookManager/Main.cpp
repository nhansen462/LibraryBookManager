// Library Book Manager
// Nicholas Hansen

#include <iostream>
#include <conio.h>

using namespace std;

struct Book{
	string title;
	string author;
	int yearPublished;
	int numPages;
};

int main() {
	const int numBooks = 4;
	Book hobbit = { "The Hobbit", "J.R.R. Tolkien", 1937, 346 };

	// To Kill a Mockingbird release year: 1960
	Book mockingbird = { "To Kill a Mockingbird", "Harper Lee", NULL, 281 };

	// Frankenstein author: Mary Shelley
	// Frankenstein release year: 1818
	Book frankenstein = { "Frankenstein", "Victor Frankenstein", 1931, 280 };

	// Crime and Punishment page count: 527
	Book crime = { "Crime and Punishment", "Fyodor Dostoevsky", 1866 };

	Book books[numBooks] = { hobbit, mockingbird, frankenstein, crime };

	for (int i = 0; i < numBooks; i++) {
		cout << books[i].title << " written by " << books[i].author << " in " << books[i].yearPublished << ". Has " << books[i].numPages << " pages.\n\n";
	}

	int bookID = 0;
	//Checks to see if the user would like to quit
	while (true) {
		cout << "Enter Book ID to modify (0-3) [-1 to quit]: ";
		cin >> bookID;
		if (bookID == -1) {
			break;
		}

		//checks to see if the bookID is valid
		while (!(bookID >= 0 && bookID < numBooks)) {
			cout << "Enter a valid Book ID (0-3): ";
			cin >> bookID;
		}

		// instanciating variables to be used later
		string title = books[bookID].title;
		string author = books[bookID].author;
		int yearPublished = books[bookID].yearPublished;
		int pageCount = books[bookID].numPages;
		bool complete = true;
		char check;
		int input = -1;

		while (complete) {
			// Asks user for input on what they would like to change
			cout << "What would you like to change?\n[0] for Title\n[1] for Author\n[2] for Year Published\n[3] for Page Count\n[4] to quit\n";
			cin >> input;
			// Checks to see if the user input is a valid number
			while (!(input >= 0 && input <= 4)) {
				cout << "Enter a valid number.\n[0] for Title\n[1] for Author\n[2] for Year Published\n[3] for Page Count\n[4] to quit\n";
			}

			// Checks to see if the user would like to quit
			if (input != 4) {
				do {
					// Uses the input to determine what the user would like to change
					if (input == 0) {
						cout << "What would you like to change the title to? ";
						cin >> title;
					}
					else if (input == 1) {
						cout << "What would to like to change to author to? ";
						cin >> author;
					}
					else if (input == 2) {
						cout << "What would you like to change the release year to? ";
						cin >> yearPublished;
					}
					else {
						cout << "What would you like to change the page count to? ";
						cin >> pageCount;
					}

					input = -1;
					// Asks the user if they would like to continue modifying
					cout << "Would you like to make any more changes to this book? [y/n] ";
					cin >> check;
					if (check == 'n') {
						complete = false;
					}
					else {
						cout << "What would you like to change?\n[0] for Title\n[1] for Author\n[2] for Year Published\n[3] for Page Count\n[4] to quit\n";
						cin >> input;
						// Checks to see if the user input is a valid number
						while (!(input >= 0 && input <= 4)) {
							cout << "Enter a valid number.\n[0] for Title\n[1] for Author\n[2] for Year Published\n[3] for Page Count\n[4] to quit\n";
						}
					}

				} while (complete);


				cout << "Would you like to save the changes made? [y/n] ";
				cin >> check;
				if (check == 'y') {
					books[bookID].title = title;
					books[bookID].author = author;
					books[bookID].yearPublished = yearPublished;
					books[bookID].numPages = pageCount;

					cout << "The following has been updated.\n";
					cout << books[bookID].title << " written by " << books[bookID].author << " in " << books[bookID].yearPublished << ". Has " << books[bookID].numPages << " pages.\n\n";
				}
			}
		}
	}

	(void)_getch();
	return 0;
}