#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;



enum enPositiveOrNegativeOrZero {
    Zero,
    Positive,
    Negative
};

enum enOddEven {
    None,
    Odd,
    Even
};

enum enPrimality {
    Prime,
    NotPrime
};


// Output function helpers

void Print(const string& prompt = "", const string& value) {
    cout << prompt << " " << value;
}

void Print(const string& prompt = "", int value) {
    cout << prompt << " " << value;
}

void Print(const string& prompt = "", short value) {
    cout << prompt << " " << value;
}
void Print(const string& prompt = "", long value) {
    cout << prompt << " " << value;
}
void Print(const string& prompt = "", float value) {
    cout << prompt << " " << value;
}

void Print(const string& prompt = "", double value) {
    cout << prompt << " " << value;
}
void Print(const string& prompt = "", char value) {
    cout << prompt << " " << value;
}
void Print(const string& prompt = "", bool value) {
    cout << prompt << " " << (value) ? "Yes" : "No";
}

void Print(const string& prompt) {
    cout << prompt << endl;
}
//----------------------------------------------



//------------------Read Functions

short ReadShortNumber(const string& prompt) {
    Print(prompt);
    short number;
    cin >> number;
    return (short)number;
}

int ReadIntegerNumber(const string& prompt) {
    Print(prompt);
    int number;
    cin >> number;
    return  number;
}
long ReadLongNumber(const string& prompt) {
    Print(prompt);
    long number;
    cin >> number;
    return (long)number;
}
float ReadFloatNumber(const string& prompt) {
    Print(prompt);
    float number;
    cin >> number;
    return (float)number;
}
double ReadDoubleNumber(const string& prompt) {
    Print(prompt);
    double number;
    cin >> number;
    return (double)number;
}


char ReadChar(const string& prompt) {
    Print(prompt);
    char value;
    cin >> value;
    return value;
}

bool ReadBoolean(const string& prompt) {
    Print(prompt);
    bool value;
    cin >> value;
    return value;
}

string ReadString(const string& prompt) {
    Print(prompt);
    string txt;
    getline(cin, txt);
    return txt;
}


//----------------Arithematic operations

int Add(int first, int second) {
    return first + second;
}

int Subtract(int first, int second) {
    return first - second;
}
int Multiply(int first, int second) {
    return first * second;
}

int Multiply(int first, int second, int third) {
    return first * second * third;
}

int Divide(int first, int second) {
    if (second == 0) return 0;
    else
        return first / second;
}
int Mod(int first, int second) {
    return first % second;
}

//-----------------------Logical Operations

bool And(bool first, bool second) {
    return first && second;
}
bool OR(bool first, bool second) {
    return first || second;
}

bool Not(bool value) {
    return !value;
}

//--------------------------comparison operations


bool IsEqual(int first, int second) {
    return first == second;
}

bool IsNotEqual(int first, int second) {
    return first != second;
}
bool IsGreater(int first, int second) {
    return first > second;
}
bool IsLess(int first, int second) {
    return first < second;
}
bool IsGreaterOrEqual(int first, int second) {
    return first >= second;
}
bool IsLessOrEqual(int first, int second) {
    return first <= second;
}


//-----------------------Bitwise operations

 // Function for bitwise AND
int bitwiseAND(int a, int b) {
    return a & b;
}

// Function for bitwise OR
int bitwiseOR(int a, int b) {
    return a | b;
}

// Function for bitwise XOR
int bitwiseXOR(int a, int b) {
    return a ^ b;
}

// Function for bitwise NOT
int bitwiseNOT(int a) {
    return ~a;
}

// Function for left shift
int leftShift(int a, int shift) {
    return a << shift;
}

// Function for right shift
int rightShift(int a, int shift) {
    return a >> shift;
}

//------------------------------------------------------------------------------


// other functions built on the previous functions


bool IsZero(int value) {
    return IsEqual(value, 0);
}

bool IsNotZero(int value) {
    return !IsZero(value);
}

