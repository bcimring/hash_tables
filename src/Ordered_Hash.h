/*
 * Ordered_Hash.h
 *
 *  Created on: Sep 26, 2020
 *      Author: BCimr
 */
#include "Node.h"
#include "Linked_List.h"
#include "vector"

#ifndef ORDERED_HASH_H_
#define ORDERED_HASH_H_

class Ordered_Hash {
private:
	long m;

public:
	std::vector<Linked_List> T;

	Ordered_Hash( long size );

	Ordered_Hash( const Ordered_Hash& other );

	Ordered_Hash& operator=( const Ordered_Hash& other );

	~Ordered_Hash( );

	Node* search( long key );

	bool remove( long to_delete );

	bool insert( long to_insert, std::string caller );

	bool is_empty();

	long get_size();

	void print_row( long x );

};

#endif /* ORD_HASH_H_ */
