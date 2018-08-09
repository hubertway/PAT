
#include<iostream>
#include<vector>
using namespace std;
int n;
int main(){
	scanf("%d", &n);
	vector<int>v(100001,0);
	vector<int>a(100001);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		v[a[i]]++;
	}
	int i;
	for (i = 0; i < 100001; i++){
		if (v[a[i]] == 1){
			printf("%d", a[i]);
			break;
		}
	}
	if (i == 100001)printf("None\n");
	return 0;
}
