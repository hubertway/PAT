#include <iostream>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

int main() {
	int m, n, tol;
	scanf("%d %d %d", &m, &n, &tol);
	vector<vector<int> >v(n);
	map<int, int>r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int pix;
			scanf("%d", &pix);
			v[i].push_back(pix);
			r[v[i][j]]++;  //标记该像素值点的个数
		}
	}
	int cnt = 0; //符合的像素点点的个数
	int column, row;
	for (int i = 0; i < n; i++) { // i是行 排除第一行和最后一行
		for (int j = 0; j < m ; j++) { // j是列 排除第一列和最后一列
			if (r[v[i][j]] == 1) {  //确保这样的点是独一无二的。
				if (((i - 1 >= 0 && j - 1 >= 0) ? (abs(v[i][j] - v[i - 1][j - 1]) > tol) : true) &&
					((i - 1 >= 0) ? (abs(v[i][j] - v[i - 1][j]) > tol) : true) &&
					((i - 1 >= 0 && j + 1 < m) ? (abs(v[i][j] - v[i - 1][j + 1]) > tol) : true) &&
					((j - 1 >= 0) ? (abs(v[i][j] - v[i][j - 1]) > tol) : true) &&
					((j + 1 < m) ? (abs(v[i][j] - v[i][j + 1]) > tol) : true) &&
					((i + 1 < n && j - 1 >= 0) ? (abs(v[i][j] - v[i + 1][j - 1]) > tol) : true) &&
					((i + 1 < n) ? (abs(v[i][j] - v[i + 1][j]) > tol) : true) &&
					((i + 1 < n && j + 1 < m) ? (abs(v[i][j] - v[i + 1][j + 1]) > tol) : true)){
					//问号运算来处理边界一周的点
					cnt++;
					row = i + 1; 
					column = j + 1;
				}
			}
		}
	}
	if (cnt == 0) printf("Not Exist\n");
	else if (cnt == 1) printf("(%d, %d): %d\n", column, row, v[row - 1][column - 1]);
	else printf("Not Unique\n");

	return 0;
}
