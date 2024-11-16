//#include <iostream>
//#include <vector>
//#include <string>
//#include <memory>
//
//// Enum for EmailType
//enum class EmailType {
//    Home,
//    Work,
//    Other
//};
//
//// Enum for PhoneNumberType
//enum class PhoneNumberType {
//    Home,
//    Mobile,
//    Main,
//    Work,
//    Other
//};
//
//// Abstract base class for Contact Information
//class ContactInfo {
//public:
//    virtual ~ContactInfo() = default;
//    virtual void Display() const = 0; // Abstract method for displaying info
//};
//
//// PhoneNumber Class
//class PhoneNumber : public ContactInfo {
//    std::string Number;
//    PhoneNumberType Type;
//    bool IsPrimary;
//
//public:
//    PhoneNumber(std::string number, PhoneNumberType type, bool isPrimary = false)
//        : Number(number), Type(type), IsPrimary(isPrimary) {}
//
//    void Display() const override {
//        std::cout << "  - " << Number << " ("
//            << (Type == PhoneNumberType::Home ? "Home" :
//                Type == PhoneNumberType::Mobile ? "Mobile" :
//                Type == PhoneNumberType::Main ? "Main" :
//                Type == PhoneNumberType::Work ? "Work" : "Other")
//            << ", " << (IsPrimary ? "Primary" : "Secondary") << ")\n";
//    }
//};
//
//// Email Class
//class Email : public ContactInfo {
//    std::string Address;
//    EmailType Type;
//    bool IsPrimary;
//
//public:
//    Email(std::string address, EmailType type, bool isPrimary = false)
//        : Address(address), Type(type), IsPrimary(isPrimary) {}
//
//    void Display() const override {
//        std::cout << "  - " << Address << " ("
//            << (Type == EmailType::Home ? "Home" :
//                Type == EmailType::Work ? "Work" : "Other")
//            << ", " << (IsPrimary ? "Primary" : "Secondary") << ")\n";
//    }
//};
//
//// Contact Class
//class Contact {
//    int ContactID;
//    std::string FirstName, MiddleName, LastName;
//    std::string Prefix, Suffix, NickName, Notes, Website, Company, Department, JobTitle, BirthDate;
//    bool IsFavorite;
//    std::vector<std::shared_ptr<ContactInfo>> ContactInfos;
//
//public:
//    Contact(int id, std::string firstName, std::string lastName)
//        : ContactID(id), FirstName(firstName), LastName(lastName), IsFavorite(false) {}
//
//    void AddContactInfo(std::shared_ptr<ContactInfo> info) {
//        ContactInfos.push_back(info);
//    }
//
//    void Display() const {
//        std::cout << "Contact ID: " << ContactID << "\n";
//        std::cout << "Name: " << FirstName << " " << (MiddleName.empty() ? "" : MiddleName + " ") << LastName << "\n";
//        if (!Prefix.empty()) std::cout << "Prefix: " << Prefix << "\n";
//        if (!Suffix.empty()) std::cout << "Suffix: " << Suffix << "\n";
//        std::cout << "Favorite: " << (IsFavorite ? "Yes" : "No") << "\n";
//        if (!NickName.empty()) std::cout << "Nickname: " << NickName << "\n";
//        if (!Notes.empty()) std::cout << "Notes: " << Notes << "\n";
//        if (!Website.empty()) std::cout << "Website: " << Website << "\n";
//        if (!Company.empty()) std::cout << "Company: " << Company << "\n";
//        if (!Department.empty()) std::cout << "Department: " << Department << "\n";
//        if (!JobTitle.empty()) std::cout << "Job Title: " << JobTitle << "\n";
//        if (!BirthDate.empty()) std::cout << "Birth Date: " << BirthDate << "\n";
//
//        std::cout << "Contact Information:\n";
//        for (const auto& info : ContactInfos) {
//            info->Display();
//        }
//    }
//};
//
//int main() {
//    // Create a Contact
//    Contact contact(1, "John", "Doe");
//    contact.Display();
//
//    // Add Emails and Phone Numbers
//    contact.AddContactInfo(std::make_shared<Email>("john.doe@example.com", EmailType::Work, true));
//    contact.AddContactInfo(std::make_shared<Email>("johndoe@gmail.com", EmailType::Home));
//    contact.AddContactInfo(std::make_shared<PhoneNumber>("123-456-7890", PhoneNumberType::Mobile, true));
//    contact.AddContactInfo(std::make_shared<PhoneNumber>("098-765-4321", PhoneNumberType::Work));
//
//    // Display Contact Details
//    contact.Display();
//
//    return 0;
//}


