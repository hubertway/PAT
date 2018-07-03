输入两个非负10进制整数A和B(≤2^30 -1)，输出A+B的D (1 < D ≤ 10)进制数。

输入格式：
输入在一行中依次给出3个整数A、B和D。
输出格式：
输出A+B的D进制数。

输入样例：
123 456 8
输出样例：
1103

code:

#include <iostream>
#include <vector>
using namespace std;
int main() {
	int a, b, r;
	cin >> a >> b >> r;
	long d = a + b;
	vector<int>v;
	do {
		int y = d % r;
		v.push_back(y);
		d /= r;
	} while (d);
	for (int i = v.size()-1; i >= 0; i--) 
		printf("%d", v[i]);
	return 0;
}
