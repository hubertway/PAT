This time, you are supposed to find A+B where A and B are two polynomials.

Input
Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 a~N1~ N2 a~N2~ ... NK a~NK~, where K is the number of nonzero terms in the polynomial, Ni and a~Ni~ (i=1, 2, ..., K) are the exponents and coefficients, respectively. 
It is given that 1 <= K <= 10，0 <= NK < ... < N2 < N1 <=1000.
Output
For each test case you should output the sum of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.

Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output
3 2 1.5 1 2.9 0 3.2

code:
//设立p数组，长度为指数的最大值，p[i] = j表示指数i的系数为j。
#include<iostream>
using namespace std;

int main(){
	double p[1001] = { 0 };
	int K;
	int e; double c;
	scanf("%d", &K);
	for (int i = 0; i < K; i++){
		scanf("%d%lf", &e, &c);
		p[e] += c;
	}
	scanf("%d", &K);
	for (int i = 0; i < K; i++){
		scanf("%d%lf", &e, &c);
		p[e] += c;
	}
	int count = 0;
	for (int i = 0; i < 1001; i++){
		if (p[i] != 0) count++;
	}
	printf("%d", count);
	if (count){
		for (int i =1000; i >= 0; i--){
			if (p[i] != 0.0)
				printf(" %d %.1lf", i, p[i]);
		}
	}
}
