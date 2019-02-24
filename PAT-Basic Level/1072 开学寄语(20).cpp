#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
	int n, m; //学生人数，物品种类
	scanf("%d %d", &n, &m);
	vector<int>v(m);
	for (int i = 0; i < m; i++)scanf("%d", &v[i]);
	string s;
	int num;
	map<string, vector<int> > r;
	int p = 0, t = 0; //学生总人数，物品总数
	for (int i = 0; i < n; i++) {
		cin >> s>>num;
		int id;
		bool f1 = false;
		for (int j = 0; j < num; j++) {
			scanf("%d", &id);
			bool  f2 = false;
			for (int k = 0; k < m; k++) {
				if (id == v[k]) {
					f1 = true;
					f2 = true;
					t++;
					break;
				}
			}
			if (f2) r[s].push_back(id);
		}
		if (f1) {
			p++;
			cout << s << ":";
			for (int x = 0; x < r[s].size(); x++) printf(" %04d", r[s][x]);
			printf("\n");
		}
	}
	printf("%d %d\n", p, t);

	return 0;
}