// Function to check if a value is within a range, inclusive of the boundaries
bool IsInRange(int value, int lower, int upper) {
    bool firstCondition = IsGreaterOrEqual(value, lower);
    bool secondCondition = IsLessOrEqual(value, upper);
    return And(firstCondition, secondCondition);
}

// Function to check if a value is within a range, exclusive of the boundaries
bool IsBetween(int value, int lower, int upper) {
    bool firstCondition = IsGreater(value, lower);
    bool secondCondition = IsLess(value, upper);
    return And(firstCondition, secondCondition);
}

bool IsPositive(int value) {
    return IsGreater(value, 0);
}

bool IsNegative(int value) {
    return !IsPositive(value);
}

bool IsEven(int value) {
    int result = Mod(value, 2);
    return IsZero(result);
}

bool IsOdd(int value) {
    return !IsEven(value);
}




//------------------------------

int Add(int first, int second, int third) {
    int result = Add(first, second);
    result = Add(result, third);
    return result;
}


float Average(double sum, int size) {
    return Divide(sum, size);
}



//----------------------------making programs by me

const double FAHRENHEIT_SCALE = Divide(9.0, 5.0);
const double FAHRENHEIT_OFFSET = 32.0;
const double KELVIN_OFFSET = 273.15;
const double SECONDS_PER_HOUR = 3600;
const double SECONDS_PER_MINUTE = 60;

// Temperature Conversion Functions
double CelsiusToFahrenheit(double celsius) {
    int result = Multiply(celsius, FAHRENHEIT_SCALE);
    return Add(result, FAHRENHEIT_OFFSET);
}

double CelsiusToKelvin(double celsius) {
    return Add(celsius, KELVIN_OFFSET);
}

double FahrenheitToCelsius(double fahrenheit) {
    int result = Subtract(fahrenheit, FAHRENHEIT_OFFSET);
    return Divide(result, FAHRENHEIT_SCALE);
}

double KelvinToCelsius(double kelvin) {
    return Subtract(kelvin, KELVIN_OFFSET);
}

// BMI Calculator
const double BMI_SCALE = 1.0; // Keeps scale for modularity in case adjustments are needed
double calculateBMI(double weight, double height) {
    double result = Multiply(height, height);
    int result1 = Divide(weight, result);
    return Multiply(result1, BMI_SCALE);
}

// Simple Interest Calculator
double calculateSimpleInterest(double principal, double rate, double time) {
    double result = Multiply(principal, rate, time);
    return Divide(result, 100);
}

// Compound Interest Calculator
double calculateCompoundInterest(double principal, double rate, double time, int n) {
    return principal * pow((1 + rate / (n * 100)), n * time);
}

// Time Converter
void convertTime(int seconds) {
    int hours = Divide(seconds, SECONDS_PER_HOUR);
    seconds %= static_cast<int>(SECONDS_PER_HOUR);
    int minutes = Divide(seconds, SECONDS_PER_MINUTE);
    seconds %= static_cast<int>(SECONDS_PER_MINUTE);

    cout << "Time: " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds." << endl;
}

// Currency Converter
double convertCurrency(double amount, double exchangeRate) {
    return Multiply(amount, exchangeRate);
}

// Age Calculator
int calculateAge(int birthYear, int birthMonth, int birthDay, int currentYear, int currentMonth, int currentDay) {
    int age = Subtract(currentYear, birthYear);
    if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) {
        age--;
    }
    return age;
}













//--------------------------------------- Running Programs programs

// Function to calculate the sum of two numbers
void RunAddTwoNumbersProgram() {
    double num1, num2;
    num1 = ReadDoubleNumber("Enter first Number: ");
    num2 = ReadDoubleNumber("Enter second Number : ");
    double Summation = Add(num1, num2);
    Print("Sum Of Two Numbers is :", Summation);
}

// Function to calculate the difference of two numbers
void RunSubtractTwoNumbersProgram() {
    double num1, num2;
    num1 = ReadDoubleNumber("Enter first Number: ");
    num2 = ReadDoubleNumber("Enter second Number : ");
    double subtraction = Subtract(num1, num2);
    Print("Subtraction Of Two Numbers is :", subtraction);
}

