#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Random Enum Generator
template<typename EnumType>
EnumType randomEnum(int max) {
    return static_cast<EnumType>(rand() % (max + 1));
}

// Random String Generator
string randomString(int length) {
    const string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string result;
    for (int i = 0; i < length; ++i) {
        result += charset[rand() % charset.size()];
    }
    return result;
}

// Random Number Generator for Integers
int randomInt(int min, int max) {
    return min + rand() % ((max - min) + 1);
}




// Enumerations for categorizing properties
enum class Accessibility { Private, Public, Protected };
enum class Scope { Local, Global, BlockScope, ClassScope, NamespaceScope };
enum class LifeTime { Dynamic, Static, Automatic, Temporary };
enum class Modifier { Constant, Volatile, Mutable, Restrict };
enum class TypeOfBinding { EarlyBinding, LateBinding };
enum class DataType { Int, Short, Long, Double, Float, Char, Bool, String, Void, Enum, Struct, Class, Union, Array, Pointer, FunctionPointer };
enum class StorageClass { Extern, Register, Static, Auto, ThreadLocal };
enum class ParameterPassingMechanism { ByValue, ByReference, ByPointer };
enum class Direction { Input, Output, InputOutput };

// Structures
struct Parameter {
    string Name;
    DataType Type;
    string DefaultValue;
    ParameterPassingMechanism Mechanism;
    Direction DirectionType;
    Modifier Modifiers;
    Accessibility Access;
    bool IsOptional;
};

// Expression structure
struct Expression {
    string ResultType;         // Type of the resulting value
    string Result;             // Computed result (if known at compile-time)
    vector<string> Operands;   // List of operands
    char Operator;             // Operator used in the expression
    string SourceCode;         // Original source code of the expression
};

struct Attribute {
    string Name;
    DataType Type;
    string Size;
    string Value;
    string DefaultValue;
    bool IsStatic;
    bool IsConst;
    bool IsInitialized;
    LifeTime Lifetime;
    Scope ScopeOfAttribute;
    StorageClass StorageCls;
    Accessibility Access;
};

struct Function {
    string Name;
    DataType ReturnType;
    vector<Parameter> Parameters;
    Accessibility Access;
    bool IsVirtual;
    bool IsStatic;
    bool IsInline;
    TypeOfBinding Binding;
};

// Class/Struct representation
struct ClassRepresentation {
    string Name;                            // Name of the class
    vector<Attribute> Attributes;           // List of attributes (members)
    vector<Function> Methods;               // List of methods
    Accessibility DefaultAccess;            // Default access specifier
    vector<string> BaseClasses;             // List of base classes (if any)
    bool HasVirtualMethods;                 // Whether it has virtual methods
    bool IsAbstract;                        // Abstract class indicator
    string VTableAddress;                   // Address of the virtual table (if applicable)
};


enum class ArithmeticOperator { Addition, Subtraction, Multiplication, Division, Modulus };
enum class LogicalOperator { And, Or, Not };
enum class RelationalOperator { Equal, NotEqual, GreaterThan, LessThan, GreaterOrEqual, LessOrEqual };
enum class BitwiseOperator { And, Or, Xor, Not, LeftShift, RightShift };

// Function to convert an arithmetic operator to a string
string arithmeticOperatorToString(ArithmeticOperator op) {
    switch (op) {
    case ArithmeticOperator::Addition: return "+";
    case ArithmeticOperator::Subtraction: return "-";
    case ArithmeticOperator::Multiplication: return "*";
    case ArithmeticOperator::Division: return "/";
    case ArithmeticOperator::Modulus: return "%";
    default: return "Unknown";
    }
}

// Function to convert a logical operator to a string
string logicalOperatorToString(LogicalOperator op) {
    switch (op) {
    case LogicalOperator::And: return "&&";
    case LogicalOperator::Or: return "||";
    case LogicalOperator::Not: return "!";
    default: return "Unknown";
    }
}

// Function to convert a relational operator to a string
string relationalOperatorToString(RelationalOperator op) {
    switch (op) {
    case RelationalOperator::Equal: return "==";
    case RelationalOperator::NotEqual: return "!=";
    case RelationalOperator::GreaterThan: return ">";
    case RelationalOperator::LessThan: return "<";
    case RelationalOperator::GreaterOrEqual: return ">=";
    case RelationalOperator::LessOrEqual: return "<=";
    default: return "Unknown";
    }
}

