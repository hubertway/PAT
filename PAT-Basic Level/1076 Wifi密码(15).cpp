#include <iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int>r(n);
	for (int i = 0; i < n; i++) {
		scanf("\n");
		int num;
		for (int j = 0; j < 4; j++) {
			char ans, chose;
			scanf("%c-%c", &ans, &chose);
			if (j != 3) scanf(" ");
			if (chose == 'T') {
				switch (ans){
				case 'A':num = 1; break;
				case 'B':num = 2; break;
				case 'C':num = 3; break;
				case 'D':num = 4; break;
				}
			}
		}
		r[i] = num;
	}

	for (int i = 0; i < n; i++) {
		printf("%d", r[i]);
	}

	return 0;
}
