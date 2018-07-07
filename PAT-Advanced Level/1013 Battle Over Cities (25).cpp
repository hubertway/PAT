It is vitally important to have all the cities connected by highways in a war. If a city is occupied by the enemy, all the highways from/toward that city are closed. We must know immediately if we need to repair any other highways to keep the rest of the cities connected. Given the map of cities which have all the remaining highways marked, you are supposed to tell the number of highways need to be repaired, quickly.

For example, if we have 3 cities and 2 highways connecting city~1~-city~2~ and city~1~-city~3~. Then if city~1~ is occupied by the enemy, we must have 1 highway repaired, that is the highway city~2~-city~3~.

Input
Each input file contains one test case. Each case starts with a line containing 3 numbers N (&lt1000), M and K, which are the total number of cities, the number of remaining highways, and the number of cities to be checked, respectively. Then M lines follow, each describes a highway by 2 integers, which are the numbers of the cities the highway connects. The cities are numbered from 1 to N. Finally there is a line containing K numbers, which represent the cities we concern.

Output
For each of the K cities, output in a line the number of highways need to be repaired if that city is lost.

Sample Input
3 2 3
1 2
1 3
1 2 3
Sample Output
1
0
0

code:
//给出顶点(city)和边(highway)，求假如去掉某个顶点(lost)，要使剩余顶点连通，需要添加几条新边
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int g[1002][1002];
bool visited[1002];  
int n, m, k;
void DFS(int vertex);
int main(){
	cin >> n >> m >> k;
	if (n == 0 )printf("0\n");
	int v, w;
	for (int i = 0; i < m; i++){
		cin >> v >> w;
		g[v][w] = g[w][v] = 1;
	}
	
	for (int i = 0; i < k; i++){
		int l,cnt = 0;
		fill(visited, visited + 1002, false); //重置是否访问过
		cin >> l;
		visited[l] = true;
		for (int j = 1; j <=n; j++){ //访问每个连通集
			if (visited[j] == false){
				DFS(j);
				cnt++;  //这是在统计去掉 lost 以后,剩下多少个连通分量
			}
		}
		printf("%d\n", cnt - 1);  //cnt个独立连通分量变为连通图要cnt个边
	}
	return 0;
}
void DFS(int vertex){
	visited[vertex] = true;
	for (int i = 1; i <= n; i++){
		if (visited[i] == false && g[vertex][i] == 1){
			DFS(i);
		}
	}
}
