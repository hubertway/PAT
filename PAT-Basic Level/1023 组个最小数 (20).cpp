#include <iostream>
using namespace std;
int num[10];
int main() {
	for (int i = 0; i < 10; i++) 
		scanf("%d", &num[i]);
	for (int i = 1; i < 10; i++) {
		if (num[i]) {
			printf("%d", i);
			num[i]--;
			break;
		}
	}
	for (int i = 0; i < 10; i++) {
		while(num[i]) {
			printf("%d", i);
			num[i]--;
		}
	}
	return 0;
}
