As an emergency rescue team leader of a city, you are given a special map of your country. 
The map shows several scattered cities connected by some roads. 
Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. 
When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.

Input
Each input file contains one test case.
For each test case, the first line contains 4 positive integers: N (<= 500) - the number of cities (and the cities are numbered from 0 to N-1), M - the number of roads, C1 and C2 - the cities that you are currently in and that you must save, respectively. 
The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city.
Then M lines follow, each describes a road with three integers c1, c2 and L, which are the pair of cities connected by a road and the length of that road, respectively. 
It is guaranteed that there exists at least one path from C1 to C2.

Output
For each test case, print in one line two numbers: the number of different shortest paths between C1 and C2, and the maximum amount of rescue teams you can possibly gather.
All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.

Sample Input
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
Sample Output
2 4

code:
/*
@求最短路径，最短相等则求顶点权重和最大者，有权图的单源最短路Dijkstra算法
@最后打印有多少条不同的最短路径，以及能聚集的最大人数
@从i到i这样的自己到自己，也是一种最短路径，救援人数就是该顶点权重(人数)
*/
#include<iostream>
#include<algorithm>

using namespace std;
#define MaxVertex 501
#define INFINITY 99999

int N, M, C1, C2;
int human[MaxVertex];  //记录每个顶点的权重
int G[MaxVertex][MaxVertex];
int dist[MaxVertex]; //dist[i]表示从出发点到i的距离
int hands[MaxVertex]; //hands[i]表示表示从出发点到i能叫来的人手
int num[MaxVertex]; //num[i]表示从出发点到i点的不同最短路径条数
bool collected[MaxVertex];

int main() {
	scanf("%d%d%d%d", &N, &M, &C1, &C2);
	for (int i = 0; i < N; i++) // 录入顶点权重
		scanf("%d", &human[i]);

	for (int i = 0; i < MaxVertex; i++) //初始化图
		fill(G[i], G[i] + MaxVertex, INFINITY);

	int v1, v2, el;  //顶点v1,v2，和它们间的边长el
	for (int i = 0; i < M; i++){ //录入无向图
		scanf("%d%d%d", &v1, &v2, &el);
		G[v1][v2] = el; G[v2][v1] = el;
	}

	fill(dist, dist + MaxVertex, INFINITY);
	for (int i = 0; i < N; i++) dist[i] = G[C1][i];//初始化dist

	for (int i = 0; i < N; i++){  //初始化hands 和 num
		if (G[C1][i] != INFINITY && C1 != i){
			hands[i] = human[C1] + human[i];
			num[i] = 1;
		}
	}
	hands[C1] = human[C1]; 
	collected[C1] = true;
	num[C1] = 1;  

	while (1){
		int v = -1, mind = INFINITY;
		for (int i = 0; i < N; i++){
			if (collected[i] == false && mind>dist[i]){
				v = i;
				mind = dist[i];
			}
		}
		if (v == -1)break;
		collected[v] = true;
		for (int w = 0; w < N; w++){
			if (collected[w] == false && G[v][w] != INFINITY){
				if (dist[w]>dist[v] + G[v][w]){
					dist[w] = dist[v] + G[v][w]; //更新最短路径
					hands[w] = hands[v] + human[w];
					num[w] = num[v];  //救援路径经过的顶点变多，但是距离变短，不同的最短路径条数便更新为前一个顶点的数据
				}
				else if (dist[w] == dist[v] + G[v][w]){
					num[w] = num[w] + num[v]; //又多了最短救援路径
					if (hands[w] < hands[v] + human[w])
						hands[w] = hands[v] + human[w]; // 把救援人数更新到最大
				}
			}
		}
	}
	printf("%d %d\n", num[C2], hands[C2]);
	return 0;
}
