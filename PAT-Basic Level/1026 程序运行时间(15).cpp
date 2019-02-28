#include <iostream>
using namespace std;
int main() {
	int c1, c2;
	cin >> c1 >> c2;
	double t = 1.0*(c2 - c1) / 100;
	int h = t / 3600;
	int m = t / 60 - h * 60;
	int s = int(t + 0.5) % 60;  //保证四舍五入，浮点数+0.5再取整
	printf("%02d:%02d:%02d", h, m, s);
	return 0;
}
