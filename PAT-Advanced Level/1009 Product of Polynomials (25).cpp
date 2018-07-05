
This time, you are supposed to find A*B where A and B are two polynomials.

Input Specification:
Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 a~N1~ N2 a~N2~ ... NK a~NK~, where K is the number of nonzero terms in the polynomial, Ni and a~Ni~ (i=1, 2, ..., K) are the exponents and coefficients, respectively. It is given that 1 <= K <= 10, 0 <= NK < ... < N2 < N1 <=1000.

Output Specification:
For each test case you should output the product of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate up to 1 decimal place.

Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output
3 3 3.6 2 6.0 1 1.6

code:

#include<iostream>
using namespace std;
double a[1002];
double b[1002];
double c[2002];  //最多有1000+1000+1种指数
int main(){
	int l1;
	scanf("%d", &l1);
	int ex ;
	double co;
	for (int i = 0; i <l1; i++){
		scanf("%d %lf", &ex, &co);
		a[ex] = co;
	}
	int l2;
	scanf("%d", &l2);
	for (int i = 0; i <l2; i++){
		scanf("%d %lf", &ex, &co);
		b[ex] = co;
	}
	for (int i = 1001; i >= 0; i--){
		if (a[i] != 0){
			for (int j = 1001; j >= 0; j--){
				if (b[j] != 0) c[i + j] += a[i] * b[j];
			}
		}
	}
	int count=0;
	for (int i = 2001; i >= 0; i--){
		if (c[i] != 0) count++;
	}
	printf("%d", count);
	for (int i = 2001; i >= 0; i--){
		if (c[i] != 0)printf(" %d %.1lf", i,c[i]);
	}
	return 0;
}
