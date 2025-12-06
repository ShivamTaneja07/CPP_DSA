#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++){
		int num = 1;
		for (int j = 1; j <= i; j++){
			cout << num <<" ";
			num++;
		}
		for (int j = 1; j <= n-i; j++){
			cout<<"*" <<" ";
		}
		cout<<endl;
	}

	return 0;
}