#include <iostream>
#include <string>
#include <vector>
class Worker {
	int id, age;
	std::string name, gender, job_title, department;
public:
	Worker() {
		id = 1;
		name = "малюкова Ксения Игоревна";
		gender = "Женский";
		age = 17;
		job_title = "Программист";
		department = "1";
	}
	Worker(int _id) :Worker() { id = _id; }
	Worker(int _id, std::string _name) :Worker(_id) { name = _name; }
	Worker(int _id, std::string _name, std::string _gender) :Worker(_id, _name) { gender = _gender; }
	Worker(int _id, std::string _name, std::string _gender, int _age) :Worker(_id, _name, _gender) { age = _age; }
	Worker(int _id, std::string _name, std::string _gender, int _age, std::string _job_title) :Worker(_id, _name, _gender, _age) { job_title = _job_title; }
	Worker(int _id, std::string _name, std::string _gender, int _age, std::string _job_title, std::string _department) :Worker(_id, _name, _gender, _age, _job_title) { department = _department; }


	void printWorker() {
		std::cout << "id: " << id << "\n" << "Name: " << name << "\n" << "Gender: " << gender << "\n"<< "Age: " << age << "\n" << "Position: " << job_title << "\n" << "Department: " << department << "\n";
	}
	void editWorker(std::string new_name, std::string new_gender, int new_age, std::string new_job_title, std::string new_department) {
		name = new_name;
		gender = new_gender;
		age = new_age;
		job_title = new_job_title;
		department = new_department;
	}
	void setId(int new_id) {
		id = new_id;
	}
	int getId() {
		return id;
	}
};
int main() {
	system("chcp 1251");
	std::vector<Worker>workers;
	int choice, current_id = 1;

	do {
		system("pause");
		system("cls");
		std::cout << "1. Создать рабочего\n" << "2. Редактировать рабочего\n"<< "3. Вывести рабочих\n" << "4. удалить рабочего\n" << "5. Выход\n" << "Введите действие: "; std::cin >> choice;

		switch (choice) {
		case 1: {
			int id = 0, age = 0;
			std::string name, gender, job_title, department;
			std::cout << "enter name for worker: "; std::cin.ignore(); std::getline(std::cin, name);
			std::cout << "enter gender for worker: "; std::cin >> gender; std::cin.ignore();
			std::cout << "enter age: "; std::cin >> age;
			std::cout << "enter position: "; std::getline(std::cin, job_title);
			std::cout << "enter depatment: "; std::cin >> department;

			Worker new_worker;
			new_worker.setId(current_id++);
			workers.push_back(new_worker);
			std::cout << "Рабочий добавлен успешно!\n";
			break;
		}
		case 2: {
			int id;
			std::cout << "Введите id рабочего для редактирования: "; std::cin >> id;
			for (int i = 0; i < workers.size(); i++) {
				if (id == workers.at(i).getId()) {
					int id = 0, age = 0;
					std::string name, gender, job_title, department;
					std::cout << "enter new name: "; std::cin.ignore(); std::getline(std::cin, name);
					std::cout << "enter new gender for worker: ";std::cin >> gender;
					std::cout << "enter new age: "; std::cin >> age;
					std::cout << "enter new position: "; std::cin.ignore(); std::getline(std::cin, job_title);
					std::cout << "enter new depatment: "; std::cin >> department;
					workers.at(i).editWorker(name, gender, age, job_title, department);
					std::cout << "Рабочий отредактирован успешно!\n";
					break;
				}
			}
			break;
		}
		case 3: {
			for (int i = 0; i < workers.size(); i++) {
				workers.at(i).printWorker();
			}
			break;
		}
		case 4: {
			int id = 0;
			std::cout << "enter worker ID to delete:";
			std::cin >> id;

			for (int i = 0; i < workers.size(); i++) {
				workers.erase(workers.begin(), workers.end());
			}
			std::cout << "worker deleted successfully!!\n";
		}
		default:
			std::cout << "error.\n";
			break;
		}
	} while (choice != 0);
	return 0;
}