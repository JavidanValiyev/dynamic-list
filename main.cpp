#include <iostream>
#include <cassert>
#include "Core/List.h"
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

void BenchmarkRemove() {
    const int N = 2000000;
    const int targetIndex = 500000;

    List myList;
    for (int i = 0; i < N; i++) myList.Add(i);

    auto start = high_resolution_clock::now();
    myList.RemoveAt(targetIndex);
    auto stop = high_resolution_clock::now();

    auto durationList = duration_cast<microseconds>(stop - start);

    vector<int> myVector;
    for (int i = 0; i < N; i++) myVector.push_back(i);

    start = high_resolution_clock::now();
    myVector.erase(myVector.begin() + targetIndex);
    stop = high_resolution_clock::now();

    auto durationVector = duration_cast<microseconds>(stop - start);


    cout << "       --- 2.000.000 items, Deleting element from middle of list ---" << endl;
    cout << "List::RemoveAt (memmove):  " << durationList.count() << " us (microsecond)" << endl;
    cout << "Vector::erase:             " << durationVector.count() << " us (microsecond)" << endl;
}
void Benchmark() {
    const int N = 1000000;
    List myList;
    auto start = high_resolution_clock::now();

    for (int i = 0; i < N; i++) {
        myList.Add(i);
    }
    auto stop = high_resolution_clock::now();
    const auto durationListAdd = duration_cast<milliseconds>(stop - start);
    vector<int> myVector;
    start = high_resolution_clock::now();

    for (int i = 0; i < N; i++) {
        myVector.push_back(i);
    }

    stop = high_resolution_clock::now();
    const auto durationVectorAdd = duration_cast<milliseconds>(stop - start);
    cout << "       --- Performance Results (100.000 Items) ---" << endl;
    cout << "List::Add:    " << durationListAdd.count() << " ms" << endl;
    cout << "Vector::push_back: " << durationVectorAdd.count() << " ms" << endl;
}
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
    std::cout << "Test: Element Shifting... ";
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
    cout << "-------------------------------------------------------------------"<<endl;
    Benchmark();
    cout << "-------------------------------------------------------------------"<<endl;
    BenchmarkRemove();
    cout << "-------------------------------------------------------------------"<<endl;
    Test_AddAndExpand();
    cout << "-------------------------------------------------------------------"<<endl;
    Test_RemoveAndShrink();
    cout << "-------------------------------------------------------------------"<<endl;
    Test_Exceptions();
    cout << "-------------------------------------------------------------------"<<endl;
    Test_ElementShifting();
    cout << "-------------------------------------------------------------------"<<endl;
    return 0;
}
