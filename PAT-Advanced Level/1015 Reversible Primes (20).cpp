A reversible prime in any number system is a prime whose "reverse" in that number system is also a prime. For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime.

Now given any two positive integers N (< 10^5^) and D (1 < D <= 10), you are supposed to tell if N is a reversible prime with radix D.

Input Specification:
The input file consists of several test cases. Each case occupies a line which contains two integers N and D. The input is finished by a negative N.

Output Specification:
For each test case, print in one line "Yes" if N is a reversible prime with radix D, or "No" if not.

Sample Input:
73 10
23 2
23 10
-2
Sample Output:
Yes
Yes
No

code:

#include<iostream>
using namespace std;
bool isPrime(int n){
	bool flag = true;
	if (n < 2)return false;
	for (int i = 2; i*i <= n; i++){
		if (n%i == 0){
			flag = false;
			break;
		}
	}
	return flag;
}
int main(){
	int n, d;
	while (1){
		cin >> n;
		if (n<0)break;
		cin >> d;
		if (!isPrime(n)) //n<0或n不是素数
			printf("No\n");
		else{
			int rev = 0;
			while (n > 0){
				rev = d*rev + n%d;
				n /= d;
			}
			if (isPrime(rev)) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}
