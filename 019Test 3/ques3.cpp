#include <iostream>
using namespace std;
int main (){
	int n ;
	cin >> n;
	int arr[105];
	int sum = 0;
	for (int i = 0; i < n; i++){
		cin >> arr[i];
		sum += arr[i];
	}

	for (int i = 0; i < n - 1; i++){
		for(int j = 0 ; j < n - 1 - i ; j++){
			if (arr[j] < arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j + 1] = temp;
			}
		}
	}
	int newsum = 0;
	int count = 0;
	for(int i = 0; i < n; i++){
		newsum += arr[i];
		count++;
		if(newsum > sum - newsum){
			break;
		}
	}
	cout << count;
	return 0;

}