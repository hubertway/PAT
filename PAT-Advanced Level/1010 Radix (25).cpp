Given a pair of positive integers, for example, 6 and 110, can this equation 6 = 110 be true? The answer is "yes", if 6 is a decimal number and 110 is a binary number.

Now for any pair of positive integers N1 and N2, your task is to find the radix of one number while that of the other is given.

Input Specification:
Each input file contains one test case. Each case occupies a line which contains 4 positive integers:\ N1 N2 tag radix\ Here N1 and N2 each has no more than 10 digits. A digit is less than its radix and is chosen from the set {0-9, a-z} where 0-9 represent the decimal numbers 0-9, and a-z represent the decimal numbers 10-35. The last number "radix" is the radix of N1 if "tag" is 1, or of N2 if "tag" is 2.

Output Specification:
For each test case, print in one line the radix of the other number so that the equation N1 = N2 is true. If the equation is impossible, print "Impossible". If the solution is not unique, output the smallest possible radix.

Sample Input 1:
6 110 1 10
Sample Output 1:
2
Sample Input 2:
1 ab 1 2
Sample Output 2:
Impossible

code:

#include<iostream>
#include<cstring>  //pat系统include<string>不行，必须得cstring
#include<algorithm>
using namespace std;

long long converToTen(char a[], long long radix); //将a[]转换成10进制整数
long long findLargestDigit(char a[]); //寻找字符数组a[]中最大的一位，用来确定将来要查找的radix的下界，即最大位数值+1
int cmp(char a[], long long radix, long long t);//用来比较能n2和t(也就是n1)在基数radix下的大小
long long binarySearch(char a[], long long left, long long right, long long t); //二分查找radix

long long map[256]; //存储字符数组n[]中，每一位字符所对应的十进制整数大小，也就是一个映射数组。"扩展ASCI"共256个字符，很多没用到，不过可以以防万一
char n1[12],n2[12];  //n不超过10位，再加上'\0'
int tag, radix;

int main(){
	cin >> n1 >> n2 >> tag >> radix;
	for (char c = '0'; c <= '9'; c++){
		map[c] = c - '0';
	}
	for (char c = 'a'; c <= 'z'; c++){
		map[c] = c - 'a' + 10;
	}
	if (tag == 2){ //假如题目给的是n2的radix，就交换n1和n2，方便统一处理
		swap(n1, n2);
	}
	long long t = converToTen(n1,radix); // t暂存n1的十进制结果
	long long low = findLargestDigit(n2);  //用low存储将来要二分查找的radix范围下界
	long long high = max(low, t) + 1; //上界max{已知基数的N, 下界}
	long long result = binarySearch(n2,low,high,t); //用二分查找寻找可能的radix
	if (result == -1)printf("Impossible\n");
	else printf("%lld\n", result);

	return 0;
}

long long converToTen(char a[], long long radix){  
	long long result = 0;
	int len = strlen(a);
	for (int i = 0; i < len; i++){
		result = result*radix + map[a[i]];
		/* 假如是 (ab,15), result第一次循环=0*15+map[a] =10;第二次循环=10*15+map[b]=161。
		15进制下的ab=11(b)+15*10(a) = 161。所以这样算是对的。
		直接用十进制举例好像更直观 (32,10) ，result = (0+3)*10+2=32*/
	}
	return result;
}
long long findLargestDigit(char a[]){ 
	int result = -1, len = strlen(a);
	for (int i = 0; i < len; i++){
		if (map[a[i]]>result){
			result = map[a[i]];  //更新到最大值
		}
	}
	return result + 1; //当然也是用十进制表示返回值radix
}
int cmp(char a[], long long radix, long long t){
	int len = strlen(a);
	long long num = converToTen(a, radix);
	if (num < 0)return 1; //n2小于0,返回0 
	if (num < t)return-1; //n2小于n1
	return (t == num) ? 0 : 1; //n2==n1返回0，不n2!=n1，返回1
}
long long binarySearch(char a[], long long left, long long right, long long t){
	long long mid;
	while (left <= right){
		mid = (left + right) / 2;
		int flag = cmp(n2, mid, t);
		if (flag == 0)return mid;
		/*分为两种情况：第一种n2是个负数，不用比较了，直接返回最终结果为当前mid(题目测试点应该不会出现这组情况吧？)；
		第二种找到了n2==n1的radix=mid*/
		else if (flag == -1) left = mid + 1; //在该radix下n2算出来比n1小，继续向右找
		else right = mid - 1; //继续向左找
	}
	return -1; //完全没找到
}