// Function to check if a number is odd or even
void RuncheckOddEvenProgram() {
    int num;
    num = ReadIntegerNumber("Enter a number to check if it is odd or even: ");
    int remainder = Mod(num, 2);
    if (IsZero(remainder)) {
        Print("Number is Even ");
    }
    else {
        Print("Number is Odd ");
    }
}


enPositiveOrNegativeOrZero getPostiveOrNegativeStatus(int num) {
    if (IsGreater(num, 0)) {
        return enPositiveOrNegativeOrZero::Positive;
    }
    else if (IsLess(num, 0)) {
        return enPositiveOrNegativeOrZero::Negative;
    }
    else {
        return enPositiveOrNegativeOrZero::Zero;
    }
}


string getPostiveOrNegativeStatusAsString(enPositiveOrNegativeOrZero en) {
    switch (en) {
    case enPositiveOrNegativeOrZero::Positive: return "Positive";
        break;
    case enPositiveOrNegativeOrZero::Negative: return "Negative";
        break;
    case enPositiveOrNegativeOrZero::Zero: return "Zero";

    }
}

// Function to check if a number is positive or negative
void checkPositiveNegative() {
    double num = ReadDoubleNumber("Enter a number to check if it is positive or negative: ");
    enPositiveOrNegativeOrZero result = getPostiveOrNegativeStatus(num);
    Print(getPostiveOrNegativeStatusAsString(result));

}

// Function to check if a number is prime
void checkPrime() {
    int num, i;
    bool isPrime = true;

    num = ReadIntegerNumber("Enter number to check: ");
   

    if (IsLessOrEqual(num, 1)) {
        isPrime = false;
    }
    else {
        for (i = 2; i <= num / 2; ++i) {
            if (IsEqual(Mod(num, i), 0)) {
                isPrime = false;
                break;
            }
        }
    }

    if (isPrime) {
        cout << num << " is a prime number." << endl;
    }
    else {
        cout << num << " is not a prime number." << endl;
    }
}

// Function to check if a number is a perfect number
void checkPerfectNumber() {
    int num, sum = 0;

    cout << "Enter a number to check if it is a perfect number: ";
    cin >> num;

    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }

    if (sum == num) {
        cout << num << " is a perfect number." << endl;
    }
    else {
        cout << num << " is not a perfect number." << endl;
    }
}



// Check if positive or negative
void checkPositiveNegative() {
    double num;
    cout << "Enter a number to check if it's positive or negative: ";
    cin >> num;
    if (num > 0)
        cout << num << " is positive." << endl;
    else if (num < 0)
        cout << num << " is negative." << endl;
    else
        cout << "The number is zero." << endl;
}

// Check odd or even
void checkOddEven() {
    int num;
    cout << "Enter a number to check if it is odd or even: ";
    cin >> num;
    if (num % 2 == 0)
        cout << num << " is even." << endl;
    else
        cout << num << " is odd." << endl;
}

// Factorial
void factorial() {
    int num;
    long long result = 1;
    cout << "Enter a number to calculate factorial: ";
    cin >> num;
    for (int i = 1; i <= num; ++i) {
        result *= i;
    }
    cout << "Factorial of " << num << " is " << result << endl;
}

// Area of rectangle
void rectangleArea() {
    double length, width;
    cout << "Enter length and width of rectangle: ";
    cin >> length >> width;
    cout << "Area of rectangle: " << length * width << endl;
}

// Conversion of seconds to other units
void convertTime() {
    long long seconds;
    cout << "Enter time in seconds: ";
    cin >> seconds;
    long long minutes = seconds / 60;
    long long hours = seconds / 3600;
    long long days = seconds / 86400;
    cout << "Minutes: " << minutes << ", Hours: " << hours << ", Days: " << days << endl;
}

// Full name
void fullName() {
    string firstName, lastName;
    cout << "Enter your first name: ";
    cin >> firstName;
    cout << "Enter your last name: ";
    cin >> lastName;
    cout << "Full Name: " << firstName << " " << lastName << endl;
}

// Sum of three numbers
void sumOfThree() {
    double num1, num2, num3;
    cout << "Enter three numbers: ";
    cin >> num1 >> num2 >> num3;
    cout << "Sum: " << num1 + num2 + num3 << endl;
}

