#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	vector<int>v(N);
	for (int i = 0; i < N; i++) scanf("%d", &v[i]);
	int sum = 0;
	for (int j = 0; j < N; j++) {
		for (int k = 0; k < N; k++) {
			if (j != k) sum = sum + 10 * v[j] + v[k];
		}
	}
	printf("%d", sum);
	return 0;
}
