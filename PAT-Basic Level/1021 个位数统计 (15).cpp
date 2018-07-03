给定一个k位整数N = d~k-1~*10^k-1^ + ... + d~1~*10^1^ + d~0~ (0<=d~i~<=9, i=0,...,k-1, d~k-1~>0)，请编写程序统计每种不同的个位数字出现的次数。例如：给定N = 100311，则有2个0，3个1，和1个3。

输入格式：
每个输入包含1个测试用例，即一个不超过1000位的正整数N。
输出格式：
对N中每一种不同的个位数字，以D:M的格式在一行中输出该位数字D及其在N中出现的次数M。要求按D的升序输出。

输入样例：
100311
输出样例：
0:2
1:3
3:1

code:

#include <iostream>
#include <string>
using namespace std;
int times[10];
string n;
int main() {
	cin >> n;
	for (int i = 0; i < n.length(); i++) 
		times[n[i]-'0']++;
	for (int i = 0; i < 10; i++)
		if(times[i])
			printf("%d:%d\n", i, times[i]);	
	return 0;
}
