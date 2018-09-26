
#include <iostream>
#include <string>
#include<algorithm>
using namespace std;
bool avi[128]; //表示128个ascii字符是否可用
int main() {
	fill(avi, avi + 128, true); //填充为全部可用
	string s1, s2;
	getline(cin, s1);  //此处参考柳婼 为了防止第一行是空的，不能用cin >> ,用getline(cin, ...)
	getline(cin, s2);
	transform(s1.begin(), s1.end(), s1.begin(), ::tolower);  //把字符串里的全部变成小写
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] == '+') { 
			for (int j = 'A'; j <='Z'; j++) {
				avi[j] = false;  //即大写全部不可用
			}
		}
		else if (s1[i]>='a'&& s1[i]<='z') {
			avi[s1[i]] = false;  //小写标记不可用
			avi[s1[i] - 32] = false;  //大写标记不可用 ,大小写ascii码差32
		}
		else {
			avi[s1[i]] = false;
		}
	}
	for (int i = 0; i < s2.length(); i++) {
		if (avi[s2[i]]) 
			printf("%c", s2[i]);
	}
	return 0;
}

/*
 柳婼的判断和输出方式后序值得借鉴：

   for (int i = 0, length = should.length(); i < length; i++) {
    if (bad.find(toupper(should[i])) != string::npos) continue;
    if (isupper(should[i]) && bad.find('+') != string::npos) continue;
    cout << should[i];
  }
*/
