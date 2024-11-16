#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <map>
#include <algorithm>
using namespace std;

// Structs for Book and User
struct Book {
    int id;
    string title;
    string author;
    string category;
    bool isIssued;
    string issuedTo;
    time_t dueDate;
    vector<string> reservations;
};

struct User {
    string username;
    string password;
    bool isAdmin;
    bool isActive;
    int borrowedBooks;
};

// Global variables
vector<Book*> library;
vector<User> users;
map<string, int> fineRates = { {"default", 10} };

const int MAX_BORROW_LIMIT = 3;

// Function prototypes
void loadBooks();
void saveBooks();
void loadUsers();
void saveUsers();
void adminMenu();
void memberMenu(const string& username);
void addBook();
void listBooks();
void searchBook();
void issueBook(const string& username);
void returnBook(const string& username);
void reserveBook(const string& username);
void calculateFine(const string& username);
void setFineRates();
void deactivateUser();
time_t calculateDueDate(int days);
string formatDate(time_t rawTime);
void login();
void registerUser();
void displayMemberMenu();
void displayAdminMenu();

//Function prototypes
void loadBooks();
void saveBooks();
void loadUsers();
void saveUsers();
void adminMenu();
void memberMenu(const string& username);
void addBook();
void listBooks();
void searchBook();
void searchAdvanced();
void issueBook(const string& username);
void returnBook(const string& username);
void reserveBook(const string& username);
void calculateFine(const string& username);
void overdueNotifications(const string& username);
void recommendBooks();
void setFineRates();
void deactivateUser();
time_t calculateDueDate(int days);
string formatDate(time_t rawTime);
void login();
void registerUser();
void displayMemberMenu();
void displayAdminMenu();

void exportBorrowingHistory(const string& username);
void sendReturnReminders();
void displayPopularBooks();
void searchByYear(int year);
void resetPassword(const string& username);







// --- FILE OPERATIONS ---
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
        getline(inFile, book->category);
        inFile >> book->id >> book->isIssued >> book->dueDate;
        inFile.ignore();
        getline(inFile, book->issuedTo);
        int reserveCount;
        inFile >> reserveCount;
        inFile.ignore();
        for (int j = 0; j < reserveCount; ++j) {
            string username;
            getline(inFile, username);
            book->reservations.push_back(username);
        }
        library.push_back(book);
    }
    inFile.close();
}

void saveBooks() {
    ofstream outFile("books.txt");
    outFile << library.size() << "\n";
    for (const auto& book : library) {
        outFile << book->title << "\n"
            << book->author << "\n"
            << book->category << "\n"
            << book->id << "\n"
            << book->isIssued << "\n"
            << book->dueDate << "\n"
            << book->issuedTo << "\n"
            << book->reservations.size() << "\n";
        for (const auto& user : book->reservations) {
            outFile << user << "\n";
        }
    }
    outFile.close();
}

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
        inFile >> user.isAdmin >> user.isActive >> user.borrowedBooks;
        inFile.ignore();
        users.push_back(user);
    }
    inFile.close();
}

void saveUsers() {
    ofstream outFile("users.txt");
    outFile << users.size() << "\n";
    for (const auto& user : users) {
        outFile << user.username << "\n"
            << user.password << "\n"
            << user.isAdmin << "\n"
            << user.isActive << "\n"
            << user.borrowedBooks << "\n";
    }
    outFile.close();
}

// --- CORE FEATURES ---
void addBook() {
    Book* book = new Book;
    cout << "Enter Book Title: ";
    cin.ignore();
    getline(cin, book->title);
    cout << "Enter Book Author: ";
    getline(cin, book->author);
    cout << "Enter Book Category: ";
    getline(cin, book->category);
    cout << "Enter Book ID: ";
    cin >> book->id;

    book->isIssued = false;
    book->issuedTo = "";
    book->dueDate = 0;

    library.push_back(book);
    cout << "Book added successfully!\n";
}

