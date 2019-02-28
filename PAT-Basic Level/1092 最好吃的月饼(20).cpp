#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;  
	cin >> n >> m;
	vector<int>v(n + 1, 0);
	for (int i = 0; i < m; i++) {
		for (int j = 1; j <= n; j++) {
			int sale;
			cin >> sale;
			v[j] += sale;
		}
	}
	int max = -1;
	for (int i = 1; i <= n; i++) {
		if (max < v[i]) max = v[i];
	}
	cout << max << endl;
	bool flag = false;
	for (int i = 1; i <= n; i++) {
		if (v[i] == max) {
			if (flag)printf(" ");
			cout << i;
			flag = true;
		}
	}

	return 0;
}