//--------------------------------------------


//#include <iostream>
//#include <vector>
//#include <string>
//#include <memory>
//#include <map>
//
//// Enum for EmailType
//enum class EmailType {
//    Home,
//    Work,
//    Other
//};
//
//// Enum for PhoneNumberType
//enum class PhoneNumberType {
//    Home,
//    Mobile,
//    Main,
//    Work,
//    Other
//};
//
//// Utility functions for Enum to String conversion
//std::string EmailTypeToString(EmailType type) {
//    switch (type) {
//    case EmailType::Home: return "Home";
//    case EmailType::Work: return "Work";
//    default: return "Other";
//    }
//}
//
//std::string PhoneNumberTypeToString(PhoneNumberType type) {
//    switch (type) {
//    case PhoneNumberType::Home: return "Home";
//    case PhoneNumberType::Mobile: return "Mobile";
//    case PhoneNumberType::Main: return "Main";
//    case PhoneNumberType::Work: return "Work";
//    default: return "Other";
//    }
//}
//
//// Abstract base class for Contact Information
//class ContactInfo {
//public:
//    virtual ~ContactInfo() = default;
//    virtual void Display() const = 0;
//};
//
//// PhoneNumber Class
//class PhoneNumber : public ContactInfo {
//    std::string Number;
//    PhoneNumberType Type;
//    bool IsPrimary = false;
//
//public:
//    PhoneNumber(const std::string& number, PhoneNumberType type, bool isPrimary = false)
//        : Number(number), Type(type), IsPrimary(isPrimary) {}
//
//    void Display() const override {
//        std::cout << "  - " << Number << " ("
//            << PhoneNumberTypeToString(Type)
//            << ", " << (IsPrimary ? "Primary" : "Secondary") << ")\n";
//    }
//};
//
//// Email Class
//class Email : public ContactInfo {
//    std::string Address;
//    EmailType Type;
//    bool IsPrimary = false;
//
//public:
//    Email(const std::string& address, EmailType type, bool isPrimary = false)
//        : Address(address), Type(type), IsPrimary(isPrimary) {}
//
//    void Display() const override {
//        std::cout << "  - " << Address << " ("
//            << EmailTypeToString(Type)
//            << ", " << (IsPrimary ? "Primary" : "Secondary") << ")\n";
//    }
//};
//
//// Contact Class
//class Contact {
//    int ContactID;
//    std::string FirstName, MiddleName, LastName;
//    std::string Prefix, Suffix, NickName, Notes, Website, Company, Department, JobTitle, BirthDate;
//    bool IsFavorite = false;
//    std::vector<std::shared_ptr<ContactInfo>> ContactInfos;
//
//public:
//    Contact(int id, const std::string& firstName, const std::string& lastName)
//        : ContactID(id), FirstName(firstName), LastName(lastName) {}
//
//    void AddContactInfo(std::shared_ptr<ContactInfo> info) {
//        ContactInfos.push_back(info);
//    }
//
//    void Display() const {
//        std::cout << "Contact ID: " << ContactID << "\n";
//        std::cout << "Name: " << FirstName
//            << (MiddleName.empty() ? "" : " " + MiddleName)
//            << " " << LastName << "\n";
//        if (!Prefix.empty()) std::cout << "Prefix: " << Prefix << "\n";
//        if (!Suffix.empty()) std::cout << "Suffix: " << Suffix << "\n";
//        std::cout << "Favorite: " << (IsFavorite ? "Yes" : "No") << "\n";
//        if (!NickName.empty()) std::cout << "Nickname: " << NickName << "\n";
//        if (!Notes.empty()) std::cout << "Notes: " << Notes << "\n";
//        if (!Website.empty()) std::cout << "Website: " << Website << "\n";
//        if (!Company.empty()) std::cout << "Company: " << Company << "\n";
//        if (!Department.empty()) std::cout << "Department: " << Department << "\n";
//        if (!JobTitle.empty()) std::cout << "Job Title: " << JobTitle << "\n";
//        if (!BirthDate.empty()) std::cout << "Birth Date: " << BirthDate << "\n";
//
//        std::cout << "Contact Information:\n";
//        for (const auto& info : ContactInfos) {
//            info->Display();
//        }
//    }
//
//    // Setters for optional fields
//    void SetMiddleName(const std::string& middleName) { MiddleName = middleName; }
//    void SetPrefix(const std::string& prefix) { Prefix = prefix; }
//    void SetSuffix(const std::string& suffix) { Suffix = suffix; }
//    void SetNickName(const std::string& nickName) { NickName = nickName; }
//    void SetNotes(const std::string& notes) { Notes = notes; }
//    void SetWebsite(const std::string& website) { Website = website; }
//    void SetCompany(const std::string& company) { Company = company; }
//    void SetDepartment(const std::string& department) { Department = department; }
//    void SetJobTitle(const std::string& jobTitle) { JobTitle = jobTitle; }
//    void SetBirthDate(const std::string& birthDate) { BirthDate = birthDate; }
//    void SetFavorite(bool isFavorite) { IsFavorite = isFavorite; }
//};
//
//// Main function
//int main() {
//    Contact contact(1, "John", "Doe");
//    contact.SetNickName("Johnny");
//    contact.SetFavorite(true);
//    contact.SetCompany("TechCorp");
//    contact.SetJobTitle("Software Engineer");
//
//    contact.AddContactInfo(std::make_shared<Email>("john.doe@example.com", EmailType::Work, true));
//    contact.AddContactInfo(std::make_shared<Email>("johndoe@gmail.com", EmailType::Home));
//    contact.AddContactInfo(std::make_shared<PhoneNumber>("123-456-7890", PhoneNumberType::Mobile, true));
//    contact.AddContactInfo(std::make_shared<PhoneNumber>("098-765-4321", PhoneNumberType::Work));
//
//    contact.Display();
//
//    return 0;
//}




