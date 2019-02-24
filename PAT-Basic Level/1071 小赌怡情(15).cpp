#include <iostream>
using namespace std;

int main() {
	int T, K;
	scanf("%d %d", &T, &K);
	int n1, b, t, n2;
	for (int i = 0; i < K; i++) {
		scanf("%d %d %d %d", &n1, &b,&t,&n2);
		if (t > T)printf("Not enough tokens.  Total = %d.\n", T);
		else {
			if (b) {
				if (n2 > n1) {
					T += t;
					printf("Win %d!  Total = %d.\n", t,T);
				}
				else {
					T -= t;
					printf("Lose %d.  Total = %d.\n",t,T);
					if (T <= 0) {
						printf("Game Over.\n");
						break;
					}
				}
			}
			else {
				if (n2 < n1) {
					T += t;
					printf("Win %d!  Total = %d.\n",t,T);
				}
				else {
					T -= t;
					printf("Lose %d.  Total = %d.\n", t,T);
					if (T <= 0) { 
						printf("Game Over.\n"); 
						break;
					}
				}
			}
		}
	}
	return 0;
}
