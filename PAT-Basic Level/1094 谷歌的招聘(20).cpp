#include <iostream>
#include <string>
using namespace std;

bool isPri(int a) {
	bool flag = true;
	if (a < 2) return false;
	for (int i = 2; i*i <= a; i++) {
		if (a%i == 0) {
			flag = false;
			break;
		}
	}
	return flag;
}

int main() {
	int l, k;
	cin >> l >> k;
	string s;
	cin >> s;
	int i = 0;
	bool flag = false;
	while (i + k <= l) {
		string t;
		t = s.substr(i, k);
		int a = stoi(t);
		if (isPri(a)) {
			cout << t;
			flag = true;
			break;
		}
		i++;
	}
	if (!flag)cout << "404";
	return 0;
}
