#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>

using namespace std;

struct Book {
    int id;
    string title;
    string author;
    bool isIssued;
    string issuedTo; // Username of the member who issued the book
    time_t dueDate;  // Due date for return
};

struct User {
    string username;
    string password;
    bool isAdmin; // True for admin, false for member
};

vector<Book*> library; // Dynamically allocated books
vector<User> users;    // User accounts

// Function prototypes
void loadBooks();
void saveBooks();
void loadUsers();
void saveUsers();
void addBook();
void listBooks();
void searchBook();
void issueBook(const string& username);
void returnBook(const string& username);
void calculateFine(const string& username);
void displayMenu(bool isAdmin);
void adminMenu();
void memberMenu(const string& username);
void login();
void registerUser();
time_t calculateDueDate(int days);
string formatDate(time_t rawTime);

int main() {
    loadBooks();
    loadUsers();
    login();
    saveBooks();
    saveUsers();
    return 0;
}

// Load books from file
void loadBooks() {
    ifstream inFile("books.txt");
    if (!inFile) return;

    int bookCount;
    inFile >> bookCount;
    inFile.ignore();

    for (int i = 0; i < bookCount; ++i) {
        Book* book = new Book;
        getline(inFile, book->title);
        getline(inFile, book->author);
        inFile >> book->id >> book->isIssued >> book->dueDate;
        inFile.ignore();
        getline(inFile, book->issuedTo);
        library.push_back(book);
    }

    inFile.close();
}

// Save books to file
void saveBooks() {
    ofstream outFile("books.txt");
    outFile << library.size() << "\n";
    for (const auto& book : library) {
        outFile << book->title << "\n"
            << book->author << "\n"
            << book->id << "\n"
            << book->isIssued << "\n"
            << book->dueDate << "\n"
            << book->issuedTo << "\n";
    }
    outFile.close();
}

// Load users from file
void loadUsers() {
    ifstream inFile("users.txt");
    if (!inFile) return;

    int userCount;
    inFile >> userCount;
    inFile.ignore();

    for (int i = 0; i < userCount; ++i) {
        User user;
        getline(inFile, user.username);
        getline(inFile, user.password);
        inFile >> user.isAdmin;
        inFile.ignore();
        users.push_back(user);
    }

    inFile.close();
}

// Save users to file
void saveUsers() {
    ofstream outFile("users.txt");
    outFile << users.size() << "\n";
    for (const auto& user : users) {
        outFile << user.username << "\n"
            << user.password << "\n"
            << user.isAdmin << "\n";
    }
    outFile.close();
}

// Add a new book
void addBook() {
    Book* book = new Book;
    cout << "Enter Book Title: ";
    cin.ignore();
    getline(cin, book->title);
    cout << "Enter Book Author: ";
    getline(cin, book->author);
    cout << "Enter Book ID: ";
    cin >> book->id;

    book->isIssued = false;
    book->issuedTo = "";
    book->dueDate = 0;

    library.push_back(book);
    cout << "Book added successfully!\n";
}

// List all books
void listBooks() {
    if (library.empty()) {
        cout << "No books in the library.\n";
        return;
    }

    cout << setw(5) << "ID" << setw(20) << "Title" << setw(20) << "Author"
        << setw(10) << "Status" << setw(20) << "Issued To"
        << setw(20) << "Due Date" << "\n";

    for (const auto& book : library) {
        cout << setw(5) << book->id
            << setw(20) << book->title
            << setw(20) << book->author
            << setw(10) << (book->isIssued ? "Issued" : "Available")
            << setw(20) << (book->isIssued ? book->issuedTo : "-")
            << setw(20) << (book->isIssued ? formatDate(book->dueDate) : "-")
            << "\n";
    }
}

