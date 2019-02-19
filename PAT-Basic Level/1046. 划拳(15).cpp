#include <iostream>
using namespace std;

int main() {
	int N;
	scanf("%d\n", &N);
	int jcnt = 0, ycnt = 0;
	int jha, jhu, yha, yhu;
	for (int i = 0; i < N; i++) {
		cin>>jha>>jhu>> yha>>yhu;
		if ((jhu == (jha + yha)) && (yhu != (jha + yha))) {
			ycnt++;
		}
		else if ((jhu != (jha + yha)) && (yhu == (jha + yha))) {
			jcnt++;
		}
		else continue;
	}
	cout << jcnt << " " << ycnt << endl;
	return 0;
}
