https://pintia.cn/problem-sets/994805342720868352/problems/994805424153280512

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int weight;
	vector<int >child;
};
int n, m, s;
vector<node>v;
vector<int>path;
bool cmp1(int a, int b){
	return v[a].weight > v[b].weight;
}
void DFS(int root, int num, int sum){ //节点，当前路径上的节点数目，目前权重和
	if (sum > s) return;  //已经大于了目标权重，返回忽视
	if (sum == s){
		if (v[root].child.size() != 0) return; //不是叶节点
		for (int i = 0; i < num;i++){  //符合所有条件，输出路径
			if (i != 0) printf(" ");
			printf("%d",v[path[i]].weight);
			if (i == num - 1) printf("\n");
		}
	}
	for (int i = 0; i < v[root].child.size(); i++){ //dfs该结点所有子节点，统计权重
		int node = v[root].child[i];
		path[num] = node;
		DFS(node, num + 1, sum + v[node].weight);
	}
}

int main(){
	cin >> n >> m >> s;
	v.resize(n); path.resize(n);
	int weight;
	for (int i = 0; i < n; i++){
		cin >> weight;
		v[i].weight = weight;
	}
	int node, k;
	for (int i = 0; i < m; i++){
		cin >> node >> k;
		v[node].child.resize(k);
		for (int j = 0; j < k; j++){
			scanf("%d", &v[node].child[j]);
		}
		sort(v[node].child.begin(), v[node].child.end(), cmp1); //将node结点的所有子树按weight排序，方便后序输出
	}

	DFS(0, 1, v[0].weight);
	return 0;
}
