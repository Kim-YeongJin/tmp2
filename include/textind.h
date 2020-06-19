//textind.h

#ifndef TEXTIND_H
#define TEXTIND_H
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class TextIndex
{
  public:
	TextIndex (int maxKeys = 100, int unique = 1);
	~TextIndex ();
	int Insert (const char * key, int recAddr); // add to index
	int Remove (const char * key);
	//int Update (const char * key);
	// search for key, return recaddr
	int Search (const char * key) const;
	void Print(ostream &) const;

protected:
	int MaxKeys;	// maximum number of entries
	int MinKeys;	// minimum number of entries
	int NumKeys;	// actual number of entries
	char ** Keys;	// array of key values
	int *RecAddrs;	// array of record references
	int Find (const char * key) const;
	int Init (int maxKeys, int unique);
	int Unique; // if true, each key value must be unique in the index	

	friend class TextIndexBuffer;
};



#endif
