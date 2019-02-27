#include <iostream>
#include <map>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	map<int, int>m;
	for (int i = 1; i <= n; i++) {
		m[i / 2 + i / 3 + i / 5]++;
	}
	printf("%d", m.size());
	return 0;
}
