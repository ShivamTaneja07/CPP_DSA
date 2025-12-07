#include <iostream>
#include <vector>
using namespace std;
int main (){
	int t;
	cin>>t;
	while(t--){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int maxzero = 0;
	int currzero = 0;

	for (int i = 0; i < n; i++){
		if(arr[i]==0){
			currzero++;
		}
		else{
			maxzero=max(maxzero,currzero);
			currzero = 0;
		}
	}
	maxzero = max(maxzero, currzero);
	cout << maxzero << "\n";
}

	return 0;
}