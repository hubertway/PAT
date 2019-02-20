#include<iostream>
#include <math.h>
using namespace std;

int main() {
	double R1, P1, R2, P2;
	cin >> R1 >> P1 >> R2 >> P2;
	double a = (R1 * R2) * cos(P1 + P2);
	double b = (R1 * R2) * sin(P1 + P2);
	if (fabs(a) < 0.01) a = 0.00;
	if (fabs(b) < 0.01) b = 0.00;
	if (b < 0) printf("%.2lf%.2lfi", a, b);
	else printf("%.2lf+%.2lfi", a, b);
	return 0;
}
