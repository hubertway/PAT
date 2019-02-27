#include <iostream>
#include <string>
using namespace std;

char h[13] = { '0','1','2','3','4','5','6','7','8','9','J','Q','K' };
int main() {
	string A, B;
	cin >> A >> B;
	int i = A.size() - 1;
	int j = B.size() - 1;

	if (i > j) {
		int l = i - j;
		string x;
		for (int a = 0; a < l; a++) x += '0';
		B = x + B;
	}
	if (i < j) {
		int l = j - i;
		string x;
		for (int a = 0; a < l; a++) x += '0';
		A = x + A;
		i = j;
	}
	int t;
	int d = 1;
	while (i >= 0) {
		if (d % 2 != 0) { //奇数位
			t = ((B[i] - '0') + (A[i] - '0')) % 13;
			B[i] = h[t];
		}
		else {
			t = B[i] - A[i];
			if (t < 0) t += 10;
			B[i] = h[t];
		}
		d++;
		i--;
	}
	cout << B;

	return 0;
}
