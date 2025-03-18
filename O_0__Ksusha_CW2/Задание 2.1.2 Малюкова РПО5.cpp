#include <iostream>
#include <string>
#include <vector>

class Company {
private:
    std::string name;
    int income, expenses, turnover, net_profit;
    bool type;    //true - государ

public:
    
    Company() {
        std::string name = " ";
        income = 0, expenses = 0;
        turnover = income + expenses;
        net_profit = income - expenses;
    }
    Company(std::string name, int income, int expenses, bool type) : name(name), income(income), expenses(expenses), type(type) {
        turnover = income + expenses;
        net_profit = income - expenses;
    }

    void setName(std::string new_name) {
        name = new_name;
    }

    void setIncome(int new_income) {
        income = new_income;
        turnover = income + expenses;
        net_profit = income - expenses;
    }

    void setExpenses(int new_expenses) {
        expenses = new_expenses;
        turnover = income + expenses;
        net_profit = income - expenses;
    }

    std::string getName() const {
        return name;
    }

    int getIncome() const {
        if (type) {
            std::cout << "Доходы государственной компании недоступны" << std::endl;
            return 0;
        }
        if (turnover < 5000000) {
            std::cout << "Доходы компании с оборотом менее 5 миллионов рублей недоступны" << std::endl;
            return 0;
        }
        return income;
    }

    int getExpenses() const {
        if (type) {
            std::cout << "Расходы государственной компании недоступны" << std::endl;
            return 0;
        }
        if (turnover < 5000000) {
            std::cout << "Расходы компании с оборотом менее 5 миллионов рублей недоступны" << std::endl;
            return 0;
        }
        return expenses;
    }

    int getNetProfit() const {
        if (type) {
            std::cout << "Чистая прибыль государственной компании недоступна" << std::endl;
            return 0;
        }
        if (turnover < 5000000) {
            std::cout << "Чистая прибыль компании с оборотом менее 5 миллионов рублей недоступна" << std::endl;
            return 0;
        }
        return net_profit;
    }

    int getTurnover() const {
        if (turnover < 5000000) {
            std::cout << "Оборот компании с оборотом менее 5 миллионов рублей недоступна" << std::endl;
            return 0;
        }
        return turnover;
    }

    std::string getType() const {
        return (type?"Государстенная":"Частная");
    }

    void displayCompanies()  {
            std::cout << "Название: " << getName() << std::endl;
            std::cout << "Тип: " << getType() << std::endl;
            std::cout << "Оборот: " << getTurnover() << std::endl;
            std::cout << "Доходы: " << getIncome() << std::endl;
            std::cout << "Расходы: " << getExpenses() << std::endl;
            std::cout << "Чистая прибыль: " << getNetProfit() << std::endl << std::endl;
    }
};


int main() {
    system("chcp 1251");
    std::vector<Company> company_vect;
    
    company_vect.push_back(Company("ООО Муслимкина хрюшка", 30000000, 1000000, false));
    company_vect.push_back(Company("Газпром", 100000000, 9000000, true));
    for (size_t i = 0; i < company_vect.size(); i++)
    {
    company_vect.at(i).displayCompanies();
    }

    return 0;
}