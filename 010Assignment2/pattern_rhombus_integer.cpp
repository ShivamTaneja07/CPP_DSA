#include <iostream>
using namespace std;
int main (){
	int n ;
	cin >> n;
	

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n-i; j++){
			cout << "  ";
		}
		int num = i;
		for(int j = 1; j <= i;j++){
			cout << num << " ";
			num++;
		}
		 num = 2 * i - 2;
		for(int j = 2; j <= i; j++){
			cout << num << " ";
			num--;

		}
		cout<<endl;

	}
	for (int i = n - 1; i>= 1; i--){
		for(int j = 1; j <= n - i; j++){
		 	cout <<"  ";
		}
		int num = i;
		for(int j = 1; j <= i;j++){
			cout << num << " ";
			num++;
		}
		 num = 2 * i - 2;
		for(int j = 2; j <= i; j++){
			cout << num << " ";
			num--;

		}
		cout<<endl;

	}


	return 0;
}