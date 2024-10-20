#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip> // For formatting dates

using namespace std;

// User model
struct User {
    string username;
    string password; // In a real application, use hashed passwords

    User(const string& uname, const string& pwd) : username(uname), password(pwd) {}
};

// Task model
struct Task {
    int id;
    string description;
    bool completed;
    string dueDate; // Format: YYYY-MM-DD
    string category;
    int priority; // 1 (high) to 5 (low)

    Task(int id, const string& desc, const string& due, const string& cat, int pri)
        : id(id), description(desc), completed(false), dueDate(due), category(cat), priority(pri) {}
};

// Manager: Manages the core business logic of handling tasks
class TaskManager {
private:
    vector<Task> tasks;
    int taskIdCounter;

public:
    TaskManager() : taskIdCounter(0) {}

    // Add a new task
    void addTask(const string& description, const string& dueDate, const string& category, int priority) {
        tasks.emplace_back(++taskIdCounter, description, dueDate, category, priority);
        cout << "Task added: " << description << endl;
    }

    // Mark a task as completed
    void completeTask(int id) {
        for (auto& task : tasks) {
            if (task.id == id) {
                task.completed = true;
                cout << "Task " << id << " marked as completed." << endl;
                return;
            }
        }
        cout << "Task not found." << endl;
    }

    // Remove a task
    void removeTask(int id) {
        for (auto it = tasks.begin(); it != tasks.end(); ++it) {
            if (it->id == id) {
                cout << "Task removed: " << it->description << endl;
                tasks.erase(it);
                return;
            }
        }
        cout << "Task not found." << endl;
    }

    // List all tasks
    void listTasks() {
        if (tasks.empty()) {
            cout << "No tasks available." << endl;
            return;
        }

        for (const auto& task : tasks) {
            cout << "ID: " << task.id
                << " | Description: " << task.description
                << " | Completed: " << (task.completed ? "Yes" : "No")
                << " | Due Date: " << task.dueDate
                << " | Category: " << task.category
                << " | Priority: " << task.priority << endl;
        }
    }
};

// Controller: Handles user input and interacts with the TaskManager
class TaskController {
private:
    TaskManager& manager;
    User currentUser;

public:
    TaskController(TaskManager& mgr, const User& user) : manager(mgr), currentUser(user) {}

    void showMenu() {
        cout << "\n=== To-Do List Menu for " << currentUser.username << " ===" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Complete Task" << endl;
        cout << "3. Remove Task" << endl;
        cout << "4. List Tasks" << endl;
        cout << "5. Exit" << endl;
        cout << "Select an option: ";
    }

    void handleInput() {
        int choice;
        do {
            showMenu();
            cin >> choice;
            cin.ignore(); // Ignore newline left in the buffer

            switch (choice) {
            case 1: {
                string description, dueDate, category;
                int priority;
                cout << "Enter task description: ";
                getline(cin, description);
                cout << "Enter due date (YYYY-MM-DD): ";
                getline(cin, dueDate);
                cout << "Enter task category: ";
                getline(cin, category);
                cout << "Enter task priority (1-5, 1 being highest): ";
                cin >> priority;
                manager.addTask(description, dueDate, category, priority);
                break;
            }
            case 2: {
                int id;
                cout << "Enter task ID to complete: ";
                cin >> id;
                manager.completeTask(id);
                break;
            }
            case 3: {
                int id;
                cout << "Enter task ID to remove: ";
                cin >> id;
                manager.removeTask(id);
                break;
            }
            case 4:
                manager.listTasks();
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid option, try again." << endl;
                break;
            }
        } while (choice != 5);
    }
};

// User Management for Login
class UserManager {
private:
    vector<User> users;

public:
    void registerUser(const string& username, const string& password) {
        users.emplace_back(username, password);
        cout << "User registered: " << username << endl;
    }

    User* login(const string& username, const string& password) {
        for (auto& user : users) {
            if (user.username == username && user.password == password) {
                cout << "Login successful for: " << username << endl;
                return &user;
            }
        }
        cout << "Login failed." << endl;
        return nullptr;
    }
};

// Main function
int main() {
    UserManager userManager;
    TaskManager taskManager;

    // Sample user registration
    userManager.registerUser("alice", "password123");
    userManager.registerUser("bob", "password456");

    // User login
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    User* user = userManager.login(username, password);
    if (user) {
        TaskController controller(taskManager, *user);
        controller.handleInput();
    }

    return 0;
}
