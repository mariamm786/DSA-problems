#include <iostream>
using namespace std;

int main() {
    int n = 4;
    for (int i = 0; i < n; i++) {
        char ch='A';
        for (int j = 1; j < n; j++) {
            cout<<ch;
            ch = ch+1;
        }
        cout << endl;
    }
    return 0;
}

