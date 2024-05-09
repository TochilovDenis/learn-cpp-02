#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;

const string names[] = { "Денис", "Александр", "Никита", "Алексей", "Дмитрий" };
const string surnames[] = { "Точилов", "Михайлов", "Сердитов", "Кузнецов", "Морозов" };
const string groups[] = { "311", "22", "343", "24", "545" };

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

	friend ostream& operator<<(ostream& os, const Student& student) {
    		os << student.GetString(student);
    		return os;
	}
	static string GetString(const Student& sttudent) {
		string idStr = to_string(student.ID());
 		(idStr.length() > 3) ? idStr = idStr.substr(idStr.length() - 3) :
     			idStr = string(3 - idStr.length(), ' ') + idStr;
 		string formattedName    = student.Name();
 		string formattedSurname = student.Surname();
 		string formattedGroup   = student.Group();

 		ostringstream oss;
 		oss << " | Имя: "     << left << setw(9) << formattedName 
		    << " | Фамилия: " << setw(9) << formattedSurname 
		    << " | Группа: "  << setw(4) << formattedGroup 
		    << " | ID: "      << setw(3) << idStr << " |\n";
	       	return oss.str();	
	}
};

class StudentsList{
	vector<Student> students;
public:
	void Add(const Student& s){
		students.push_back(s);
	}
	
	void PrintAll() const {
		for(const auto& student : students){
			cout << student << endl;
		}
	}
	
	void PrintBySurname(const string& surname) const {
		for(const auto& student: students){
			if(student.Surname() == surname){
				cout << student << endl;
			}
		}
	}

        void PrintByName(const std::string& name) const {
		for (const auto& student : students) {
            		if (student.Name() == name) {
                		cout << student << endl;
			}
		}
	}
};

int main() {
	setlocale(LC_ALL, "");
 	srand(time(0));
	StudentsList studentsList;
 	for (int i = 1; i <= 200; ++i) {
     		int nameIndex = rand() % 5;
     		int surnameIndex = rand() % 5;
     		int groupIndex = rand() % 5;
     		int idIndex = rand() % 200;
     		studentsList.Add(Student(names[nameIndex], surnames[surnameIndex], groups[groupIndex], idIndex));
 	}
 	cout << "--Список студента--\n\n";
 	studentsList.PrintAll();
 	cout << "\n--Поиск Фамилия--\n\n";
 	studentsList.PrintBySurname("Точилов");
 	cout << "\n--Поиск Имя-- \n\n";
 	studentsList.PrintByName("Денис");
 	return 0;
}
