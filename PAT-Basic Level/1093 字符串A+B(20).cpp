#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	string a, b;
	getline(cin, a);
	getline(cin, b);
	map<char, bool>m;
	for (int i = 0; i < a.length(); i++) m[a[i]] = true;
	for (int i = 0; i < b.length(); i++) m[b[i]] = true;

	for (int i = 0; i < a.length(); i++) {
		if (m[a[i]]) {
			printf("%c", a[i]);
			m[a[i]] = false;
		}
	}
	for (int i = 0; i < b.length(); i++) {
		if (m[b[i]]) {
			printf("%c", b[i]);
			m[b[i]] = false;
		}
	}
	return 0;
}
