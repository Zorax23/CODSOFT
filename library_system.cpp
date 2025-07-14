#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Book {
    string title;
    string author;
    string isbn;
    bool isAvailable = true;
};

struct Borrower {
    string name;
    string isbn;
    int borrowDays;
    bool isReturned = false;
};

vector<Book> books;
vector<Borrower> borrowers;

void addBook() {
    Book book;
    cout << "\nEnter book title: ";
    cin.ignore();
    getline(cin, book.title);
    cout << "Enter author: ";
    getline(cin, book.author);
    cout << "Enter ISBN: ";
    getline(cin, book.isbn);
    books.push_back(book);
    cout << "Book added successfully!" << endl;
}

void viewBooks() {
    cout << "\nLibrary Books:\n";
    if (books.empty()) {
        cout << "No books in the library.\n";
        return;
    }
    for (const auto& book : books) {
        cout << "Title: " << book.title
             << " | Author: " << book.author
             << " | ISBN: " << book.isbn
             << " | Status: " << (book.isAvailable ? "Available" : "Checked Out") << endl;
    }
}

void searchBook() {
    int choice;
    string query;

    cout << "\nSearch Book By:\n1. Title\n2. Author\n3. ISBN\nEnter choice: ";
    cin >> choice;
    cin.ignore();

    cout << "Enter search keyword: ";
    getline(cin, query);

    bool found = false;
    for (const auto& book : books) {
        if ((choice == 1 && book.title.find(query) != string::npos) ||
            (choice == 2 && book.author.find(query) != string::npos) ||
            (choice == 3 && book.isbn == query)) {
            found = true;
            cout << "\nTitle: " << book.title
                 << "\nAuthor: " << book.author
                 << "\nISBN: " << book.isbn
                 << "\nStatus: " << (book.isAvailable ? "Available" : "Checked Out") << "\n";
        }
    }

    if (!found) {
        cout << "No matching book found." << endl;
    }
}

void checkoutBook() {
    string isbn, borrowerName;
    cout << "\nCheckout Book\nEnter ISBN: ";
    cin.ignore();
    getline(cin, isbn);

    for (auto& book : books) {
        if (book.isbn == isbn && book.isAvailable) {
            cout << "Enter borrower's name: ";
            getline(cin, borrowerName);
            Borrower b;
            b.name = borrowerName;
            b.isbn = isbn;
            cout << "Enter number of days to borrow: ";
            cin >> b.borrowDays;
            b.isReturned = false;

            borrowers.push_back(b);
            book.isAvailable = false;
            cout << "Book checked out successfully!" << endl;
            return;
        }
    }

    cout << "Book is not available or ISBN is incorrect." << endl;
}

void returnBook() {
    string isbn;
    cout << "\nReturn Book\nEnter ISBN: ";
    cin.ignore();
    getline(cin, isbn);

    bool bookFound = false, borrowerFound = false;

    for (auto& book : books) {
        if (book.isbn == isbn && !book.isAvailable) {
            bookFound = true;

            for (auto& b : borrowers) {
                if (b.isbn == isbn && !b.isReturned) {
                    borrowerFound = true;

                    int returnDays;
                    cout << "Enter number of days book was kept: ";
                    cin >> returnDays;
                    int overdue = returnDays - b.borrowDays;

                    if (overdue > 0) {
                        cout << "Book is overdue by " << overdue << " days.\n";
                        cout << "Fine: ₹" << overdue * 2 << endl;
                    } else {
                        cout << "Book returned on time. No fine." << endl;
                    }

                    book.isAvailable = true;
                    b.isReturned = true;
                    return;
                }
            }
        }
    }

    if (!bookFound)
        cout << "Book not found or not checked out." << endl;
    else if (!borrowerFound)
        cout << "Borrower record not found or already returned." << endl;
}

void showMenu() {
    cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
    cout << "1. Add Book\n";
    cout << "2. View All Books\n";
    cout << "3. Search Book\n";
    cout << "4. Checkout Book\n";
    cout << "5. Return Book\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: searchBook(); break;
            case 4: checkoutBook(); break;
            case 5: returnBook(); break;
            case 6: cout << "Exiting... Thank you!\n"; break;
            default: cout << "Invalid choice. Try again!\n"; break;
        }
    } while (choice != 6);

    return 0;
}
