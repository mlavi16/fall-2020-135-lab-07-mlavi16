/*
    Test:
      1. Open/close brackets on same line.
      2. Nested loops.
*/
#include <iostream>
using namespace std;

int main(){
    // Hi, I'm a program!
    int x = 1; 
    for(int i = 0; i < 10; i++) {
        cout << i;
        cout << endl;
        for(int i = 0; i < 10; i++) {}
            cout << i;
        for (int i = 0; i < 10; i++) {
            cout << "i";
        }
        cout << "hello";
        }
    for(int i = 0; i < 10; i++) { for(int i = 0; i < 10; i++){ cout << i; }
        cout << i;
    }

    cout << "i";
}