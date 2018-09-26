#include <iostream>
#include <string>
using namespace std;

int w[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
char m[11] = { '1','0','X','9','8','7','6' ,'5','4','3','2'};
bool flag = true;
int n;
void Func(string s);

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		Func(s);
	}
	if (flag) printf("All passed");
	return 0;
}

void Func(string s) {
	int sum = 0;
	int d;
	for (int i = 0; i < 17; i++) {
		d = s[i] - '0';
		sum += d * w[i];
	}
	int z = sum % 11;
	if (m[z] != (s[s.length() - 1])) {//即得出的校验值，不等于身份证最后一位的校验值。
		flag = false;
		cout << s << endl;
	}
}
