#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	int  n;
	scanf("%d", &n);
	vector<int>v(n);
	for (int i = 0; i < n; i++)scanf("%d", &v[i]);

	set<int>s;
	for (int i = 0; i < n; i++) {
		int num = v[i];
		int d; //正整数的每一位。
		int f=0; //朋友证号
		while (num) {
			d = num % 10;
			f += d;
			num /= 10;
		}
		s.insert(f);
	}
	printf("%d\n", s.size());
	for (auto it = s.begin(); it != s.end(); it++) {
		if (it != s.begin()) printf(" ");
		printf("%d", *it);
	}

	return 0;
}
