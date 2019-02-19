#include <iostream>
#include <string>
using namespace std;

char h[13] = { '0','1','2','3','4','5','6','7','8','9','J','Q','K' };
int main() {
	string A, B;
	cin >> A >> B;
	int i = B.size() - 1;
	int j = A.size() - 1;
	int t;
	while ((i >= 0) && (j >= 0)) {
		t = ((B[i] - '0') + (A[j] - '0')) % 13;
		B[i] = h[t];
		i--; j--;
		if (!((i >= 0) && (j >= 0))) break;
		t = B[i] - A[j] ;
		if (t < 0) t += 10;
		B[i] = h[t];
		i--; j--;
	}
	cout << B;

	return 0;
}
