#include <iostream>
#include <math.h>
#include <map>
#include <stack>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	map<int, int>m; //<差值，次数>
	int x;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		m[fabs(x - i)]++;
	}
	stack<pair<int ,int> >s;
	for (auto it = m.begin(); it != m.end(); it++) { //map默认从小到大排的
		if (it->second > 1) {
			s.push(make_pair(it->first, it->second));
		}
	}
	pair<int, int>p;
	while (!s.empty()) {
		p = s.top();
		cout << p.first << " " << p.second << endl;
		s.pop();
	}
	return 0;
}
