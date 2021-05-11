/*
 * Node.h
 *
 *  Created on: Sep 15, 2020
 *      Author: BCimr
 */
#include "string"

#ifndef NODE_H_
#define NODE_H_

class Node {
private:
	Node* p_next;
	Node* p_last;
	double data;
	std::string caller;

public:

	Node( Node* p_next, Node* p_last, long data, std::string caller );

	~Node( );

	Node* get_p_next();
	Node* get_p_last();

	void set_p_next( Node* new_p );
	void set_p_last( Node* new_p );

	long get_data();

	std::string get_caller();

	void set_data( long new_data );

	void set_caller( std::string new_caller );
};

#endif /* Node_H_ */

