https://pintia.cn/problem-sets/994805342720868352/problems/994805407749357568

code:
#include <stdio.h>
#include <stdlib.h>
#include<math.h>

#define Min(a,b) (((a)<(b))?(a):(b))

int cmpfunc(const void * a, const void * b);//排序函数中的比较算法
int Log2(int n);//计算以二为底对数，向下取整
int GetLeftLength(int n);//求左子树数组长度
void Solve(int A[], int ALeft, int ARight, int T[], int TRoot);

int main(){
	int N;
	scanf("%d", &N);
	int *A = (int*)malloc(sizeof(int)*N);//存放输入的数组
	int i;
	for (i = 0; i < N; i++){
		scanf("%d", &A[i]);
	}
	qsort(A, N, sizeof(int), cmpfunc);//数组排序

	int *T = (int*)malloc(sizeof(int)*N);//结果树
	Solve(A, 0, N - 1, T, 0);
	for (i = 0; i < N; i++){
		printf("%d", T[i]);
		if (i < N - 1) printf(" ");
		else printf("\n");
	}
	return 0;
}

int cmpfunc(const void * a, const void * b){
	return (*(int*)a - *(int*)b);
}
void Solve(int A[], int ALeft, int ARight, int T[], int TRoot){
	//初始调用为 Solve(A,0,N-1,T,0)
	int n = ARight - ALeft + 1;//总长度
	if (n == 0)return;
	int L = GetLeftLength(n);//计算出n个结点的树其左子树共有多少个结点
	T[TRoot] = A[ALeft + L];
	int LeftTRoot = TRoot * 2 + 1;
	int RightTRoot = LeftTRoot + 1;
	Solve(A, ALeft, ALeft + L - 1, T, LeftTRoot);
	Solve(A, ALeft + L + 1, ARight, T, RightTRoot);
}
int Log2(int n){
	double temp = log(n) / log(2);//double log(double x)函数 返回 x 的自然对数(基数为 e 的对数)
	return ((int)floor(temp));//double floor(double x)函数 返回小于或等于 x 的最大的整数值（向下取整）
}
int GetLeftLength(int n){
	int H = Log2(n + 1);
	int X = n + 1 - pow(2, H);//double pow(double x, double y)函数 返回 x 的 y 次幂
	X = Min(X, pow(2, H - 1));
	return pow(2, H - 1)-1+X;
}
