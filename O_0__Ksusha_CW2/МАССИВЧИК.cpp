#include <iostream>
#include <string>
#include <vector>

int main() {
	std::vector <std::string> str_vect = { "hello", "world" };
	for (int i = 0; i < str_vect.size(); i++){ std::cout << i + 1 << " " << str_vect.at(i) << std::endl; }
}               