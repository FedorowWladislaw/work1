#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* data;
    int size;

public:
    DynamicArray(int arraySize) {
        size = arraySize;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = 0;
        }
    }

    ~DynamicArray() {
        delete[] data;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void setValue(int index, int value) {
        if (index < 0 || index >= size) {
            cout << "Error: index out of bounds!" << endl;
            return;
        }

        if (value < -100 || value > 100) {
            cout << "Error: value must be between -100 and 100!" << endl;
            return;
        }

        data[index] = value;
    }

    int getValue(int index) {
        if (index < 0 || index >= size) {
            cout << "Error: index out of bounds!" << endl;
            return 0;
        }

        return data[index];
    }

    void fillFromUser() {
        cout << "Enter " << size << " array elements (values from -100 to 100):" << endl;
        for (int i = 0; i < size; i++) {
            int value;
            cout << "Element [" << i << "]: ";
            cin >> value;
            setValue(i, value);
        }
    }
};

int main() {
    int size;

    cout << "Enter array size: ";
    cin >> size;

    DynamicArray arr(size);

    arr.fillFromUser();

    cout << "Your array: ";
    arr.print();

    int index;
    cout << "Enter element index to view: ";
    cin >> index;
    cout << "Element with index " << index << ": " << arr.getValue(index) << endl;

    cout << "Enter element index to modify: ";
    cin >> index;
    int value;
    cout << "Enter new value: ";
    cin >> value;
    arr.setValue(index, value);

    cout << "Updated array: ";
    arr.print();

    return 0;
}