// Search a book by ID
void searchBook() {
    int id;
    cout << "Enter Book ID to search: ";
    cin >> id;

    for (const auto& book : library) {
        if (book->id == id) {
            cout << "Book Found!\n";
            cout << "ID: " << book->id << ", Title: " << book->title
                << ", Author: " << book->author
                << ", Status: " << (book->isIssued ? "Issued" : "Available")
                << "\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

// Issue a book
void issueBook(const string& username) {
    int id;
    cout << "Enter Book ID to issue: ";
    cin >> id;

    for (auto& book : library) {
        if (book->id == id) {
            if (book->isIssued) {
                cout << "Book is already issued.\n";
            }
            else {
                book->isIssued = true;
                book->issuedTo = username;
                book->dueDate = calculateDueDate(7); // 7 days due
                cout << "Book issued successfully. Due date: "
                    << formatDate(book->dueDate) << "\n";
            }
            return;
        }
    }
    cout << "Book not found.\n";
}

// Return a book
void returnBook(const string& username) {
    int id;
    cout << "Enter Book ID to return: ";
    cin >> id;

    for (auto& book : library) {
        if (book->id == id && book->issuedTo == username) {
            book->isIssued = false;
            book->issuedTo = "";
            book->dueDate = 0;
            cout << "Book returned successfully.\n";
            return;
        }
    }
    cout << "Book not found or not issued to you.\n";
}

// Calculate fine for overdue books
void calculateFine(const string& username) {
    const int finePerDay = 10;
    int totalFine = 0;

    for (const auto& book : library) {
        if (book->issuedTo == username && time(nullptr) > book->dueDate) {
            int overdueDays = (time(nullptr) - book->dueDate) / (24 * 3600);
            totalFine += overdueDays * finePerDay;
        }
    }

    cout << "Total fine for overdue books: $" << totalFine << "\n";
}

// Login user
void login() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    for (const auto& user : users) {
        if (user.username == username && user.password == password) {
            if (user.isAdmin) {
                adminMenu();
            }
            else {
                memberMenu(username);
            }
            return;
        }
    }
    cout << "Invalid credentials. Try again.\n";
    login();
}

// Register new user
void registerUser() {
    User user;
    cout << "Enter username: ";
    cin >> user.username;
    cout << "Enter password: ";
    cin >> user.password;
    cout << "Are you an admin? (1 for yes, 0 for no): ";
    cin >> user.isAdmin;

    users.push_back(user);
    cout << "User registered successfully!\n";
}

// Calculate due date
time_t calculateDueDate(int days) {
    return time(nullptr) + days * 24 * 3600;
}

string formatDate(time_t rawTime) {
    struct tm timeInfo;
    char buffer[20];

    // Use localtime_s instead of localtime
    if (localtime_s(&timeInfo, &rawTime) != 0) {
        return "Error in date formatting";
    }

    strftime(buffer, sizeof(buffer), "%Y-%m-%d", &timeInfo);
    return string(buffer);
}


// Format time to string
//string formatDate(time_t rawTime) {
//    char buffer[20];
//    strftime(buffer, sizeof(buffer), "%Y-%m-%d", localtime(&rawTime));
//    return string(buffer);
//}

// Admin menu
void adminMenu() {
    int choice;
    do {
        cout << "\n--- Admin Menu ---\n";
        cout << "1. Add Book\n";
        cout << "2. List Books\n";
        cout << "3. Search Book\n";
        cout << "4. Register User\n";
        cout << "5. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addBook();
            break;
        case 2:
            listBooks();
            break;
        case 3:
            searchBook();
            break;
        case 4:
            registerUser();
            break;
        case 5:
            cout << "Logging out...\n";
            return;
        default:
            cout << "Invalid choice.\n";
        }
    } while (true);
}

// Member menu
void memberMenu(const string& username) {
    int choice;
    do {
        cout << "\n--- Member Menu ---\n";
        cout << "1. List Books\n";
        cout << "2. Search Book\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Calculate Fine\n";
        cout << "6. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            listBooks();
            break;
        case 2:
            searchBook();
            break;
        case 3:
            issueBook(username);
            break;
        case 4:
            returnBook(username);
            break;
        case 5:
            calculateFine(username);
            break;
        case 6:
            cout << "Logging out...\n";
            return;
        default:
            cout << "Invalid choice.\n";
        }
    } while (true);
}
