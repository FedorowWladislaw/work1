#include <iostream>
using namespace std;

bool checkValue(int value) {
    return value >= -100 && value <= 100;
}

void addToArray(int*& array, int& currentSize, int& maxSize, int newValue) {
    if (!checkValue(newValue)) {
        cout << "ERROR! Number " << newValue << " must be between -100 and 100!" << endl;
        return;
    }

    if (currentSize >= maxSize) {
        int newMaxSize = maxSize * 2;
        int* newArray = new int[newMaxSize];

        for (int i = 0; i < currentSize; i++) {
            newArray[i] = array[i];
        }

        delete[] array;
        array = newArray;
        maxSize = newMaxSize;

        cout << "Array expanded to " << maxSize << " elements" << endl;
    }

    array[currentSize] = newValue;
    currentSize++;
    cout << "Added number: " << newValue << endl;
}

void showArray(int* array, int size) {
    cout << "Array: [";
    for (int i = 0; i < size; i++) {
        cout << array[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    int maxSize = 4;
    int currentSize = 0;
    int* numbers = new int[maxSize];

    addToArray(numbers, currentSize, maxSize, 25);
    addToArray(numbers, currentSize, maxSize, -75);
    addToArray(numbers, currentSize, maxSize, 88);
    addToArray(numbers, currentSize, maxSize, -42);

    showArray(numbers, currentSize);
    cout << "Size: " << currentSize << "/" << maxSize << endl;

    addToArray(numbers, currentSize, maxSize, 67);
    showArray(numbers, currentSize);
    cout << "Size: " << currentSize << "/" << maxSize << endl;

    addToArray(numbers, currentSize, maxSize, 125);
    addToArray(numbers, currentSize, maxSize, -150);

    addToArray(numbers, currentSize, maxSize, 99);
    showArray(numbers, currentSize);

    delete[] numbers;

    return 0;
}