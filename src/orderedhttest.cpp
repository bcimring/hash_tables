/*
 * orderedhttest.cpp
 *
 *  Created on: Sep 26, 2020
 *      Author: BCimr
 */

#include "Node.h"
#include "Linked_List.h"
#include "Ordered_Hash.h"
#include "iostream"
#include "string"

void display( Ordered_Hash H ) {
	std::cout << "Current Table:" << std::endl;
	for ( long i = 0; i < H.get_size(); i++ ) {
		Node* p_temp = H.T[i].get_head();
		std::cout << i << '\t';
		while ( p_temp != nullptr ) {
			std::cout << p_temp->get_data() << '\t' << p_temp->get_caller() << '\t';
			p_temp = p_temp->get_p_next();
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return;
}

bool instr( std::string txt, char m ) {
	for ( unsigned int i = 0; i < txt.length(); i++ ) {
		if ( txt[i] == m ) {
			return true;
		}
	}
	return false;
}

long str2int( std::string string ) {
	long result{};
	bool dec_flag = false;
	double div{1.0};

	for ( int i = 0; i < string.length(); i++ ) {
		if ( string[i]-46 == 0 ) {
			dec_flag = true;
		} else if (string[i] == '\n') {
			break;
		} else {
			result = result*10 + string[i]-48;
			if ( dec_flag ) {
				div *= 10;
			}
		}
	}
	return result/div;
}

int main() {

	Ordered_Hash H = Ordered_Hash(0);
	std::string line {};
	bool instantiated = false;


	while ( !std::cin.eof() )  {
		getline(std::cin, line);

		if ( line == "exit" ) {
			return 0;
		}

		if ( line[line.size()-1] == '\r' ) {
			line = line.substr(0, line.size()-1);
		}

		int instant_idx = line.find("n")+1;
		int insert_idx = line.find("i")+1;
		int search_idx = line.find("s")+1;
		int delete_idx = line.find("d")+1;
		int print_idx = line.find("p")+1;
		int exit_idx = line.find("exit")+1;

		if (instant_idx == 1) {
			long sof_idx{}, eof_idx{}, m{};
			if ( line[2] == '-' ) {
				std::cout << "failure" <<std::endl;

			} else {
				sof_idx = 2;
				eof_idx = line.length();
				m = str2int( line.substr(sof_idx, eof_idx-sof_idx) );
				//H.~Ordered_Hash();
				if ( ( m < 0 )  || ( instr( line.substr( sof_idx, eof_idx-sof_idx ), '.' ) ) ) {
					std::cout << "failure" << std::endl;
				} else {
					Ordered_Hash F = Ordered_Hash( m );
					H = F;
					instantiated = true;
					std::cout << "success" << std::endl;
				}
			}

		} else if (instantiated) {
			if (insert_idx == 1) {
				long sof_key{}, eof_key{};
				sof_key = 2;
				eof_key = line.find( ";", 0 );
				long key = str2int( line.substr( sof_key, eof_key-sof_key ));
				if ( ( key < 0 ) || ( instr( line.substr( sof_key, eof_key-sof_key ), '.' ) ) ) {
					std::cout << "failure" << std::endl;
				} else {
					std::string caller = line.substr( eof_key + 1, line.length() - eof_key-1 );
					bool success = H.insert( key, caller );
					if (success) {
						std::cout << "success" << std::endl;
					} else {
						std::cout << "failure" << std::endl;
					}
				}

			} else if (delete_idx == 1) {
				long key = str2int( line.substr( 2, line.length()-2 ));
				if ( ( key < 0 ) || ( instr( line.substr( 2, line.length()-2 ), '.' ) ) ) {
					std::cout << "failure" << std::endl;
				} else {
					bool success = H.remove( key );
					if (success) {
						std::cout << "success" << std::endl;
					} else {
						std::cout << "failure" << std::endl;
					}
				}

			} else if (search_idx == 1) {
				long key = str2int( line.substr( 2, line.length()-2 ));
				if ( ( key < 0 ) || ( instr( line.substr( 2, line.length()-2 ), '.' ) ) ) {
					std::cout << "failure" << std::endl;
				} else {
					Node* entry = H.search( key );
					if (entry != nullptr) {
						std::cout << "found " << entry->get_caller() << " in " << key%H.get_size() << std::endl;
					} else {
						std::cout << "not found" << std::endl;
					}
				}


			} else if (print_idx == 1) {
				if ( line[2] == '-' ) {
					std::cout << "failure" << std::endl;
				} else {
					long x = str2int( line.substr( 2, line.length()-2 ));
					if ( ( x < 0 ) || ( instr( line.substr( 2, line.length()-2 ), '.') ) || ( x > H.get_size() ) ) {

					} else {
						H.print_row(x);
					}
				}
			} else if (exit_idx == 1) {
				break;
			}
		} else if ( exit_idx != 0 ) {
			break;

		} else {
			std::cout << "failure" << std::endl;
		}
	}
	return 0;

}


