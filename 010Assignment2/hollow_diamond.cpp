#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            for (int j = 1; j <= 2*n - 1; j++) cout << "*";
        } else {
            int stars = n - i + 1;
            int spaces = 2*i - 3;

            for (int j = 1; j <= stars; j++) cout << "*";

            for (int j = 1; j <= spaces; j++) cout << " ";

            for (int j = 1; j <= stars; j++) cout << "*";
        }
        cout << "\n";
    }
    for (int i = n-1; i >= 1; i--) {
        if (i == 1) {
            for (int j = 1; j <= 2*n - 1; j++) cout << "*";
        } else {
            int stars = n - i + 1;
            int spaces = 2*i - 3;

            for (int j = 1; j <= stars; j++) cout << "*";

            for (int j = 1; j <= spaces; j++) cout << " ";

            for (int j = 1; j <= stars; j++) cout << "*";
        }
        cout << "\n";
    }
}
