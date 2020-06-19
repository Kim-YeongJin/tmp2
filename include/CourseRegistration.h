#ifndef __COURSEREGISTRATION_H_
#define __COURSEREGISTRATION_H_

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <strstream>
#include "fixfld.h"
#include "delim.h"
#include "length.h"

using namespace std;

class CourseRegistration{
private:
    char courseID[10];
    char studentID[10];
    char creditHour[5];
    char grade[3];


public:
    CourseRegistration();
    CourseRegistration(char* courseID, char* studentID, char* creditHour, char* grade);

    friend istream& operator>> (istream& i, CourseRegistration& target);
    friend ostream& operator<< (ostream& o, CourseRegistration& target);

    static int InitBuffer (DelimFieldBuffer &);
    static int InitBuffer (LengthFieldBuffer &);
    static int InitBuffer (FixedFieldBuffer &);

    char * Key () const; 
    int Unpack (IOBuffer &);
    int Pack (IOBuffer &) const;
    void Print (ostream &, char * label = 0) const;

    void Clear ();

    char* getCourseID();
    void setCourseID(string newCID);

    char* getStudentID();
    void setStudentID(string newSID);

    char* getCreditHour();
    void setCreditHour(string newCreditHour);

    char* getGrade();
    void setGrade(string newGrade);

};

#endif
