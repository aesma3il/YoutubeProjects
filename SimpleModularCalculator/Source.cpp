#include <iostream>
#include <stdexcept> // For std::runtime_error
#include <limits>    // For std::numeric_limits
using namespace std;

// Enum for available operations
enum Operation { ADD, SUBTRACT, MULTIPLY, DIVIDE, MODULUS, INVALID };

// Enum for error types
enum ErrorType {
    NO_ERROR,
    DIVIDE_BY_ZERO,
    INVALID_OPERATION,
    INVALID_INPUT
};

// Struct to hold the numbers and the operation
struct Calculator {
    double num1;
    double num2;
    Operation operation;
};

// Math functions
double Add(double first, double second) {
    return first + second;
}
double Subtract(double first, double second) {
    return first - second;
}
double Multiply(double first, double second) {
    return first * second;
}
double Divide(double first, double second) {
    return first / second;
}
int Mod(int first, int second) {
    return first % second; // Correct modulus operation for integers
}

// Output functions
void Print(const string& title, double value) {
    cout << title << " : " << value << '\n';
}

// Input reading functions
double getNumberFromUser(const string& prompt) {
    double num;
    cout << prompt;
    while (!(cin >> num)) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        cout << "Invalid input. " << prompt; // Ask for input again
    }
    return num;
}

int ReadInteger(const string& prompt) {
    int number;
    cout << prompt;
    while (!(cin >> number)) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        cout << "Invalid input. " << prompt; // Ask for input again
    }
    return number;
}

// Struct to represent each operation in the menu
struct MenuOption {
    string name;
    char symbol;
};

// Array to store the operations
const MenuOption operations[] = {
    {"Addition", '+'},
    {"Subtraction", '-'},
    {"Multiplication", '*'},
    {"Division", '/'},
    {"Modulus", '%'}
};

// Function to display the menu using the array of structs
void displayMenu() {
    cout << "Select operation:\n";
    for (int i = 0; i < 5; ++i) {
        cout << i + 1 << ". " << operations[i].name << " (" << operations[i].symbol << ")\n";
    }
    cout << "Enter choice (1-5): ";
}

// Get operation type
Operation GetOperationType() {
    int choice = ReadInteger("");
    switch (choice) {
    case 1: return ADD;
    case 2: return SUBTRACT;
    case 3: return MULTIPLY;
    case 4: return DIVIDE;
    case 5: return MODULUS;
    default: return INVALID;
    }
}

// Validate the operation
bool isValidOperation(Operation operation) {
    return operation != INVALID;
}

// Perform calculation based on the operation
ErrorType performCalculation(double num1, double num2, Operation operation, double& result) {
    switch (operation) {
    case ADD:
        result = Add(num1, num2);
        return NO_ERROR;
    case SUBTRACT:
        result = Subtract(num1, num2);
        return NO_ERROR;
    case MULTIPLY:
        result = Multiply(num1, num2);
        return NO_ERROR;
    case DIVIDE:
        if (num2 == 0) return DIVIDE_BY_ZERO;
        result = Divide(num1, num2);
        return NO_ERROR;
    case MODULUS:
        if (num2 == 0) return DIVIDE_BY_ZERO; // Modulus by zero is also an error
        result = Mod(static_cast<int>(num1), static_cast<int>(num2));
        return NO_ERROR;
    default:
        return INVALID_OPERATION;
    }
}

// Display the result
void displayResult(double result) {
    cout << "Result: " << result << endl;
}

// Main calculator function
void runCalculator() {
    Calculator calc;
    double result;

    // Get the input numbers from the user
    calc.num1 = getNumberFromUser("Enter first number: ");
    calc.num2 = getNumberFromUser("Enter second number: ");

    // Display menu and get operation
    displayMenu();
    calc.operation = GetOperationType();

    // Validate the operation
    if (!isValidOperation(calc.operation)) {
        cout << "Error: Invalid operation chosen!\n";
        return; // Exit early
    }

    // Perform the calculation and check for errors
    ErrorType error = performCalculation(calc.num1, calc.num2, calc.operation, result);
    switch (error) {
    case NO_ERROR:
        displayResult(result);
        break;
    case DIVIDE_BY_ZERO:
        cout << "Error: Division by zero!\n";
        break;
    case INVALID_OPERATION:
        cout << "Error: Invalid operation selected!\n";
        break;
    case INVALID_INPUT:
        cout << "Error: Invalid input!\n";
        break;
    }
}

// Main function
int main() {
    runCalculator();
    return 0;
}




























