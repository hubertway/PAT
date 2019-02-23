#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int>v(n);
	for (int i = 0; i < n; i++) scanf("%d", &v[i]);

	sort(v.begin(), v.end());
	int maxLength = v[0];
	for (int i = 1; i < n; i++) {
		maxLength = (maxLength + v[i]) / 2;
	}

	printf("%d", maxLength);
	return 0;
}
