#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string n, sa, sb;
	cin >> n >> sa >> sb;
	vector<int>radix; //进制表,注意0是10进制
	vector<int>a; 
	vector<int>b;   //将字符sa、sb的每一位放入a、b数组对应位置
	for (int i = 0; i < n.size(); i++) {
		int x = n[i] - '0';
		if (x == 0) x = 10;
		radix.push_back(x);
	}
	if (sa.size() != radix.size()) { //通过添0，将sa与n等长
		int l = radix.size() - sa.size();
		for (int i = 0; i < l; i++) sa = '0' + sa;
	}
	for (int i = 0; i < sa.size(); i++)a.push_back(sa[i] - '0');
	if (sb.size() != radix.size()) {  //通过添0，将sb与n等长
		int l = radix.size() - sb.size();
		for (int i = 0; i < l; i++) sb = '0' + sb;
	}
	for (int i = 0; i < sb.size(); i++)b.push_back(sb[i] - '0');

	vector<int>ans; //ans要是倒过来的读
	int d; //某位数值
	int r = 0; //进位值
	for(int i = radix.size() - 1; i >= 0; i--) {
		d = a[i] + b[i] + r;
		if (d >= radix[i]) {
			r = d / radix[i]; 
			d = d % radix[i];
			ans.push_back(d);
		}
		else {
			r = 0;
			ans.push_back(d);
		}
		
	}
	if (r) ans.push_back(r);

	bool flag = false; //过滤掉一开始的0
	for (int i = ans.size() - 1; i >= 0; i--) {
		if (ans[i] != 0) flag = true;
		if(flag) printf("%d", ans[i]);
	}
	if (!flag) printf("0"); //计算后为0

	return 0;
}
