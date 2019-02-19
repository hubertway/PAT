#include <iostream>
#include <map>
using namespace std;

int main() {
	int N;
	scanf("%d\n", &N);
	int tnum,mnum,score;
	map<int, int>mp;
	for (int i = 0; i < N; i++) {
		scanf("%d-%d %d", &tnum, &mnum, &score);
		mp[tnum] += score;
	}
	int maxs = -1,cha;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		if (maxs < it->second) {
			maxs = it->second;
			cha = it->first;
		}
	}
	cout << cha << " " << maxs << endl;
	return 0;
}
