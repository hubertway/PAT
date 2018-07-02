本题要求计算A/B，其中A是不超过1000位的正整数，B是1位正整数。你需要输出商数Q和余数R，使得A = B * Q + R成立。

输入格式：
输入在1行中依次给出A和B，中间以1空格分隔。

输出格式：
在1行中依次输出Q和R，中间以1空格分隔。

输入样例：
123456789050987654321 7
输出样例：
17636684150141093474 3

code:

#include <iostream>
#include <string>
using namespace std;
int main() {
	string A;
	int B;
	cin >> A >> B;
	int temp=A[0] - '0';
	string Q;
	int R=0;
	for (int i = 0; i < A.length();i++) {
		if (temp < B) {
			R = temp;
			Q = Q + '0';
			if (i + 1 < A.length())
				temp = temp * 10 + (A[i + 1] - '0');
		}
		else {
			R = temp % B;
			Q = Q + to_string(temp / B);
			if (i + 1 < A.length())
				temp = R * 10 + (A[i + 1] - '0');
		}
	}
	auto  it = Q.begin();
	while (it != Q.end()) { //找到第一个不是0的位置
		if (*it == '0') it++;
		else break;
	}
    /*
    不知道为什么不能写成
     while(*it == '0' && it != Q.end())
        t++; 
    */
	if (it == Q.end())printf("0");  //商Q中全是0，单独输出
	while (it < Q.end()) { 
		printf("%c", *it); 
		it++;
	}
	cout << " " << R;
	return 0;
}
