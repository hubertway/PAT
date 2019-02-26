#include <iostream>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int master = 10000;
	int rookie = -1;
	int mid, rid;
	int id, x, y;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d",&id, &x, &y);
		if (master > (x * x + y * y) ) {
			master = (x * x + y * y);
			mid = id;
		}
		if (rookie < (x * x + y * y)) {
			rookie = (x * x + y * y);
			rid = id;
		}
	}
	printf("%04d %04d\n", mid, rid);
	return 0;
}
