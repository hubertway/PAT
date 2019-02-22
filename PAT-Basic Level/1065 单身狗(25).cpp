#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	map<int, int>cp;  
	for (int i = 0; i < n; i++) {
		int id1, id2;
		scanf("%d %d", &id1, &id2);
		cp[id1] = id2; cp[id2] = id1;
	}
	int m;
	scanf("%d", &m);
	vector<int>v(m);
	for (int i = 0; i < m; i++) scanf("%d", &v[i]);

	vector<int>r;
	for (int i = 0; i < m; i++) {
		int id = v[i];
		auto it = cp.find(id);
		if (it== cp.end())  r.push_back(id);
		else {
			bool flag = false;
			for (int j = 0; j < m; j++) {
				if (j != i && it->second == v[j]) 
					flag = true;
			}
			if (!flag) r.push_back(id);
		}
	}

	sort(r.begin(), r.end());
	printf("%d\n", r.size());
	for (int i = 0; i < r.size(); i++) {
		if (i) printf(" ");
		printf("%05d", r[i]);
	}

	return 0;
}
