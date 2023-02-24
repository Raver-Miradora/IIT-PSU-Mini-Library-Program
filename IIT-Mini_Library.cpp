#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Book {
    string accessionnumber;
    string title;
    string author;
    string publisher;
    int year;
    bool issued = false;
    int numCopies;
};

char displayMenu();
void addBook(vector<Book> &books);
void printBookDetails(vector<Book> &books);
void issueBook(vector<Book> &books);
void printallBook(vector<Book> &books);
void deleteBook(vector<Book> &books);
void returnBook(vector<Book> &books);
int getCopiesByTitle(string title);
int getCopiesByAuthor(string author);


int main(){

    vector<Book> books;
    string author, title;
    char c;
    while(c != 'q' && c != 'Q'){
        c = displayMenu();
        switch(c){
            case 'a':
            case 'A':
                addBook(books);
                break;
            case 'b':
            case 'B':
                deleteBook(books);
                break;
            case 'e':
            case 'E':
                printBookDetails(books);
                break;
            case 'c':
            case 'C':
                issueBook(books);
                break;
            case 'h':
            case 'H':
                printallBook(books);
                break;
            case 'd':
            case 'D':
                returnBook(books);
                break;
            case 'f':
            case 'F':
                getCopiesByTitle(title);
                break;
            case 'g':
            case 'G':
                getCopiesByAuthor(author);
                break;
            case 'q':
            case 'Q':
                cout << "Terminating program.\n";
                break;
            default:
                cout << "Invalid input. Try again.\n";
        }
    }
    return 0;
}
char displayMenu(){
    char op;

    cout << "\nWelcome to IIT Mini Library\n"
        << "\t[A] Add new acquired book\n"
        << "\t[B] Delete book record\n"
        << "\t[C] Issue a book\n"
        << "\t[D] Return a book\n"
        << "\t[E] Print details of particular books\n"
        << "\t[F] Get number of copies per title\n"
        << "\t[G] Get number of copies per author\n"
        << "\t[H] Print details of all books\n"
        << "\t[Q] terminate the program\n"
        << "What do you want to do? ";
        cin >> op;
        return op;
}
void addBook(vector<Book> &books){

    Book tmp;

    cout << "Input the details for the new book.\n";
    cout << "Accession number: ";
    cin.ignore();
    getline(cin, tmp.accessionnumber);

    cout << "Title: ";
    getline(cin, tmp.title);

    cout << "Author: ";
    getline(cin, tmp.author);

    cout << "Publisher: ";
    getline(cin, tmp.publisher);

    cout << "Year Published: ";
    cin >> tmp.year;

    cout << "Book successfully added to the record.\n";

    books.push_back(tmp);

}

void printBookDetails(vector<Book> &books){

    string accession;

    cout << "Input the accession number of the books you want to check the details.\n";
    cin.ignore();
    getline(cin, accession);

    for(int i = 0; i < books.size(); i++){
        if(accession == books[i].accessionnumber){
            cout << "Accession Number: " << accession << endl
                << "Title: " << books[i].title
                << "\nAuthor: " << books[i].author
                << "\nPublisher: " << books[i].publisher << "\t"
                << "\nYear Published: " << books[i].year << endl
                << "Issued: " << (books[i].issued ? "Yes" : "No") << endl;
                break;
        }
    }
}

void issueBook(vector<Book> &books){
    string accession;
    bool found = false;

    cout << "Input the accession number of the book you want to issue: ";
    cin.ignore();
    getline(cin, accession);

    for(int i = 0; i < books.size(); i++){
        if(accession == books[i].accessionnumber){
            books[i].issued = true;
            cout << "Book successfully added.\n";
            found = true;
            break;
        }
    }

    if(!found){

        cout << "The book with accession number " << accession
            << " was not found.\n";
    }
}

void printallBook(vector<Book> &books){

    for(int i = 0; i < books.size(); i++){
        cout << "Accession Number" << "\t\tTitle" << "\t\tAuthor"
            << "\t\tPublisher" << "\t\tYear Published" << "\t\tIssued?\n";
        cout << books[i].accessionnumber << "\t" << books[i].title << "\t"
             << books[i].author << "\t" << books[i].publisher << "\t"
             << books[i].year << "\t" << books[i].issued << endl;

             break;
    }
}

void deleteBook(vector<Book> &books){
    string accession;
    bool found = false;

    cout << "Input the accession number of the book you want to delete: ";
    cin.ignore();
    getline(cin, accession);

    for (auto it = books.begin(); it != books.end(); it++) {
        if (it->accessionnumber == accession) {
            books.erase(it);
            cout << "Book successfully deleted.\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "The book with accession number " << accession
            << " was not found.\n";
    }
}

void returnBook(vector<Book> &books){
    string accession;
    bool found = false;

    cout << "Input the accession number of the book you want to return: ";
    cin.ignore();
    getline(cin, accession);

    for(int i = 0; i < books.size(); i++){
        if(accession == books[i].accessionnumber){
            if (books[i].issued) {
                books[i].issued = false;
                cout << "Book successfully returned.\n";
            } else {
                cout << "The book with accession number " << accession
                    << " is not currently issued.\n";
            }
            found = true;
            break;
        }
    }

    if(!found){
        cout << "The book with accession number " << accession
            << " was not found.\n";
    }
}

// Returns the number of copies of books with a particular title
int getCopiesByTitle(string title) {
    vector<Book> books;
    int totalCopies = 0;
    for (int i = 0; i < books.size(); i++) {
        if (books[i].title == title) {
            totalCopies += books[i].numCopies;
        }
    }
    return totalCopies;
}

// Returns the number of copies of books by a particular author
int getCopiesByAuthor(string author) {
    int totalCopies = 0;
    vector<Book> books;
    for (int i = 0; i < books.size(); i++){
        if (books[i].author == author){
            totalCopies += books[i].numCopies;
        }
    }
    return totalCopies;
}
