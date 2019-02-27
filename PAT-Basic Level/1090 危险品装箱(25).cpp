#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	map<int, vector<int> >r;
	for (int i = 0; i < n; i++) {
		int id1, id2;
		cin >> id1 >> id2;
		r[id1].push_back(id2);
		r[id2].push_back(id1);
	}
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		vector<int>v(k);
		int  a[100000] = { 0 };  //利用数组a[]来查找不相容货物,可以少一层循环
		for (int j = 0; j < k; j++) {
			cin >> v[j];
			a[v[j]] = 1;
		}
		bool flag = true;
		for (int x = 0; x < k; x++) {  
			for (int y = 0; y < r[v[x]].size(); y++) {
				if (a[r[v[x]][y]] == 1) {	   //找到不相容货物
					cout << "No" << endl;
					flag = false;
					break;
				}
			}
			if (!flag) break;
		}
		if (flag) cout << "Yes" << endl;
	}
	return 0;
}
