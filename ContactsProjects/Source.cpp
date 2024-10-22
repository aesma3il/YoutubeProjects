#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct Group {
	int GroupID;
	string GroupName;
};

struct conName {
	string NamePrefix, FirstName, MiddleName, LastName, SuffixName;
};

struct PhoneticName {
	string FirstName, MiddleName, LastName;
};

struct GroupManager {
	vector<Group> contactList;
};

struct AddressType {
	int TypeID;
	string TypeName;
};

struct AddressTypeManager {
	vector<AddressType> addressTypeList;
};


struct Address {
	int ID;
	string Street, City, State, ZipCode, Country;
};

struct WorkInfo {
	int WorkInfoID;
	string JobTitle, CompanyName;
};

struct AddressManager {
	vector<Address> addressList;
};


struct EmailAddressType {
	int TypeID;
	string TypeName;
};

struct EmailAddressTypeManager {
	vector< EmailAddressType> emailTypeList;
};

struct Website {
	int WebsiteID;
	string WebsiteURL;
};

struct WebsiteManager {
	vector<Website> websitesList; 
};


struct Contact {
	int ContactID;
	conName ContactName;
	PhoneticName PhoneticName;
	string Nickname;
	
	string  PhoneNumber, Email;
};


int main() {

}