// Average of three numbers
void averageOfThree() {
    double num1, num2, num3;
    cout << "Enter three numbers: ";
    cin >> num1 >> num2 >> num3;
    cout << "Average: " << (num1 + num2 + num3) / 3 << endl;
}

// Arithmetic and Calculation Operations
void remainder() {
    int num1, num2;
    cout << "Enter two integers to find the remainder (num1 % num2): ";
    cin >> num1 >> num2;
    if (num2 != 0) {
        cout << "Remainder: " << num1 % num2 << endl;
    }
    else {
        cout << "Error: Division by zero is not allowed." << endl;
    }
}

void calculateProfitOrLoss() {
    double costPrice, sellingPrice;
    cout << "Enter cost price and selling price: ";
    cin >> costPrice >> sellingPrice;
    if (sellingPrice > costPrice) {
        cout << "Profit: " << sellingPrice - costPrice << endl;
    }
    else if (sellingPrice < costPrice) {
        cout << "Loss: " << costPrice - sellingPrice << endl;
    }
    else {
        cout << "No profit, no loss." << endl;
    }
}

void calculateDiscount() {
    double price, discountRate;
    cout << "Enter original price and discount rate (in %): ";
    cin >> price >> discountRate;
    double discount = price * (discountRate / 100);
    cout << "Discount amount: " << discount << endl;
    cout << "Price after discount: " << price - discount << endl;
}

void calculateTax() {
    double price, taxRate;
    cout << "Enter price and tax rate (in %): ";
    cin >> price >> taxRate;
    double tax = price * (taxRate / 100);
    cout << "Tax amount: " << tax << endl;
    cout << "Price after tax: " << price + tax << endl;
}

// Max and Min Calculations
void maxOfTwo() {
    double num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    cout << "Maximum: " << ((num1 > num2) ? num1 : num2) << endl;
}

void maxOfThree() {
    double num1, num2, num3;
    cout << "Enter three numbers: ";
    cin >> num1 >> num2 >> num3;
    cout << "Maximum: " << max(max(num1, num2), num3) << endl;
}

void minOfTwo() {
    double num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    cout << "Minimum: " << ((num1 < num2) ? num1 : num2) << endl;
}

void minOfThree() {
    double num1, num2, num3;
    cout << "Enter three numbers: ";
    cin >> num1 >> num2 >> num3;
    cout << "Minimum: " << min(min(num1, num2), num3) << endl;
}

// Swap two numbers
void swapNumbers() {
    int a, b;
    cout << "Enter two numbers to swap: ";
    cin >> a >> b;
    int temp = a;
    a = b;
    b = temp;
    cout << "Swapped values: " << a << " and " << b << endl;
}

// Prime Number Check
void checkPrime() {
    int num;
    bool isPrime = true;
    cout << "Enter a number to check if it's prime: ";
    cin >> num;

    if (num <= 1) {
        isPrime = false;
    }
    else {
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }
    }

    if (isPrime) {
        cout << num << " is a prime number." << endl;
    }
    else {
        cout << num << " is not a prime number." << endl;
    }
}

// Perfect Number Check
void checkPerfectNumber() {
    int num, sum = 0;
    cout << "Enter a number to check if it is a perfect number: ";
    cin >> num;

    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }

    if (sum == num) {
        cout << num << " is a perfect number." << endl;
    }
    else {
        cout << num << " is not a perfect number." << endl;
    }
}

// Additional Operations: Age Validation and Grade
void validateAge() {
    int age;
    cout << "Enter age: ";
    cin >> age;
    if (age >= 18 && age <= 35) {
        cout << "Age is within the valid range (18-35)." << endl;
    }
    else {
        cout << "Age is not within the valid range (18-35)." << endl;
    }
}

