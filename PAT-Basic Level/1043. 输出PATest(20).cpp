#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	string s;
	cin >> s;
	map<char, int>m;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] == 'P' || s[i] == 'A' || s[i] == 'T' ||
			s[i] == 't' || s[i] == 'e' || s[i] == 's') {
			m[s[i]]++;
		}
	}
	bool flag = true; //还有字母
	bool Pb = true, Ab = true, Tb = true;
	bool tb = true, eb = true, sb = true;
	while (flag) {
		if (m['P']) {
			printf("P");
			m['P']--;
		}
		else Pb = false;
		if (m['A']) {
			printf("A");
			m['A']--;
		}
		else Ab = false;
		if (m['T']) {
			printf("T");
			m['T']--;
		}
		else Tb = false;
		if (m['e']) {
			printf("e");
			m['e']--;
		}
		else eb = false;
		if (m['s']) {
			printf("s");
			m['s']--;
		}
		else sb = false;
		if (m['t']) {
			printf("t");
			m['t']--;
		}
		else tb = false;
		if (!Pb && !Ab && !Tb && !tb && !eb && !sb)
			flag = false;
	}

	return 0;
}
