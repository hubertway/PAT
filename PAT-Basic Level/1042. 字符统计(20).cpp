#include <iostream>
#include <string>
#include <map>
#include <cctype>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	map<char, int>m;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		if ((s[i] >= 'A' && s[i] <= 'Z') ||  //只统计英文字母
			(s[i] >= 'a' && s[i] <= 'z')) {
			s[i] = tolower(s[i]);  //不区分大小写统计，输出小写字母
			m[s[i]]++;
		}
	}
	int max = -1;
	char c;
	for (auto it = m.begin(); it != m.end(); it++) {
		if (max < it->second) {
			max = it->second;
			c = it->first;
		}
	}
	cout << c << " " << max;

	return 0;
}
