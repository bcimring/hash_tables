/*
 * Linked_List.cpp
 *
 *  Created on: Sep 26, 2020
 *      Author: BCimr
 */

#include "Linked_List.h"
#include "Node.h"
#include "iostream"
#include "cmath"

Linked_List::Linked_List( long n, long Nodes[], std::string callers[] ) {
	size = n;
	p_head = new Node( nullptr, nullptr, Nodes[0], callers[0] );
	Node* p_temp = new Node( nullptr, nullptr, Nodes[1], callers[1] );
	Node* p_temp2 = p_head;
	for ( int i = 2; i < n; i++ ) {
		p_temp2->set_p_next( p_temp );
		p_temp->set_p_last( p_temp2 );
		p_head = p_temp2;

		p_temp2 = p_temp;
		p_temp = new Node( nullptr, nullptr, Nodes[i], callers[i] );
	}

	p_tail = p_temp;
}

Linked_List::Linked_List( ) {
	p_head =  nullptr;//new Node( nullptr, nullptr, 0, " " );
	size = 0;
	p_tail = p_head;
}

Linked_List::Linked_List( const Linked_List &other) {
	size = other.size;

	if ( other.p_head != nullptr ) {
		Node* p_temp2{ other.p_head->get_p_next() };
		p_head = new Node( nullptr, nullptr, other.p_head->get_data(), other.p_head->get_caller() );
		Node* p_temp1{ p_head };


		while ( ( p_temp1 != nullptr ) && ( p_temp2 != nullptr ) ) {
			p_temp1->set_p_next( new Node( nullptr, p_temp1, p_temp2->get_data(), p_temp2->get_caller() ) );

			p_temp1 = p_temp1->get_p_next();
			p_temp2 = p_temp2->get_p_next();
		}
		p_tail = p_temp1;

	} else {
		p_head = nullptr;
		p_tail = nullptr;
	}

}

Linked_List& Linked_List::operator=( const Linked_List &other ) {
	// Inspired heavily by Tiuley Alguindigue's implementation of Linked_List class
	// from Linked_List.cpp at source: <https://learn.uwaterloo.ca/d2l/le/content/597415/viewContent/3219333/View>

	Linked_List temp(other);
	std::swap(size, temp.size);
	if ( temp.p_head != nullptr ) {
		std::swap(p_head, temp.p_head);
		std::swap(p_tail, temp.p_tail);
	} else {
		p_head = nullptr;
		p_tail = nullptr;
	}


	return *this;
}


Linked_List::~Linked_List() {
	while (p_head != nullptr ) {
		Node *p_temp_head{ this->get_head() };

		p_head = get_head()->get_p_next();
		delete p_temp_head;
		p_temp_head = nullptr;
	}

}

long Linked_List::get_size() {
	return size;
}

Node* Linked_List::get_head() {
	return p_head;
}

Node* Linked_List::get_tail() {
	return p_tail;
}

bool Linked_List::operator==( Linked_List other ) {
	Node* p_temp1 = this->get_head();
	Node* p_temp2 = other.get_head();
	bool eq = true;

	while ( ( p_temp1 != nullptr ) && ( p_temp2 != nullptr ) ) {
		if ( fabs(p_temp1->get_data() - p_temp2->get_data()) > 0.00000000001 ) {
			eq = false;

			break;
		}
		p_temp1 = p_temp1->get_p_next();
		p_temp2 = p_temp2->get_p_next();
	}

	if ( ( p_temp1 != nullptr ) || ( p_temp2 != nullptr ) ) {
		eq = false;
	}

	return eq;
}

bool Linked_List::is_empty() {
	return (size == 0);
}

bool Linked_List::insert( Node* to_insert ) {
	if ( size == 0 ) {
		this->set_head( to_insert );
		to_insert->set_p_last( nullptr );
		to_insert->set_p_next( nullptr );
		this->set_tail( to_insert );
		size++;

	} else {
		Node* p_temp = this->get_head();
		while ( ( p_temp->get_data() < to_insert->get_data() ) && ( p_temp != p_tail ) ) {

			p_temp = p_temp->get_p_next();

		}
		if ( p_temp->get_data() == to_insert->get_data() ) {
			return false;
		}
		if ( ( p_temp == p_tail ) && ( p_temp->get_data() <= to_insert->get_data() ) ) {
			p_temp->set_p_next( to_insert );
			to_insert->set_p_last( p_temp );
			p_tail = to_insert;

		} else {
			if ( p_temp == p_head ) {
				p_head = to_insert;
				to_insert->set_p_next( p_temp );
				p_temp->set_p_last( p_head );
				p_head->set_p_last( nullptr );
			} else {
				p_temp->get_p_last()->set_p_next( to_insert );
				to_insert->set_p_last( p_temp->get_p_last() );
				to_insert->set_p_next( p_temp );
				p_temp->set_p_last( to_insert );
			}
		}
		size++;
	}

	return true;
}

bool Linked_List::remove( long to_delete ) {
	Node* p_temp = this->get_head();

	while (p_temp != nullptr ) {
		if (p_temp->get_data() == to_delete) {
			break;
		}
		p_temp = p_temp->get_p_next();
	}

	if ( p_temp != nullptr ) {
		if ( p_temp == p_tail ) {
			if ( p_temp == p_head ) {
				delete p_head;
				p_head = nullptr;
			} else {
				p_tail = p_tail->get_p_last();
				delete p_tail->get_p_next();
				p_tail->set_p_next( nullptr );
			}
		} else if ( p_temp == p_head ) {
			p_head = p_head->get_p_next();
			delete p_head->get_p_last();
			p_head->set_p_last( nullptr );
		} else {
			p_temp->get_p_next()->set_p_last( p_temp->get_p_last() );
			p_temp->get_p_last()->set_p_next( p_temp->get_p_next() );
			delete p_temp;
		}
		size--;
		return true;

	}

	return false;
}

Node* Linked_List::search( long data ) {
	Node* p_temp = this->get_head();
	while ( (p_temp != nullptr) && ( p_temp->get_data() != data ) ) {
		p_temp = p_temp->get_p_next();
	}

	return p_temp;
}

void Linked_List::set_head( Node* new_head ) {
	p_head = new_head;
	return;
}

void Linked_List::set_tail( Node* new_tail ) {
	p_tail = new_tail;
	return;
}