// Function to convert a bitwise operator to a string
string bitwiseOperatorToString(BitwiseOperator op) {
    switch (op) {
    case BitwiseOperator::And: return "&";
    case BitwiseOperator::Or: return "|";
    case BitwiseOperator::Xor: return "^";
    case BitwiseOperator::Not: return "~";
    case BitwiseOperator::LeftShift: return "<<";
    case BitwiseOperator::RightShift: return ">>";
    default: return "Unknown";
    }
}








// Function to input parameter information
Parameter inputParameter() {
    Parameter param;
    cout << "Enter Parameter Name: ";
    cin >> param.Name;
    int type;
    cout << "Enter Parameter Type (0: Int, 1: Float, etc.): ";
    cin >> type;
    param.Type = static_cast<DataType>(type);
    cout << "Enter Default Value (or 'none'): ";
    cin >> param.DefaultValue;
    cout << "Is Optional (1 for Yes, 0 for No): ";
    cin >> param.IsOptional;
    return param;
}


// Structure for Conditional Statements
struct ConditionalStatement {
    string Condition;            // The condition expression
    vector<string> IfBlock;      // Statements in the `if` block
    vector<string> ElseIfBlocks; // Optional, conditions and statements in `else if` blocks
    vector<string> ElseBlock;    // Optional, statements in the `else` block
    string SourceCode;           // Optional, original source code
};

// Function to input Conditional Statement information
ConditionalStatement inputConditionalStatement() {
    ConditionalStatement cond;
    cout << "Enter the Condition Expression: ";
    cin.ignore(); // To clear newline from input buffer
    getline(cin, cond.Condition);

    // Input for the `if` block
    cout << "Enter the number of statements in the 'if' block: ";
    int ifCount;
    cin >> ifCount;
    cond.IfBlock.resize(ifCount);
    cin.ignore(); // Clear input buffer
    for (int i = 0; i < ifCount; ++i) {
        cout << "Enter statement " << i + 1 << " in the 'if' block: ";
        getline(cin, cond.IfBlock[i]);
    }

    // Input for `else if` blocks
    cout << "Enter the number of 'else if' blocks: ";
    int elseifCount;
    cin >> elseifCount;
    cond.ElseIfBlocks.resize(elseifCount);
    cin.ignore();
    for (int i = 0; i < elseifCount; ++i) {
        cout << "Enter condition and statements for 'else if' block " << i + 1 << ": ";
        getline(cin, cond.ElseIfBlocks[i]);
    }

    // Input for the `else` block
    cout << "Enter the number of statements in the 'else' block: ";
    int elseCount;
    cin >> elseCount;
    cond.ElseBlock.resize(elseCount);
    cin.ignore();
    for (int i = 0; i < elseCount; ++i) {
        cout << "Enter statement " << i + 1 << " in the 'else' block: ";
        getline(cin, cond.ElseBlock[i]);
    }

    // Optional source code
    cout << "Enter the original source code (if available): ";
    getline(cin, cond.SourceCode);

    return cond;
}

// Function to display Conditional Statement information
void displayConditionalStatement(const ConditionalStatement& cond) {
    cout << "Condition: " << cond.Condition << endl;

    cout << "If Block Statements:" << endl;
    for (const auto& stmt : cond.IfBlock) {
        cout << "  " << stmt << endl;
    }

    cout << "Else If Blocks:" << endl;
    for (const auto& elseif : cond.ElseIfBlocks) {
        cout << "  " << elseif << endl;
    }

    cout << "Else Block Statements:" << endl;
    for (const auto& stmt : cond.ElseBlock) {
        cout << "  " << stmt << endl;
    }

    if (!cond.SourceCode.empty()) {
        cout << "Source Code: " << cond.SourceCode << endl;
    }
}





// Structure for Loop Statements
struct LoopStatement {
    string LoopType;              // Loop type: "for", "while", "do-while"
    string Initialization;        // Initialization expression (e.g., int i = 0)
    string Condition;             // Condition to control the loop
    string Update;                // Update expression (e.g., i++)
    vector<string> Body;          // Statements in the loop body
    string SourceCode;            // Optional, original source code
};

