/*
 * openhttest.cpp
 *
 *  Created on: Sep 26, 2020
 *      Author: BCimr
 */

#include "Open_Hash.h"
#include "Ordered_Hash.h"
#include "iostream"
#include "string"
#include "bitset"

void display( Open_Hash H ) {
	std::cout << "Current Table:" << std::endl;
	for ( long i = 0; i < H.get_size(); i++ ) {
		std::cout << i << '\t' << H.T[i].get_key() << '\t'  << H.T[i].get_caller()  << '\t' << H.status[i] << std::endl;
	}
	std::cout << std::endl;
	return;
}

bool in_str( std::string txt, char m ) {
	for ( unsigned int i = 0; i < txt.length(); i++ ) {
		if ( txt[i] == m ) {
			return true;
		}
	}
	return false;
}

double str2double( std::string string ) {
	double result{};
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
/*
int main() {

	Open_Hash H = Open_Hash(0);
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
		int exit_idx = line.find("exit")+1;

		if (instant_idx == 1) {
			long sof_idx{}, eof_idx{}, m{};
			if ( line[2] == '-' ) {
				std::cout << "failure" <<std::endl;

			} else {
				sof_idx = 2;
				eof_idx = line.length();
				m = str2double( line.substr(sof_idx, eof_idx-sof_idx) );
				if ( ( m < 0 )  || ( in_str( line.substr( sof_idx, eof_idx-sof_idx ), '.' ) ) ) {
					std::cout << "failure" << std::endl;
				} else {
					H = Open_Hash( m );
					instantiated = true;

					std::cout << "success" << std::endl;
				}
			}

		} else if (instantiated) {
			if (insert_idx == 1) {
				long sof_key{}, eof_key{};
				sof_key = 2;
				eof_key = line.find( ";", 0 );
				long key = str2double( line.substr( sof_key, eof_key-sof_key ));
				if ( ( key < 0 ) || ( in_str( line.substr( sof_key, eof_key-sof_key ), '.' ) ) ) {
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
				long key = str2double( line.substr( 2, line.length()-2 ));
				if ( ( key < 0 ) || ( in_str( line.substr( 2, line.length()-2 ), '.' ) ) ) {
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
				long key = str2double( line.substr( 2, line.length()-2 ));
				if ( ( key < 0 ) || ( in_str( line.substr( 2, line.length()-2 ), '.' ) ) ) {
					std::cout << "failure" << std::endl;
				} else {
					long idx = H.search( key );
					if (H.T[idx].key == key) {
						std::cout << "found " << H.T[idx].get_caller() << " in " << idx << std::endl;
					} else {
						std::cout << "not found" << std::endl;
					}
				}

			} else if (exit_idx == 1) {
				break;
			} else {
				std::cout << "failure" << std::endl;
			}
		} else if ( exit_idx == 1 ) {
			break;

		} else {
			std::cout << "failure" << std::endl;
		}
	}
	return 0;

}

*/
