//#include <iostream>
//using namespace std;
//
//struct Arithmetic {
//    static int add(int a, int b) { return a + b; }
//    static int subtract(int a, int b) { return a - b; }
//    static int multiply(int a, int b) { return a * b; }
//    static int divide(int a, int b) { return (b != 0) ? a / b : 0; } // Handles divide by zero case
//    static int modulus(int a, int b) { return (b != 0) ? a % b : 0; } // Handles modulus by zero case
//};
//
//struct Relational {
//    static bool equalTo(int a, int b) { return a == b; }
//    static bool notEqualTo(int a, int b) { return a != b; }
//    static bool greaterThan(int a, int b) { return a > b; }
//    static bool lessThan(int a, int b) { return a < b; }
//    static bool greaterThanOrEqualTo(int a, int b) { return a >= b; }
//    static bool lessThanOrEqualTo(int a, int b) { return a <= b; }
//};
//
//struct Logical {
//    static bool logicalAnd(bool x, bool y) { return x && y; }
//    static bool logicalOr(bool x, bool y) { return x || y; }
//    static bool logicalNot(bool x) { return !x; }
//};
//
//struct Bitwise {
//    static int bitwiseAnd(int a, int b) { return a & b; }
//    static int bitwiseOr(int a, int b) { return a | b; }
//    static int bitwiseXor(int a, int b) { return a ^ b; }
//    static int leftShift(int a) { return a << 1; }
//    static int rightShift(int a) { return a >> 1; }
//};
//
//struct Helpers {
//    bool IsPositive(int number) {
//        return Relational::greaterThan(number, 0);
//    }
//};
//
//
//
//
//
//
//
//
//
//
//int main() {
//    int a = 10, b = 3;
//
//    // Arithmetic operations
//    cout << "Addition: " << Arithmetic::add(a, b) << endl;
//    cout << "Subtraction: " << Arithmetic::subtract(a, b) << endl;
//    cout << "Multiplication: " << Arithmetic::multiply(a, b) << endl;
//    cout << "Division: " << Arithmetic::divide(a, b) << endl;
//    cout << "Modulus: " << Arithmetic::modulus(a, b) << endl;
//
//    // Relational operations
//    cout << "Equal to: " << Relational::equalTo(a, b) << endl;
//    cout << "Not equal to: " << Relational::notEqualTo(a, b) << endl;
//    cout << "Greater than: " << Relational::greaterThan(a, b) << endl;
//    cout << "Less than: " << Relational::lessThan(a, b) << endl;
//    cout << "Greater than or equal to: " << Relational::greaterThanOrEqualTo(a, b) << endl;
//    cout << "Less than or equal to: " << Relational::lessThanOrEqualTo(a, b) << endl;
//
//    // Logical operations
//    cout << "AND: " << Logical::logicalAnd(true, false) << endl;
//    cout << "OR: " << Logical::logicalOr(true, false) << endl;
//    cout << "NOT: " << Logical::logicalNot(true) << endl;
//
//    // Bitwise operations
//    cout << "Bitwise AND: " << Bitwise::bitwiseAnd(a, b) << endl;
//    cout << "Bitwise OR: " << Bitwise::bitwiseOr(a, b) << endl;
//    cout << "Bitwise XOR: " << Bitwise::bitwiseXor(a, b) << endl;
//    cout << "Left Shift: " << Bitwise::leftShift(a) << endl;
//    cout << "Right Shift: " << Bitwise::rightShift(a) << endl;
//
//    return 0;
//}

#include <iostream>

int main() {
    int c;
    int charCount = 0;

    while ((c = std::cin.get()) != EOF) {
        charCount++;
    }

    std::cout << charCount << std::endl;
    return 0;
}