//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//
//// Base User Class
//class User {
//protected:
//    int userId;
//    std::string name;
//public:
//    User(int id, const std::string& name) : userId(id), name(name) {}
//    virtual void assignTask(int taskId) = 0;
//    virtual ~User() = default;
//    int getUserId() const { return userId; }
//    std::string getName() const { return name; }
//};
//
//class AdminUser : public User {
//public:
//    AdminUser(int id, const std::string& name) : User(id, name) {}
//    void assignTask(int taskId) override {
//        // Admin-specific task assignment
//    }
//    void createProject() { /* Admin-specific method */ }
//};
//
//class EditorUser : public User {
//public:
//    EditorUser(int id, const std::string& name) : User(id, name) {}
//    void assignTask(int taskId) override {
//        // Editor-specific task assignment
//    }
//    void editTask(int taskId) { /* Editor-specific method */ }
//};
//
//class ViewerUser : public User {
//public:
//    ViewerUser(int id, const std::string& name) : User(id, name) {}
//    void assignTask(int taskId) override {
//        std::cout << "Viewers cannot assign tasks.\n";
//    }
//};
//
//// Task and Dependency Classes
//class Task {
//protected:
//    int taskId;
//    std::string title;
//    std::string description;
//    int priority;
//    std::string status;
//public:
//    Task(int id, const std::string& title, const std::string& desc, int priority)
//        : taskId(id), title(title), description(desc), priority(priority), status("ToDo") {}
//
//    virtual void addSubtask(Task* subtask) = 0;
//    virtual void setDependency(Task* dependency) = 0;
//    virtual ~Task() = default;
//};
//
//class ConcreteTask : public Task {
//public:
//    ConcreteTask(int id, const std::string& title, const std::string& desc, int priority)
//        : Task(id, title, desc, priority) {}
//
//    void addSubtask(Task* subtask) override {
//        std::cout << "Adding subtask to ConcreteTask\n";
//        // Implementation for adding subtask
//    }
//
//    void setDependency(Task* dependency) override {
//        std::cout << "Setting dependency in ConcreteTask\n";
//        // Implementation for setting dependency
//    }
//};
//
//class SubTask : public Task {
//private:
//    Task* parentTask;
//public:
//    SubTask(int id, const std::string& title, const std::string& desc, int priority, Task* parent)
//        : Task(id, title, desc, priority), parentTask(parent) {}
//
//    void addSubtask(Task* subtask) override {
//        std::cout << "Subtask cannot have its own subtasks.\n";
//    }
//    void setDependency(Task* dependency) override {
//        // Dependency management
//    }
//};
//
//class Dependency {
//private:
//    Task* dependentTask;
//    Task* requiredTask;
//public:
//    Dependency(Task* dependent, Task* required) : dependentTask(dependent), requiredTask(required) {}
//};
//
//// Project, Category, and Tag Classes
//class Category {
//    int categoryId;
//    std::string categoryName;
//public:
//    Category(int id, const std::string& name) : categoryId(id), categoryName(name) {}
//};
//
//class Tag {
//    int tagId;
//    std::string tagName;
//public:
//    Tag(int id, const std::string& name) : tagId(id), tagName(name) {}
//};
//
//class Project {
//    int projectId;
//    std::string projectName;
//    std::vector<Task*> tasks;
//    std::vector<Category> categories;
//    std::vector<Tag> tags;
//public:
//    Project(int id, const std::string& name) : projectId(id), projectName(name) {}
//
//    void addTask(Task* task) { tasks.push_back(task); }
//    void addCategory(const Category& category) { categories.push_back(category); }
//    void addTag(const Tag& tag) { tags.push_back(tag); }
//};
//
//// Team Class
//class Team {
//    int teamId;
//    std::string teamName;
//    std::vector<User*> members;
//public:
//    Team(int id, const std::string& name) : teamId(id), teamName(name) {}
//
//    void addMember(User* user) { members.push_back(user); }
//    void removeMember(User* user) {
//        members.erase(std::remove(members.begin(), members.end(), user), members.end());
//    }
//};
//
//// Notification and Reminder Interfaces
//class INotificationService {
//public:
//    virtual void sendNotification(const User& user, const std::string& message) = 0;
//    virtual ~INotificationService() = default;
//};
//
//class EmailNotification : public INotificationService {
//public:
//    void sendNotification(const User& user, const std::string& message) override {
//        std::cout << "Email sent to " << user.getName() << ": " << message << std::endl;
//    }
//};
//
//class Reminder {
//    int reminderId;
//    Task* task;
//    int reminderTime;
//public:
//    Reminder(int id, Task* task, int time) : reminderId(id), task(task), reminderTime(time) {}
//
//    void scheduleReminder() {
//        // Schedule reminder logic
//    }
//};
//
//// Comment and Attachment Classes
//class Comment {
//    int commentId;
//    User* user;
//    std::string text;
//public:
//    Comment(int id, User* user, const std::string& text) : commentId(id), user(user), text(text) {}
//};
//
//class Attachment {
//    int attachmentId;
//    std::string filename;
//    std::string filePath;
//public:
//    Attachment(int id, const std::string& name, const std::string& path)
//        : attachmentId(id), filename(name), filePath(path) {}
//};
//
//// Report Class
//class Report {
//    std::vector<Task*> tasks;
//public:
//    void generateProgressReport() {
//        // Generate and display a progress report based on task status
//    }
//
//    void generateUserActivityReport(const User& user) {
//        // Generate report based on user's activity
//    }
//};
//
//int main() {
//    // Example usage
//    AdminUser admin(1, "Admin One");
//    EditorUser editor(2, "Editor One");
//    ViewerUser viewer(3, "Viewer One");
//
//    EmailNotification emailNotifier;
//    emailNotifier.sendNotification(admin, "You have a new task assigned!");
//
//    Project project(1, "Project Alpha");
//    Category category(1, "Development");
//    Tag tag(1, "Urgent");
//
//    project.addCategory(category);
//    project.addTag(tag);
//
//    Task* mainTask = new ConcreteTask(1, "Main Task", "Complete the main task", 5);
//    Task* subTask = new SubTask(2, "Sub Task", "A subtask under main task", 3, mainTask);
//
//    project.addTask(mainTask);
//
//    delete mainTask;
//    delete subTask;
//
//    return 0;
//}







