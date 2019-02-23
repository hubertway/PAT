#include <iostream>
#include <vector>
using namespace std;

int main() {
	int m, n, a, b, r;
	scanf("%d %d %d %d %d", &m, &n, &a, &b, &r);
	vector<vector<int> >v(n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int pix;
			scanf("%d", &pix);
			v[i].push_back(pix);
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j] >= a && v[i][j] <= b)
				v[i][j] = r;
		}
	}
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (j)printf(" ");
			printf("%03d", v[i][j]);
		}
		printf("\n");
	}

	return 0;
}
