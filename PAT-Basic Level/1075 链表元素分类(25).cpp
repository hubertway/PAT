#include <iostream>
#include  <vector>
using namespace std;

int main() {
	int fa, n, k; //第 1 个结点的地址、结点总个数、基准数k
	cin >> fa >> n >> k;
	vector<int>v(100010);			//v[adress] = data
	vector<int>next(100010);		//next[adress] = next
	vector<int> result(100010);	//输出顺序 result[adress] = new next
	for (int i = 0; i < n; i++) {
		int A, D, N;
		cin >> A >> D >> N;
		v[A] = D; next[A] = N;
	}

    //找到 new first adress
	int fn; //new first adress
	bool flag = false;  //确定是否找到 new first adress
	int ad = fa;
	while (!flag && ad !=-1) {
		if (v[ad] < 0) {
			flag = true;
			fn = ad;
		}
		ad = next[ad];
	}
	while (!flag && ad != -1) {
		if (v[ad] >= 0 && v[ad] <=k) {
			flag = true;
			fn = ad;
		}
		ad = next[ad];
	}
	while (!flag && ad != -1) {
		if (v[ad] > k) {
			flag = true;
			fn = ad;
		}
		ad = next[ad];
	}

    //分别找出 <0 , [0,k],>k的三类结点。 
	ad = fa;
	int t = fn;
	//先读所有负值元素
	while (ad != -1) {
		if (v[ad] < 0 && ad != fn) {
			result[t] = ad;
			t = ad;
		}
		ad = next[ad];
	}
	//再读[0, K] 区间内的元素
	ad = fa;
	while (ad != -1) {
		if (v[ad] >= 0 && v[ad] <= k  && ad != fn) {
			result[t] = ad;
			t = ad;
		}
		ad = next[ad];
	}
	//最后读大于 K 的元素
	ad = fa;
	while (ad != -1) {
		if (v[ad] > k && ad != fn) {
			result[t] = ad;
			t = ad;
		}
		ad = next[ad];
	}
	result[t] = -1;  //收尾

	//输出
	ad= fn;
	while (ad != -1) {
		if(result[ad] !=-1 )printf("%05d %d %05d\n", ad, v[ad], result[ad]);
		else printf("%05d %d -1\n", ad, v[ad]);
		ad = result[ad];
	}


	return 0;
}
