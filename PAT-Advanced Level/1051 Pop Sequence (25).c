https://pintia.cn/problem-sets/994805342720868352/problems/994805427332562944

code:

#include <stdio.h>
#include <stdlib.h>

typedef struct Snode{
	int data;
	struct Snode * next;
}*Prt;
typedef Prt Stack;

Stack Createstack();//建立堆栈
int IsEmpty(Stack S);//判空
void Push(Stack S, int X);//入栈
void Pop(Stack S);//出栈
int Size(Stack S);//测量堆栈内元素个数
int Top(Stack S);//读取栈顶元素

int main(){
	int m, n, k;
	scanf("%d %d %d", &m, &n, &k);
	for (int i = 0; i < k; i++){
		int flag = 0;//判断最终结果
		Stack S = Createstack();
		int *a = (int*)malloc(sizeof(int)*(n + 1));
		//创建长度为n+1的数组,a[0]抛弃，方便从1开始计数
		for (int j = 1; j <= n;j++){
			scanf("%d", &a[j]);
		}
		int now = 1;//从数组第一个开始，检查是否与栈顶元素相等；
		for (int k = 1; k <= n; k++){
			Push( S , k );//从1开始顺序入栈
			if (Size(S) > m) break;
			while (!IsEmpty(S) && Top(S) == a[now]){
				Pop(S);
				now++;
			}
		}
		if (now == n + 1) flag = 1;
		if (flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

Stack Createstack(){
	Stack S;
	S = (Stack)malloc(sizeof(struct Snode));
	S->next = NULL;
	return S;
}
int IsEmpty(Stack S){
	if (S->next == NULL) return 1;
	else return 0;
}
void Push(Stack S, int X){
	Prt TmpC = (Prt)malloc(sizeof(struct Snode));
	TmpC->data = X;
	TmpC->next = S->next;
	S->next = TmpC;
}
void Pop(Stack S){
	Prt FstC;
	if (IsEmpty(S) == 0){
		FstC = S->next;
		S->next = FstC->next;
	}
}
int Size(Stack S){
	int cnt = 0;
	Prt Tmp = S;
	while (IsEmpty(Tmp) == 0){
			cnt++;
			Tmp = Tmp->next;
	}
	 return cnt;
}
int Top(Stack S){
	int data;
	if (IsEmpty(S) == 0){
		data = S->next ->data;
		return data;
	}
}
