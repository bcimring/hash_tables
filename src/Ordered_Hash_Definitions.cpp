/*
 * Ordered_Hash_Definitions.cpp
 *
 *  Created on: Sep 26, 2020
 *      Author: BCimr
 */
#include "Ordered_Hash.h"
#include "vector"
#include "iostream"
#include "cmath"

Ordered_Hash::Ordered_Hash( long size ) {
	m = size;
	for ( long i = 0; i < m; i++ ) {
		Linked_List M = Linked_List();
		T.push_back(Linked_List());
	}
}

Ordered_Hash::~Ordered_Hash() {
	//for ( int i = 0; i < m; i++ ) {
	//	T[i].~Linked_List();
	//}
	T.erase(T.begin(), T.end());

	return;
}

Ordered_Hash::Ordered_Hash( const Ordered_Hash &other ) {
	m = other.m;
	T.clear();
	for ( long i = 0; i < m; i++ ) {
		Linked_List L = other.T[i];
		T.push_back(L);
	}
}

Ordered_Hash& Ordered_Hash::operator=( const Ordered_Hash &other ) {
	Ordered_Hash temp(other);

	std::swap(m, temp.m);
	T.erase(T.begin(), T.end());
	for ( long i = 0; i < m; i++ ) {
		Linked_List L = Linked_List();
		std::swap(L, temp.T[i]);
		T.push_back(L);
	}
}

bool Ordered_Hash::insert( long key, std::string caller ) {
	// hash function
	long x = fmod(key,m);
	Node* inserting = new Node( nullptr, nullptr, key, caller );
	if ( T[x].insert( inserting ) == false ) {
		delete inserting; return false;
	} else {return true;}
}

Node* Ordered_Hash::search( long key ) {
	// hash function
	long x = key%m;
	return T[x].search( key );
}

bool Ordered_Hash::remove( long key ) {
	// hash function
	long x = key%m;
	return T[x].remove( key );
}

long Ordered_Hash::get_size() {
	return m;
}

void Ordered_Hash::print_row( long x ) {
	if ( T[x].get_size() > 0 ) {
		Node* p_temp = T[x].get_head();
		std::cout << p_temp->get_data();
		while ( p_temp->get_p_next() != nullptr ) {
			p_temp = p_temp->get_p_next();
			std::cout << ' ' << p_temp->get_data();

		}
		std::cout << std::endl;
	}
	return;
}



