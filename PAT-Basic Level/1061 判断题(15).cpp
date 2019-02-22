#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	vector<int>v(M); //分值
	for (int i = 0; i < M; i++) scanf("%d", &v[i]);
	vector<int>r(M); //答案
	for (int i = 0; i < M; i++) scanf("%d", &r[i]);

	for (int i = 0; i < N; i++) {
		int ans;
		int sum = 0;
		for (int j = 0; j < M; j++) {
			scanf("%d", &ans);
			if (ans == r[j]) sum += v[j];
		}
		printf("%d\n", sum);
	}
	return 0;i
}
