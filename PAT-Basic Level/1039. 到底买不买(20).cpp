#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	string g, n;
	cin >> g >> n;
	map<char, int>m;
	for (int i = 0; i < g.length(); i++) {
		m[g[i]]++;
	}
	bool ans = true;
	int d=0; //不够的话，差的个数
	for (int i = 0; i < n.length(); i++) {
		if (m[n[i]] != 0) {
			m[n[i]]--;
		}
		else {
			ans = false;
			d++;
		}
	}
	if (ans) {
		printf("Yes");
		int sum=0; //够的话，多的个数；
		for (auto it = m.begin(); it != m.end(); it++) {
			sum += it->second;
		}
		printf(" %d", sum);
	}
	else {
		printf("No %d",d);
	}
	return 0;
}
