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
