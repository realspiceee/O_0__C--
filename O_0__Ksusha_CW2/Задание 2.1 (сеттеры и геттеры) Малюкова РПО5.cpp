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

	Planet& setName(std::string _name) { 
		name = _name;
		return *this;
	}
	Planet& setTemp(float _temp) {
		temp = _temp;
		return *this;
	}
	Planet& setDiameter(float _diameter) {
		diameter = _diameter;
		return *this;
	}
	std::string getName() const { return name; }
	float getTemp() const { return temp; }
	float getDiameter() const { return diameter; }

	
};
std::vector <Planet> sort(std::vector<Planet> planets) {
		for (int i = 0; i < planets.size(); ++i) {
			for (int j = 0; j < planets.size() - i - 1; ++j) {
				if (planets[j].getTemp() > planets[j + 1].getTemp()) {
					std::swap(planets[j], planets[j + 1]);
				}
			}
		}
		return planets;
	}
int main() {
	system("chcp 1251");
	std::vector<Planet>planets;

	planets.push_back(Planet("Меркурий", 167, 4879));
	planets.push_back(Planet("Венера", 464, 12104));
	planets.push_back(Planet("Земля", 15, 12756));
	planets.push_back(Planet("Марс", -65, 6794));
	for (int i = 0; i < planets.size(); i++) planets.at(i).printPlanet();
	std::cout << "-------------------" << std::endl;
	planets = sort(planets);
	for (int i = 0; i < planets.size(); i++) planets.at(i).printPlanet();
} 