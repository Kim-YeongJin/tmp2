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
#include "buffile.h"
#include "recfile.h"
#include "recfile.cpp"  // for template
#include "btnode.h"
#include "./btindex/btnode.cpp" // for template method body
#include "btree.h"
#include "./btindex/btree.cpp"   // for template method body

Student * st[50];
const int BTreeSize = 5;

void st_record()
{
        st[0] = new Student ("0", "st1", "Seoul", "2014", "30");
        st[1] = new Student ("1", "st2", "Seoul", "2014", "30");
        st[2] = new Student ("2", "st3", "Seoul", "2014", "30");
        st[3] = new Student ("3", "st4", "Seoul", "2014", "30");
        st[4] = new Student ("4", "st5", "Seoul", "2014", "30");
        st[5] = new Student ("5", "st6", "Seoul", "2014", "30");
        st[6] = new Student ("6", "st7", "Seoul", "2014", "30");
        st[7] = new Student ("7", "st8", "Seoul", "2014", "30");
        st[8] = new Student ("8", "st9", "Seoul", "2014", "30");
        st[9] = new Student ("9", "st10", "Seoul", "2014", "30");
        st[10] = new Student ("10", "st11", "Busan", "2014", "30");
        st[11] = new Student ("11", "st12", "Busan", "2014", "30");
        st[12] = new Student ("12", "st13", "Busan", "2014", "30");
        st[13] = new Student ("13", "st14", "Busan", "2014", "30");
        st[14] = new Student ("14", "st15", "Busan", "2014", "30");
        st[15] = new Student ("15", "st16", "Busan", "2014", "30");
        st[16] = new Student ("16", "st17", "Busan", "2014", "30");
        st[17] = new Student ("17", "st18", "Busan", "2014", "30");
        st[18] = new Student ("18", "st19", "Busan", "2014", "30");
        st[19] = new Student ("19", "st20", "Busan", "2014", "30");
        st[20] = new Student ("20", "st1", "Seoul", "2014", "30");
        st[21] = new Student ("21", "st2", "Seoul", "2014", "30");
        st[22] = new Student ("22", "st3", "Seoul", "2014", "30");
        st[23] = new Student ("23", "st4", "Seoul", "2014", "30");
        st[24] = new Student ("24", "st5", "Seoul", "2014", "30");
        st[25] = new Student ("25", "st6", "Seoul", "2014", "30");
        st[26] = new Student ("26", "st7", "Seoul", "2014", "30");
        st[27] = new Student ("27", "st8", "Seoul", "2014", "30");
        st[28] = new Student ("28", "st9", "Seoul", "2014", "30");
        st[29] = new Student ("29", "st10", "Seoul", "2014", "30");
	st[30] = new Student ("30", "st11", "Busan", "2014", "30");
        st[31] = new Student ("31", "st12", "Busan", "2014", "30");
        st[32] = new Student ("32", "st13", "Busan", "2014", "30");
        st[33] = new Student ("33", "st14", "Busan", "2014", "30");
        st[34] = new Student ("34", "st15", "Busan", "2014", "30");
        st[35] = new Student ("35", "st16", "Busan", "2014", "30");
        st[36] = new Student ("36", "st17", "Busan", "2014", "30");
        st[37] = new Student ("37", "st18", "Busan", "2014", "30");
        st[38] = new Student ("38", "st19", "Busan", "2014", "30");
        st[39] = new Student ("39", "st20", "Busan", "2014", "30");
        st[40] = new Student ("40", "st11", "Busan", "2014", "30");
        st[41] = new Student ("41", "st12", "Busan", "2014", "30");
        st[42] = new Student ("42", "st13", "Busan", "2014", "30");
        st[43] = new Student ("43", "st14", "Busan", "2014", "30");
        st[44] = new Student ("44", "st15", "Busan", "2014", "30");
        st[45] = new Student ("45", "st16", "Busan", "2014", "30");
        st[46] = new Student ("46", "st17", "Busan", "2014", "30");
        st[47] = new Student ("47", "st18", "Busan", "2014", "30");
        st[48] = new Student ("48", "st19", "Busan", "2014", "30");
        st[49] = new Student ("49", "st20", "Busan", "2014", "30");

}


int main(int argc, char ** argv)
{

	int result, i;
	BTree <char *> bt (BTreeSize);
	result = bt.Create ("st.dat",ios::in|ios::out);
	if (!result){cout<<"Please delete student.dat"<<endl;return 0;}

	st_record();

	for (i = 0; i<50; i++)
	{
		cout<<"Inserting "<<st[i]->getStudentID()<<endl;
		result = bt.Insert(st[i]->getStudentID(),i);
		cout << result << endl;
		bt.Print(cout);
	}

	cout << bt.Search("0") << endl;
	// Delete Test
	for (i = 0; i<50; i++)
	{
		cout<<"Deleting "<<st[i]->getStudentID()<<endl;
		result = bt.Remove(st[i]->getStudentID(),i);
		cout << result << endl;
	}

	bt.Close();
	return 0;


}







