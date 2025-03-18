#include <iostream>
#include <string>
#include <vector>

class Planet {
	std::string name;
	float temp, diameter;

public:
	Planet(std::string name, float temp, float diameter) {
		this->name = name;
		this->temp = temp;
		this->diameter = diameter;
	}

	void printPlanet() {
		std::cout << "Название: " << name << "\n" << "Температура: " << temp << "\n" << "Диаметр: " << diameter << "\n";
	}
};

int main() {
	system("chcp 1251");
	std::vector<Planet>planets;

	planets.push_back(Planet("Меркурий", 167, 4879));
	planets.push_back(Planet("Венера", 464, 12104));
	planets.push_back(Planet("Земля", 15, 12756));
	planets.push_back(Planet("Марс", -65, 6794));
	for (size_t i = 0; i < planets.size(); i++) {
		planets.at(i).printPlanet();
	}
}