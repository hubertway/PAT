大侦探福尔摩斯接到一张奇怪的字条：“我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm”。大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间“星期四 14:04”，因为前面两字符串中第1对相同的大写英文字母（大小写有区分）是第4个字母'D'，代表星期四；第2对相同的字符是'E'，那是第5个英文字母，代表一天里的第14个钟头（于是一天的0点到23点由数字0到9、以及大写字母A到N表示）；后面两字符串第1对相同的英文字母's'出现在第4个位置（从0开始计数）上，代表第4分钟。现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。

输入格式：
输入在4行中分别给出4个非空、不包含空格、且长度不超过60的字符串。
输出格式：
在一行中输出约会的时间，格式为“DAY HH:MM”，其中“DAY”是某星期的3字符缩写，即MON表示星期一，TUE表示星期二，WED表示星期三，THU表示星期四，FRI表示星期五，SAT表示星期六，SUN表示星期日。题目输入保证每个测试存在唯一解。

输入样例：
3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm
输出样例：
THU 14:04

code:
//柳婼代码
#include <iostream>
#include <cctype>
#include <string>
using namespace std;
int main() {
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    char t[2];
    int pos, i = 0, j = 0;
    while(i < a.length() && i < b.length()) {
        if (a[i] == b[i] && (a[i] >= 'A' && a[i] <= 'G')) {
            t[0] = a[i];
            break;
        }
        i++;
    }
    i = i + 1;
    while (i < a.length() && i < b.length()) {
        if (a[i] == b[i] && ((a[i] >= 'A' && a[i] <= 'N') || isdigit(a[i]))) { ////isdigit()判断是否是字母，在<cctype>里
            t[1] = a[i];
            break;
        }
        i++;
    }
    while (j < c.length() && j < d.length()) {
        if (c[j] == d[j] && isalpha(c[j])) {  //isalpha()判断是否是字母，在<cctype>里
            pos = j;
            break;
        }
        j++;
    }
    string week[7] = {"MON ", "TUE ", "WED ", "THU ", "FRI ", "SAT ", "SUN "};
    int m = isdigit(t[1]) ? t[1] - '0' : t[1] - 'A' + 10;
    cout << week[t[0]-'A'];
    printf("%02d:%02d", m, pos);
    return 0;
}


//多次理解错题意的代码
#include<iostream>
#include<vector>
#include<string>
using namespace std;
string w[] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
int main() {
	string a, b, c, d;
	cin >> a >> b >>c >> d;
	vector<char>ua; 
	vector<char>ub;
	for (int i = 0; i < a.length(); i++) {
		char t = a[i];
		if (t >= 'A'&&t <= 'G')
			ua.push_back(t);
	}
	for (int i = 0; i < b.length(); i++) {
		char t = b[i];
		if (t >= 'A'&&t <= 'N')
			ub.push_back(t);
	}
	int k = 0;
	vector<char>ec;
	vector<char>ed;
	for (int i = 0; i < c.length(); i++) {
		char t = c[i];
		if ((t >= 'a'&&t <= 'z') || (t >= 'A'&&t <= 'Z'))
			ec.push_back(t);
	}
	for (int i = 0; i < d.length(); i++) {
		char t = d[i];
		if( (t >= 'a'&&t <= 'z')||(t >= 'A'&&t <= 'Z'))
			ed.push_back(t);
	}
	int flag = 0;
	for (int i = 0; i < ec.size(); i++) {
		char x = ec[i];
		for (int j = 0; j < ed.size(); j++) {
			char y = ed[j];
			if (x == y) {
				printf("%02d", j+1);
				flag = 1;
				break;
			}
		}
		if (flag)break;
	}
	return 0;
}
