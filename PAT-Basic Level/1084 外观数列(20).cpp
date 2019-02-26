#include <iostream>
#include <string>
using namespace std;

int main() {
	int d, n;
	scanf("%d %d", &d, &n);
	if (n == 1)printf("%d\n", d);
	else {
		int cnt = 1;
		string s = to_string(d);
		while (1) {
			string t;
			int num = 1;
			char c = s[0];
			for (int i = 1; i < s.size(); i++) {
				if (c == s[i]) num++;
				else {
					t += c;
					t += to_string(num);
					c = s[i];
					num = 1;
				}
			}
			t += c;
			t += to_string(num);
			cnt++;
			if (cnt == n) {
				cout << t << endl;
				break;
			}
			else s = t;
		}
	}
	
	return 0;
}
