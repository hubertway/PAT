There is a public bike service in Hangzhou City which provides great convenience to the tourists from all over the world. 
One may rent a bike at any station and return it to any other stations in the city.

The Public Bike Management Center (PBMC) keeps monitoring the real-time capacity of all the stations. 
A station is said to be in perfect condition if it is exactly half-full. 
If a station is full or empty, PBMC will collect or send bikes to adjust the condition of that station to perfect.
And more, all the stations on the way will be adjusted as well.

When a problem station is reported, PBMC will always choose the shortest path to reach that station.
If there are more than one shortest path, the one that requires the least number of bikes sent from PBMC will be chosen.

The stations are represented by vertices and the roads correspond to the edges.
The number on an edge is the time taken to reach one end station from another. 
The number written inside a vertex S is the current number of bikes stored at S.
Given that the maximum capacity of each station is 10.
To solve the problem at S3, we have 2 different shortest paths:
1. PBMC -> S1 -> S3. In this case, 4 bikes must be sent from PBMC, because we can collect 1 bike from S1 and then take 5 bikes to S3, so that both stations will be in perfect conditions.
2. PBMC -> S2 -> S3. This path requires the same time as path 1, but only 3 bikes sent from PBMC and hence is the one that will be chosen.

## Input Specification:
Each input file contains one test case. For each case, the first line contains 4 numbers: Cmax (<= 100), always an even number, is the maximum capacity of each station; N (<= 500), the total number of stations; S~p~, the index of the problem station (the stations are numbered from 1 to N, and PBMC is represented by the vertex 0); and M, the number of roads. 
The second line contains N non-negative numbers Ci (i=1,...N) where each Ci is the current number of bikes at Si respectively. 
Then M lines follow, each contains 3 numbers: Si, Sj, and Tij which describe the time Tij taken to move betwen stations Si and Sj. All the numbers in a line are separated by a space.

## Output Specification:
For each test case, print your results in one line. 
First output the number of bikes that PBMC must send. 
Then after one space, output the path in the format: 0->S1->...->Sp. 
Finally after another space, output the number of bikes that we must take back to PBMC after the condition of Sp is adjusted to perfect.

Note that if such a path is not unique, output the one that requires minimum number of bikes that we must take back to PBMC. 
The judge's data guarantee that such a path is unique.

## Sample Input:
```
10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1
```
## Sample Output:
```
3 0->2->3 0
```

------------------------

code:
```cpp
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int inf = 99999999;
int Cm, N, Sp, M;
int minNeed = inf, minBack = inf;
int g[502][502];
int cap[502];  // cap[i]表示i站现车数目，和完美状态相差多少
int dis[502];  //距离PBMC点距离
bool visited[502] ;
vector<int> pre[502];
vector<int> path, temppath;

void dfs(int v) {  //该部分参考柳婼
	temppath.push_back(v);
	if (v == 0) { //递归边界，退回到原点PBMC时
		int need = 0, back = 0;
		for (int i = temppath.size() - 1; i >= 0; i--) {
			int id = temppath[i];
			if (cap[id] > 0) {  //如果第id站车辆比完美量多
				back += cap[id]; //返回去车数目增加
			}
			else {  //如果第id站车辆比完美量少，或者已经完美
				if (back > (0 - cap[id])) { //如果返回去的数目比id站需要的车辆多
					back += cap[id];  //那从返回去的车中减去需要补充的车数
				}
				else {
					need += ((0 - cap[id]) - back); //得从need中补充需要的车数
					back = 0;  //back中一定已经在上一步中补充空了，重置。
				}
			}
		}
		if (need < minNeed) { 
			minNeed = need;
			minBack = back;
			path = temppath;
		}
		else if (need == minNeed && back < minBack) {
			minBack = back;
			path = temppath;
		}
		temppath.pop_back(); //删除这条已经尝试过的路径
		return;
	}
	for (int i = 0; i < pre[v].size(); i++) //一直往回退后，知道推到0点
		dfs(pre[v][i]);
	temppath.pop_back();
}

int main(){
	cin >> Cm >> N >> Sp >> M;
	for (int i = 1; i <= N; i++){
		scanf("%d", &cap[i]);
		cap[i] = cap[i] - Cm / 2;
	}

	for (int i = 0; i <502; i++){
		fill(g[i], g[i] + 502, inf); //初始图
	}
	int v, w, d;
	for (int i = 0; i < M; i++){
		cin >> v >> w >> d;
		g[v][w] = g[w][v] = d;
	}
	fill(dis, dis + 502, inf);
	fill(visited, visited + 502, false);
	dis[0] = 0;
	for (int i = 0; i <= N; i++) {
		int u = -1, min = inf;
		for (int j =  0; j <= N;j++){  //找最短距离点
			if (visited[j] == false && dis[j] < min){
				u = j; min = dis[j];
			}
		}
		if (u == -1)break;
		visited[u] = true;
		for (int v = u; v <= N; v++){
			if (visited[v] == false && g[u][v] != inf){
				if (dis[u] + g[u][v] < dis[v]){
					dis[v] = dis[u] + g[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (dis[u] + g[u][v] == dis[v]){
					pre[v].push_back(u);
				}
			}
		}
	}
	dfs(Sp);
	printf("%d 0", minNeed);
	for (int i = path.size() - 2; i >= 0; i--)
		printf("->%d", path[i]);
	printf(" %d", minBack);
	return 0;
}
```
