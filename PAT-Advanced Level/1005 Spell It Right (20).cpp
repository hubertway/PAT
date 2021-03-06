Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.

Input Specification:
Each input file contains one test case. Each case occupies one line which contains an N (<= 10^100^).

Output Specification:
For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.

Sample Input:
12345
Sample Output:
one five

code:

#include<iostream>
#include<string>
#include<stack>
using namespace std;
string n;
int sum = 0;
stack<int>s;
int main(){
	cin >> n;
	for (int i = 0; i < n.size(); i++){
		sum += (n[i]-'0');
	}
	int d;
	if (!sum) printf("zero");
	while (sum){
		d = sum % 10;
		s.push(d);
		sum /= 10;
	}
	int x;
	while (!s.empty()){
		x = s.top();
		switch (x){
		case 0:printf("zero"); break;
		case 1:printf("one"); break;
		case 2:printf("two"); break;
		case 3:printf("three"); break;
		case 4:printf("four"); break;
		case 5:printf("five"); break;
		case 6:printf("six"); break;
		case 7:printf("seven"); break;
		case 8:printf("eight"); break;
		case 9:printf("nine"); break;
		default:break;
		}
		s.pop();
		if (!s.empty()) printf(" ");
	}
	return 0;
}
