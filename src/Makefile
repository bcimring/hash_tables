all: openhtdriver orderedhtdriver
openhtdriver: openhttest.cpp
	g++ -std=c++11 -o openhtdriver openhttest.cpp Open_Hash_Definitions.cpp Open_Hash_Elems_Definitions.cpp
orderedhtdriver: orderedhttest.cpp
	g++ -std=c++11 -o orderedhtdriver orderedhttest.cpp Ordered_Hash_Definitions.cpp Linked_List_Definitions.cpp Node_Definitions.cpp
clean:
	rm openhtdriver
	rm orderedhtdriver