// Function to input Loop Statement information
LoopStatement inputLoopStatement() {
    LoopStatement loop;
    cout << "Enter Loop Type ('for', 'while', 'do-while'): ";
    cin >> loop.LoopType;

    if (loop.LoopType == "for") {
        cout << "Enter Initialization Expression: ";
        cin.ignore();
        getline(cin, loop.Initialization);
        cout << "Enter Condition Expression: ";
        getline(cin, loop.Condition);
        cout << "Enter Update Expression: ";
        getline(cin, loop.Update);
    }
    else if (loop.LoopType == "while" || loop.LoopType == "do-while") {
        cout << "Enter Condition Expression: ";
        cin.ignore();
        getline(cin, loop.Condition);
    }

    cout << "Enter the number of statements in the loop body: ";
    int bodyCount;
    cin >> bodyCount;
    loop.Body.resize(bodyCount);
    cin.ignore();
    for (int i = 0; i < bodyCount; ++i) {
        cout << "Enter statement " << i + 1 << " in the loop body: ";
        getline(cin, loop.Body[i]);
    }

    // Optional source code
    cout << "Enter the original source code (if available): ";
    getline(cin, loop.SourceCode);

    return loop;
}

// Function to display Loop Statement information
void displayLoopStatement(const LoopStatement& loop) {
    cout << "Loop Type: " << loop.LoopType << endl;

    if (loop.LoopType == "for") {
        cout << "Initialization: " << loop.Initialization << endl;
        cout << "Condition: " << loop.Condition << endl;
        cout << "Update: " << loop.Update << endl;
    }
    else if (loop.LoopType == "while" || loop.LoopType == "do-while") {
        cout << "Condition: " << loop.Condition << endl;
    }

    cout << "Loop Body Statements:" << endl;
    for (const auto& stmt : loop.Body) {
        cout << "  " << stmt << endl;
    }

    if (!loop.SourceCode.empty()) {
        cout << "Source Code: " << loop.SourceCode << endl;
    }
}






// Function to display parameter information
void displayParameter(const Parameter& param) {
    cout << "Parameter Name: " << param.Name << endl;
    cout << "Type: " << static_cast<int>(param.Type) << endl;
    cout << "Default Value: " << param.DefaultValue << endl;
    cout << "Is Optional: " << (param.IsOptional ? "Yes" : "No") << endl;
}

// Function to input function information
Function inputFunction() {
    Function func;
    cout << "Enter Function Name: ";
    cin >> func.Name;
    int returnType;
    cout << "Enter Return Type (0: Int, 1: Float, etc.): ";
    cin >> returnType;
    func.ReturnType = static_cast<DataType>(returnType);

    cout << "Enter Number of Parameters: ";
    int paramCount;
    cin >> paramCount;
    for (int i = 0; i < paramCount; i++) {
        cout << "Input Parameter " << i + 1 << ":" << endl;
        func.Parameters.push_back(inputParameter());
    }

    return func;
}

// Function to display function information
void displayFunction(const Function& func) {
    cout << "Function Name: " << func.Name << endl;
    cout << "Return Type: " << static_cast<int>(func.ReturnType) << endl;
    cout << "Parameters:" << endl;
    for (const auto& param : func.Parameters) {
        displayParameter(param);
    }
}

// Function to input attribute information
Attribute inputAttribute() {
    Attribute attr;
    cout << "Enter Attribute Name: ";
    cin >> attr.Name;
    int type;
    cout << "Enter Attribute Type (0: Int, 1: Float, etc.): ";
    cin >> type;
    attr.Type = static_cast<DataType>(type);
    cout << "Enter Default Value (or 'none'): ";
    cin >> attr.DefaultValue;
    cout << "Is Initialized (1 for Yes, 0 for No): ";
    cin >> attr.IsInitialized;
    return attr;
}

// Function to display attribute information
void displayAttribute(const Attribute& attr) {
    cout << "Attribute Name: " << attr.Name << endl;
    cout << "Type: " << static_cast<int>(attr.Type) << endl;
    cout << "Default Value: " << attr.DefaultValue << endl;
    cout << "Is Initialized: " << (attr.IsInitialized ? "Yes" : "No") << endl;
}

// Function to input Expression information
Expression inputExpression() {
    Expression expr;
    cout << "Enter Result Type: ";
    cin >> expr.ResultType;
    cout << "Enter Result (if known, or 'none'): ";
    cin >> expr.Result;
    cout << "Enter Operator: ";
    cin >> expr.Operator;

    cout << "Enter the number of operands: ";
    int operandCount;
    cin >> operandCount;
    expr.Operands.resize(operandCount);
    for (int i = 0; i < operandCount; ++i) {
        cout << "Enter Operand " << i + 1 << ": ";
        cin >> expr.Operands[i];
    }

    cout << "Enter Source Code (if available): ";
    cin.ignore();
    getline(cin, expr.SourceCode);

    return expr;
}

