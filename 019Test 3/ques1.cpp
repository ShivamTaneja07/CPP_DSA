#include <iostream>
using namespace std;
int minimumswap(int arr[], int n){
	int max_H = arr[0], min_H = arr[0];
	int maxIndex = 0;
	int minIndex = 0;

	for (int i = 0 ; i < n ; i++){
		if (arr[i] > max_H){
			max_H = arr[i];
			maxIndex = i;
		}
	}
	for (int i = 0 ; i < n ; i++){
		if (arr[i] <= min_H){
			min_H = arr[i];
			minIndex = i;
		}
	}
	int swaps = maxIndex + (n - 1 - minIndex);

	if (maxIndex > minIndex){
		swaps--;
	}
	return swaps;
}
int main (){
	int n ;
	cin >> n;
	int arr[100];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	cout << minimumswap(arr, n);
	return 0;
}