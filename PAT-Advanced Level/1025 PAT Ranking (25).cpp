https://pintia.cn/problem-sets/994805342720868352/problems/994805474338127872

#include <iostream>
#include <algorithm>
using namespace std;

typedef struct node {
	long long id;
	int score;
	int local_id;
	int local_rank;
}Student;

bool cmp(node a, node b) {
	if (a.score != b.score) return a.score > b.score;
	else return a.id < b.id;
}

int main() {
	Student data[30010];
	int n, k, total = 0; //n个考场，k个考生，total个总考生数
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			scanf("%lld  %d", &data[total].id, &data[total].score);
			data[total].local_id = i+1;
			total++;
		}
		sort(data + total - k, data + total, cmp); //为该考场的考生排序
		data[total - k].local_rank = 1;		//该考场第一个排名为1
		for (int j = total-k+1; j < total; j++) {		 //该考场剩下的人排名
			if (data[j].score == data[j - 1].score) data[j].local_rank = data[j - 1].local_rank;
			else data[j].local_rank = j+1-(total-k);
		}
	}
	cout << total << endl;
	sort(data, data + total, cmp);
	int r = 1;  //全部考生的总排名
	for (int i = 0; i < total; i++) {
		if (i > 0 && data[i].score != data[i - 1].score)
			r = i + 1;
		printf("%lld %d %d %d\n", data[i].id,  r,  data[i].local_id,  data[i].local_rank);
	}
	return 0;
}
