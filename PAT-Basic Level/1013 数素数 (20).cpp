#include<iostream>
#include<vector>
using namespace std;
bool isPrime(int a) {
	if (a == 2) return true;
	bool ans = true;
	for (int i = 2; i*i <= a; i++) {
		if (a%i == 0) {
			ans = false;
			break;
		}
	}
	return ans;
}
int m, n;
int main() {
	cin >> m >> n;
	vector<int>p;
	int cnt = 0;
	for (int i = 2;;i++) {
		if (isPrime(i)) {
			cnt++;
			p.push_back(i);
		}
		if (cnt > n) break;
	}
	int flag = 0;
	for (int i = m-1; i < n; i++) {
		if (flag)printf(" ");
		printf("%d", p[i]);
		flag++;
		if (flag == 10) {
			printf("\n");
			flag = 0;
		}
	}
	return 0;
}
