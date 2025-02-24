#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // For std::setw

using namespace std;

class Book {
private:
    string title;
    string author;
    int year;

public:
    // Constructor
    Book(string t, string a, int y) : title(t), author(a), year(y) {}

    // Getters
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getYear() const { return year; }

    // Method to display book details
    void display() const {
        cout << setw(30) << left << title
             << setw(20) << left << author
             << year << endl;
    }
};

class Library {
private:
    vector<Book> books; // Vector to store books

public:
    // Method to add a book
    void addBook(const Book& book) {
        books.push_back(book);
        cout << "Book added successfully!" << endl;
    }

    // Method to display all books
    void displayBooks() const {
        cout << "Book List:" << endl;
        cout << setw(30) << left << "Title"
             << setw(20) << left << "Author"
             << "Year" << endl;
        cout << string(70, '-') << endl; // Separator line
        for (const auto& book : books) {
            book.display();
        }
    }

    // Method to search for a book by title
    void searchBook(const string& title) const {
        for (const auto& book : books) {
            if (book.getTitle() == title) {
                cout << "Book found!" << endl;
                cout << "Title: " << book.getTitle() << endl;
                cout << "Author: " << book.getAuthor() << endl;
                cout << "Year: " << book.getYear() << endl;
                return;
            }
        }
        cout << "Book not found!" << endl;
    }
};

int main() {
    Library library;
    int choice;

    do {
        // Display menu
        cout << "Menu" << endl;
        cout << "1 - Add Book" << endl;
        cout << "2 - Display Books" << endl;
        cout << "3 - Search Book" << endl;
        cout << "4 - Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the newline character from the input buffer

        switch (choice) {
            case 1: {
                // Add Book
                string title, author;
                int year;
                cout << "Enter title: ";
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                cout << "Enter year: ";
                cin >> year;
                cin.ignore(); // Clear the newline character
                Book newBook(title, author, year);
                library.addBook(newBook);
                break;
            }
            case 2:
                // Display Books
                library.displayBooks();
                break;
            case 3: {
                // Search Book
                string searchTitle;
                cout << "Enter a book title to search: ";
                getline(cin, searchTitle);
                library.searchBook(searchTitle);
                break;
            }
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}