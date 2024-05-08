#include <iostream>
#include <string>
using namespace std;
int main() {
    setlocale(LC_ALL, "");
    string name;
    cout << "Введите ваше имя: ";
    getline(std::cin, name);

    for (int i = name.length() - 1; i >= 0; --i) {
        cout << name[i];
    }
    cout << endl;

    return 0;
}
