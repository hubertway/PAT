大家应该都会玩“锤子剪刀布”的游戏.
现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

输入格式：
输入第1行给出正整数N（<=10^5^），即双方交锋的次数。随后N行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C代表“锤子”、J代表“剪刀”、B代表“布”，第1个字母代表甲方，第2个代表乙方，中间有1个空格。

输出格式：
输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有1个空格。如果解不唯一，则输出按字母序最小的解。

输入样例：
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J
输出样例：
5 3 2
2 3 5
B B

code:

#include <iostream>
using namespace std;
struct node {
	int s, p, f; //胜、平、负次数
};
int cmp(char a, char b) {
	if( (a == 'C' && b == 'J')||
		(a == 'J' && b == 'B')||
		(a == 'B' && b == 'C'))
		return 1;
	else if (a == b) return 0;
	else return -1;
}
int n;
node r[2];
int main() {
	cin >> n;
	int ac =0, aj =0, ab = 0;
	int bc = 0, bj = 0, bb = 0;
	for (int i = 0; i < n; i++) {
		char a, b;
		cin >> a >> b;
		if (cmp(a, b) == 1) {
			r[0].s++;
			r[1].f++;
			if (a == 'C') ac++;
			if (a == 'J')aj++;
			if (a == 'B')ab++;
		}
		if (cmp(a, b) == 0) {
			r[0].p++;
			r[1].p++;
		}
		if (cmp(a, b) == -1) {
			r[1].s++;
			r[0].f++;
			if (b == 'C') bc++;
			if (b == 'J')bj++;
			if (b == 'B')bb++;
		}
	}
	printf("%d %d %d\n", r[0].s, r[0].p, r[0].f);
	printf("%d %d %d\n", r[1].s, r[1].p, r[1].f);
	if (ac >= aj && ac > ab)printf("C ");
	if (aj > ac && aj > ab)printf("J ");
	if (ab >= ac && ab >= aj)printf("B ");
	if (bc >= bj && bc > bb)printf("C");
	if (bj > bc && bj > bb)printf("J");
	if (bb >= bc && bb >= bj)printf("B");
	return 0;
}