void gradeCalculator() {
    int marks;
    cout << "Enter your marks (0-100): ";
    cin >> marks;

    if (marks >= 90) {
        cout << "Grade: A" << endl;
    }
    else if (marks >= 80) {
        cout << "Grade: B" << endl;
    }
    else if (marks >= 70) {
        cout << "Grade: C" << endl;
    }
    else if (marks >= 60) {
        cout << "Grade: D" << endl;
    }
    else if (marks >= 50) {
        cout << "Grade: E" << endl;
    }
    else {
        cout << "Grade: F" << endl;
    }
}


// Geometric Area Calculations
void triangleArea() {
    double base, height;
    cout << "Enter base and height of triangle: ";
    cin >> base >> height;
    cout << "Area of triangle: " << 0.5 * base * height << endl;
}

void circleArea() {
    double radius;
    cout << "Enter radius of the circle: ";
    cin >> radius;
    cout << "Area of circle: " << M_PI * radius * radius << endl;
}

void circleAreaDiameter() {
    double diameter;
    cout << "Enter diameter of the circle: ";
    cin >> diameter;
    double radius = diameter / 2.0;
    cout << "Area of circle using diameter: " << M_PI * radius * radius << endl;
}

// Power Calculations
void powerOfTwo() {
    int exponent;
    cout << "Enter exponent for 2^n: ";
    cin >> exponent;
    cout << "2^" << exponent << " = " << pow(2, exponent) << endl;
}

void powerOfM() {
    double base, exponent;
    cout << "Enter base and exponent: ";
    cin >> base >> exponent;
    cout << base << "^" << exponent << " = " << pow(base, exponent) << endl;
}

// Sum Until 99
void sumUntil99() {
    int num, sum = 0;
    cout << "Enter numbers to sum (Enter 99 to stop):" << endl;
    while (true) {
        cin >> num;
        if (num == 99) break;
        sum += num;
    }
    cout << "Sum until 99: " << sum << endl;
}

// Commission Percentage Calculator
void calculateCommission() {
    double sales, commissionRate;
    cout << "Enter sales amount and commission rate (%): ";
    cin >> sales >> commissionRate;
    double commission = sales * (commissionRate / 100);
    cout << "Commission: " << commission << endl;
}

// Conversion among Measurement Units (Length example)
void convertLength() {
    double meters;
    cout << "Enter length in meters: ";
    cin >> meters;
    cout << "In centimeters: " << meters * 100 << " cm" << endl;
    cout << "In kilometers: " << meters / 1000 << " km" << endl;
}

// Loan Installment Calculation
void monthlyLoanInstallment() {
    double principal, rate;
    int months;
    cout << "Enter loan principal, annual interest rate (%), and loan term in months: ";
    cin >> principal >> rate >> months;
    rate = rate / 12 / 100;  // Monthly interest rate
    double installment = (principal * rate) / (1 - pow(1 + rate, -months));
    cout << "Monthly loan installment: " << installment << endl;
}

// ATM Pin Entry with 3 Attempts
void atmPinEntry() {
    const int correctPin = 1234;
    int pin, attempts = 0;
    bool success = false;

    while (attempts < 3) {
        cout << "Enter your 4-digit PIN: ";
        cin >> pin;
        if (pin == correctPin) {
            cout << "Access granted." << endl;
            success = true;
            break;
        }
        else {
            cout << "Incorrect PIN. Try again." << endl;
            attempts++;
        }
    }

    if (!success) {
        cout << "Access denied. Account locked due to too many failed attempts." << endl;
    }
}

// Alphabet Printing (A to Z)
void printAlphabets() {
    cout << "Alphabets from A to Z: ";
    for (char letter = 'A'; letter <= 'Z'; ++letter) {
        cout << letter << " ";
    }
    cout << endl;
}


// Service Fee and Sales Tax Calculation
void calculateServiceFeeAndTax() {
    double amount, serviceFeeRate, taxRate;
    cout << "Enter amount, service fee rate (%), and tax rate (%): ";
    cin >> amount >> serviceFeeRate >> taxRate;
    double serviceFee = amount * (serviceFeeRate / 100);
    double tax = amount * (taxRate / 100);
    cout << "Service Fee: " << serviceFee << ", Tax: " << tax << endl;
    cout << "Total Amount: " << amount + serviceFee + tax << endl;
}

