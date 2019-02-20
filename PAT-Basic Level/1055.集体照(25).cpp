#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
struct node {
	string name;
	int height;
};
int cmp(struct node a, struct node b) {
	return a.height != b.height ? a.height > b.height : a.name < b.name;
}
int main() {
	int n, k, m;  
	cin >> n >> k;
	vector<node> stu(n);
	for (int i = 0; i < n; i++) {
		cin >> stu[i].name;
		cin >> stu[i].height;
	}
	sort(stu.begin(), stu.end(), cmp); //按身高从高到底排序
	int t = 0, row = k;
	//t为已排好的人数
	//m为该排人数
	while (row) {
		if (row == k) {
			m = n - n / k * (k - 1);
			//多出来的人全部站在最后一排
		}
		else {
			m = n / k;
		}
		vector<string> stemp(m); //一排的站位
		stemp[m / 2] = stu[t].name;
		// 左边
		int j = m / 2 - 1; 
		for (int i = t + 1; i < t + m; i = i + 2)
			stemp[j--] = stu[i].name;
		// 右边
		j = m / 2 + 1;
		for (int i = t + 2; i < t + m; i = i + 2)
			stemp[j++] = stu[i].name;
		// 输出当前排
		cout << stemp[0]; 
		for (int i = 1; i < m; i++)
			cout << " " << stemp[i];
		cout << endl;
		t = t + m;
		row--;
	}
	return 0;
}
