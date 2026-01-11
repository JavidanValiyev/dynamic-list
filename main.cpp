#include <iostream>

#include "Core/List.h"
using namespace std;


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
