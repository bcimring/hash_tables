/*
 * Open_Hash_Definitions.cpp
 *
 *  Created on: Sep 26, 2020
 *      Author: BCimr
 */
#include "Open_Hash.h"
#include "vector"
#include "cmath"
#include "iostream"
#include "algorithm"
#include "Open_Hash_Elems.h"

Open_Hash::Open_Hash( long size ) {
	m = size;
	num_entries = 0;

	long nil = 0;
	std::string nil_str = "";
	Open_Hash_Elems element = Open_Hash_Elems( nil_str, nil );
	for ( long i = 0; i < size; i++ ) {
		status.push_back("empty");
		T.push_back( element );

	}

	return;

}

Open_Hash::Open_Hash( const Open_Hash &other ) {
	m = other.m;
	num_entries = other.num_entries;
	T.erase(T.begin(), T.end());
	status.erase(status.begin(), status.end());
	T.reserve(m);
	status.reserve(m);

	for ( long i = 0; i < m; i++ ) {
		T.push_back(other.T[i]);
		status.push_back(other.status[i]);
	}

}


Open_Hash::~Open_Hash() {
	T.erase(T.begin(), T.end());
	status.erase(status.begin(), status.end());

	return;
}

Open_Hash& Open_Hash::operator=( const Open_Hash &other ) {
	Open_Hash temp(other);
	std::swap(m, temp.m);
	std::swap(num_entries, temp.num_entries);
	std::swap(T, temp.T);
	std::swap(status, temp.status);

	return *this;
}

bool Open_Hash::insert( long key, std::string caller ) {
	long tst_idx = this->search( key );
	if ( ( this->is_full() ) || ( ( T[tst_idx].get_key() == key ) && ( status[tst_idx] == "occupied" ) ) ) {
		return false;
	}
	// hash function
	long x = key%m;
	long cnt = 0;
	double k = key;
	double m_t = m;
	int ratio = floor(k/m_t);
	long offs = ratio%m + (1-(ratio%m)%2);
	if ( offs == 0 ) {
		offs++;
	}
	while ( ( status[x] == "occupied" ) && ( cnt < m ) ) {
		if ( T[x].get_key() == key ) {
			return false;
		}
		x += offs;
		x = x%m;
		cnt++;
	}

	if ( cnt == m ) {
		return false;
	} else {
		T[x].set_key(key);
		T[x].set_caller(caller);
		status[x] = "occupied";
		num_entries++;
	}

	return true;
}

long Open_Hash::search( long key ) {
	// hash function
	long x = key%m;
	long cnt = 0;
	double k = key;
	double m_t = m;
	int ratio = floor(k/m_t);
	long offs = ratio%m + (1-(ratio%m)%2);
	if ( offs == 0 ) {
		offs++;
	}
	while ( ( ( status[x] == "occupied" ) || ( status[x] == "deleted" ) ) && ( cnt < m ) && ( T[x].get_key() != key) ) {
		x += offs;
		x = x%m;
		cnt++;
	}
	return x;

}

bool Open_Hash::remove( long key ) {
	// hash function
	long x = key%m;
	long cnt = 0;
	double k = key;
	double m_t = m;
	int ratio = floor(k/m_t);
	long offs = ratio%m + (1-(ratio%m)%2);
	if ( offs == 0 ) {
		offs++;
	}
	while ( ( ( status[x] == "occupied" ) || ( status[x] == "deleted" ) ) && ( cnt < m ) && ( T[x].get_key() != key) ) {
		x += offs;
		x = x%m;
		cnt++;
	}

	if ( ( cnt == m ) || ( key != T[x].get_key() ) ) {

		return false;
	} else {
		T[x].set_key(0);
		T[x].set_caller("");
		status[x] = "deleted";
		num_entries--;
		return true;
	}
}

long Open_Hash::get_size() {
	return m;
}

bool Open_Hash::is_empty() {
	if ( num_entries == 0 ) {
		return true;
	}
	return false;
}

bool Open_Hash::is_full() {
	if ( num_entries == m ) {
		return true;
	}
	return false;
}

