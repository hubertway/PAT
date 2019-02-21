#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin , s);
	int N = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'A'&&s[i] <= 'Z') N = N + (s[i] - 'A' + 1);
		if (s[i] >= 'a'&&s[i] <= 'z') N = N + (s[i] - 'a' + 1);
	}
	int one = 0, zero = 0;

	while (N){
		if (N % 2) one++;
		else zero++;
		N /= 2;
	 } 

	printf("%d %d", zero, one);
	return 0;
}
