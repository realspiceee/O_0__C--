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
		std::cout << "���: " << getName() << std::endl;
		std::cout << "�������: " << getAge() << std::endl;
		std::cout << "����� ��������: " << getStudyClass() << std::endl;
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

	students.push_back(Student("�����", 17, 11));
	students.push_back(Student("����", 14, 8));
	students.push_back(Student("�����", 15, 9));

	do {
		system("pause"); system("cls");
		std::cout << "1. �������� ��������\n" << "2. ������� ��������\n" << "3. �������������� ��������\n" << "4. ������� ���� ���������\n" << "5. ������� ��������������� ���������\n" << "0. �����\n" << "�������� ��������: "; std::cin >> choice;

		switch (choice) {
		case 1: {
			std::string name;
			int age, study_class;
			std::cout << "������� ��� ��� ������ ��������: "; std::cin.ignore(); std::getline(std::cin, name);
			std::cout << "������� ��� �������: "; std::cin >> age;
			std::cout << "������� �����, � ������� �� ���������: "; std::cin >> study_class;
			students.push_back(Student(name, age, study_class));
			std::cout << "������� ������� ��������!\n";
			break;
		}
		case 2: {
			int id = 0;
			std::cout << "������� ID ��������, �������� ������ �������: "; std::cin >> id;
			bool found = false;
			for (int i = 0; i < students.size(); i++) {
				if (students.at(i).getId() == id) {
					students.erase(students.begin() + i);
					found = true;
					std::cout << "������� � ID - " << id << " ������� �����!\n";
				}
			}
			break;
		}
		case 3: {
			int id;
			std::cout << "������� ID ��������, �������� ������ �������������: ";
			std::cin >> id;
			bool found = false;
			for (int i = 0; i < students.size(); i++) {
				if (students.at(i).getId() == id) {
					found = true;
					std::string name;
					int age;
					int study_class;
					std::cout << "������� ���: " << students.at(i).getName() << ". ������� ����� ���: ";
					std::cin.ignore();
					std::getline(std::cin, name);
					students.at(i).setName(name);
					std::cout << "������� �������: " << students.at(i).getAge() << ". ������� ����� �������: ";
					std::cin >> age;
					students.at(i).setAge(age);
					std::cout << "������� �����: " << students.at(i).getStudyClass() << ". ������� ����� �����: ";
					std::cin >> study_class;
					students.at(i).setStudyClass(study_class);
					std::cout << "������� � ID - " << id << " �������!\n";
					break;
				}
			}
			if (!found) {
				std::cout << "������� �� ������.\n";
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
			std::cout << "��������������� �������� �� ��������: \n";
			for (int i = 0; i < students.size(); i++) {
				sortStudent(students);
				students.at(i).displayStudent();
			}
			break;
		}
		case 0: {
			std::cout << "����� �� ���������.\n";
			break;
		}
		default:
			std::cout << "������ �����. ���������� ��� ���." << std::endl;
			break;
		}
	} while (choice != 0);
	return 0;
}