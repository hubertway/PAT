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
