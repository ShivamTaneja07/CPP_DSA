#include <iostream>
using namespace std;
int main (){
	int n;
	cin >> n;
	string previous, current;
	int grp = 0;
	for(int i = 1; i <= n; i++){
		cin >> current;
		if(i == 1 or current != previous){
			grp++;
			previous = current;
		}
	}
	cout << grp;
	return 0;
}