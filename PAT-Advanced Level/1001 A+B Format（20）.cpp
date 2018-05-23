Calculate a + b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

Input
Each input file contains one test case. Each case contains a pair of integers a and b where -1000000 <= a, b <= 1000000. The numbers are separated by a space.
Output

For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

Sample Input
-1000000 9
Sample Output
-999,991

code：
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int a, b;
	cin >> a >> b;
	int sum = a + b;
	if (sum<0){
		printf("-");
		sum = -sum;
	}
	if (sum == 0) printf("0");
	vector<int>s;
	int d = 10;
	while (sum > 0){
		s.push_back(sum%d);
		sum /= d;
	}
	reverse(s.begin(), s.end());
	int len = s.size();
	int temp = len;
	for (int i = 0; i < len; i++){
		cout << s[i];
		if (temp % 3 == 1 && temp!=1) cout << ",";
		temp--;
	}
	return 0;
}
