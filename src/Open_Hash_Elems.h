/*
 * Open_Hash_Elems.h
 *
 *  Created on: Sep 30, 2020
 *      Author: BCimr
 */

#include "string"

#ifndef OPEN_HASH_ELEMS_H_
#define OPEN_HASH_ELEMS_H_

class Open_Hash_Elems {
private:

public:
	std::string caller;
	long key;

	Open_Hash_Elems( std::string caller_string, long key_input );

	~Open_Hash_Elems();

	std::string get_caller();

	long get_key();

	void set_caller( std::string new_caller );

	void set_key( long new_key );
};



#endif /* OPEN_HASH_ELEMS_H_ */
