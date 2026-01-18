#include <iostream>
#include <cassert>
#include "Core/List.h"
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

void Benchmark() {
    const int N = 100000; // 100 bin eleman

    // --- 1. SENIN LIST SINIFIN TESTI ---
    List myList;
    auto start = high_resolution_clock::now();

    for (int i = 0; i < N; i++) {
        myList.Add(i);
    }

    auto stop = high_resolution_clock::now();
    auto durationListAdd = duration_cast<milliseconds>(stop - start);

    // --- 2. STD::VECTOR TESTI ---
    vector<int> myVector;
    start = high_resolution_clock::now();

    for (int i = 0; i < N; i++) {
        myVector.push_back(i);
    }

    stop = high_resolution_clock::now();
    auto durationVectorAdd = duration_cast<milliseconds>(stop - start);

    // SONUÇLARI YAZDIR
    cout << "--- Performans Sonuclari (100.000 Eleman) ---" << endl;
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
    Benchmark();
    // Test_AddAndExpand();
    // Test_RemoveAndShrink();
    // Test_Exceptions();
    // Test_ElementShifting();
    return 0;
}
