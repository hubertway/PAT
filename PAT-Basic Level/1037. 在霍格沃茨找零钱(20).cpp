#include <iostream>
using namespace std;

struct Money {
	int gal, sic, knut;
	int sum;
};
Money P, A;
int main() {
	scanf("%d.%d.%d %d.%d.%d", 
		&P.gal, &P.sic, &P.knut, &A.gal, &A.sic, &A.knut);
	P.sum = P.knut + 29 * P.sic + 29 * 17 * P.gal;
	A.sum = A.knut + 29 * A.sic + 29 * 17 * A.gal;
	int sum = A.sum - P.sum;
	if (sum < 0) {
		printf("-");
		sum = -sum;
	}
	int gal, sic, knut;
	gal = sum / (17 * 29);
	sum = sum % (17 * 29);
	sic = sum / 29;
	sum = sum % 29;
	knut = sum;
	printf("%d.%d.%d", gal, sic, knut);
	return 0;
}
