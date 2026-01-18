

#include "List.h"
#include <iostream>
#include <cstring>

List::List() {
    currentPosition = -1;
    array = new int[size];
}


void List::Add(const int item) {
    currentPosition++;
    if (currentPosition == size) {
        Expand();
    }
    array[currentPosition] = item;
}

void List::RemoveAt(int const index) {
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

int List::Get(const int item) const {
    if (item > currentPosition)
        throw std::out_of_range("Index out of range");
    return array[item];
}

int &List::operator[](const int item) const {
    if (item > currentPosition)
        throw std::out_of_range("Index out of range");
    return array[item];
}


void List::Shrink() {
    if (size==1)
        return;
    size = size / 2;
    const auto newArray = new int[size];
    memcpy(newArray, array, size * sizeof(int));
    delete[] array;
    array = newArray;
}

void List::Expand() {
    size = size * 2;
    const auto newArray = new int[size];
    memcpy(newArray, array, size * sizeof(int));
    delete[] array;
    array = newArray;
}

int List::Count() const {
    return currentPosition+1;
}

List::~List() {
    delete[] array;
}
