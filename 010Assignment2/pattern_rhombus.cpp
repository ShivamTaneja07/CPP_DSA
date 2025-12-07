#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n / 2 + 1 ; i++){
		for(int j = 1; j <= ( n / 2 ) - i + 1 ; j++) {
			cout << "  ";
		}
		for(int j = 1; j <= i ; j++){
			cout << j << " ";
		}
		for(int j = i-1; j >= 1; j--){
			cout << j << " ";
		}
		cout << endl;
	}
	for (int i = 1; i <= n / 2; i++ ){
		for(int j = 1; j <= i ; j++){
			cout << "  ";
		}
		for(int j = 1; j <= n - i - 2 ; j++){
			cout << j << " ";
		}
		for(int j = (n/2) - i ; j >= 1 ; j--){
        cout << j << " ";
    }
		
		cout<<endl;
	}
	return 0;
}