//#include <iostream>
//#include <stdexcept> // For std::runtime_error
//using namespace std;
//
//// Enum for available operations
//enum Operation { ADD, SUBTRACT, MULTIPLY, DIVIDE, MODULUS, INVALID };
//
//// Enum for error types
//enum ErrorType {
//    NO_ERROR,
//    DIVIDE_BY_ZERO,
//    INVALID_OPERATION,
//    INVALID_INPUT
//};
//
//// Struct to hold the numbers and the operation
//struct Calculator {
//    double num1;
//    double num2;
//    Operation operation;
//};
//
//// Math functions
//double Add(double first, double second) {
//    return first + second;
//}
//double Subtract(double first, double second) {
//    return first - second;
//}
//double Multiply(double first, double second) {
//    return first * second;
//}
//double Divide(double first, double second) {
//    if (second == 0) throw std::runtime_error("Division by zero");
//    return first / second;
//}
//int Mod(int first, int second) {
//    return first % second; // Correct modulus operation for integers
//}
//
//// Output functions
//void Print(const string& title, double value) {
//    cout << title << " : " << value << '\n';
//}
//
//// Input reading functions
//double getNumberFromUser(const string& prompt) {
//    double num;
//    cout << prompt;
//    while (!(cin >> num)) {
//        cin.clear(); // Clear the error flag
//        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
//        cout << "Invalid input. " << prompt; // Ask for input again
//    }
//    return num;
//}
//
//int ReadInteger(const string& prompt) {
//    int number;
//    cout << prompt;
//    while (!(cin >> number)) {
//        cin.clear(); // Clear the error flag
//        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
//        cout << "Invalid input. " << prompt; // Ask for input again
//    }
//    return number;
//}
//
//// Struct to represent each operation in the menu
//struct MenuOption {
//    string name;
//    char symbol;
//};
//
//// Array to store the operations
//const MenuOption operations[] = {
//    {"Addition", '+'},
//    {"Subtraction", '-'},
//    {"Multiplication", '*'},
//    {"Division", '/'},
//    {"Modulus", '%'}
//};
//
//// Function to display the menu using the array of structs
//void displayMenu() {
//    cout << "Select operation:\n";
//    for (int i = 0; i < 5; ++i) {
//        cout << i + 1 << ". " << operations[i].name << " (" << operations[i].symbol << ")\n";
//    }
//    cout << "Enter choice (1-5): ";
//}
//
//// Get operation type
//Operation GetOperationType() {
//    int choice = ReadInteger("");
//    switch (choice) {
//    case 1: return ADD;
//    case 2: return SUBTRACT;
//    case 3: return MULTIPLY;
//    case 4: return DIVIDE;
//    case 5: return MODULUS;
//    default: return INVALID;
//    }
//}
//
//// Validate the operation
//bool isValidOperation(Operation operation) {
//    return operation != INVALID;
//}
//
////// Perform calculation based on the operation
////double performCalculation(double num1, double num2, Operation operation) {
////    switch (operation) {
////    case ADD: return Add(num1, num2);
////    case SUBTRACT: return Subtract(num1, num2);
////    case MULTIPLY: return Multiply(num1, num2);
////    case DIVIDE: return Divide(num1, num2); // Division already handles zero check
////    case MODULUS: return Mod((int)num1, (int)num2); // Cast to int for modulus
////    default: throw std::runtime_error("Invalid operation selected");
////    }
////}
//
//ErrorType performCalculation(double num1, double num2, Operation operation, double& result) {
//    switch (operation) {
//    case ADD:
//        result = Add(num1, num2);
//        return NO_ERROR;
//    case SUBTRACT:
//        result = Subtract(num1, num2);
//        return NO_ERROR;
//    case MULTIPLY:
//        result = Multiply(num1, num2);
//        return NO_ERROR;
//    case DIVIDE:
//        if (num2 == 0) return DIVIDE_BY_ZERO;
//        result = Divide(num1, num2);
//        return NO_ERROR;
//    case MODULUS:
//        if (num2 == 0) return DIVIDE_BY_ZERO; // Modulus by zero is also an error
//        result = Mod(static_cast<int>(num1), static_cast<int>(num2));
//        return NO_ERROR;
//    default:
//        return INVALID_OPERATION;
//    }
//}
//
//
//// Display the result
//void displayResult(double result) {
//    cout << "Result: " << result << endl;
//}
//
////// Main calculator function
////void runCalculator() {
////    Calculator calc;
////
////    try {
////        // Get the input numbers from the user
////        calc.num1 = getNumberFromUser("Enter first number: ");
////        calc.num2 = getNumberFromUser("Enter second number: ");
////
////        // Display menu and get operation
////        displayMenu();
////        calc.operation = GetOperationType();
////
////        // Validate the operation before performing calculation
////        if (!isValidOperation(calc.operation)) {
////            throw std::runtime_error("Error: Invalid operation chosen!");
////        }
////
////        // Perform the operation and display the result
////        double result = performCalculation(calc.num1, calc.num2, calc.operation);
////        displayResult(result);
////    }
////    catch (const std::runtime_error& e) {
////        cout << "Exception: " << e.what() << '\n';
////    }
////}
//
//void runCalculator() {
//    Calculator calc;
//    double result;
//
//    // Get the input numbers from the user
//    calc.num1 = getNumberFromUser("Enter first number: ");
//    calc.num2 = getNumberFromUser("Enter second number: ");
//
//    // Display menu and get operation
//    displayMenu();
//    calc.operation = GetOperationType();
//
//    // Validate the operation
//    if (!isValidOperation(calc.operation)) {
//        cout << "Error: Invalid operation chosen!\n";
//        return; // Exit early
//    }
//
//    // Perform the calculation and check for errors
//    ErrorType error = performCalculation(calc.num1, calc.num2, calc.operation, result);
//    switch (error) {
//    case NO_ERROR:
//        displayResult(result);
//        break;
//    case DIVIDE_BY_ZERO:
//        cout << "Error: Division by zero!\n";
//        break;
//    case INVALID_OPERATION:
//        cout << "Error: Invalid operation selected!\n";
//        break;
//    case INVALID_INPUT:
//        cout << "Error: Invalid input!\n";
//        break;
//    }
//}
//
//
//
//
//
//// Main function
//int main() {
//    runCalculator();
//    return 0;
//}