// Function to display Expression information
void displayExpression(const Expression& expr) {
    cout << "Result Type: " << expr.ResultType << endl;
    cout << "Result: " << (expr.Result.empty() ? "Unknown" : expr.Result) << endl;
    cout << "Operator: " << expr.Operator << endl;
    cout << "Operands: ";
    for (const auto& operand : expr.Operands) {
        cout << operand << " ";
    }
    cout << endl;
    cout << "Source Code: " << (expr.SourceCode.empty() ? "N/A" : expr.SourceCode) << endl;
}

// Function to input ClassRepresentation information
ClassRepresentation inputClassRepresentation() {
    ClassRepresentation cls;
    cout << "Enter Class Name: ";
    cin >> cls.Name;

    cout << "Enter Default Accessibility (0: Private, 1: Public, 2: Protected): ";
    int defaultAccess;
    cin >> defaultAccess;
    cls.DefaultAccess = static_cast<Accessibility>(defaultAccess);

    // Input Attributes
    cout << "Enter the number of Attributes: ";
    int attrCount;
    cin >> attrCount;
    for (int i = 0; i < attrCount; ++i) {
        cout << "Input Attribute " << i + 1 << ":" << endl;
        cls.Attributes.push_back(inputAttribute());
    }

    // Input Methods
    cout << "Enter the number of Methods: ";
    int methodCount;
    cin >> methodCount;
    for (int i = 0; i < methodCount; ++i) {
        cout << "Input Method " << i + 1 << ":" << endl;
        cls.Methods.push_back(inputFunction());
    }

    cout << "Is the Class Abstract? (1 for Yes, 0 for No): ";
    cin >> cls.IsAbstract;

    cout << "Enter the number of Base Classes: ";
    int baseClassCount;
    cin >> baseClassCount;
    cls.BaseClasses.resize(baseClassCount);
    for (int i = 0; i < baseClassCount; ++i) {
        cout << "Enter Base Class " << i + 1 << ": ";
        cin >> cls.BaseClasses[i];
    }

    return cls;
}

// Function to display ClassRepresentation information
void displayClassRepresentation(const ClassRepresentation& cls) {
    cout << "Class Name: " << cls.Name << endl;
    cout << "Default Accessibility: " << static_cast<int>(cls.DefaultAccess) << endl;

    cout << "Attributes:" << endl;
    for (const auto& attr : cls.Attributes) {
        displayAttribute(attr);
    }

    cout << "Methods:" << endl;
    for (const auto& method : cls.Methods) {
        displayFunction(method);
    }

    cout << "Is Abstract: " << (cls.IsAbstract ? "Yes" : "No") << endl;

    cout << "Base Classes: ";
    for (const auto& baseClass : cls.BaseClasses) {
        cout << baseClass << " ";
    }
    cout << endl;
}









int main() {
    cout << "=============================" << endl;
    cout << "Input and Display: Function" << endl;
    cout << "=============================" << endl;
    Function func = inputFunction();
    cout << "\nDisplaying Function Information:\n";
    displayFunction(func);

    cout << "=============================" << endl;
    cout << "Input and Display: Attribute" << endl;
    cout << "=============================" << endl;
    Attribute attr = inputAttribute();
    cout << "\nDisplaying Attribute Information:\n";
    displayAttribute(attr);

    cout << "=============================" << endl;
    cout << "Input and Display: Class Representation" << endl;
    cout << "=============================" << endl;
    ClassRepresentation myClass = inputClassRepresentation();
    cout << "\nDisplaying Class Representation:\n";
    displayClassRepresentation(myClass);

    cout << "=============================" << endl;
    cout << "Input and Display: Expression" << endl;
    cout << "=============================" << endl;
    Expression expr = inputExpression();
    cout << "\nDisplaying Expression Information:\n";
    displayExpression(expr);

    cout << "=============================" << endl;
    cout << "Input and Display: Conditional Statement" << endl;
    cout << "=============================" << endl;
    ConditionalStatement cond = inputConditionalStatement();
    cout << "\nDisplaying Conditional Statement Information:\n";
    displayConditionalStatement(cond);

    cout << "=============================" << endl;
    cout << "Input and Display: Loop Statement" << endl;
    cout << "=============================" << endl;
    LoopStatement loop = inputLoopStatement();
    cout << "\nDisplaying Loop Statement Information:\n";
    displayLoopStatement(loop);


















    return 0;
}
