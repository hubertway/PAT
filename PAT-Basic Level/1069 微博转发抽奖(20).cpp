#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main() {
	int m, n, s;
	scanf("%d %d %d", &m, &n, &s);
	vector<string>v(m + 1);
	map<string, bool>e; //是否领过奖
	for (int i = 1; i <= m; i++) {
		cin >> v[i];
		e[v[i]] = false;
	}
	if (m < s)printf("Keep going...\n");
	else {
		cout << v[s] << endl;
		e[v[s]] = true;
		int i = s + n;
		while (i <= m) {
			if (!e[v[i]]) {
				cout << v[i] << endl;
				e[v[i]] = true;
				i += n;
			}
			else i++; //已经抽过了，顺次下取一位
		}
	}

	return 0;
}
