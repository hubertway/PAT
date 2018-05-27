设计函数求一元多项式的导数。（注：x^n^（n为整数）的一阶导数为n*x^n-1^。）

输入格式：以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。

输出格式：以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。注意“零多项式”的指数和系数都是0，但是表示为“0 0”。

输入样例：
3 4 -5 2 6 1 -2 0
输出样例：
12 3 -10 1 6 0

code:

/*有一个3分的测试点一直通不过，根据柳婼答案猜想：
应该是每一对 系数-指数 求导后，如果为0项。都要输出 0 0 
用数组方式没办法做到这一点。*/
#include<iostream>
#include<algorithm>
using namespace std;
const int inf = 99999;
int p[10001]; //多项式
int d[10001];//微分
int main() {
	fill(p, p + 10001, inf);
	fill(d, d + 10001, inf);
	int c, e;
	while (cin>>c>>e) {
		p[e] = c;
	}
	for (int i = 0; i < 10001; i++) {
		if (p[i] != inf) {
			int tc, te;
			tc = i * p[i];
			te = i-1;
			if(te>=0)d[te] = tc;
			else d[0] = 0;
		}
	}
	bool flag = false;
	for (int i = 10000; i >=0; i--) {
		if (d[i] != inf) {
			if (flag) printf(" ");
			printf("%d %d", d[i], i);
			flag = true;
		}
	}
	return 0;
}

/*柳婼*/
#include <iostream>
using namespace std;
int main() {
    int a, b, flag = 0;
    while (cin >> a >> b) {
        if (flag == 0 && b == 0) cout << "0 0";
        if (b != 0) {
            if (flag == 1) cout << " ";
            cout << a * b << " " << b - 1;
            flag = 1;
        } 
    }
    return 0;
}
