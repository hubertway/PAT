A family hierarchy is usually presented by a pedigree tree. Your job is to count those family members who have no child.

Input
Each input file contains one test case. Each case starts with a line containing 0 < N < 100, the number of nodes in a tree, and M (< N), the number of non-leaf nodes. 
Then M lines follow, each in the format:
ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID's of its children. 
For the sake of simplicity, let us fix the root ID to be 01.

Output
For each test case, you are supposed to count those family members who have no child for every seniority level starting from the root. 
The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.

The sample case represents a tree with only 2 nodes, where 01 is the root and 02 is its only child. Hence on the root 01 level, there is 0 leaf node; and on the next level, there is 1 leaf node. 
Then we should output "0 1" in a line.

Sample Input
2 1
01 1 02
Sample Output
0 1

code:
/*
@通过家谱树找出没有孩子的成员
@给出树结点总个数和非叶节点个数，再给出非叶节点的子节点个数和编号，层序输出叶节点的个数
@参考柳婼设立level数组，保存i结点的层数
*/
#include<iostream>
#include<queue>
#include <vector>
#define MaxN 101
using namespace std;

int N, M;
vector<int>t[MaxN];
int num[MaxN]; //表示第i层有num[i]个叶节点
int maxlevel = -1; //记录最大层数
int level[MaxN]; //保存i结点的层数

int main() {
	scanf("%d %d", &N, &M);
	if (N){ //N不为零
		int node, k, child;
		for (int i = 0; i < M; i++){
			scanf("%d %d", &node, &k);
			for (int j = 0; j < k; j++){
				scanf("%d", &child);
				t[node].push_back(child);
			}
		}

		queue<int>q;
		q.push(1);
		while (!q.empty()){
			int temp = q.front();
			q.pop();
			maxlevel = level[temp];
			if (t[temp].size() == 0)
				num[level[temp]]++;
			for (int i = 0; i < t[temp].size(); i++){
				q.push(t[temp][i]);
				level[t[temp][i]] = level[temp] + 1;
			}
		}

		printf("%d", num[0]);
		for (int i = 1; i <= maxlevel; i++)
			printf(" %d", num[i]);
	}
	return 0;
}
