#include <iostream>
#include <stdlib.h> // for qsort

#include "Sortings.hpp"
#include "Benchmark.hpp"

using namespace Sortings;

typedef void (*f_t1)(int*, int); 		// function type1
typedef void (*f_t2)(int*, int, int);   // function type2

void TestsCall(int argc, char* argv[]); 
void CheckInputs(int argc, char* argv[]); 
	
int main(int argc, char* argv[])
{	
	try {
	CheckInputs(argc, argv);
	TestsCall(argc, argv);
	} catch (const char* msg) {
		std::cout << msg << std::endl;
	}

	return 0;
}

void TestsCall(int argc, char* argv[]) {

	int size = atoi(argv[1]);
	int tests_count = atoi(argv[2]);	
	int* array = RandomArrayGenerator(size);
	
	std::string function_name[] = { "BubbleSort   ", "InsertionSort", "SelectionSort",
	"ShellSort    ", "HeapSort     ", "RadixSort    ", "STLQuickSort ", "QuickSort    ", "MergeSort    " };
	f_t1 array_of_sorts1[]={ BubbleSort, InsertionSort, SelectionSort,
							ShellSort, HeapSort, RadixSort, STLQuickSort };	
	f_t2 array_of_sorts2[] = { QuickSort , MergeSort }; 

	if (2 <= tests_count) {
		PrintDesign();	
	}

	for (int i = 0, j = 0; i < 8; ++i) {
		if (i < 6) {	
			std::cout << function_name[i] << "  ";		
			Testing1(array, size, array_of_sorts1[i], tests_count);
		} else {
			std::cout << function_name[i] << "  ";		
			Testing2(array, 0, size - 1, array_of_sorts2[j], tests_count);
			++j;
		}
	}
	delete[] array;
}

void CheckInputs(int argc, char* argv[]) {
	if (3 != argc) {
		throw "Error: Please, enter the size of array and tests count.";
	}
	
	if (3 < atoi(argv[2]) || atoi(argv[2]) < 1) {
		throw "Warning: The count of tests should be less than 4.";
	}

	if (10000 < atoi(argv[1])) {
		std::cout << "Please Wait ..." << std::endl;
	}
}