// Pay Remainder Calculation
void payRemainder() {
    double totalAmount, paidAmount;
    cout << "Enter total amount and paid amount: ";
    cin >> totalAmount >> paidAmount;
    cout << "Remaining amount to pay: " << totalAmount - paidAmount << endl;
}

// Grade Calculation based on percentage
void calculateGrade() {
    double percentage;
    cout << "Enter percentage: ";
    cin >> percentage;

    if (percentage >= 90) cout << "Grade: A" << endl;
    else if (percentage >= 80) cout << "Grade: B" << endl;
    else if (percentage >= 70) cout << "Grade: C" << endl;
    else if (percentage >= 60) cout << "Grade: D" << endl;
    else if (percentage >= 50) cout << "Grade: E" << endl;
    else cout << "Grade: F" << endl;
}

// Task Duration Conversion (seconds to various units)
void taskDurationConversion() {
    long long seconds;
    cout << "Enter task duration in seconds: ";
    cin >> seconds;
    cout << "Minutes: " << seconds / 60 << endl;
    cout << "Hours: " << seconds / 3600 << endl;
    cout << "Days: " << seconds / 86400 << endl;
    cout << "Weeks: " << seconds / 604800 << endl;
}

// Print numbers from 1 to n
void printNumbersUptoN() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    for (int i = 1; i <= n; ++i) cout << i << " ";
    cout << endl;
}

// Print numbers from n to 1
void printNumbersDownFromN() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    for (int i = n; i >= 1; --i) cout << i << " ";
    cout << endl;
}

// Print all odd numbers up to n
void printOddNumbersUptoN() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    for (int i = 1; i <= n; i += 2) cout << i << " ";
    cout << endl;
}

// Print all even numbers up to n
void printEvenNumbersUptoN() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    for (int i = 2; i <= n; i += 2) cout << i << " ";
    cout << endl;
}

// Login Function with username and password
void login() {
    string username, password;
    const string correctUsername = "user";
    const string correctPassword = "pass";

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (username == correctUsername && password == correctPassword)
        cout << "Login successful!" << endl;
    else
        cout << "Login failed. Incorrect username or password." << endl;
}

// Sum until a specified limit (e.g., 99)
void sumUntilLimit() {
    int num, sum = 0;
    cout << "Enter numbers to sum (Enter 99 to stop):" << endl;
    while (true) {
        cin >> num;
        if (num == 99) break;
        sum += num;
    }
    cout << "Sum until 99: " << sum << endl;
}

// Piggy Bank Calculator
void piggyBankCalculator() {
    int coins[5] = { 1, 5, 10, 25, 50 }; // Coin denominations in cents
    int count[5], total = 0;
    cout << "Enter the number of 1¢, 5¢, 10¢, 25¢, and 50¢ coins respectively: ";
    for (int i = 0; i < 5; ++i) {
        cin >> count[i];
        total += count[i] * coins[i];
    }
    cout << "Total money in piggy bank: " << total / 100 << " dollars and " << total % 100 << " cents." << endl;
}

// Print lowercase letters a to z
void printLowercaseAlphabets() {
    cout << "Alphabets from a to z: ";
    for (char letter = 'a'; letter <= 'z'; ++letter) cout << letter << " ";
    cout << endl;
}


void fibonacci(int n) {
    int a = 0, b = 1, next;
    cout << "Fibonacci Sequence: ";
    for (int i = 1; i <= n; ++i) {
        cout << a << " ";
        next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
}

bool isPalindrome(string str) {
    int len = str.length();
    for (int i = 0; i < len / 2; ++i) {
        if (str[i] != str[len - i - 1]) return false;
    }
    return true;
}
int binaryToDecimal(string binary) {
    int decimal = 0;
    int base = 1;  // 2^0
    for (int i = binary.length() - 1; i >= 0; --i) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }
    return decimal;
}


const int N = 3;  // Dimension for simplicity

