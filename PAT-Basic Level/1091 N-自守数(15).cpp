#include <iostream>
#include <vector>
using namespace std;

int main() {
	int m;
	cin >> m;
	vector<int>v(m);
	for (int i = 0; i < m; i++) cin >> v[i];
	for (int i = 0; i < m; i++) {
		int t = v[i];
		int d = 1;  
		while (t) {
			d *= 10;
			t /= 10;
		}
		bool flag = false;
		int x = 1;
		while (x < 10 ) {
			if (x * v[i] * v[i] % d == v[i]) {
				flag = true;
				break;
			}
			x++;
		}
		if (flag) cout << x << " " << x* v[i] * v[i] << endl;
		else cout << "No" << endl;
	}
	return 0;
}
