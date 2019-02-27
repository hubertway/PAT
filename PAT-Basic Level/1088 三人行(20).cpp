#include <iostream>
#include <math.h>
using namespace std;

void Cmp(int m, int p) {
	if (m > p) printf("Gai");
	else if (m == p) printf("Ping");
	else printf("Cong");
}

int main() {
	int m, x, y;
	scanf("%d %d %d", &m, &x, &y);
	int pj = 10, a = 1, b = 0;  //甲的能力值、甲能力值的十位、个位
	bool flag = false;
	while (a < 10) {
		while (b < 10) {
			if ((10 * b + a)*x == fabs(9 * a - 9 * b)*y) {
				int t  = 10 * a + b;
				flag = true;
				if (pj < t) pj = t;
			}
			b++;
		}
		a++;
		b = 0;
	}
	if ( !flag )printf("No Solution");
	else {
		printf("%d ", pj);
		int py = 10 * (pj % 10) + pj / 10;
		double pb = 1.0*py / y;  //丙不一定是整数，比较时不能用int
		Cmp(m, pj); printf(" ");
		Cmp(m, py); printf(" ");
		if (m > pb) printf("Gai");
		else if (m == pb) printf("Ping");
		else printf("Cong");
	}
	return 0;
}
