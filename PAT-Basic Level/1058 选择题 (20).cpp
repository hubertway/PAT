#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Qus {
	int score, n, p; //分值、选项个数、正确个数
	string s;  //正确选项
};

int main() {
	int N, M;

	scanf("%d %d", &N, &M);
	vector<Qus>op(M + 1);
	vector<int>sum(N + 1); // 总分
	for (int i = 1; i <= N; i++) sum[i] = 0;
	vector<int>cnt(M + 1); //错误次数
	for (int i = 1; i <= M; i++) cnt[i] = 0;
	int maxW =0; //最大错误次数

	for (int i = 1; i <= M; i++) {
		scanf("%d %d %d", &op[i].score, &op[i].n, &op[i].p);
		for (int j = 0; j < op[i].p; j++) { //正确选项依次加入op[i].s中
			char c;
			scanf(" %c", &c);
			op[i].s += c;
		}
	}

	for (int i = 1; i <= N; i++) {
		scanf("\n"); //很重要,过掉换行
		for (int k = 1; k <= M; k++) {
			if (k != 1)scanf(" "); //很重要，过掉两个括号支架你的空格
			string ans;
			int n;
			scanf("(%d", &n);
			for (int j = 0; j < n; j++) { //读正确答案
				char c;
				scanf(" %c", &c);
				ans += c;
			}
			scanf(")");
			if (ans == op[k].s) { // 答案正确
				sum[i] += op[k].score; //加到总分里
			}
			else cnt[k]++; //答错，次数加一
		}
	}

	for (int i = 1; i <= N; i++)  printf("%d\n", sum[i]);	//输出分数
	for (int i = 1; i <= N; i++) { //找到最大错误次数
		if (maxW < cnt[i])
			maxW = cnt[i];
	}
	if (maxW != 0) {
		printf("%d", maxW); //输出最大次数
		for (int i = 1; i <= M; i++) {
			if (cnt[i] == maxW)
				printf(" %d", i);
		}
		printf("\n");
	}else printf("Too simple\n");
	return 0;
}
