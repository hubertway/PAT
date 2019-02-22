#include <iostream>
#include <vector>
using namespace std;
int main() {
	int a, b, r;
	cin >> a >> b >> r;
	long d = a + b;
	vector<int>v;
	do {
		int y = d % r;
		v.push_back(y);
		d /= r;
	} while (d);
	for (int i = v.size()-1; i >= 0; i--) 
		printf("%d", v[i]);
	return 0;
}
