#include <iostream>

class DynamicArray {
	int* arr;
public:
	DynamicArray(){
		std::cout << "������ ������";
	}
	~DynamicArray() {
		std::cout << "������ �����";
	}
	void printInfo() {
		std::cout << arr;
	}
	
};
