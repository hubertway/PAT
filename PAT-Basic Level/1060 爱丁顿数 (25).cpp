//从下标1开始存储n天的公里数在数组a中，对n个数据从大到小排序，i表示了骑车的天数,那么满足a[i] > i的最大值即为所求。
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int N;
	scanf("%d", &N);
	vector<int>v(N+1);
	for (int i = 1; i <= N; i++) scanf("%d", &v[i]);
	sort(v.begin() + 1, v.end(), cmp);
	int day=1, maxE = 0; 
	while (maxE <= N && v[day] > day) {
		maxE++;
		day++;
	}
	printf("%d", maxE);

	return 0;
}
