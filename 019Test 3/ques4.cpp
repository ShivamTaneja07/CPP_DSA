#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long arr[100005];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        long long temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    long long waitingt = 0;
    int goodt = 0;

    for (int i = 0; i < n; i++) {
        if (waitingt <= arr[i]) {
            goodt++;
            waitingt += arr[i];
        } else {
            break;
        }
    }

    cout << goodt;
    return 0;
}