void multiplyMatrices(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void printMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void primeFactors(int n) {
    cout << "Prime factors of " << n << " are: ";
    while (n % 2 == 0) {
        cout << "2 ";
        n /= 2;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }
    if (n > 2) cout << n;
    cout << endl;
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}


void guessingGame() {
    srand(time(0));
    int numberToGuess = rand() % 100 + 1;
    int userGuess, attempts = 0;

    cout << "Guess the number between 1 and 100!" << endl;
    do {
        cout << "Enter your guess: ";
        cin >> userGuess;
        attempts++;
        if (userGuess < numberToGuess) {
            cout << "Too low!" << endl;
        }
        else if (userGuess > numberToGuess) {
            cout << "Too high!" << endl;
        }
        else {
            cout << "Congratulations! You've guessed the number in " << attempts << " attempts." << endl;
        }
    } while (userGuess != numberToGuess);
}



bool isArmstrong(int num) {
    int sum = 0, temp = num, n = 0;

    while (temp != 0) {
        temp /= 10;
        ++n;
    }

    temp = num;
    while (temp != 0) {
        int digit = temp % 10;
        sum += pow(digit, n);
        temp /= 10;
    }

    return (sum == num);
}
void temperatureConversion() {
    double celsius, fahrenheit, kelvin;
    cout << "Enter temperature in Celsius: ";
    cin >> celsius;

    fahrenheit = (celsius * 9 / 5) + 32;
    kelvin = celsius + 273.15;

    cout << "Temperature in Fahrenheit: " << fahrenheit << endl;
    cout << "Temperature in Kelvin: " << kelvin << endl;
}
void calculateBMI() {
    double weight, height, bmi;
    cout << "Enter weight in kg: ";
    cin >> weight;
    cout << "Enter height in meters: ";
    cin >> height;

    bmi = weight / (height * height);
    cout << "Your BMI is: " << bmi << endl;
}


bool isPalindrome(string str) {
    int len = str.length();
    for (int i = 0; i < len / 2; ++i) {
        if (str[i] != str[len - i - 1]) return false;
    }
    return true;
}



int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

const int N = 9;

bool isSafe(int grid[N][N], int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num) return false;
    }
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) return false;
        }
    }
    return true;
}

bool solveSudoku(int grid[N][N], int row, int col) {
    if (row == N - 1 && col == N) return true;
    if (col == N) { row++; col = 0; }
    if (grid[row][col] > 0) return solveSudoku(grid, row, col + 1);
    for (int num = 1; num <= N; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1)) return true;
            grid[row][col] = 0;
        }
    }
    return false;
}

void printGrid(int grid[N][N]) {
    for (int r = 0; r < N; r++) {
        for (int d = 0; d < N; d++) {
            cout << grid[r][d] << " ";
        }
        cout << endl;
    }
}

 








struct RockSisorc {
    // Enumeration for choices
    enum Choice { ROCK, PAPER, SCISSORS };

    // Function to get the user's choice
    Choice getUserChoice() {
        int choice;
        cout << "Enter your choice: (0 = Rock, 1 = Paper, 2 = Scissors): ";
        cin >> choice;

        while (choice < 0 || choice > 2) {
            cout << "Invalid choice. Please enter 0, 1, or 2: ";
            cin >> choice;
        }

        return static_cast<Choice>(choice);
    }

    // Function to generate the computer's choice
    Choice getComputerChoice() {
        srand(time(0)); // Seed for random number generation
        int choice = rand() % 3; // Generate a random number between 0 and 2
        return static_cast<Choice>(choice);
    }

    // Function to convert Choice enum to string
    string choiceToString(Choice choice) {
        switch (choice) {
        case ROCK: return "Rock";
        case PAPER: return "Paper";
        case SCISSORS: return "Scissors";
        }
        return "";
    }

    // Function to determine the winner
    string determineWinner(Choice userChoice, Choice computerChoice) {
        if (userChoice == computerChoice) {
            return "It's a tie!";
        }
        else if ((userChoice == ROCK && computerChoice == SCISSORS) ||
            (userChoice == PAPER && computerChoice == ROCK) ||
            (userChoice == SCISSORS && computerChoice == PAPER)) {
            return "You win!";
        }
        else {
            return "Computer wins!";
        }
    }

