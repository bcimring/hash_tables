/*
 * Open_Hash_Elems_Definitions.cpp
 *
 *  Created on: Sep 30, 2020
 *      Author: BCimr
 */
#include "Open_Hash_Elems.h"

Open_Hash_Elems::Open_Hash_Elems( std::string caller_string, long key_input ) {
	caller = caller_string;
	key = key_input;
}

Open_Hash_Elems::~Open_Hash_Elems() {

}

std::string Open_Hash_Elems::get_caller() {
	return caller;
}

long Open_Hash_Elems::get_key() {
	return key;
}

void Open_Hash_Elems::set_caller( std::string new_caller ) {
	caller = new_caller;
	return;
}

void Open_Hash_Elems::set_key( long new_key ) {
	key = new_key;
	return;
}



