#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		int size = s.length();
		if (size < 6) cout << "Your password is tai duan le." << endl;
		else {
			int word = 0, num = 0;
			int law = true;
			for (int j = 0; j < s.length(); j++) {
				if (s[j] >= '0'&&s[j] <= '9')num++;
				else if ((s[j] >= 'a'&&s[j] <= 'z') || (s[j] >= 'A'&&s[j] <= 'Z')) word++;
				else if(s[j] != '.'){
					law = false;
					break;
				}
			}
			if (!law) cout << "Your password is tai luan le." << endl;
			else {
				if (word == 0 && num != 0) cout << "Your password needs zi mu." << endl;
				else if (word != 0 && num == 0)cout << "Your password needs shu zi." << endl;
				else cout << "Your password is wan mei." << endl;
			}
		}
	}
	return 0;
}
