#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPal(string s) {
	bool flag = true;
	int len = s.length();
	for (int i = 0; i < len/2; i++) {
		if (s[i] != s[len - 1 - i]) {
			flag = false;
			break;
		}		
	}
	return flag;
}

int main() {
	string s;
	cin >> s;
	int cnt = 0;
	if (isPal(s))cout << s << " is a palindromic number." << endl;
	else {
		while (!(isPal(s))  && cnt <10){
			string t; //s的逆序
			for (int i = s.length()-1; i >= 0; i--) t += s[i];
			string sum; //s+t的结果,现实反过来的
			int r=0, d;		//进位、数值
			for (int x = s.length()-1; x >= 0; x--) {
				d = (s[x] - '0') + (t[x] - '0') + r;
				if (d > 9) {
					r = d / 10;
					d = d % 10;
				} 
				else r = 0;
				char c = d + '0';  //将0~9的int转换为char
				sum += c;
			}
			if (r) {
				char cr = r + '0';
				sum = sum +cr ;
			}
			reverse(sum.begin(), sum.end());
			cout << s << " + " << t << " = " << sum << endl;
			cnt++;
			s = sum;
		}
		if (cnt == 10) printf("Not found in 10 iterations.\n");
		else  cout << s << " is a palindromic number." << endl;
	}

	return 0;
}

/*
string转换函数：
stoi Convert string to integer 
stol Convert string to long int 
stoul Convert string to unsigned integer 
stoll Convert string to long long 
stoull Convert string to unsigned long long
stof Convert string to float 
stod Convert string to double 
stold Convert string to long double 
*/