#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// User Class and Derived Roles
class User {
protected:
    int userId;
    std::string name;
public:
    User(int id, const std::string& name) : userId(id), name(name) {}
    virtual void assignTask(int taskId) = 0;
    virtual ~User() = default;
    int getUserId() const { return userId; }
    std::string getName() const { return name; }
};

class AdminUser : public User {
public:
    AdminUser(int id, const std::string& name) : User(id, name) {}
    void assignTask(int taskId) override {
        // Admin-specific task assignment
    }
    void createProject() { /* Admin-specific method */ }
};

class EditorUser : public User {
public:
    EditorUser(int id, const std::string& name) : User(id, name) {}
    void assignTask(int taskId) override {
        // Editor-specific task assignment
    }
    void editTask(int taskId) { /* Editor-specific method */ }
};

class ViewerUser : public User {
public:
    ViewerUser(int id, const std::string& name) : User(id, name) {}
    void assignTask(int taskId) override {
        std::cout << "Viewers cannot assign tasks.\n";
    }
};

// CQRS for Task Read and Write Operations
class Task {
protected:
    int taskId;
    std::string title;
    std::string description;
    int priority;
    std::string status;
public:
    Task(int id, const std::string& title, const std::string& desc, int priority)
        : taskId(id), title(title), description(desc), priority(priority), status("ToDo") {}

    int getId() const { return taskId; }
    std::string getTitle() const { return title; }
    std::string getStatus() const { return status; }
    virtual ~Task() = default;
};

// Read Interface for Task
class ITaskReadService {
public:
    virtual Task getTaskById(int taskId) const = 0;
    virtual std::vector<Task> getTasksByStatus(const std::string& status) const = 0;
    virtual ~ITaskReadService() = default;
};

// Write Interface for Task
class ITaskWriteService {
public:
    virtual void createTask(const Task& task) = 0;
    virtual void updateTaskStatus(int taskId, const std::string& status) = 0;
    virtual void deleteTask(int taskId) = 0;
    virtual ~ITaskWriteService() = default;
};

