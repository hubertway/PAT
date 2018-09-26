#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	long long p;  //系数
	cin >> N >> p;
	long long  *a = new long long[N];
	for (int i = 0; i < N; i++)  cin >> a[i];
	sort(a, a + N);  //非递减排序
	int result = 0, temp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + result; j < N; j++) {
			if (a[j] <= a[i] * p) {
				temp = j - i + 1;
				if (temp > result) result = temp;
			}
			else break;
		}
	}
	printf("%d", result);

	delete[] a;
	return 0;
}


/*自己的方式，一个3分测试点超时：
long long m ;
	long long M = a[N - 1];
	int ans = 0; 
	for (int i = 0; i <= N-1; i++) {
		m = a[i];
		int j,cnt=0;
		for (j= N - 2; j >=i; j--) {
			if (M > m * p) {
				M = a[j];
				cnt++;
			} 
			else break;
		}
		if (ans < N - cnt - i) ans = N - cnt - i;
	}
*/
