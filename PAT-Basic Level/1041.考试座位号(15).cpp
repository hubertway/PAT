#include <iostream>
#include <string>
#include <map>
using namespace std;

typedef struct data {
	string id; //准考证号
	int num; //考试座位号
}Inf;

int main() {
	int N;
	map<int, Inf>m;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		string s;
		int a, b;  //a为试机，b为考试
		Inf d;
		cin >> s >> a >> b;
		d.id = s;
		d.num = b;
		m[a] = d;
	}
	int M;
	scanf("%d", &M);
	int t; //需要查询的试机号
	for (int i = 0; i < M; i++) {
		scanf("%d", &t);
		cout << m[t].id << " " << m[t].num << endl;
	}
	return 0;
}
