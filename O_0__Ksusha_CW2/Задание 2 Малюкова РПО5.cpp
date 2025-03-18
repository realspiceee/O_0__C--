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
		std::cout << "��������: " << name << "\n" << "�����������: " << temp << "\n" << "�������: " << diameter << "\n";
	}
};

int main() {
	system("chcp 1251");
	std::vector<Planet>planets;

	planets.push_back(Planet("��������", 167, 4879));
	planets.push_back(Planet("������", 464, 12104));
	planets.push_back(Planet("�����", 15, 12756));
	planets.push_back(Planet("����", -65, 6794));
	for (size_t i = 0; i < planets.size(); i++) {
		planets.at(i).printPlanet();
	}
}