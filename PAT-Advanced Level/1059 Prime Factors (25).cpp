https://pintia.cn/problem-sets/994805342720868352/problems/994805415005503488

code:
/*《算法笔记》结论：
对一个证整数n来说，如果它存在[2,n]范围内的质因子，要么这些质因子全部 小于或等于 根号n ；
要么只存在一个大于 根号n 的质因子，而其余的质因子全部小于等于根号n。
*/
#include <iostream>
#include <vector>
#include <math.h>
#define maxn 100010
using namespace std;

bool isPrime(int n) {
	if (n == 1) return false;
	int sqr = (int)sqrt(1.0*n);
	for (int i = 2; i <= sqr; i++) {
		if (n%i == 0) return false;
	}
	return true;
}

vector<int>prime;
void findPrime() {
	for (int i = 2; i < maxn; i++) {
		if (isPrime(i) == true) {
			prime.push_back(i);
		}
	}
}

struct factor {
	int x,cnt; //x为质数因子，cnt为其个数
}fac[10];

int main() {
	findPrime();
	int n, num = 0; //num为n的不同质子的个数
	scanf("%d", &n);
	if (n == 1)printf("1=1");
	else {
		printf("%d=", n);
		int pNum = prime.size();
		int sqr = (int)sqrt(1.0*n);
		for (int i = 0; i < pNum && prime[i] <= sqr; i++) {
			if (n%prime[i] == 0) { //如果prime[i]是n的质数因子
				fac[num].x = prime[i]; //记录下该因子
				fac[num].cnt = 0;
				while (n%prime[i] == 0) {  //计算该因子出现个数
					fac[num].cnt++;
					n /= prime[i];
				}
				num++;  //不同的质数因子个数+1
			}
			if (n == 1)break;
		}
		if (n != 1) { //如果如果无法被根号n以内的质因子除尽
			fac[num].x = n;  //那么一定有且仅有一个大于根号n的质数因子
			fac[num].cnt = 1;
			num++;
		}
		//输出结果
		for (int i = 0; i <num; i++) {
			if (i > 0)printf("*");
			printf("%d", fac[i].x);
			if (fac[i].cnt > 1) {
				printf("^%d", fac[i].cnt);
			}
		}
	}
	return 0;
}
