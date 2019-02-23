#include <iostream>
#include <string>
using namespace std;

int main() {
	string p;
	int n;
	cin >> p >> n;
	getchar();
	int cnt = 0;
	string s;
	bool flag = false;
	while (1){
		getline(cin,s);
		 if (s == "#") break;
		 cnt++;
		 if (s == p) {
			 printf("Welcome in\n");
			 break;
		 }
		 else  if (s != p) {
			 cout << "Wrong password: " << s << endl;
			 if (cnt == n) {
				 printf("Account locked\n");
				 break;
			 }
		 }
	 } 	
	return 0;
}
