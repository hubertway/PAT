/*
柳婼分析：每个人说的数字保存在v数组中，i从1～n、j从i+1～n遍历，
分别假设i和j是狼人，a数组表示该人是狼人还是好人，等于1表示是好人，等于-1表示是狼人。
k从1～n分别判断k所说的话是真是假，k说的话和真实情况不同（即v[k] * a[abs(v[k])] < 0）则表示k在说谎，将k放在lie数组中；
遍历完成后判断lie数组，如果说谎人数等于2并且这两个说谎的人一个是好人一个是狼人（即a[lie[0]] + a[lie[1]] == 0）表示满足题意，
此时输出i和j并return，否则最后的时候输出No Solution.
*/
//柳婼代码
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) cin >> v[i];
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			vector<int> lie, a(n + 1, 1);  //vector<int> a(n + 1, 1);意为 声明一个初始大小为n+1，且值都是1的向量a。
			a[i] = a[j] = -1;  //假设i、j为狼人（-1表示狼人，1表示好人）。
			for (int k = 1; k <= n; k++)     
				if (v[k] * a[abs(v[k])] < 0) lie.push_back(k);  //abs()整型绝对值、fabs()浮点型绝对值
                /*⭐若k说的话和真实情况不同，将k放在lie数组中。
                  v[k]值就是k对第v[k]个人的描述，a[abs(v[k])]是第v[k]个人真实的情况
                  v[k] * a[abs(v[k])]则表示描述和真实情况不同*/
			if (lie.size() == 2 && a[lie[0]] + a[lie[1]] == 0) { //如果说谎人数等于2并且这两个说谎的人一个是好人一个是狼人,则满足题意。
				cout << i << " " << j;
				return 0;
			}
		}
	}
	cout << "No Solution";
	return 0;
}
