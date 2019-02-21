#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	vector<int>v(N);
	for (int i = 0; i < N; i++) scanf("%d", &v[i]);

	int day, mile, maxE=0; //天数、英里数、最大整数
	for (int i = 0; i <= N; i++) {
		day = i; mile = 0;
		for (int j = 0; j < N; j++) {
			if (v[j] > day) mile++;
		}
		if (day > mile) break;
		else  {
			if (maxE < day) maxE = day;
		}
	}
	printf("%d", maxE);

	return 0;
}
