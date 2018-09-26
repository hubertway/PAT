#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

void PrintA(int A[], int N);
int IsInsert(int A[],int R[], int N);
void InsertOne(int A[], int N,int B); //插入排序再迭代一次，B为中间序列顺序不对的跳出点
void MergeOne(int A[], int N); //归并排序再迭代一次
void Merge(int A[], int TmpA[], int L, int R, int RightEnd);
void Merge_pass(int A[], int TmpA[], int N, int length);

int main(){
	int N;
	scanf("%d", &N);
	int *A = (int*)malloc(sizeof(int)*N);//原来序列
	int i;
	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);
	int *R = (int*)malloc(sizeof(int)*N);//中间序列
	for (i = 0; i < N; i++)
		scanf("%d", &R[i]);

	int flag = IsInsert(A, R, N);
	if (flag){
		printf("Insertion Sort\n");
		InsertOne(R, N, flag);
		PrintA(R, N);
	}
	else{
		printf("Merge Sort\n");
		MergeOne(R, N);
		PrintA(R, N);
	}
	return 0;
}

void PrintA(int A[], int N){
	int i;
	for (i = 0; i < N; i++){
		printf("%d", A[i]);
		if (i == N - 1) printf("\n");
		else printf(" ");
	}	
}

int IsInsert(int A[], int R[], int N){
	int i,temp=0;
	for (i = 0; i < N; i++){
		if (R[i] > R[i + 1]){ //判断顺序 
			temp = i;
			break;
		}
	}
	for (++i; i < N; i++){
		if (A[i] != R[i]){ //与原始数列对比
			return 0;
			break;
		}
	}
	if (i == N) return temp+1;
	else return 0;
}
void InsertOne(int A[], int N, int B) {
	int  temp, i;
	temp = A[B];
	for (i = B; i>0 && A[i - 1] > temp; i--)
		A[i] = A[i - 1];
	A[i] = temp;
}
void MergeOne(int A[], int N){
	int length ;//归并段长度
	for (length = 2; length < N; length *= 2){
		int temp = length;
		int flag = 0;
		while (temp<=N){
			if (A[temp - 1] <= A[temp])
				temp *= 3;
			else { 
				flag = 1; 
				break;
			}
		}
		if (flag == 1) break;
	}
	int *TmpA = (int *)malloc(sizeof(int)*N);
	Merge_pass(A, TmpA, N, length);//以当前length再归并一次
	free(TmpA);
}

void Merge(int A[], int TmpA[], int L, int R, int RightEnd){ 
	int LeftEnd, NumElements, Tmp;
	int i;

	LeftEnd = R - 1; // 左边终点位置 
	Tmp = L;      //有序序列的起始位置 
	NumElements = RightEnd - L + 1;

	while (L <= LeftEnd && R <= RightEnd) {
		if (A[L] <= A[R])
			TmpA[Tmp++] = A[L++]; // 将左边元素复制到TmpA 
		else
			TmpA[Tmp++] = A[R++]; // 将右边元素复制到TmpA 
	}

	while (L <= LeftEnd) // 直接复制左边剩下的
		TmpA[Tmp++] = A[L++]; 
	while (R <= RightEnd)//直接复制右边剩下的
		TmpA[Tmp++] = A[R++]; 

	for (i = 0; i < NumElements; i++, RightEnd--)
		A[RightEnd] = TmpA[RightEnd]; // 将有序的TmpA[]复制回A[] 
}
void Merge_pass(int A[], int TmpA[], int N, int length){
	int i, j;
	for (i = 0; i <= N - 2 * length; i += 2 * length)
		Merge(A, TmpA, i, i + length, i + 2 * length - 1);
	if (i + length < N) 
		Merge(A, TmpA, i, i + length, N - 1);
	else
		for (j = i; j < N; j++) TmpA[j] = A[j];
}
