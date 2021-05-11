/*
 * Open_Hash.h
 *
 *  Created on: Sep 26, 2020
 *      Author: BCimr
 */

#include "Node.h"
#include "Linked_List.h"
#include "vector"
#include "string"
#include "Open_Hash_Elems.h"

#ifndef OPEN_HASH_H_
#define OPEN_HASH_H_

class Open_Hash {
private:
	long m;
	long num_entries;

public:
	std::vector<Open_Hash_Elems> T;
	std::vector<std::string> status;

	Open_Hash( long size );
	Open_Hash( const Open_Hash &other );

	~Open_Hash( );

	Open_Hash& operator=( const Open_Hash &other );

	long search( long key );

	bool remove( long to_delete );

	bool insert( long to_insert, std::string caller );

	bool is_empty();

	bool is_full();

	long get_size();

};

#endif /* OPEN_HASH_H_ */
