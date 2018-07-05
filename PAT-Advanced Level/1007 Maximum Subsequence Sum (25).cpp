Given a sequence of K integers { N~1~, N~2~, ..., N~K~ }. A continuous subsequence is defined to be { N~i~, N~i+1~, ..., N~j~ } where 1 <= i <= j <= K. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.

Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.

Input Specification:
Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer K (<= 10000). The second line contains K numbers, separated by a space.

Output Specification:
For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique, output the one with the smallest indices i and j (as shown by the sample case). If all the K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.

Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:
10 1 4

code:

#include<iostream>
using namespace std;
#define MaxNum 10000
int k, first=0, last=0,sum=0;
int a[MaxNum];
int main() {
	scanf("%d", &k);
	int flag = 0;  //确定序列里是否只有负数
	for (int i = 0; i < k; i++){
		scanf("%d", &a[i]);
		if (a[i] >= 0) flag = 1;
	}
	if (flag){
		int thissum = 0, maxsum = -1;
		int t = 0;
		for (int i = 0; i < k; i++){
			thissum += a[i];
			if (thissum > maxsum){
				maxsum = thissum;
				first = t;
				last = i;
			}
			else if (thissum < 0){
				thissum = 0;
				if (a[i + 1] >= 0 && i < k){
					t = i + 1;
				}
			}
		}
		sum = maxsum;
		printf("%d %d %d\n", sum, a[first], a[last]);
	}
	else printf("%d %d %d\n",sum, a[0], a[k - 1]);
	return 0;
}
