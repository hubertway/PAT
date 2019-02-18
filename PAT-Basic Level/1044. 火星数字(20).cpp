#include <iostream>
#include <string>
using namespace std;

string d[13] = { "tret","jan","feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" }; //低位
string g[13] = { "tret","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" }; //高位

void func(string s) {
	int len = s.length();
	if (s[0] >= '0' && s[0] <= '9') {  //输入的是地球数字
		int num = 0; //把字符串转换成整数
		int r = 1;
		for (int i = len - 1; i >= 0; i--) {
			num += (s[i] - '0')*r;
			r *= 10;
		}
		int y, x; //火星数字的低位和高位
		x = num / 13;
		y = num % 13;
		if (x) {
			cout << g[x] << " " << d[y] << endl;
		}
		else {
			cout << d[y] << endl;
		}
	}
	else { //输入的是火星文
		if ((len > 3) && s.substr(0, 4) !="tret") { // 也就是输入的是两位有效火星数字
			string s1 = s.substr(0, 3); // 切片，从0开始，长度为3的子串
			string s2 = s.substr(4, 3);
			int num = 0;
			int i;
			for (i = 1; s1 != g[i] && i < 13; i++);
			num = i * 13;
			for (i = 0; s2 != d[i] && i < 13; i++);
			num = num + i;
			printf("%d\n", num);
		}
		else {  //只输入了一位有效火星数字
			if (s.substr(0, 4) == "tret"&& len>4) s = s.substr(5, 3); //去掉无效的0
			int i;
			for (i = 0; s != d[i] && i < 13; i++); //找到对应
			if (i < 13) printf("%d\n", i);
			else {
				for (i = 1; s != g[i] && i < 13; i++);
				printf("%d\n", i * 13);
			}
		}
	}
}

int main() {
	int N;
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++) {
		string s;
		getline(cin, s);
		func(s);
	}
	return 0;
}
