/*
1.字符串中必须仅有P, A, T这三种字符，不可以包含其它字符；
2.任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
	【中间一个A左右加上等量的A（不加也行）都是正确的】
3.如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
	｛ 对于字符串 PAT 正确， 也是就 a和c为空，b为A。那么aPbATca就是  PAAT 也正确，以此类推 PAAAAAAAT(不管中间多少个A都对)
		对于字符串 AAPATAA根据条件2，也正确，其中a为AA,b为A,c为AA。 那么aPbATca就是 AAPAATAAAA ,也将正确。
		然后针对正确的AAPAATAAAA，a为AA，b为AA，c为AAAA， 那么aPbATca就是AAPAAATAAAAAA,也将正确。｝
@开始归纳，设a代表x个A，则c一开始的A数也为x，要正确则b一开始为1个A，那么有：
		  xP1Tx  ——>  xP(1+1)T(x+x) ——> xP(1+1+1)T(x+x+x)·····,即为 xPnTnx,x可以为0.
@一句话总结字符串的要求：只能有一个P一个T，中间末尾和开头可以随便插入A。但是必须满足开头的A的个数 * 中间的A的个数 = 结尾的A的个数		
*/
#include <iostream>
#include<string>
#include<cstdbool>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	bool ans = true;
	int a = 0, b = 0, c = 0; //统计a,b,c位置A的个数
	bool x = true,y = true; //记录字符串位置
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] != 'P' && s[j] != 'T' && s[j] != 'A') {
				ans = false;
				break;
			}
			else {
				if (x==true && s[j] == 'A') {
					a++;
				}
				else if (y == true && s[j] !='T') {
					if(s[j] == 'P')x = false;
					b++;
				}
				else {
					y = false;
					c++;
				}
			}
		}
		b--; c--; //b位置多算了一个P，c位置多算了一个T，都剪掉
		if (!ans)printf("NO\n");
		else {
			if (a*b == c && b != 0) printf("YES\n");
			else printf("NO\n");
		}
		ans = true; x = true; y = true; //重置位置信息，和个数信息
		a = 0; b = 0; c = 0;
	}
	return 0;
}
