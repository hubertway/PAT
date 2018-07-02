正整数A的“D~A~（为1位整数）部分”定义为由A中所有D~A~组成的新整数P~A~。例如：给定A = 3862767，D~A~ = 6，则A的“6部分”P~A~是66，因为A中有2个6。

现给定A、D~A~、B、D~B~，请编写程序计算P~A~ + P~B~。

输入格式：
输入在一行中依次给出A、D~A~、B、D~B~，中间以空格分隔，其中0 < A, B < 10^10^。

输出格式：
在一行中输出P~A~ + P~B~的值。

输入样例1：
3862767 6 13530293 3
输出样例1：
399

输入样例2：
3862767 1 13530293 8
输出样例2：
0

code:
#include <iostream>
using namespace std;
int A, DA, B, DB;
int PA = 0, PB = 0;
int Part(int a,int d) {
	int p=0;
	while (a) {
		int t = a % 10;
		if (t == d) 
			p = p * 10 + t;
		a /= 10;
	}
	return p;
};
int main() {
	cin>> A>>DA>>B>>DB;
	PA = Part(A, DA);
	PB = Part(B, DB);
	printf("%d", PA + PB);
	return 0;
}
