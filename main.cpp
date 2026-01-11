#include <iostream>
using namespace std;


struct List {
private:
    int size = 100;
    int *array;
    int currentPosition;

    void Shrink() {
        if (size < 200)
            return;
        size = size / 2;
        const auto newArray = new int[size];
        memcpy(newArray, array, size * sizeof(int));
        free(array);
        array = newArray;
    }

public:
    List() {
        currentPosition = -1;
        array = new int[size];
    }

    void Add(const int item) {
        currentPosition++;
        if (currentPosition == size) {
            size = size * 2;
            const auto newArray = new int[size];
            memcpy(newArray, array, size * sizeof(int));
            free(array);
            array = newArray;
        }
        array[currentPosition] = item;
    }

    [[nodiscard]] int Get(const int item) const {
        if (item > currentPosition)
            throw std::out_of_range("Index out of range");
        return array[item];
    }
    int& operator[](const int item) const {
        if (item > currentPosition)
            throw std::out_of_range("Index out of range");
        return array[item];
    }
    void RemoveAt(int const index) {
        if (index < 0 || index >= currentPosition) throw std::out_of_range("Index out of range");
        currentPosition--;
        const int *source = &array[index + 1];
        int *destination = &array[index];
        if (const int elementsToMove = currentPosition - index - 1; elementsToMove > 0) {
            memmove(destination, source, elementsToMove * sizeof(int));
        }
        if (static_cast<float>(currentPosition) / static_cast<float>(size) <= 0.2) {
            this->Shrink();
        }
    }

    ~List() {
        free(array);
    }
};


int main() {
    List l1;
    for (int i = 0; i < 100; i++) {
        l1.Add(i);
    }
    cout << l1[99] << endl;
    cout << l1.Get(2) << endl;
    try {
        cout<<l1[100]<<endl;

    } catch (out_of_range &e) {
        cout << e.what() << endl;
    }
    try {
        l1.RemoveAt(100);
    } catch (out_of_range &e) {
        cout<< e.what()<<endl;
    }
    return 0;
}
