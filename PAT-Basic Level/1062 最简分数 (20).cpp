#include <iostream>
using namespace std;

int gcd(int a, int b) {  //辗转相除法求最大公约数
	if (b == 0)return a;
	else return gcd(b, a%b);
}

int main() {
	int N1, M1, N2, M2;
	int K;
	scanf("%d/%d %d/%d %d", &N1, &M1, &N2, &M2, &K);
	if (N1 * M2 > N2 * M1) {  //也就是 是否 N1/M1<N2/M2
		swap(N1, N2);
		swap(M1, M2);
	} //保证是从小到大的范围

	int x = 1;
	while (N1*K >= M1 * x) x++; //进入所给范围

	int flag = 0;
	while (N1*K < M1*x && N2*K > M2*x) {
		if (gcd(x, K) == 1) {
			if (flag) printf(" ");
			printf("%d/%d", x, K);
			flag = 1;
		}
		x++;
	}

	return 0;
}
