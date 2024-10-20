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
    vector<pair<string, int>> grades; // <student username, grade>

    Assignment(string t, string desc, string due, int max)
        : title(t), description(desc), dueDate(due), maxGrade(max) {}

    void addGrade(const string& studentUsername, int grade) {
        grades.push_back(make_pair(studentUsername, grade));
    }

    void displayGrades() {
        cout << "Grades for Assignment: " << title << endl;
        for (const auto& grade : grades) {
            cout << "Student: " << grade.first << ", Grade: " << grade.second << endl;
        }
    }
};

// Assignment Solution model
class AssignmentSolution {
public:
    string studentUsername;
    string solution;
    string submissionDate;
    int grade;
    string feedback;

    AssignmentSolution(string student, string sol, string date)
        : studentUsername(student), solution(sol), submissionDate(date), grade(0), feedback("") {}
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

    void enrollStudent(const string& courseCode, User* student) {
        Course* course = findCourse(courseCode);
        if (course) {
            course->enrolledStudents.push_back(student);
            cout << student->fullName << " has been enrolled in " << course->courseName << endl;
        }
        else {
            cout << "Course not found.\n";
        }
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

    vector<User>& getUsers() {
        return users;
    }
};

// Manager: Handles assignment management
class AssignmentManager {
private:
    vector<Assignment> assignments;

public:
    void createAssignment(const string& title, const string& description, const string& dueDate, int maxGrade) {
        assignments.emplace_back(title, description, dueDate, maxGrade);
        cout << "Assignment created: " << title << endl;
    }

    void listAssignments() {
        cout << "Assignments:\n";
        for (const auto& assignment : assignments) {
            cout << " - " << assignment.title << " (Due: " << assignment.dueDate << ")\n";
        }
    }

    Assignment* findAssignment(const string& title) {
        for (auto& assignment : assignments) {
            if (assignment.title == title) {
                return &assignment;
            }
        }
        return nullptr;
    }
};

// Controller: Handles user interactions
class UserController {
private:
    UserManager& userManager;
    CourseManager& courseManager;
    AssignmentManager& assignmentManager;

public:
    UserController(UserManager& um, CourseManager& cm, AssignmentManager& am)
        : userManager(um), courseManager(cm), assignmentManager(am) {}

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
            cout << "3. Create Assignment\n";
            cout << "4. List Assignments\n";
            cout << "5. Log Out\n";
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
            case 3: {
                string title, description, dueDate;
                int maxGrade;
                cout << "Enter assignment title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter assignment description: ";
                getline(cin, description);
                cout << "Enter due date: ";
                getline(cin, dueDate);
                cout << "Enter maximum grade: ";
                cin >> maxGrade;
                assignmentManager.createAssignment(title, description, dueDate, maxGrade);
                break;
            }
            case 4:
                assignmentManager.listAssignments();
                break;
            case 5:
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid option, try again.\n";
                break;
            }
        } while (choice != 5);
    }

    void studentMenu(User* student) {
        int choice;
        do {
            cout << "\n=== Student Menu ===\n";
            cout << "1. List Available Courses\n";
            cout << "2. Submit Assignment Solution\n";
            cout << "3. Log Out\n";
            cout << "Select an option: ";
            cin >> choice;

            switch (choice) {
            case 1:
                courseManager.listCourses();
                break;
            case 2: {
                string assignmentTitle, solution;
                cout << "Enter assignment title: ";
                cin.ignore();
                getline(cin, assignmentTitle);
                cout << "Enter your solution: ";
                getline(cin, solution);
                // Assume submission date is the current date for simplicity
                AssignmentSolution submission(student->username, solution, "2024-10-21");
                cout << "Submitted solution for " << assignmentTitle << endl;
                break;
            }
            case 3:
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid option, try again.\n";
                break;
            }
        } while (choice != 3);
    }
};

int main() {
    UserManager userManager;
    CourseManager courseManager;
    AssignmentManager assignmentManager;
    UserController userController(userManager, courseManager, assignmentManager);

    userController.mainMenu();

    return 0;
}
