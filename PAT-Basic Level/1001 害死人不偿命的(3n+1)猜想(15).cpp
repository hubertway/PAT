#include <iostream>
using namespace std;

int main() {
	int n, cnt = 0;
	cin >> n;
	while (n != 1 && n!=0) {
		if (n % 2 == 0) {
			n = n / 2;
			cnt++;
		}
		else {
			n = (3 * n + 1) / 2;
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
