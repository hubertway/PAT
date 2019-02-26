#include <iostream>
#include <string>
using namespace std;

int main() {
	char c;
	scanf("%c", &c);
	getchar();
	string s;
	getline(cin, s);
	if (c == 'C') {
		char t = s[0];
		int cnt = 1;
		for (int i = 1; i < s.length(); i++) {
			if (s[i] == t) cnt++;
			else {
				if (cnt != 1)printf("%d", cnt);
				printf("%c", t);
				t = s[i];
				cnt = 1;
			}
		}
		if (cnt != 1)printf("%d", cnt);
		printf("%c", t);
	}
	if (c == 'D') {
		char t = s[0];
		int i = 0;
		while (i < s.length()) {
			if ((t >= 'a'&&t <= 'z') || (t >= 'A' && t <= 'Z') || t == ' ') { //字符不是数字
				printf("%c", t);
				i++;
				t = s[i];
			}
			else {
				string x; //数字字符串
				while (t>='0'&&t<='9') {//找到不是数字的字符，并统计数字
					x = x + t;  
					i++;
					t = s[i];
				}
				int cnt = stoi(x);   //stoi()是将sting转化为int
				t = s[i];
				for (int j = 0; j < cnt; j++)printf("%c", t);
				i++;
				t = s[i];
			}
		}
	}
	
	return 0;
}
