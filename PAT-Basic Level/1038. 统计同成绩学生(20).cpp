#include <iostream>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	int score[100] = {0};
	int num;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		score[num]++;
	}
	int K;
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d", &num);
		if (i != 0)printf(" ");
		printf("%d", score[num]);
	}
	return 0;
}
