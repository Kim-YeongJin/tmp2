#include "CourseRegistration.h"

CourseRegistration::CourseRegistration() {
    Clear ();
}

CourseRegistration::CourseRegistration(char* courseID, char* studentID, char*creditHour, char* grade){
    strcpy(this->courseID, courseID);
    strcpy(this->studentID, studentID);
    strcpy(this->creditHour, creditHour);
    strcpy(this->grade, grade);
}

istream& operator>> (istream& i, CourseRegistration& target){

    char cID[10];
    char sID[20];
    char cHour[5];
    char grade[3];

    cout << "courseID: ";
    cin.getline(cID, 10);
    cout << "studentID: ";
    cin.getline(sID, 20);
    cout << "Credit Hour: ";
    cin.getline(cHour, 5);
    cout << "grade: ";
    cin.getline(grade, 3);
    
    target.setCourseID(cID);
    target.setStudentID(sID);
    target.setCreditHour(cHour);
    target.setGrade(grade);

    return i;
}

ostream& operator<< (ostream& o, CourseRegistration& target){

    cout << "------------------------------------" << endl;
    cout << "courseID:        " << target.getCourseID() << endl;
    cout << "studentID:       " << target.getStudentID() << endl;
    cout << "Credit Hour:     " << target.getCreditHour() << endl;
    cout << "Grade:		 " << target.getGrade() << endl;

    return o;
}

void CourseRegistration::Clear() {

    // set each field to an empty string
    courseID[0] = 0;
    studentID[0] = 0;
    creditHour[0] = 0;
    grade[0] = 0;

}

char * CourseRegistration::Key () const
{// produce key as concatenation of Label and IdNum
	ostrstream key;
	key << courseID << ends;
	return key.str();	
}

int CourseRegistration::Pack (IOBuffer & Buffer) const {

    int numBytes;
    Buffer . Clear ();

    numBytes = Buffer.Pack (courseID);
    if (numBytes == -1) return FALSE;

    numBytes = Buffer.Pack (studentID);
    if (numBytes == -1) return FALSE;

    numBytes = Buffer.Pack (creditHour);
    if (numBytes == -1) return FALSE;

    numBytes = Buffer.Pack (grade);
    if (numBytes == -1) return FALSE;

    return TRUE;
}

int CourseRegistration::Unpack (IOBuffer & Buffer) {

    Clear ();
    int numBytes;

    numBytes = Buffer.Unpack (courseID);
    if (numBytes == -1) return FALSE;
    courseID[numBytes] = 0;

    numBytes = Buffer.Unpack (studentID);
    if (numBytes == -1) return FALSE;
    studentID[numBytes] = 0;

    numBytes = Buffer.Unpack (creditHour);
    if (numBytes == -1) return FALSE;
    creditHour[numBytes] = 0;

    numBytes = Buffer.Unpack (grade);
    if (numBytes == -1) return FALSE;
    grade[numBytes] = 0;

    return TRUE;

}

int CourseRegistration::InitBuffer(FixedFieldBuffer & Buffer){

// initialize a FixedFieldBuffer to be used for Persons

    int result;

    result = Buffer.AddField (9); // courseID [10];
    result = result && Buffer.AddField (9); // studentID [10];
    result = result && Buffer.AddField (4); // creditHour [5];
    result = result && Buffer.AddField (2); // grade [3];

    return result;

}

int CourseRegistration::InitBuffer (DelimFieldBuffer & Buffer) {

    // initialize a DelimFieldBuffer to be used for Persons
    return TRUE;
}

// initialize a LengthFieldBuffer to be used for Persons

int CourseRegistration::InitBuffer (LengthFieldBuffer & Buffer) {

    return TRUE;
}

void CourseRegistration::Print (ostream & stream, char * label) const {

    if (label == 0) stream << "Course:";
    else stream << label;

    stream << "\n\t  Course ID '"<<courseID<<"'\n"
	<< "\t Student ID '"<<studentID<<"'\n"
	<< "\tCredit Hour '"<<creditHour<<"'\n"
	<< "\t      Grade '"<<grade<<"'\n"  <<flush;
}

char* CourseRegistration::getCourseID(){
    return this->courseID;
}

void CourseRegistration::setCourseID(string newCID){
    strcpy(this->courseID, newCID.c_str());
}

char* CourseRegistration::getStudentID(){
    return this->studentID;
}

void CourseRegistration::setStudentID(string newSID){
    strcpy(this->studentID, newSID.c_str());
}

char* CourseRegistration::getCreditHour(){
    return this->creditHour;
}

void CourseRegistration::setCreditHour(string newCreditHour){
    strcpy(this->creditHour, newCreditHour.c_str());
}

char* CourseRegistration::getGrade(){
    return this->grade;
}

void CourseRegistration::setGrade(string newGrade){
    strcpy(this->grade, newGrade.c_str());
}





