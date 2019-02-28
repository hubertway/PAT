#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct node {
	string str; //准考证号
	char level;//级别
	int room; //考场号
	string time; //日期
	string id;     //考生编号
	int sco; //分数
};

struct tp3 {
	int room, num = 0; //考场号,总人数
};

bool cmp1(node a, node b) { //指令1的比较函数
	if (a.sco != b.sco)return a.sco > b.sco;
	else if (a.room != b.room) return a.room < b.room;
}
bool cmp3(tp3 a, tp3 b) {
	if (a.num != b.num) return  a.num > b.num;
	else if (a.room != b.room) return a.room < b.room;
}


int main() {
	int n, m; 
	cin >> n >> m;
	vector<node>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].str >> v[i].sco;
		v[i].level = v[i].str[0];
		v[i].room = stoi(v[i].str.substr(1, 3));
		v[i].time = v[i].str.substr(4, 6);
		v[i].id = v[i].str.substr(10, 3);
	}

	for (int i = 0; i < m; i++) {
		vector<node>x(n);
		for (int i = 0; i < n; i++) x[i] = v[i];
		int t; cin >> t; //指令类型
		if (t == 1) {
			char c; cin >> c;
			cout << "Case " << i + 1 << ": 1 " << c << endl;
			sort(x.begin(), x.end(), cmp1);
			bool flag = false;
			for (int j = 0; j < n; j++) {
				if (x[j].level == c) {
					flag = true;
					cout << x[j].str << " " << x[j].sco << endl;
				}
			}
			if (!flag) cout << "NA" << endl;
		}
		if (t == 2) {
			int num; cin >> num;
			cout << "Case "<<i+1<<": 2 " << num << endl;
			int cnt = 0, sum = 0;
			bool flag = false;
			for (int j = 0; j < n; j++) {
				if (x[j].room == num) {
					cnt++;
					sum += x[j].sco;
					flag = true;
				}
			}
			if (!flag) cout << "NA" << endl;
			else {
				cout << cnt << " " << sum << endl;
			}
		}
		if (t == 3) {
			string date; cin >> date;
			cout << "Case " << i + 1 << ": 3 " << date << endl;
			bool flag = false;
			int cnt[1000] = { 0 };
			for (int j = 0; j < n; j++) {
				if (date == x[j].time) {
					flag = true;
					cnt[x[j].room]++;
				}
			}
			if (!flag) cout << "NA" << endl;
			else {
				vector<tp3>w;
				tp3 q;
				for (int k = 0; k < 1000; k++) {
					if (cnt[k] != 0) {
						q.room = k;
						q.num = cnt[k];
						w.push_back(q);
					}
				}
				sort(w.begin(), w.end(), cmp3);
				for (int u = 0; u < w.size(); u++) {
					cout << w[u].room << " " << w[u].num << endl;
				}
			}
		}
	}

	return 0;
}
