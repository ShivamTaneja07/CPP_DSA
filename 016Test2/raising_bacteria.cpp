#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int count = 0;
    while (x > 0) {
        if (x & 1) {
        count++;
    }
        x >>= 1;
    }

    cout << count;
    return 0;
}