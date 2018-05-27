让我们定义 d~n~ 为：d~n~ = p~n+1~ - p~n~，其中 p~i~ 是第i个素数。显然有 d~1~=1 且对于n&gt1有 d~n~ 是偶数。
“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

现给定任意正整数N (< 10^5^)，请计算不超过N的满足猜想的素数对的个数。

输入格式：每个测试输入包含1个测试用例，给出正整数N。
输出格式：每个测试用例的输出占一行，不超过N的满足猜想的素数对的个数。

输入样例：
20
输出样例：
4

code:

#include <iostream>
#include <vector>
using namespace std;
bool isPrime(int n) {
	if (n == 2) return true;
	bool flag = true;
	if (n > 2) {
		for (int i = 2; i*i <= n; i++) {
			if (n%i == 0) {
				flag = false;
				break;
			}
		}
	}
	return flag;
}
int main() {
	int n;
	cin >> n;
	vector<int>p;
	for (int i=2; i <= n; i++) {
		if (isPrime(i))
			p.push_back(i);
	}
	int i = 0,cnt=0;
	while ( i+1<p.size()) {
		if (p[i + 1] - p[i] == 2)
			cnt++;
		i++;
	}
	cout << cnt;
	return 0;
}
