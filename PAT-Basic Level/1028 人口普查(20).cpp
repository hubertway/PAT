某城镇进行人口普查，得到了全体居民的生日。现请你写个程序，找出镇上最年长和最年轻的人。
这里确保每个输入的日期都是合法的，但不一定是合理的——假设已知镇上没有超过200岁的老人，而今天是2014年9月6日，所以超过200岁的生日和未出生的生日都是不合理的，应该被过滤掉。

输入格式：
输入在第一行给出正整数N，取值在(0, 10^5^]；随后N行，每行给出1个人的姓名（由不超过5个英文字母组成的字符串）、以及按“yyyy/mm/dd”（即年/月/日）格式给出的生日。题目保证最年长和最年轻的人没有并列。
输出格式：
在一行中顺序输出有效生日的个数、最年长人和最年轻人的姓名，其间以空格分隔。

输入样例：
5
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 1967/11/20
输出样例：
3 Tom John

code:

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
struct node {
	string name;
	int y, m, d;
};
bool cmp(node a, node b) {
	if (a.y != b.y) return a.y < b.y;
	else if (a.m != b.m) return a.m < b.m;
	else if (a.d != b.d)  return a.d < b.d;
}
int main() {
	int n;
	cin >> n;
	vector<node>v;
	int count = 0;
	for (int i = 0; i < n; i++) {
		node temp;
		cin >> temp.name;
		int y, m, d;
		scanf("%d/%d/%d", &y, &m, &d);
		temp.y = y; temp.m = m; temp.d = d;
		if (y == 1814) {
			if (m > 9) {
				v.push_back(temp);
				count++;
			}
			if (m == 9 && d >= 6) {
				v.push_back(temp);
				count++;
			}
		}
		if (y < 2014 && y >1814) {
			v.push_back(temp);
			count++;
		}
		if (y == 2014 && m < 9) {
			v.push_back(temp);
			count++;
		}
		if (y == 2014 && m == 9 && d <= 6) {
			v.push_back(temp);
			count++;
		}
	}
	if (!v.empty()) {
		sort(v.begin(), v.end(), cmp);
		cout << count << ' ' << v[0].name << ' ' << v[v.size() - 1].name;
	}
	else cout << count;
	return 0;
}
