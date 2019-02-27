#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int k;
	scanf("%d", &k);
	vector<int>v(k);
	for (int i = 0; i < k; i++) scanf("%d", &v[i]);
	sort(v.begin(), v.end(), cmp);
	int c[1000010] = { 0 };  //未验证为0，已验证为1,不知道3n+1多大，就尽可能给多点
	for (int i = 0; i < k; i++) {
		int t = v[i];
		while (t != 1) {
			if (t % 2 == 0) {
				t = t / 2;
				c[t] = 1;
			}
			else {
				t = (3 * t + 1) / 2;
				c[t] = 1;
			}
		}
	}
	int flag = false;
	for (int i = 0; i < k; i++) {
		if (c[v[i]] == 0) {
			if (flag) printf(" ");
			printf("%d", v[i]);
			flag = true;
		}
	}

	return 0;
}
