#include <iostream>
#include<string>
#define mod 1000000007
#define max 100010
using namespace std;

int main() {
	int leftNumP[max] = { 0 };
	string str;
	cin >> str;
	int len = str.length();
	for (int i = 0; i < len; i++) {
		if (i > 0)leftNumP[i] = leftNumP[i - 1]; //继承上一位的结果
		if (str[i] == 'P') leftNumP[i]++;
	}
	int ans = 0, rightNumT = 0;
	for (int i = len - 1; i >= 0; i--) {
		if (str[i] == 'T') rightNumT++;
		else if (str[i] == 'A') {
			ans = (ans + leftNumP[i] * rightNumT) % mod;
		}
	}
	printf("%d", ans);
	return 0;
}
