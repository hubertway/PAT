令P~i~表示第i个素数。现任给两个正整数M <= N <= 10^4^，请输出P~M~到P~N~的所有素数。

输入格式：
输入在一行中给出M和N，其间以空格分隔。

输出格式：
输出从P~M~到P~N~的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。

输入样例：
5 27
输出样例：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103

code:
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
