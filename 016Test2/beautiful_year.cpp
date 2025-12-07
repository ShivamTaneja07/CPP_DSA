#include <iostream>
using namespace std;

bool distinct(int y) {
    int a = y % 10; 
    y /= 10;
    int b = y % 10; 
    y /= 10;
    int c = y % 10; 
    y /= 10;
    int d = y % 10;

    return a != b && a != c && a != d && b != c && b != d && c != d;
}

int main() {
    int y;
    cin >> y;
    while (true) {
        y++;
        if (distinct(y)) {
            cout << y;
            break;
        }
    }

    return 0;
}
