#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <regex>

using namespace std;

// User roles
enum Role {
    DOCTOR,
    STUDENT,
    TA
};

// Base class for Users
class User {
public:
    string username;
    string password;
    string fullName;
    string email;
    Role role;

    User(string user, string pass, string name, string mail, Role r)
        : username(user), password(pass), fullName(name), email(mail), role(r) {}
};

// Course model
class Course {
public:
    string courseName;
    string courseCode;
    vector<User*> enrolledStudents;

    Course(string name, string code) : courseName(name), courseCode(code) {}
};

// Assignment model
class Assignment {
public:
    string title;
    string description;
    string dueDate;
    int maxGrade;
    vector<int> grades;

    Assignment(string t, string desc, string due, int max)
        : title(t), description(desc), dueDate(due), maxGrade(max) {}
};

// Manager: Handles course management and assignment management
class CourseManager {
private:
    vector<Course> courses;

public:
    void createCourse(const string& name, const string& code) {
        courses.emplace_back(name, code);
        cout << "Course created: " << name << " (" << code << ")" << endl;
    }

    void listCourses() {
        cout << "Available Courses:\n";
        for (const auto& course : courses) {
            cout << " - " << course.courseName << " (" << course.courseCode << ")\n";
        }
    }

    Course* findCourse(const string& code) {
        for (auto& course : courses) {
            if (course.courseCode == code) {
                return &course;
            }
        }
        return nullptr;
    }
};

// Manager: Handles user management
class UserManager {
private:
    vector<User> users;

public:
    void registerUser(const string& user, const string& pass, const string& name, const string& mail, Role role) {
        users.emplace_back(user, pass, name, mail, role);
        cout << "User registered: " << name << endl;
    }

    User* signIn(const string& user, const string& pass) {
        for (auto& u : users) {
            if (u.username == user && u.password == pass) {
                return &u;
            }
        }
        return nullptr;
    }

    bool isEmailValid(const string& email) {
        const regex pattern(R"(^\w+@[a-zA-Z_]+?\.[a-zA-Z]{2,3}$)");
        return regex_match(email, pattern);
    }
};

// Controller: Handles user interactions
class UserController {
private:
    UserManager& userManager;
    CourseManager& courseManager;

public:
    UserController(UserManager& um, CourseManager& cm) : userManager(um), courseManager(cm) {}

    void mainMenu() {
        int choice;
        do {
            cout << "\n=== LMS Main Menu ===\n";
            cout << "1. Register User\n";
            cout << "2. Sign In\n";
            cout << "3. Exit\n";
            cout << "Select an option: ";
            cin >> choice;

            switch (choice) {
            case 1: {
                string username, password, fullName, email;
                Role role;

                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                cout << "Enter full name: ";
                cin.ignore();
                getline(cin, fullName);
                cout << "Enter email: ";
                cin >> email;

                // Validate email
                if (!userManager.isEmailValid(email)) {
                    cout << "Invalid email format.\n";
                    break;
                }

                cout << "Select role (0 for Doctor, 1 for Student, 2 for TA): ";
                int roleChoice;
                cin >> roleChoice;
                role = static_cast<Role>(roleChoice);

                userManager.registerUser(username, password, fullName, email, role);
                break;
            }
            case 2: {
                string username, password;
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;

                User* user = userManager.signIn(username, password);
                if (user) {
                    cout << "Welcome, " << user->fullName << "!\n";
                    if (user->role == DOCTOR) {
                        doctorMenu(user);
                    }
                    else if (user->role == STUDENT) {
                        studentMenu(user);
                    }
                    else {
                        cout << "TA functionality not implemented yet.\n";
                    }
                }
                else {
                    cout << "Invalid credentials.\n";
                }
                break;
            }
            case 3:
                cout << "Exiting LMS.\n";
                break;
            default:
                cout << "Invalid option, try again.\n";
                break;
            }
        } while (choice != 3);
    }

    void doctorMenu(User* doctor) {
        int choice;
        do {
            cout << "\n=== Doctor Menu ===\n";
            cout << "1. Create Course\n";
            cout << "2. List Courses\n";
            cout << "3. Log Out\n";
            cout << "Select an option: ";
            cin >> choice;

            switch (choice) {
            case 1: {
                string name, code;
                cout << "Enter course name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter course code: ";
                getline(cin, code);
                courseManager.createCourse(name, code);
                break;
            }
            case 2:
                courseManager.listCourses();
                break;
            case 3:
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid option, try again.\n";
                break;
            }
        } while (choice != 3);
    }

    void studentMenu(User* student) {
        int choice;
        do {
            cout << "\n=== Student Menu ===\n";
            cout << "1. List Available Courses\n";
            cout << "2. Log Out\n";
            cout << "Select an option: ";
            cin >> choice;

            switch (choice) {
            case 1:
                courseManager.listCourses();
                break;
            case 2:
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid option, try again.\n";
                break;
            }
        } while (choice != 2);
    }
};

// Main function
int main() {
    UserManager userManager;
    CourseManager courseManager;
    UserController userController(userManager, courseManager);

    // Adding dummy data
    userManager.registerUser("doc1", "password", "Dr. John Doe", "john@example.com", DOCTOR);
    userManager.registerUser("student1", "password", "Jane Smith", "jane@example.com", STUDENT);
    courseManager.createCourse("C++ Programming", "CS101");
    courseManager.createCourse("Data Structures", "CS102");

    // Start the application
    userController.mainMenu();

    return 0;
}
