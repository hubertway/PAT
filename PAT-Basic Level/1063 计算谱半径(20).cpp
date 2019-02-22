#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	double max = 0;
	int r, v;
	double m;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &r, &v);
		m = sqrt( r * r + v * v );
		if (max < m) max = m;
	}
	printf("%.2lf", max); 
	return 0;
}
