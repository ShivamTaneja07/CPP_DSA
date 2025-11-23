#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int maxC = 0;
    int current = 0;

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        current = current - a;
        current = current + b;
        if (current > maxC) maxC = current;
    }

    cout << maxC ;
    return 0;
}