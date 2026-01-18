#include <iostream>
#include <cassert>
#include "Core/List.h"
using namespace std;

void Test_AddAndExpand() {
    std::cout << "Test: Add ve Expand... ";
    List list;
    for (int i = 1; i <= 5; i++) {
        list.Add(i * 10);
    }
    assert(list.Count() == 5);
    assert(list[0] == 10);
    assert(list[4] == 50);
    std::cout << "SUCCESSFUL" << std::endl;
}
void Test_ElementShifting() {
    std::cout << "Test: Element Shifting (Kaydirma)... ";
    List list;


    list.Add(10);
    list.Add(20);
    list.Add(30);
    list.Add(40);
    list.Add(50);

    list.RemoveAt(1);

    assert(list.Count() == 4);
    assert(list[0] == 10);
    assert(list[1] == 30);
    assert(list[2] == 40);
    assert(list[3] == 50);

    std::cout << "SUCCESSFUL" << std::endl;
}
void Test_RemoveAndShrink() {
    std::cout << "Test: Remove ve Shrink... ";
    List list;

    for (int i = 0; i < 20; i++) list.Add(i);


    for (int i = 18; i >10; i--) {
        list.RemoveAt(i);
    }

    assert(list.Count() == 12);
    std::cout << "SUCCESSFUL" << std::endl;
}

void Test_Exceptions() {
    std::cout << "Test: Exception Handling... ";
    List list;
    list.Add(10);
    try {
        auto a = list.Get(2);
    } catch (const std::out_of_range& e) {
        std::cout << "SUCCESSFUL" << std::endl;
    }


}

int main() {
    Test_AddAndExpand();
    Test_RemoveAndShrink();
    Test_Exceptions();
    Test_ElementShifting();
    return 0;
}