// Implementation of Task Read and Write Services
class TaskReadService : public ITaskReadService {
public:
    Task getTaskById(int taskId) const override {
        // Fetch task by ID
        std::cout << "Fetching Task ID: " << taskId << "\n";
        return Task(taskId, "Sample Task", "Description of task", 3);
    }

    std::vector<Task> getTasksByStatus(const std::string& status) const override {
        // Fetch tasks by status
        std::cout << "Fetching Tasks with Status: " << status << "\n";
        return { Task(1, "Task 1", "Description 1", 2), Task(2, "Task 2", "Description 2", 1) };
    }
};

class TaskWriteService : public ITaskWriteService {
public:
    void createTask(const Task& task) override {
        std::cout << "Creating Task: " << task.getTitle() << "\n";
    }

    void updateTaskStatus(int taskId, const std::string& status) override {
        std::cout << "Updating Task ID " << taskId << " to Status: " << status << "\n";
    }

    void deleteTask(int taskId) override {
        std::cout << "Deleting Task ID: " << taskId << "\n";
    }
};

// Project Read and Write Services
class Project {
    int projectId;
    std::string projectName;
public:
    Project(int id, const std::string& name) : projectId(id), projectName(name) {}
    int getId() const { return projectId; }
    std::string getName() const { return projectName; }
};

// Project Read and Write Interfaces
class IProjectReadService {
public:
    virtual Project getProjectById(int projectId) const = 0;
    virtual std::vector<Project> getAllProjects() const = 0;
    virtual ~IProjectReadService() = default;
};

class IProjectWriteService {
public:
    virtual void createProject(const Project& project) = 0;
    virtual void updateProjectName(int projectId, const std::string& name) = 0;
    virtual void deleteProject(int projectId) = 0;
    virtual ~IProjectWriteService() = default;
};

// Implementation of Project Read and Write Services
class ProjectReadService : public IProjectReadService {
public:
    Project getProjectById(int projectId) const override {
        std::cout << "Fetching Project ID: " << projectId << "\n";
        return Project(projectId, "Project Alpha");
    }

    std::vector<Project> getAllProjects() const override {
        std::cout << "Fetching All Projects\n";
        return { Project(1, "Project Alpha"), Project(2, "Project Beta") };
    }
};

class ProjectWriteService : public IProjectWriteService {
public:
    void createProject(const Project& project) override {
        std::cout << "Creating Project: " << project.getName() << "\n";
    }

    void updateProjectName(int projectId, const std::string& name) override {
        std::cout << "Updating Project ID " << projectId << " to Name: " << name << "\n";
    }

    void deleteProject(int projectId) override {
        std::cout << "Deleting Project ID: " << projectId << "\n";
    }
};

// Category Read and Write Services
class Category {
    int categoryId;
    std::string categoryName;
public:
    Category(int id, const std::string& name) : categoryId(id), categoryName(name) {}
};

// Read and Write Interfaces for Category
class ICategoryReadService {
public:
    virtual Category getCategoryById(int categoryId) const = 0;
    virtual ~ICategoryReadService() = default;
};

class ICategoryWriteService {
public:
    virtual void createCategory(const Category& category) = 0;
    virtual void deleteCategory(int categoryId) = 0;
    virtual ~ICategoryWriteService() = default;
};

// Implementations for Category Read and Write Services
class CategoryReadService : public ICategoryReadService {
public:
    Category getCategoryById(int categoryId) const override {
        std::cout << "Fetching Category ID: " << categoryId << "\n";
        return Category(categoryId, "Development");
    }
};

class CategoryWriteService : public ICategoryWriteService {
public:
    void createCategory(const Category& category) override {
        std::cout << "Creating Category: " << category.categoryName << "\n";
    }

    void deleteCategory(int categoryId) override {
        std::cout << "Deleting Category ID: " << categoryId << "\n";
    }
};

// Additional implementations for Tag, Notification, Reminder, and Report can follow the same pattern.

int main() {
    // Using CQRS Pattern to handle read and write operations separately
    TaskReadService taskReader;
    TaskWriteService taskWriter;

    ProjectReadService projectReader;
    ProjectWriteService projectWriter;

    taskWriter.createTask(Task(1, "New Task", "Details", 1));
    taskReader.getTaskById(1);

    projectWriter.createProject(Project(1, "New Project"));
    projectReader.getProjectById(1);

    return 0;
}
