#include<iostream>
using namespace std;

int main(){
	int n;
	char c;
	cin>>n>>c;
	int m ;
	if(n%2 == 0) m= n/2;
	else m = n/2 + 1; 
	int i,j;
	for(i = 1;i <= m;i++){
		for(j = 1;j<=n;j++){
			if(i==1||i==m||j==1||j==n)
				printf("%c",c);
			else printf(" ");
		}
		printf("\n");
	}
	
	return 0;
} 
