#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Gra {
	string name;
	int x = -1;	//编程分数
	int gm = -1, gf = -1; //期中分数、期末分数
	int sum = 0;
};

bool cmp(Gra a, Gra b) {
	if (a.sum != b.sum) return a.sum > b.sum;
	else return a.name < b.name;
}

int main() {
	int p, m, n;
	cin >> p >> m >> n;
	string s; int g;
	vector<Gra>v;
	vector<Gra>r;
	map<string, int>flag;  //用map来优化查找时间
	int index = 1;  //index-1对应不同name在v[]中的位置
	for (int i = 0; i < p; i++) {
		cin >> s >> g;
		if (g >= 200) {
			Gra a;
			a.name = s; a.x = g;
			v.push_back(a);
			flag[s] = index;
			index++;
		}
	}
	for (int j = 0; j < m; j++) {
		cin >> s >> g;
		if (flag[s] != 0) {
			v[flag[s] - 1].gm = g;
		}
	}
	for (int k = 0; k < n; k++) {
		cin >> s >> g;
		if (flag[s] != 0) {
			v[flag[s] - 1].gf = g;
		}
	}

	for (int i = 0; i < v.size(); i++) {  //计算总分
		if (v[i].gm > v[i].gf) {
			if (v[i].gf == -1)v[i].gf = 0;
			v[i].sum = 0.4*v[i].gm + 0.6*v[i].gf + 0.5;  //0.5用来四舍五入
			if (v[i].gf == 0)v[i].gf = -1;
		}
		else {
			if (v[i].gf == -1)v[i].gf = 0;
			v[i].sum = v[i].gf;
			if (v[i].gf == 0)v[i].gf = -1;
		}
	}

	for (int i = 0; i < v.size(); i++) {
		if (v[i].sum >= 60) r.push_back(v[i]);
	}
	sort(r.begin(), r.end(), cmp);
	for (int i = 0; i < r.size(); i++) {
		cout << r[i].name << " " << r[i].x << " "
			<< r[i].gm << " " << r[i].gf << " "
			<< r[i].sum << endl;
	}
	return 0;
}
