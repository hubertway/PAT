旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及实际被输入的文字，请你列出肯定坏掉的那些键。

输入格式：
输入在2行中分别给出应该输入的文字、以及实际被输入的文字。每段文字是不超过80个字符的串，由字母A-Z（包括大、小写）、数字0-9、以及下划线“_”（代表空格）组成。题目保证2个字符串均非空。
输出格式：
按照发现顺序，在一行中输出坏掉的键。其中英文字母只输出大写，每个坏键只输出一次。题目保证至少有1个坏键。

输入样例：
7_This_is_a_test
_hs_s_a_es
输出样例：
7TI

code:

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
	string s1, s2, s3;
	cin >> s1 >> s2;
	for (int i = 0, j = 0; i < s1.length(); i++) {
		if (s1[i] == s2[j]) j++;
		else {
			int k;
			for (k = 0; k < s3.length(); k++) {
				if (s1[i] == s3[k]) break;
				if (s1[i] >= 'a' && s1[i] <= 'z') {
					if (toupper(s1[i]) == s3[k]) break;
				}
			}
			if (k == s3.length())s3 += toupper(s1[i]);
		}
	}
	cout << s3;
	return 0;
}

{//柳婼判断代码部分,可以学习一下
if (s2.find(s1[i]) == string::npos && ans.find(toupper(s1[i])) == string::npos)
		//如果直接找不到，且切换大写也找不到，那就是没有。
        ans += toupper(s1[i]);
	//npos可以表示string的结束位子，是string::type_size 类型的，也就是find()返回的类型
	//find()在找不到指定值得情况下会返回string::npos
}
