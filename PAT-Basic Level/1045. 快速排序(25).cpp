#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	vector<int>v;
	vector<bool>b;
	cin >> N;
	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		v.push_back(a);
		b.push_back(true);
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (i == 0) { //第一个要是主元的话，后面的都得比它大
			for (int j = 1; j < N; j++) {
				if (v[j] < v[i]) {
					b[i] = false;
					cnt++;
					break;
				}
			}
		}
		else if (i == N - 1) { //最后一个要是主元的话，前面的都得比它小
			for (int j = 0; j < N-1; j++) {
				if (v[j] > v[i]) {
					b[i] = false;
					cnt++;
					break;
				}
			}
		}
		else {
			for (int j = i+1; j < N; j++) {
				if (v[j] < v[i]) {
					b[i] = false;
					cnt++;
					break;
				}
			}
			for (int j = i - 1; j >= 0; j--) {
				if (v[j] > v[i]) {
					b[i] = false;
					cnt++;
					break;
				}
			}
		}
	}
	int x = N - cnt;
	printf("%d\n", N - cnt);
	for (int i = 0; i < N; i++) {
		if (b[i] == true) {
			x--;
			printf("%d", v[i]);
			if (x != 0)printf(" ");
		}
	}
	printf("\n");
	return 0;
}
