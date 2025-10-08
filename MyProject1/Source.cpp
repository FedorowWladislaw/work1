#include <iostream>
#include <string>

using namespace std;

class Cat {
private:
    string name;
    int age;
    string color;
    double weight;

public:
    Cat(const string& n, int a, const string& c, double w)
        : name(n), age(a), color(c), weight(w) {
    }

    Cat(const Cat& other)
        : name(other.name), age(other.age), color(other.color), weight(other.weight) {
    }

    void displayInfo() const {
        cout << "���: " << name << ", �������: " << age
            << ", ����: " << color << ", ���: " << weight << " ��" << endl;
    }

    void setName(const string& newName) {
        name = newName;
    }

    void setAge(int newAge) {
        age = newAge;
    }
};

int main() {
    setlocale(LC_ALL, "RU");

    Cat originalCat("������", 3, "�����", 4.5);
    originalCat.displayInfo();

    Cat copiedCat(originalCat);
    copiedCat.displayInfo();

    copiedCat.setName("������");
    copiedCat.setAge(1);

    originalCat.displayInfo();
    copiedCat.displayInfo();

    return 0;
}