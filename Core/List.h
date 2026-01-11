#ifndef UNTITLED_LIST_H
#define UNTITLED_LIST_H

struct List {
private:
    int size = 100;
    int *array;
    int currentPosition;
    void Shrink();
public:
    List();
    void Add(int item);
    [[nodiscard]] int Get(int item) const;
    int &operator[](int item) const;
    void RemoveAt(int index);
    ~List();
};


#endif //UNTITLED_LIST_H
