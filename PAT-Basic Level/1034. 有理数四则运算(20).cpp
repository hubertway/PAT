#include <iostream>
using namespace std;

struct Franction {
	long long up, down;
};

long long gcb(long long a, long long b) {  //求最大公约数
	return !b ? a : gcb(b, a%b);
}

Franction reduction(Franction r) {  //化简分数
	if (r.down < 0) {   //保证在负数的情况下，分子是负数，分母是正数，以方便计算
		r.down = -r.down;
		r.up = -r.up;
	}
	long long d = gcb(abs(r.up), abs(r.down));
	r.up /= d;
	r.down /= d;
	return r;
}

void print(Franction a) {  //格式化输出
	long long k = 0; //倍数
	k = a.up / a.down;
	if (k != 0) {
		a.up = a.up%a.down;
		if (k < 0) printf("(");
		if (a.down == 1) {
			if (a.up) printf("%lld %lld", k, abs(a.up));
			else printf("%lld", k);
		}
		else {
			printf("%lld %lld/%lld", k, abs(a.up), a.down);
		}
		if (k < 0) printf(")");
	}
	else {
		if (a.up < 0) printf("(");
		if (a.down == 1 || a.up == 0) {
			printf("%lld", a.up);
		}
		else {
			printf("%lld/%lld", a.up, a.down);
		}
		if (a.up < 0) printf(")");
	}
}

void add(Franction a, Franction b) {
	Franction r;
	r.up = a.up * b.down + b.up * a.down;
	r.down = a.down * b.down;
	r = reduction(r);
	print(a);
	printf(" + ");
	print(b);
	printf(" = ");
	print(r);
	printf("\n");
}

void minu(Franction a, Franction b) {
	Franction r;
	r.up = a.up * b.down - b.up * a.down;
	r.down = a.down * b.down;
	r = reduction(r);
	print(a);
	printf(" - ");
	print(b);
	printf(" = ");
	print(r);
	printf("\n");
}

void multi(Franction a, Franction b) {
	Franction r;
	r.up = a.up * b.up;
	r.down = a.down * b.down;
	r = reduction(r);
	print(a);
	printf(" * ");
	print(b);
	printf(" = ");
	print(r);
	printf("\n");
}


void divi(Franction a, Franction b) {
	if (b.up == 0) { // 除法的分母为0
		print(a);
		printf(" / ");
		print(b);
		printf(" = Inf\n");
	}
	else {
		Franction r;
		r.up = a.up * b.down;
		r.down = a.down * b.up;
		r = reduction(r);
		print(a);
		printf(" / ");
		print(b);
		printf(" = ");
		print(r);
		printf("\n");
	}
}

Franction a, b;
int main() {
	scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
	a = reduction(a);
	b = reduction(b);
	add(a, b);
	minu(a, b);
	multi(a, b);
	divi(a, b);
	return 0;
}
