#include <iostream>
#include <string>
#include <vector>

class Student {
	std::string name;
	static int amount_of_student;
	int id;
public:
	Student() {
		id = amount_of_student++; age = 1; study_class = 1;
		name = " ";
	}
	Student(std::string _name, int _age, int _study_class) : name(_name), age(_age), study_class(_study_class), id(amount_of_student++) {}

	std::string getName() const { return name; }
	int getId() const { return id; }
	int getAge() const { return age; }
	int getStudyClass() const { return study_class; }

	Student& setName(std::string new_name) { name = new_name; return *this; }
	Student& setAge(int new_age) { age = new_age; return *this; }
	Student& setStudyClass(int new_study_class) { study_class = new_study_class; return *this; }

	void displayStudent() {
		std::cout << "ID: " << getId() << std::endl;
		std::cout << "Имя: " << getName() << std::endl;
		std::cout << "Возраст: " << getAge() << std::endl;
		std::cout << "Класс обучения: " << getStudyClass() << std::endl;
	}
};
	void sortStudent(std::vector<Student>& students) {
		for (int i = 0; i < students.size() - 1; i++) {
			for (int j = 0; j < students.size() - i - 1; j++) {
				if (students.at(j).getAge() < students.at(j + 1).getAge()) {
					Student tmp = students.at(j);
					students.at(j) = students.at(j + 1);
					students.at(j + 1) = tmp;
				}
			}
		}
	}

int Student::amount_of_student = 0;

int main() {
	system("chcp 1251");
	std::vector<Student>students;
	int choice;

	students.push_back(Student("Ксюша", 17, 11));
	students.push_back(Student("Лиля", 14, 8));
	students.push_back(Student("Арина", 15, 9));

	do {
		system("pause"); system("cls");
		std::cout << "1. Добавить студента\n" << "2. Удалить студента\n" << "3. Редактирование студента\n" << "4. Вывести всех студентов\n" << "5. Вывести отсортированных студентов\n" << "0. Выход\n" << "Выберите действие: "; std::cin >> choice;

		switch (choice) {
		case 1: {
			std::string name;
			int age, study_class;
			std::cout << "Введите имя для нового студента: "; std::cin.ignore(); std::getline(std::cin, name);
			std::cout << "Введите его возраст: "; std::cin >> age;
			std::cout << "Введите класс, в котором он обучается: "; std::cin >> study_class;
			students.push_back(Student(name, age, study_class));
			std::cout << "Студент успешно добавлен!\n";
			break;
		}
		case 2: {
			int id = 0;
			std::cout << "Введите ID студента, которого хотите удалить: "; std::cin >> id;
			bool found = false;
			for (int i = 0; i < students.size(); i++) {
				if (students.at(i).getId() == id) {
					students.erase(students.begin() + i);
					found = true;
					std::cout << "Студент с ID - " << id << " успешно удалён!\n";
				}
			}
			break;
		}
		case 3: {
			int id;
			std::cout << "Введите ID студента, которого ходите редактировать: ";
			std::cin >> id;
			bool found = false;
			for (int i = 0; i < students.size(); i++) {
				if (students.at(i).getId() == id) {
					found = true;
					std::string name;
					int age;
					int study_class;
					std::cout << "Текущее имя: " << students.at(i).getName() << ". Введите новое имя: ";
					std::cin.ignore();
					std::getline(std::cin, name);
					students.at(i).setName(name);
					std::cout << "Текущий возраст: " << students.at(i).getAge() << ". Введите новый возраст: ";
					std::cin >> age;
					students.at(i).setAge(age);
					std::cout << "Текущий класс: " << students.at(i).getStudyClass() << ". Введите новый класс: ";
					std::cin >> study_class;
					students.at(i).setStudyClass(study_class);
					std::cout << "Студент с ID - " << id << " изменен!\n";
					break;
				}
			}
			if (!found) {
				std::cout << "Студент не найден.\n";
			}
			break;
		}
		case 4: {
			for (int i = 0; i < students.size(); i++) {
				students.at(i).displayStudent();
			}
			break;
		}
		case 5: {
			std::cout << "Отсортированные студенты по возрасту: \n";
			for (int i = 0; i < students.size(); i++) {
				sortStudent(students);
				students.at(i).displayStudent();
			}
			break;
		}
		case 0: {
			std::cout << "Выход из программы.\n";
			break;
		}
		default:
			std::cout << "Ошибка ввода. Попробуйте ещё раз." << std::endl;
			break;
		}
	} while (choice != 0);
	return 0;
}