void listBooks() {
    if (library.empty()) {
        cout << "No books in the library.\n";
        return;
    }

    cout << setw(5) << "ID" << setw(20) << "Title" << setw(20) << "Author"
        << setw(15) << "Category" << setw(10) << "Status"
        << setw(20) << "Issued To" << setw(20) << "Due Date" << "\n";

    for (const auto& book : library) {
        cout << setw(5) << book->id
            << setw(20) << book->title
            << setw(20) << book->author
            << setw(15) << book->category
            << setw(10) << (book->isIssued ? "Issued" : "Available")
            << setw(20) << (book->isIssued ? book->issuedTo : "-")
            << setw(20) << (book->isIssued ? formatDate(book->dueDate) : "-")
            << "\n";
    }
}



time_t calculateDueDate(int days) {
    return time(nullptr) + days * 24 * 3600;
}

string formatDate(time_t rawTime) {
    struct tm timeInfo;
    char buffer[20];
    localtime_s(&timeInfo, &rawTime);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", &timeInfo);
    return string(buffer);
}

void login() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    for (const auto& user : users) {
        if (user.username == username && user.password == password && user.isActive) {
            if (user.isAdmin) {
                adminMenu();
            }
            else {
                memberMenu(username);
            }
            return;
        }
    }
    cout << "Invalid credentials or inactive user. Try again.\n";
    login();
}

void registerUser() {
    User user;
    cout << "Enter username: ";
    cin >> user.username;
    cout << "Enter password: ";
    cin >> user.password;
    cout << "Are you an admin? (1 for yes, 0 for no): ";
    cin >> user.isAdmin;

    user.isActive = true;
    user.borrowedBooks = 0;
    users.push_back(user);
    cout << "User registered successfully!\n";
}
void searchBook() {
    int bookID;
    cout << "Enter Book ID to search: ";
    cin >> bookID;

    for (const auto& book : library) {
        if (book->id == bookID) {
            cout << "Book Found!\n";
            cout << "ID: " << book->id
                << ", Title: " << book->title
                << ", Author: " << book->author
                << ", Category: " << book->category
                << ", Status: " << (book->isIssued ? "Issued" : "Available")
                << "\n";
            return;
        }
    }
    cout << "Book not found in the library.\n";
}

void issueBook(const string& username) {
    int bookID;
    cout << "Enter Book ID to issue: ";
    cin >> bookID;

    for (auto& book : library) {
        if (book->id == bookID) {
            if (book->isIssued) {
                cout << "Book is already issued to another user.\n";
            }
            else {
                book->isIssued = true;
                book->issuedTo = username;
                book->dueDate = calculateDueDate(7); // 7 days due
                cout << "Book issued successfully! Due date: " << formatDate(book->dueDate) << "\n";
            }
            return;
        }
    }
    cout << "Book not found in the library.\n";
}

void returnBook(const string& username) {
    int bookID;
    cout << "Enter Book ID to return: ";
    cin >> bookID;

    for (auto& book : library) {
        if (book->id == bookID && book->issuedTo == username) {
            book->isIssued = false;
            book->issuedTo = "";
            book->dueDate = 0;
            cout << "Book returned successfully.\n";
            return;
        }
    }
    cout << "Book not found or not issued to you.\n";
}

void reserveBook(const string& username) {
    int bookID;
    cout << "Enter Book ID to reserve: ";
    cin >> bookID;

    for (auto& book : library) {
        if (book->id == bookID) {
            if (book->isIssued) {
                book->reservations.push_back(username);
                cout << "Book reserved successfully! You will be notified when it becomes available.\n";
            }
            else {
                cout << "Book is currently available. You can issue it directly.\n";
            }
            return;
        }
    }
    cout << "Book not found in the library.\n";
}

