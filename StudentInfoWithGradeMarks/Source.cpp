#include<iostream>
#include<string>

using namespace std;

const short NumberOfMarks = 6;

struct IOHelper {
static	void Print(const string& title) {
		cout << title << endl;
	}

static	void Print(const string& title, const string& value) {
		cout << title << " " << value << endl;
	}

static	string ReadString(const string& prompt) {
		Print(prompt);
		string text;
		getline(cin, text);
		return text;
	}

static	double ReadDouble(const string& prompt) {
		Print(prompt);
		double value;
		cin >> value;
		cin.ignore();
		return (double)value;
	}
static	int ReadInteger(const string& prompt) {
		Print(prompt);
		int value;
		cin >> value;
		cin.ignore();
		return value;
	}

static	char ReadChar(const string& prompt) {
		Print(prompt);
		char letter;
		cin >> letter;
		cin.ignore();
		return letter;
	}

};

struct stAddress {
	string StreetName, BuildingNumber, City, State, Country;

	static stAddress ReadAddressRecord() {
		stAddress ad;
		ad.StreetName = IOHelper::ReadString("Enter Street Name : ");
		ad.BuildingNumber = IOHelper::ReadString("Enter Building Number : ");
		ad.City = IOHelper::ReadString("Enter City Name : ");
		ad.State = IOHelper::ReadString("Enter State Name : ");
		ad.Country = IOHelper::ReadString("Enter Country Name : ");

		return ad;
	}
};

struct stContacts {
	string PhoneNumber, Email;
	stAddress Address;

	static stContacts ReadContactRecord() {
		stContacts cont; 
		cont.PhoneNumber = IOHelper::ReadString("Enter Phone Number : ");
		cont.Email = IOHelper::ReadString("Enter Email Address : ");
		cont.Address = stAddress::ReadAddressRecord();
		return cont;
	}

	 

};


enum class enMaritalStatus {
	None,
	Single,
	Married,
	Divorced
};


enMaritalStatus GetMaritalStatus(char status) {
	switch (status)
	{
	case 'N': return enMaritalStatus::None;
	case 'S': return enMaritalStatus::Single;
	case 'M': return enMaritalStatus::Married;
	case 'D': return enMaritalStatus::Divorced;
	default:
		return;
		break;
	}
}

string GetMaritalStatusAsString(enMaritalStatus status) {
	switch (status)
	{
	case enMaritalStatus::None: return "None";
		break;
	case enMaritalStatus::Single: return "Single";
		break;
	case enMaritalStatus::Married: return "Married";
		break;
	case enMaritalStatus::Divorced: return "Divorced";
		break;
	default:
		break;
	}
}

struct stFullName {
	string FirstName, SecondName, ThirdName, LastName;

	static stFullName ReadFullNameRecord() {
		stFullName fullname;
		fullname.FirstName = IOHelper::ReadString("Enter First Name : ");
		fullname.SecondName = IOHelper::ReadString("Enter Second Name : ");
		fullname.ThirdName = IOHelper::ReadString("Enter Third Name : ");
		fullname.LastName = IOHelper::ReadString("Enter Last Name : ");
		return fullname;
	}

};

struct stSubject {
	string SubjectName;
	double Mark;
	static stSubject ReadSubjectRecord() {
		stSubject subject;
		subject.SubjectName = IOHelper::ReadString("Enter the subject Name");
		subject.Mark = IOHelper::ReadDouble("Enter the Mark: ");
		return subject;
	}

};


struct stStudent {
	int ID;
	stFullName FullName;
	enMaritalStatus MaritalStatus ;
	stContacts ContactInfo;
	static stSubject Subjects[NumberOfMarks];

	static  void ReadSubjects() {
		for (int i = 0; i < NumberOfMarks; i++) {
			Subjects[i] = stSubject::ReadSubjectRecord();
		}
		 
	}



	 static	stStudent ReadStudentRecord() {
		stStudent st;
		st.ID = IOHelper::ReadInteger("Enter Student ID: ");
		st.FullName = stFullName::ReadFullNameRecord();
		st.MaritalStatus = GetMaritalStatus(IOHelper::ReadChar("Enter Gender N for none, S for Single, M for Married, D for Divorced"));
		st.ContactInfo = stContacts::ReadContactRecord();
		 ReadSubjects();
		return st;


}

};



int main() {

	return 0;
}




