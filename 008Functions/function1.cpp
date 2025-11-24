// #include <iostream>
// using namespace std;
// bool iseven(int n){
// 	if( n%2 == 0){
// 		return true;
// 	}
// 	else {
// 		return false;
// 	}
// }
// int main(){
// 	int n;
// 	cin >> n;
// 	if(iseven(n)){
// 		cout<<"even";
// 	}
// 	else cout<<"odd";
// 	return 0;
// }



// #include <iostream>
// using namespace std;
// void myswap(int& a, int& b){
// 	int temp = a;
// 	a = b;
// 	b = temp;
// }
// int main(){
// 	int a, b;
// 	cin >> a >> b;
// 	myswap(a, b);
// 	cout << a << " " << b << endl;
// 	return 0;
// }

// #include <iostream>
// using namespace std;
// bool prime(int n){
// 	if(n <= 1) return false;
// 	if(n == 2) return true;
// 	if(n % 2 == 0) return false;
// 	for(int i = 3;i*i <= n/2;i++){
// 		if(n%i == 0) return false;
// 	}
// 	return true;
// }
// int main(){
// 	int n;
// 	cin >> n;
// 	prime(n) ? cout << "prime"<<endl : cout << "notprime"<< endl;
// 	return 0;
// }

// #include <iostream>
// using namespace std;
// bool prime(int n){
// 	if(n <= 1) return false;
// 	if(n == 2) return true;
// 	if(n % 2 == 0) return false;
// 	for(int i = 3;i*i <= n/2;i++){
// 		if(n%i == 0) return false;
// 	}
// 	return true;
// }
// void printprime(int n){
// 	for(int i = 3; i <= n; i++){
// 		if(prime(i)) {
// 			cout << i << " ";
// 		}
// 	}
// }
// int main(){
// 	int n;
// 	cin >> n;
// 	printprime(n);
// 	return 0;
// }

