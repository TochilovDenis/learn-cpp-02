//+класс Student с полями имя, фамилия, группа и id(неповторяющийся)
//+класс StudentsList, который хранит список студентов.
//+добавляет студента в список функцией Add(Student s)
//+выводит весь список студентов
//Выводит список студентов по фамилии
//выводит список студентов по имени
//Создайте 200 студентов
//выведите всех судентов по какой-нибудь одной фамилии
//выведите всех студентов по какому нибудь имени

#include <iostream>
#include <vector>
using namespace std;

class Student{
	string name;
	string surname;
	string group;
	int id;
public:
	Student(string n, string sn, string g, int i) : name(n), surname(sn), group(g), id(i) {}
	~Student() {}
	
	string Name()    const { return name; }
	string Surname() const { return surname; }
	string Group()   const { return group; }
	int ID()         const { return id; }

	void Name(string value)    { name = value; }
	void Surname(string value) { surname = value; }
	void Group(string value)   { group = value; }
	void ID(int value)         { id = value; }

	bool operator<(const Student& other) const {
		return surname + name < other.surname + other.name;
	}
	
	string GetString() const {
		return "Name: " + Name() + "Surname: " + Surname() + "Group: " + Group() + "Id: " + ID();	}
	
	void Print() const {
		cout << GetString() << endl'
	}
};

class StudentsList{
	vector<Students> students;
public:
	void Add(const Student& s){
		students.push_back(s);
	}
	
	void PrintAll() const {
		for(const auto& student : students){
			cout << students.Print() << endl;
		}
	}
	
	void PrintBySurname(const string& surname) const {
		for(const auto& student: students){
			if(student.Surname() == surname){
				cout << students.Print() << endl;
			}
		}
	}

        void PrintByName(const std::string& name) const {
		for (const auto& student : students) {
            		if (student.Name() == name) {
                		cout << students.Print() << endl;
			}
		}
	}
};

int main() {
    StudentsList studentsList;
    for (int i = 0; i < 200; ++i) {
        studentsList.Add(Student("Денис", "Точилов", "ИНФО-01", i));
    }

    studentsList.PrintAll();

    studentsList.PrintBySurname("Точилов");

    studentsList.PrintByName("Денис");

    return 0;
}
