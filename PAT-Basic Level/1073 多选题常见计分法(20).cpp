/*
@输出样例中
	2 3-a
	2 3-b
	是指 第3题错了2次，选错过的选项按字母顺序一次是a、b；
@位运算符：包括位与(&)、位或(|)、位非(~)、位异或(^)、左移(<<)、右移(>>)
@柳婼思路：设a为00001，b为00010，c为00100，d为01000，e为10000，
		如果给定的正确答案是ac，即10001，那么如果给出的选项也是10001，异或 的结果就是0；
		如果给出的选项是a或者ab，即00001或00011，异或 之后不为0，就是错选和漏选的。
		通过 异或操作的结果，再通过与正确答案的 或运算  就可以把错选和漏选的选项找出来，
		或运算 结果等于正确选项，则为少选；如果不等于，则为错选。

*/
//柳婼代码
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
	int n = 0, m = 0, opt_num = 0, true_opt_num = 0, temp = 0, max_error_cnt = 0;
	int hash[] = { 1, 2, 4, 8, 16 }, opt[1010][110] = { 0 };
	char c;
	scanf("%d %d", &n, &m);
	vector<int> full_score(m), true_opt(m);
	vector<vector<int> > fre(m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &full_score[i], &opt_num, &true_opt_num);
		for (int j = 0; j < true_opt_num; j++) {
			scanf(" %c", &c);
			true_opt[i] += hash[c - 'a'];
		}
		fre[i].resize(5);
	}
	for (int i = 0; i < n; i++) {
		double grade = 0;
		for (int j = 0; j < m; j++) {
			getchar();
			getchar(); // '('
			scanf("%d", &temp);
			for (int k = 0; k < temp; k++) {
				scanf(" %c", &c);
				opt[i][j] += hash[c - 'a'];
			}
			getchar(); // ')'
			int el = opt[i][j] ^ true_opt[j];
			if (el) {
				if ((opt[i][j] | true_opt[j]) == true_opt[j]) {
					grade += full_score[j] * 1.0 / 2;
				}
				if (el) {
					if (el & hash[0]) fre[j][0]++; // a
					if (el & hash[1]) fre[j][1]++; // b
					if (el & hash[2]) fre[j][2]++; // c
					if (el & hash[3]) fre[j][3]++; // d
					if (el & hash[4]) fre[j][4]++; // e
				}
			}
			else
				grade += full_score[j];
		}
		printf("%.1f\n", grade);
	}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < 5; j++)
			max_error_cnt = max_error_cnt > fre[i][j] ? max_error_cnt : fre[i][j];

	if (max_error_cnt == 0) {
		printf("Too simple\n");
	}
	else {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < fre[i].size(); j++) {
				if (max_error_cnt == fre[i][j]) {
					printf("%d %d-%c\n", max_error_cnt, i + 1, 'a' + j);
				}
			}
		}
	}
	return 0;
}
