#include <iostream>
#include <string>
#include <vector>

using namespace std;

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









// Main function
int main() {
    // Example usage
    Function func = inputFunction();
    cout << "\nDisplaying Function Information:\n";
    displayFunction(func);

    Attribute attr = inputAttribute();
    cout << "\nDisplaying Attribute Information:\n";
    displayAttribute(attr);


    // Example for ClassRepresentation
    cout << "Input Class Representation:" << endl;
    ClassRepresentation myClass = inputClassRepresentation();

    cout << "\nDisplaying Class Representation:" << endl;
    displayClassRepresentation(myClass);

    // Example for Expression
    cout << "\nInput Expression:" << endl;
    Expression expr = inputExpression();

    cout << "\nDisplaying Expression:" << endl;
    displayExpression(expr);







    return 0;
}