    // Main game function
    void playGame() {
        cout << "Welcome to Rock-Paper-Scissors!" << endl;

        Choice userChoice = getUserChoice();
        Choice computerChoice = getComputerChoice();

        cout << "Your choice: " << choiceToString(userChoice) << endl;
        cout << "Computer's choice: " << choiceToString(computerChoice) << endl;

        // Determine and display the winner
        cout << determineWinner(userChoice, computerChoice) << endl;
    }

    void Run() {
        char playAgain;
        do {
            playGame();
            cout << "Do you want to play again? (y/n): ";
            cin >> playAgain;
        } while (playAgain == 'y' || playAgain == 'Y');

        cout << "Thanks for playing!" << endl;
        
    }
};


class TicTacToe {
private:
    char board[3][3];
    char player1Symbol, player2Symbol;
    bool isComputer;

    // Initialize the board with numbers 1 to 9 for reference
    void initializeBoard() {
        char counter = '1';
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = counter++;
            }
        }
    }

    // Display the current state of the board
    void displayBoard() {
        cout << "\n";
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << " " << board[i][j];
                if (j < 2) cout << " |";
            }
            if (i < 2) cout << "\n-----------\n";
        }
        cout << "\n";
    }

    // Check if there's a winner or a tie
    char checkWinner() {
        // Check rows and columns
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return board[i][0];
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return board[0][i];
        }
        // Check diagonals
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return board[0][0];
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return board[0][2];

        // Check for a tie
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[i][j] != player1Symbol && board[i][j] != player2Symbol)
                    return ' '; // Game not over

        return 'T'; // Tie
    }

    // Make a move on the board
    bool makeMove(char symbol, int position) {
        int row = (position - 1) / 3;
        int col = (position - 1) % 3;
        if (board[row][col] != player1Symbol && board[row][col] != player2Symbol) {
            board[row][col] = symbol;
            return true;
        }
        return false;
    }

    // Computer makes a move
    void computerMove() {
        int position;
        do {
            position = rand() % 9 + 1;
        } while (!makeMove(player2Symbol, position));
        cout << "Computer chose position " << position << endl;
    }

public:
    // Constructor to initialize the game settings
    TicTacToe(bool playAgainstComputer = false) : isComputer(playAgainstComputer) {
        player1Symbol = 'X';
        player2Symbol = 'O';
        initializeBoard();
        srand(time(0)); // Seed for random moves by computer
    }

    // Main game loop
    void play() {
        int position;
        char winner = ' ';
        displayBoard();

        for (int turn = 0; turn < 9 && winner == ' '; ++turn) {
            if (turn % 2 == 0) {
                cout << "Player 1, enter position (1-9): ";
                cin >> position;
                while (position < 1 || position > 9 || !makeMove(player1Symbol, position)) {
                    cout << "Invalid move. Try again: ";
                    cin >> position;
                }
            }
            else {
                if (isComputer) {
                    computerMove();
                }
                else {
                    cout << "Player 2, enter position (1-9): ";
                    cin >> position;
                    while (position < 1 || position > 9 || !makeMove(player2Symbol, position)) {
                        cout << "Invalid move. Try again: ";
                        cin >> position;
                    }
                }
            }
            displayBoard();
            winner = checkWinner();
        }

        if (winner == 'T') {
            cout << "It's a tie!" << endl;
        }
        else {
            cout << "The winner is " << winner << "!" << endl;
        }
    }
};





















// Main function
int main() {

    int grid[N][N] = { /* fill in a 9x9 grid with some values */ };
    if (solveSudoku(grid, 0, 0)) printGrid(grid);
    else cout << "No solution exists";
    int choice;

    do {
        cout << "\nChoose an operation to perform:" << endl;
        cout << "1. Add two numbers" << endl;
        cout << "2. Subtract two numbers" << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;
        cout << " . " << endl;


        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addNumbers();
            break;
        case 2:
            subtractNumbers();
            break;
        case 3:
            checkOddEven();
            break;
        case 4:
            checkPositiveNegative();
            break;
        case 5:
            checkPrime();
            break;
        case 6:
            checkPerfectNumber();
            break;
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
