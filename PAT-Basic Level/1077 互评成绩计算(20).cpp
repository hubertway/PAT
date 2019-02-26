#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int max = -1, min = 101;
		int teacher;
		int score;
		int cnt = 0; // 无效数据个数
		int sum = 0;
		double anv = 0;
		int res; 
		scanf("%d ", &teacher);
		for (int i = 0; i < n - 1; i++) {
			scanf("%d", &score);
			if (score >= 0 && score <= m) {
				sum += score;
				if (max < score) max = score;
				if (min > score) min = score;
			}
			else cnt++;
		}
		sum = sum - max - min;
		anv =1.0*sum / (n - 3 - cnt) ;
		res = 1.0*(anv + teacher) / 2 + 0.5; 
		printf("%d\n", res);
	}
	return 0;
}
