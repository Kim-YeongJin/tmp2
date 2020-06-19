#include "Student.h"

Student::Student() {
    Clear ();
}

Student::Student(char* studentID, char* name, char* address, char* enroll_date, char* creditHour){
    strcpy(this->studentID, studentID);
    strcpy(this->name, name);
    strcpy(this->address, address);
    strcpy(this->enrollDate, enroll_date);
    strcpy(this->creditHour, creditHour);
}

istream& operator>> (istream& i, Student& target){

    char studentID[10];
    char name[20];
    char address[40];
    char enrollDate[80];
    char creditHour[5];

    time_t curr_time;
    struct tm *curr_tm;
    curr_time = time(NULL);
    curr_tm = localtime(&curr_time);
    strftime(enrollDate,80,"%Y-%m-%d-%H:%M:%S",curr_tm);

    
    cout << "Please input your information" << endl;
    cout << "studentID: ";
    cin.getline(studentID, 10);
    cout << "name: ";
    cin.getline(name, 20);
    cout << "address: ";
    cin.getline(address, 40);
    cout << "Credit Hour: ";
    cin.getline(creditHour, 5);

    target.setStudentID(studentID);
    target.setName(name);
    target.setAddress(address);
    target.setEnrollDate(enrollDate);
    target.setCreditHour(creditHour);
    
    return i;
}

ostream& operator<< (ostream& o, Student& target){
    cout << "------------------------------------" << endl;
    cout << "Student " << target.getName() << "'s information" << endl;
    cout << "studentID: " << target.getStudentID() << endl;
    cout << "name: " << target.getName() << endl;
    cout << "address: " << target.getAddress() << endl;
    cout << "Enroll Date: " << target.getEnrollDate() << endl;
    cout << "Credit Hour: " << target.getCreditHour() << endl;

    return o;
}

void Student::operator= (Student& target){
    target.setStudentID(studentID);
    target.setName(name);
    target.setAddress(address);
    target.setEnrollDate(enrollDate);
    target.setCreditHour(creditHour);
    
}

void Student::Clear() {

    // set each field to an empty string
    name[0] = 0;
    studentID[0] = 0;
    address[0] = 0;
    enrollDate[0] = 0;
    creditHour[0] = 0;
}

char * Student::Key () const
{// produce key as concatenation of Label and IdNum
	ostrstream key;   // this is replaced
	key << studentID << ends;
	return key.str();	
}

int Student::Pack (IOBuffer & Buffer) const {
    int numBytes;
    Buffer.Clear();

    numBytes = Buffer.Pack(name);
    if (numBytes == -1) return FALSE; 

    numBytes = Buffer.Pack(studentID);
    if (numBytes == -1) return FALSE;

    numBytes = Buffer.Pack(address);
    if (numBytes == -1) return FALSE;

    numBytes = Buffer.Pack(enrollDate);
    if (numBytes == -1) return FALSE;

    numBytes = Buffer.Pack(creditHour);
    if (numBytes == -1) return FALSE;

    return TRUE;

}

int Student::Unpack (IOBuffer & Buffer) {
    Clear ();
    int numBytes;

    numBytes = Buffer.Unpack(name);
    if (numBytes == -1) return FALSE;
    name[numBytes] = 0;

    numBytes = Buffer.Unpack(studentID);
    if (numBytes == -1) return FALSE;
    studentID[numBytes] = 0;

    numBytes = Buffer.Unpack(address);
    if (numBytes == -1) return FALSE;
    address[numBytes] = 0;

    numBytes = Buffer.Unpack(enrollDate);
    if (numBytes == -1) return FALSE;
    enrollDate[numBytes] = 0;

    numBytes = Buffer.Unpack(creditHour);
    if (numBytes == -1) return FALSE;
    creditHour[numBytes] = 0;

    return TRUE;

}

int Student::InitBuffer(FixedFieldBuffer & Buffer){

    // initialize a FixedFieldBuffer to be used for Persons
    int result;

    result = Buffer.AddField (9); // studentID [10];
    result = result && Buffer.AddField (19); // name [20];
    result = result && Buffer.AddField (39); // address [40];
    result = result && Buffer.AddField (79); // enrollDate [80];
    result = result && Buffer.AddField (4);  // creditHour [5];

    return result;

}

int Student::InitBuffer (DelimFieldBuffer & Buffer) {
    // initialize a DelimFieldBuffer to be used for Persons

    return TRUE;
}

// initialize a LengthFieldBuffer to be used for Persons

int Student::InitBuffer (LengthFieldBuffer & Buffer){	
    return TRUE;
}

void Student::Print (ostream & stream, char * label) const {

    if (label == 0) stream << "Student:";
    else stream << label;

    stream << "\n\t Student ID '"<<studentID<<"'\n"
    	<< "\t      Name  '"<<name<<"'\n"
	<< "\t   Address  '"<<address<<"'\n"
	<< "\tEnrollDate  '"<<enrollDate<<"'\n"
	<< "\tCredit Hour '"<<creditHour <<"'\n" << flush;

}

char* Student::getStudentID(){
    return this->studentID;
}
void Student::setStudentID(string newId){
    strcpy(this->studentID, newId.c_str());
}
char* Student::getName(){
    return this->name;
}
void Student::setName(string newName){
    strcpy(this->name, newName.c_str());
}
char* Student::getAddress(){
    return this->address;
}
void Student::setAddress(string newAddress){
    strcpy(this->address, newAddress.c_str());
}
char* Student::getEnrollDate(){
    return this->enrollDate;
}
void Student::setEnrollDate(string newEnrollDate){
    strcpy(this->enrollDate, newEnrollDate.c_str());
}
char* Student::getCreditHour(){
    return this->creditHour;
}
void Student::setCreditHour(string newCreditHour){
    strcpy(this->creditHour, newCreditHour.c_str());
}







