#include <iostream>
using namespace std;

class SimpleArray {
private:
    int* arr;
    int len;

public:
    SimpleArray(int n) {
        len = n;
        arr = new int[len];
        for (int i = 0; i < len; i++) {
            arr[i] = 0;
        }
    }

    ~SimpleArray() {
        delete[] arr;
    }

    void set(int* values, int count) {
        for (int i = 0; i < len && i < count; i++) {
            arr[i] = values[i];
        }
    }

    void add(SimpleArray& other) {
        for (int i = 0; i < len; i++) {
            if (i < other.len) {
                arr[i] = arr[i] + other.arr[i];
            }
        }
    }

    void sub(SimpleArray& other) {
        for (int i = 0; i < len; i++) {
            if (i < other.len) {
                arr[i] = arr[i] - other.arr[i];
            }
        }
    }

    void show() {
        cout << "[";
        for (int i = 0; i < len; i++) {
            cout << arr[i];
            if (i < len - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
};

int main() {
    SimpleArray a(5);
    SimpleArray b(3);
    SimpleArray c(4);

    int vals1[] = { 1, 2, 3, 4, 5 };
    int vals2[] = { 10, 20, 30 };
    int vals3[] = { 5, 5, 5, 5 };

    a.set(vals1, 5);
    b.set(vals2, 3);
    c.set(vals3, 4);

    cout << "Initial arrays:" << endl;
    cout << "a: "; a.show();
    cout << "b: "; b.show();
    cout << "c: "; c.show();

    cout << "a + b:" << endl;
    a.add(b);
    a.show();

    cout << "a - c:" << endl;
    a.sub(c);
    a.show();

    return 0;
}