//----------------------
//#include <iostream>
//#include <vector>
//#include <string>
//#include <memory>
//#include <map>
//
//// Enum for EmailType
//enum class EmailType {
//    Home,
//    Work,
//    Other
//};
//
//// Enum for PhoneNumberType
//enum class PhoneNumberType {
//    Home,
//    Mobile,
//    Main,
//    Work,
//    Other
//};
//
//// Utility functions for Enum to String conversion
//std::string EmailTypeToString(EmailType type) {
//    switch (type) {
//    case EmailType::Home: return "Home";
//    case EmailType::Work: return "Work";
//    default: return "Other";
//    }
//}
//
//std::string PhoneNumberTypeToString(PhoneNumberType type) {
//    switch (type) {
//    case PhoneNumberType::Home: return "Home";
//    case PhoneNumberType::Mobile: return "Mobile";
//    case PhoneNumberType::Main: return "Main";
//    case PhoneNumberType::Work: return "Work";
//    default: return "Other";
//    }
//}
//
//// Abstract base class for Contact Information (Strategy Pattern)
//class ContactInfo {
//public:
//    virtual ~ContactInfo() = default;
//    virtual void Display() const = 0;
//};
//
//// PhoneNumber Class (Concrete Strategy)
//class PhoneNumber : public ContactInfo {
//    std::string Number;
//    PhoneNumberType Type;
//    bool IsPrimary = false;
//
//public:
//    PhoneNumber(const std::string& number, PhoneNumberType type, bool isPrimary = false)
//        : Number(number), Type(type), IsPrimary(isPrimary) {}
//
//    void Display() const override {
//        std::cout << "  - " << Number << " ("
//            << PhoneNumberTypeToString(Type)
//            << ", " << (IsPrimary ? "Primary" : "Secondary") << ")\n";
//    }
//};
//
//// Email Class (Concrete Strategy)
//class Email : public ContactInfo {
//    std::string Address;
//    EmailType Type;
//    bool IsPrimary = false;
//
//public:
//    Email(const std::string& address, EmailType type, bool isPrimary = false)
//        : Address(address), Type(type), IsPrimary(isPrimary) {}
//
//    void Display() const override {
//        std::cout << "  - " << Address << " ("
//            << EmailTypeToString(Type)
//            << ", " << (IsPrimary ? "Primary" : "Secondary") << ")\n";
//    }
//};
//
//// Factory Method for ContactInfo
//class ContactInfoFactory {
//public:
//    static std::shared_ptr<ContactInfo> CreatePhoneNumber(const std::string& number, PhoneNumberType type, bool isPrimary = false) {
//        return std::make_shared<PhoneNumber>(number, type, isPrimary);
//    }
//
//    static std::shared_ptr<ContactInfo> CreateEmail(const std::string& address, EmailType type, bool isPrimary = false) {
//        return std::make_shared<Email>(address, type, isPrimary);
//    }
//};
//
//// Builder Pattern for Contact
//class ContactBuilder {
//    std::shared_ptr<Contact> contact;
//
//public:
//    ContactBuilder(int id, const std::string& firstName, const std::string& lastName)
//        : contact(std::make_shared<Contact>(id, firstName, lastName)) {}
//
//    ContactBuilder& SetNickName(const std::string& nickName) {
//        contact->SetNickName(nickName);
//        return *this;
//    }
//
//    ContactBuilder& SetCompany(const std::string& company) {
//        contact->SetCompany(company);
//        return *this;
//    }
//
//    ContactBuilder& AddContactInfo(std::shared_ptr<ContactInfo> info) {
//        contact->AddContactInfo(info);
//        return *this;
//    }
//
//    std::shared_ptr<Contact> Build() {
//        return contact;
//    }
//};
//
//// Observer Pattern to notify changes
//class Observer {
//public:
//    virtual void Notify(const std::string& message) = 0;
//};
//
//class ConsoleLogger : public Observer {
//public:
//    void Notify(const std::string& message) override {
//        std::cout << "Logger: " << message << "\n";
//    }
//};
//
//// Contact Class with Observer Support
//class Contact {
//    int ContactID;
//    std::string FirstName, MiddleName, LastName;
//    std::string Prefix, Suffix, NickName, Notes, Website, Company, Department, JobTitle, BirthDate;
//    bool IsFavorite = false;
//    std::vector<std::shared_ptr<ContactInfo>> ContactInfos;
//    std::vector<std::shared_ptr<Observer>> Observers;
//
//public:
//    Contact(int id, const std::string& firstName, const std::string& lastName)
//        : ContactID(id), FirstName(firstName), LastName(lastName) {}
//
//    void AddContactInfo(std::shared_ptr<ContactInfo> info) {
//        ContactInfos.push_back(info);
//    }
//
//    void AddObserver(std::shared_ptr<Observer> observer) {
//        Observers.push_back(observer);
//    }
//
//    void NotifyObservers(const std::string& message) {
//        for (const auto& observer : Observers) {
//            observer->Notify(message);
//        }
//    }
//
//    void Display() const {
//        std::cout << "Contact ID: " << ContactID << "\n";
//        std::cout << "Name: " << FirstName
//            << (MiddleName.empty() ? "" : " " + MiddleName)
//            << " " << LastName << "\n";
//        if (!Prefix.empty()) std::cout << "Prefix: " << Prefix << "\n";
//        if (!Suffix.empty()) std::cout << "Suffix: " << Suffix << "\n";
//        std::cout << "Favorite: " << (IsFavorite ? "Yes" : "No") << "\n";
//        if (!NickName.empty()) std::cout << "Nickname: " << NickName << "\n";
//        if (!Notes.empty()) std::cout << "Notes: " << Notes << "\n";
//        if (!Website.empty()) std::cout << "Website: " << Website << "\n";
//        if (!Company.empty()) std::cout << "Company: " << Company << "\n";
//        if (!Department.empty()) std::cout << "Department: " << Department << "\n";
//        if (!JobTitle.empty()) std::cout << "Job Title: " << JobTitle << "\n";
//        if (!BirthDate.empty()) std::cout << "Birth Date: " << BirthDate << "\n";
//
//        std::cout << "Contact Information:\n";
//        for (const auto& info : ContactInfos) {
//            info->Display();
//        }
//    }
//
//    void SetNickName(const std::string& nickName) {
//        NickName = nickName;
//        NotifyObservers("Nickname set to: " + nickName);
//    }
//
//    void SetFavorite(bool isFavorite) {
//        IsFavorite = isFavorite;
//        NotifyObservers("Favorite status changed");
//    }
//};
//
//// Main function
//int main() {
//    auto logger = std::make_shared<ConsoleLogger>();
//
//    auto contact = ContactBuilder(1, "John", "Doe")
//        .SetNickName("Johnny")
//        .SetCompany("TechCorp")
//        .AddContactInfo(ContactInfoFactory::CreateEmail("john.doe@example.com", EmailType::Work, true))
//        .AddContactInfo(ContactInfoFactory::CreatePhoneNumber("123-456-7890", PhoneNumberType::Mobile, true))
//        .Build();
//
//    contact->AddObserver(logger);
//
//    contact->SetFavorite(true);
//    contact->Display();
//
//    return 0;
//}
