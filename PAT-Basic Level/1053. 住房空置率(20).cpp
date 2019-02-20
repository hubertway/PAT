#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, D;
	double e;
	cin >> N >> e >> D;
	int may = 0; //可能空置户
	int emp = 0; //空置户
	for (int i = 0; i < N; i++) {
		int K;
		scanf("%d", &K);
		vector<double>v;
		double d;
		int cnt = 0;
		for (int j = 0; j < K; j++) {
			scanf(" %lf", &d);
			v.push_back(d);
			if (d < e) cnt++;
		}
		if (cnt > D)	emp++;
		else if (cnt > K / 2)	may++;
	}
	double ma = 100.0 * may / N; //可能空置率
	double ep = 100.0 * emp / N; //空置率
	printf("%.1lf%% %.1lf%%", ma, ep);
	return 0;
}
