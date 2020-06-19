#ifndef RECFILE_H
#define RECFILE_H

#include "buffile.h"
#include "iobuffer.h"


// template class to support direct read and write of records
// The template parameter RecType must support the following
//	int Pack (BufferType &); pack record into buffer
//	int Unpack (BufferType &); unpack record from buffer

template <class RecType>
class RecordFile: public BufferFile
{
public:
	int Read(RecType & record, int recaddr = -1);
	int Write(const RecType & record, int recaddr = -1);
	int Append(const RecType & record, int recaddr = -1);
	int Remove (RecType & record, int recaddr = -1);
	//int Update (char * oldKey, char * newKey, int recaddr = -1);
	RecordFile (IOBuffer & buffer): BufferFile (buffer) {}
};

#endif
