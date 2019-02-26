#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct node {
	string name;
	int weight, num=0;
	int bsum = 0, asum = 0, tsum = 0;
};

bool cmp(node a, node b) {
	if (a.weight != b.weight) return a.weight > b.weight;
	else if (a.num != b.num) return a.num < b.num;
	else return a.name < b.name;
}

int main() {
	int n;
	scanf("%d", &n);
	map<string, node>m;
	vector<node>v;
	for (int i = 0; i < n; i++) {
		string id, sch;
		int sco;
		cin >> id >> sco >> sch;
		for (int j = 0; j < sch.length(); j++) {
			sch[j] = tolower(sch[j]); //变小写
		}
		m[sch].num++;
		m[sch].name = sch;
		if (id[0] == 'B') m[sch].bsum += sco;
		if (id[0] == 'A') m[sch].asum += sco;
		if (id[0] == 'T') m[sch].tsum += sco;
	}
	for (auto it = m.begin(); it != m.end(); it++) {
		it->second.weight = it->second.bsum / 1.5 + it->second.asum + it->second.tsum * 1.5;
		v.push_back(it->second);
	}
	sort(v.begin(), v.end(), cmp);
	printf("%d\n", v.size());
	int rank = 1; //排名
	int cnt = 1; //同分人数
	cout << "1 " << v[0].name << " " << v[0].weight << " " << v[0].num << endl;
	for (int i = 1; i < v.size(); i++) {
		if (v[i].weight != v[i - 1].weight) {
			rank += cnt;
			cnt = 1;
		} 
		else cnt++;
		cout << rank <<" "<< v[i].name << " " << v[i].weight << " " << v[i].num << endl;
	}
	return 0;
}
