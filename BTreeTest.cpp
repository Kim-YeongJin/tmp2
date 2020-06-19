#include <fstream>
#include <iomanip>
#include <cstring>
#include "textind.h"
#include "indfile.h"
#include "./index/indfile.cpp"
#include "iobuffer.h"
#include "fixfld.h"
#include "length.h"
#include "Student.h"
#include "CourseRegistration.h"
#include "buffile.h"
#include "recfile.h"
#include "recfile.cpp"  // for template
#include "btnode.h"
#include "./btindex/btnode.cpp" // for template method body
#include "btree.h"
#include "./btindex/btree.cpp"   // for template method body

Student student[20];
CourseRegistration course[20];
const int BTreeSize = 5;

void getTime(char* t){
    t[0] = '\0';
    time_t curr_time;
    struct tm *curr_tm;
    curr_time = time(NULL);
    curr_tm = localtime(&curr_time);
    strftime(t, 80, "%Y-%m-%d-%H:%M:%S", curr_tm);
}

void InitStudent()
{
    cout << "Initializing 20 Students"<<endl;
    char enrollDate[80];
    int recaddr;

    student[0].setStudentID("201424528");
    student[0].setName("JSG");
    student[0].setAddress("Address 1");
    getTime(enrollDate);
    student[0].setEnrollDate(enrollDate);
    student[0].setCreditHour("117");

    student[1].setStudentID("201430492");
    student[1].setName("Student 2");
    student[1].setAddress("Address 2");
    getTime(enrollDate);
    student[1].setEnrollDate(enrollDate);
    student[1].setCreditHour("107");

    student[2].setStudentID("201530192");
    student[2].setName("Student 3");
    student[2].setAddress("Address 3");
    getTime(enrollDate);
    student[2].setEnrollDate(enrollDate);
    student[2].setCreditHour("89");

    student[3].setStudentID("201540098");
    student[3].setName("Student 4");
    student[3].setAddress("Address 4");
    getTime(enrollDate);
    student[3].setEnrollDate(enrollDate);
    student[3].setCreditHour("79");

    student[4].setStudentID("201629018");
    student[4].setName("Student 5");
    student[4].setAddress("Address 5");
    getTime(enrollDate);
    student[4].setEnrollDate(enrollDate);
    student[4].setCreditHour("70");

    student[5].setStudentID("201617789");
    student[5].setName("Student 6");
    student[5].setAddress("Address 6");
    getTime(enrollDate);
    student[5].setEnrollDate(enrollDate);
    student[5].setCreditHour("68");

    student[6].setStudentID("201723659");
    student[6].setName("Student 7");
    student[6].setAddress("Address 7");
    getTime(enrollDate);
    student[6].setEnrollDate(enrollDate);
    student[6].setCreditHour("60");

    student[7].setStudentID("201820417");
    student[7].setName("Student 8");
    student[7].setAddress("Address 8");
    getTime(enrollDate);
    student[7].setEnrollDate(enrollDate);
    student[7].setCreditHour("58");

    student[8].setStudentID("201860098");
    student[8].setName("Student 9");
    student[8].setAddress("Address 9");
    getTime(enrollDate);
    student[8].setEnrollDate(enrollDate);
    student[8].setCreditHour("30");

    student[9].setStudentID("201945532");
    student[9].setName("Student 10");
    student[9].setAddress("Address 10");
    getTime(enrollDate);
    student[9].setEnrollDate(enrollDate);
    student[9].setCreditHour("41");

    student[10].setStudentID("201354863");
    student[10].setName("Student 11");
    student[10].setAddress("Address 11");
    getTime(enrollDate);
    student[10].setEnrollDate(enrollDate);
    student[10].setCreditHour("121");

    student[11].setStudentID("201548201");
    student[11].setName("Student 12");
    student[11].setAddress("Address 12");
    getTime(enrollDate);
    student[11].setEnrollDate(enrollDate);
    student[11].setCreditHour("97");

    student[12].setStudentID("201435486");
    student[12].setName("Student 13");
    student[12].setAddress("Address 13");
    getTime(enrollDate);
    student[12].setEnrollDate(enrollDate);
    student[12].setCreditHour("110");

    student[13].setStudentID("201540098");
    student[13].setName("Student 14");
    student[13].setAddress("Address 14");
    getTime(enrollDate);
    student[13].setEnrollDate(enrollDate);
    student[13].setCreditHour("79");

    student[14].setStudentID("201916883");
    student[14].setName("Student 15");
    student[14].setAddress("Address 15");
    getTime(enrollDate);
    student[14].setEnrollDate(enrollDate);
    student[14].setCreditHour("69");

    student[15].setStudentID("201768831");
    student[15].setName("Student 16");
    student[15].setAddress("Address 16");
    getTime(enrollDate);
    student[15].setEnrollDate(enrollDate);
    student[15].setCreditHour("56");

    student[16].setStudentID("201864731");
    student[16].setName("Student 17");
    student[16].setAddress("Address 17");
    getTime(enrollDate);
    student[16].setEnrollDate(enrollDate);
    student[16].setCreditHour("45");

    student[17].setStudentID("201215432");
    student[17].setName("Student 18");
    student[17].setAddress("Address 18");
    getTime(enrollDate);
    student[17].setEnrollDate(enrollDate);
    student[17].setCreditHour("116");

    student[18].setStudentID("202046883");
    student[18].setName("Student 19");
    student[18].setAddress("Address 19");
    getTime(enrollDate);
    student[18].setEnrollDate(enrollDate);
    student[18].setCreditHour("18");

    student[19].setStudentID("201728405");
    student[19].setName("Student 20");
    student[19].setAddress("Address 20");
    getTime(enrollDate);
    student[19].setEnrollDate(enrollDate);
    student[19].setCreditHour("49");

}


int main(int argc, char ** argv)
{

	int result, i;
	BTree <char *> bt (BTreeSize);
	result = bt.Create ("student.dat",ios::in|ios::out);
	if (!result){cout<<"Please delete student.dat"<<endl;return 0;}

	InitStudent();

	for (i = 0; i<20; i++)
	{
		cout<<"Inserting "<<student[i].getStudentID()<<endl;
		result = bt.Insert(student[i].getStudentID(),i);
		cout << result << endl;
		bt.Print(cout);
	}

	cout << bt.Search("201424528") << endl;
	// Delete Test
	for (i = 0; i<20; i++)
	{
		cout<<"Deleting "<<student[i].getStudentID()<<endl;
		result = bt.Remove(student[i].getStudentID(),i);
		cout << result << endl;
	}

	bt.Close();
	return 0;


}







