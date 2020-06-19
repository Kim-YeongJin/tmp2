#ifndef LENGTH_H
#define LENGTH_H

#include <iostream>
#include "varlen.h"

// a buffer which holds a length plus value fields.
// Record variables can be packed into and extracted from a buffer.
// 
// To use this class, create a LengthFieldBuffer variable and associate definitions with the fields.
// operations are provided to allow values to be associated with the fields (Pack)
//	and to fetch the values of fields (Unpack)
class LengthFieldBuffer: public VariableLengthBuffer
{  
public:
	// construct with fields of specific size
	// construct with a maximum of maxFields
	LengthFieldBuffer (int maxBytes = 1000); 
	// copy constructor
	LengthFieldBuffer (const LengthFieldBuffer & buffer) 
		: VariableLengthBuffer (buffer) {}
	void Clear (); // clear fields from buffer
	// set the value of the next field of the buffer;
	int Pack (const void * field, int size = -1); 
	// extract the value of the next field of the buffer
	int Unpack (void *field, int maxBytes = -1); 
	void Print (ostream &) const;
 	int Init ();
};

#endif
