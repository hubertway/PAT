#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<string>hand;
	vector<string>eye;
	vector<string>mouth;
	for (int i = 0; i < 3; i++) {
		string s;
		getline(cin, s);
		int len = s.length();
		int j=0,k = 0;
		while (j < len) {
			if (s[j] == '[') {
				k = j;
				while (k++ < len) {
					if (s[k] == ']') {
						if (i == 0) {
							hand.push_back(s.substr(j + 1, k - j - 1));
							break;
						}
						if (i == 1) {
							eye.push_back(s.substr(j + 1, k - j - 1));
							break;
						}
						if (i == 2) {
							mouth.push_back(s.substr(j + 1, k - j - 1));
							break;
						}
					}
				}
			}
			j++;
		}
	}
	int K;
	scanf("%d\n", &K);
	for (int i = 0; i < K; i++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		if (a > hand.size() || b > eye.size() || c > mouth.size() || d > eye.size() || e > hand.size()) {
			cout << "Are you kidding me? @\\/@" << endl;
			continue;
		}
		cout << hand[a-1] << "(" << eye[b-1] << mouth[c-1] << eye[d-1] << ")" << hand[e-1] << endl;
	}

	return 0;
}