void calculateFine(const string& username) {
    const int finePerDay = fineRates["default"];
    int totalFine = 0;

    for (const auto& book : library) {
        if (book->issuedTo == username && time(nullptr) > book->dueDate) {
            int overdueDays = (time(nullptr) - book->dueDate) / (24 * 3600);
            totalFine += overdueDays * finePerDay;
        }
    }

    cout << "Total fine for overdue books: $" << totalFine << "\n";
}

void setFineRates() {
    string category;
    int rate;
    cout << "Enter category for fine rate (use 'default' for general): ";
    cin >> category;
    cout << "Enter fine rate per day: ";
    cin >> rate;

    fineRates[category] = rate;
    cout << "Fine rate updated successfully for category: " << category << "\n";
}

void deactivateUser() {
    string username;
    cout << "Enter username to deactivate: ";
    cin >> username;

    for (auto& user : users) {
        if (user.username == username) {
            user.isActive = false;
            cout << "User deactivated successfully.\n";
            return;
        }
    }
    cout << "User not found.\n";
}







int main() {
    loadBooks();
    loadUsers();
    login();
    saveBooks();
    saveUsers();
    return 0;
}

//--- Enhanced Features ---

//Recommend books based on popular categories
void recommendBooks() {
    cout << "\nRecommended Books by Popular Categories:\n";
    map<string, int> categoryCount;
    for (const auto& book : library) {
        if (!book->isIssued) {
            ++categoryCount[book->category];
        }
    }

    for (const auto& category : categoryCount) {
        cout << category.first << " - " << category.second << " available books\n";
    }
    cout << endl;
}

// Notify users of overdue books
void overdueNotifications(const string& username) {
    cout << "\n--- Overdue Notifications ---\n";
    bool hasOverdue = false;

    for (const auto& book : library) {
        if (book->issuedTo == username && time(nullptr) > book->dueDate) {
            cout << "Book '" << book->title << "' is overdue. Please return it as soon as possible.\n";
            hasOverdue = true;
        }
    }

    if (!hasOverdue) {
        cout << "No overdue books.\n";
    }
}

