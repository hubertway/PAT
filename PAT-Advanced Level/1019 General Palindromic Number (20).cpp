https://pintia.cn/problem-sets/994805342720868352/problems/994805487143337984

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long n, b;
int main(){
	scanf("%lld%lld", &n, &b);
	vector<long long>trans ;
	if (!n)printf("Yes\n0");
	else{
		while (n > 0){
			trans.push_back(n%b);
			n /= b;
		}
		vector<long long>rev;
		rev = trans;
		reverse(rev.begin(), rev.end());
		int flag = 1;
		for (int i = 0; i < trans.size(); i++){
			if (rev[i] != trans[i]){
				flag = 0;
				break;
			}
		}
		if (flag)printf("Yes\n");
		else printf("No\n");
		for (int i = 0; i < rev.size(); i++){
			if (i != 0)printf(" ");
			printf("%lld", rev[i]);
		}
	}
	return 0;
}
