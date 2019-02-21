#include <iostream>
#include <map>
using namespace std;

struct Player {
	bool isF ; //是不是第一名
	bool isp ; //排名是否是素数
	bool check = false; //是否领过奖了，默认没有
};

bool isPrime(int a) {
	if (a < 2) return false;
	if (a == 2) return true;
	else {
		bool flag = true;
		for (int i = 2; i*i <= a; i++) {
			if (a%i == 0){
				flag = false;
				break;
			}
		}
		return flag;
	}
}

int main() {
	int N, K;
	scanf("%d", &N);
	map<int, Player>m;
	int id;
	for (int i = 1; i <=N; i++) {
		scanf("%d", &id);
		if (i == 1) m[id].isF = true;
		else m[id].isF = false;
		if (isPrime(i)) m[id].isp = true;
		else m[id].isp = false;
	}
	scanf("%d", &K); 
	int test;
	for (int i = 0; i < K; i++) {
		scanf("%d", &test);
		if (m.find(test) == m.end()) { //不存在这个id
			printf("%04d: Are you kidding?\n",test);
		}
		else {
			if (!m[test].check) { //没有领奖过
				if (m[test].isF) {  //是第一名
					printf("%04d: Mystery Award\n", test);
					m[test].check = true;
				}
				else if (m[test].isp) { // 排名是素数
					printf("%04d: Minion\n", test);
					m[test].check = true;
				}
				else { //其他人
					printf("%04d: Chocolate\n", test);
					m[test].check = true;
				}
			}
			else {
				printf("%04d: Checked\n", test);
			}
		}
	}

	return 0;
}