//Advanced book search
void searchAdvanced() {
    cout << "\n--- Advanced Search ---\n";
    int choice;
    cout << "Search by:\n1. Title\n2. Author\n3. Category\nEnter choice: ";
    cin >> choice;
    cin.ignore(); // Clear the newline character

    string query;
    cout << "Enter search query: ";
    getline(cin, query);

    bool found = false;
    for (const auto& book : library) {
        if ((choice == 1 && book->title.find(query) != string::npos) ||
            (choice == 2 && book->author.find(query) != string::npos) ||
            (choice == 3 && book->category.find(query) != string::npos)) {
            cout << "ID: " << book->id
                << ", Title: " << book->title
                << ", Author: " << book->author
                << ", Category: " << book->category
                << ", Status: " << (book->isIssued ? "Issued" : "Available") << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No books found matching the query.\n";
    }
}

//--- Member Menu ---
void memberMenu(const string& username) {
    int choice;
    do {
        displayMemberMenu();
        overdueNotifications(username); // Notify about overdue books
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            listBooks();
            break;
        case 2:
            searchAdvanced(); // Enhanced search
            break;
        case 3:
            issueBook(username);
            break;
        case 4:
            returnBook(username);
            break;
        case 5:
            reserveBook(username);
            break;
        case 6:
            calculateFine(username);
            break;
        case 7:
            recommendBooks(); // Book recommendations
            break;
        case 8:
            cout << "Logging out...\n";
            break;
        case 9:
            exportBorrowingHistory(username);
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (true);
}

// --- Admin Menu ---
void adminMenu() {
    int choice;
    string username;
    do {
        displayAdminMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addBook();
            break;
        case 2:
            listBooks();
            break;
        case 3:
            setFineRates();
            break;
        case 4:
            deactivateUser();
            break;
        case 5:
            recommendBooks(); // Book recommendations
            break;
        case 6:
            cout << "Logging out...\n";
            break;
        case 7:
            sendReturnReminders();
            break;
        case 8:
            displayPopularBooks();
            break;
        case 9:
          
            cout << "Enter username to reset password: ";
            cin >> username;
            resetPassword(username);
            break;


        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (true);
}

//--- Display Menus ---
void displayMemberMenu() {
    cout << "\n--- Member Menu ---\n";
    cout << "1. List Books\n";
    cout << "2. Search Books (Advanced)\n";
    cout << "3. Issue Book\n";
    cout << "4. Return Book\n";
    cout << "5. Reserve Book\n";
    cout << "6. Calculate Fine\n";
    cout << "7. Get Recommendations\n";
    cout << "8. Logout\n";
}

void displayAdminMenu() {
    cout << "\n--- Admin Menu ---\n";
    cout << "1. Add Book\n";
    cout << "2. List Books\n";
    cout << "3. Set Fine Rates\n";
    cout << "4. Deactivate User\n";
    cout << "5. Get Recommendations\n";
    cout << "6. Logout\n";
}


void exportBorrowingHistory(const string& username) {
    ofstream outFile(username + "_history.txt");
    if (!outFile) {
        cout << "Error creating history file.\n";
        return;
    }

    outFile << "Borrowing History for " << username << ":\n";
    for (const auto& book : library) {
        if (book->issuedTo == username) {
            outFile << "Book ID: " << book->id
                << ", Title: " << book->title
                << ", Borrowed On: " << formatDate(book->dueDate - 7 * 24 * 3600)
                << "\n";
        }
    }

    outFile.close();
    cout << "Borrowing history exported successfully to " << username << "_history.txt\n";
}
void sendReturnReminders() {
    cout << "\n--- Return Reminders ---\n";
    time_t now = time(nullptr);
    bool sent = false;

    for (const auto& book : library) {
        if (book->isIssued && (book->dueDate - now <= 2 * 24 * 3600)) {
            cout << "Reminder: Book '" << book->title << "' is due on "
                << formatDate(book->dueDate) << ". Notify user: " << book->issuedTo << "\n";
            sent = true;
        }
    }

    if (!sent) {
        cout << "No reminders to send.\n";
    }
}

void displayPopularBooks() {
    cout << "\n--- Most Popular Books ---\n";

    // Step 1: Map to store the count of issues and reservations for each book ID
    map<int, int> bookIssueCount;

    for (const auto& book : library) {
        bookIssueCount[book->id] += (book->isIssued ? 1 : 0) + book->reservations.size();
    }

    // Step 2: Create a vector from the map for sorting
    vector<pair<int, int>> sortedBooks(bookIssueCount.begin(), bookIssueCount.end());

    // Step 3: Sort the books in descending order of issues/reservations count
    sort(sortedBooks.begin(), sortedBooks.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second; // Descending order
        });

    // Step 4: Display the sorted books
    for (size_t i = 0; i < sortedBooks.size(); ++i) {
        int bookID = sortedBooks[i].first;
        int count = sortedBooks[i].second;

        for (const auto& book : library) {
            if (book->id == bookID) {
                cout << "Book ID: " << book->id
                    << ", Title: " << book->title
                    << ", Issues/Reservations: " << count << "\n";
                break; // Exit the loop once the book is found
            }
        }
    }
}







void searchByYear(int year) {
    cout << "\n--- Books Published in " << year << " ---\n";
    bool found = false;

    for (const auto& book : library) {
        if (book->category.find(to_string(year)) != string::npos) {
            cout << "ID: " << book->id
                << ", Title: " << book->title
                << ", Author: " << book->author
                << ", Category: " << book->category
                << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No books found for the given year.\n";
    }
}


void resetPassword(const string& username) {
    for (auto& user : users) {
        if (user.username == username) {
            string newPassword;
            cout << "Enter new password for user " << username << ": ";
            cin >> newPassword;
            user.password = newPassword;
            cout << "Password updated successfully.\n";
            return;
        }
    }
    cout << "User not found.\n";
}





