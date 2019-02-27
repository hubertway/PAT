#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int c = a * b;
	bool flag = false;  //用来过滤第一个0
	while (c) {
		if (c % 10 != 0 || flag) {
			flag = true;  //之后的0需要体现出来
			printf("%d", c % 10);
		}
		c /= 10;
	}
	return 0;
}
