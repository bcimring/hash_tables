/*
 * Linked_List.cpp
 *
 *  Created on: Sep 11, 2020
 *      Author: BCimr
 */

#include "iostream"
#include "Node.h"
#include "string"

Node::Node( Node* p_next, Node* p_last, long data, std::string caller_str ):
p_next( p_next ), p_last( p_last ), data( data ), caller( caller_str ) {

}

Node::~Node( ) {

}

Node* Node::get_p_next() {
	return p_next;
}

Node* Node::get_p_last() {
	return p_last;
}

void Node::set_p_next( Node* new_p ) {
	p_next = new_p;
}

void Node::set_p_last( Node* new_p ) {
	p_last = new_p;
}

long Node::get_data() {
	return data;
}

std::string Node::get_caller() {
	return caller;
}

void Node::set_data( long new_data ) {
	data = new_data;
	return;
}

void Node::set_caller( std::string new_caller ) {
	caller = new_caller;
	return;
}

