#include <iostream>
using namespace std;
int main() {
	int c1, c2;
	cin >> c1 >> c2;
	int time = 1.0*(c2 - c1)/100 + 0.5;
	int sec = time % 60; time /= 60;
	int min = time % 60; time /= 60;
	int hour = time;
	printf("%02d:%02d:%02d", hour, min, sec);
	return 0;
}
