给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。

输入格式：测试输入包含一个测试用例，在一行内给出总长度不超过80的字符串。
字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，单词之间用1个空格分开，输入保证句子末尾没有多余的空格。
输出格式：每个测试用例的输出占一行，输出倒序后的句子。

输入样例：
Hello World Here I Come
输出样例：
Come I Here World Hello

code:

#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	vector<string>v;
	string s;
	while (cin >> s) {
		v.push_back(s);
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		if (i != v.size() - 1) printf(" ");
		cout << v[i];
	}
	return 0;
}


/*之前在C语言课上使用的另一种方式*/
#include<stdio.h>
#include<string.h>
int main() {
	char str[81];
	gets_s(str,81);
	int k;
	k = strlen(str);
	char*p;
	p = str + k;   //p指向字符串最后一个位置
	while (p != str) {
		if (*p == ' ') {  //不断左移到空格的时候
			*p = '\0';
			printf("%s ", p + 1); //输出一个单词
		}
		p--; //左移
	}
	printf("%s\n", str); //输出最后一个单词
	return 0;
}
