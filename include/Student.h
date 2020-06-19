#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <ctime>
#include <strstream>
#include "fixfld.h"
#include "delim.h"
#include "length.h"

using namespace std;

class Student{
private:
    char studentID[10];
    char name[20];
    char address[40];
    char enrollDate[80];
    char creditHour[5];

public:
    Student();
    Student(char* studentID, char* name, char* address, char* enrollDate, char* creditHour);

    friend istream& operator>> (istream& i, Student& target);
    friend ostream& operator<< (ostream& o, Student& target);

    void operator= (Student& target);

    static int InitBuffer (DelimFieldBuffer &);
    static int InitBuffer (LengthFieldBuffer &);
    static int InitBuffer (FixedFieldBuffer &);

    char * Key () const;
    int Unpack (IOBuffer &);
    int Pack (IOBuffer &) const;
    void Print (ostream &, char * label = 0) const;

    void Clear ();
    
    char* getStudentID();
    void setStudentID(string newId);

    char* getName();
    void setName(string newName);

    char* getAddress();
    void setAddress(string newAddress);

    char* getEnrollDate();
    void setEnrollDate(string newEnrollDate);

    char* getCreditHour();
    void setCreditHour(string newCreditHour);
    
};

#endif
