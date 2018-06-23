给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：
A1 = 能被5整除的数字中所有偶数的和；
A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
A3 = 被5除后余2的数字的个数；
A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
A5 = 被5除后余4的数字中最大数字。

输入格式：
每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，随后给出N个不超过1000的待分类的正整数。数字间以空格分隔。

输出格式：
对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。
若其中某一类数字不存在，则在相应位置输出“N”。

输入样例1：
13 1 2 3 4 5 6 7 8 9 10 20 16 18
输出样例1：
30 11 2 9.7 9
输入样例2：
8 1 2 4 5 6 7 9 16
输出样例2：
N 11 2 N 9

code:

#include<iostream>
using namespace std;
int a1, a2, a3, a4, a5;
bool r1, r2, r3, r4, r5; //记录对应a是否存在
int x = 1, cnt; //x用于a2交错求和,cnt用于记录符合a4个数，
int n,d;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d;
		if (d % 5 == 0 && d % 2 == 0) {
			if (!r1) r1 = true;
			a1 += d;
		}
		if (d % 5 == 1) {
			if (!r2) r2 = true;
			a2 += d*x;
			x = -x;
		}
		if (d % 5 == 2) {
			if (!r3) r3 = true;
			a3++;
		}
		if (d % 5 == 3) {
			if (!r4) r4 = true;
			cnt++;
			a4 += d;
		}
		if (d % 5 == 4) {
			if (!r5) r5= true;
			if (a5 < d) a5 = d;
		}
	}

	if (r1)printf("%d ", a1);
	else printf("N ");
	if (r2)printf("%d ", a2);
	else printf("N ");
	if (r3)printf("%d ", a3);
	else printf("N ");
	if (r4)printf("%.1f ", 1.0*a4/cnt);
	else printf("N ");
	if (r5)printf("%d", a5);
	else printf("N");

	return 0;
}
