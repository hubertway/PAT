让我们用字母B来表示“百”、字母S表示“十”，用“12...n”来表示个位数字n（&lt10），换个格式来输出任一个不超过3位的正整数。例如234应该被输出为BBSSS1234，因为它有2个“百”、3个“十”、以及个位的4。

输入格式：每个测试输入包含1个测试用例，给出正整数n（&lt1000）。
输出格式：每个测试用例的输出占一行，用规定的格式输出n。

输入样例1：
234
输出样例1：
BBSSS1234
输入样例2：
23
输出样例2：
SS123

code:

#include <iostream>
using namespace std;
int main() {
	int  n;
	cin >> n;
	if (n > 99) {
		int b = n / 100;
		for (int i = 0; i < b; i++)printf("B");
	}
	n %= 100;
	if (n > 9) {
		int s = n / 10;
		for (int i = 0; i < s; i++)printf("S");
	}
	n %= 10;
	if(n>0)
		for (int i = 1; i <= n; i++)printf("%d",i);
	return 0;
}
