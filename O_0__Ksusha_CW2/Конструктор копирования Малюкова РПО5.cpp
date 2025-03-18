#include <iostream>

class DynamicArray {
	int* arr;
public:
	DynamicArray(){
		std::cout << "Объект создан";
	}
	~DynamicArray() {
		std::cout << "Объект удалён";
	}
	void printInfo() {
		std::cout << arr;
	}
	
};
