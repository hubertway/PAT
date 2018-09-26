#include<iostream>
using namespace std;

int main(){
	int s[100010]={0};
	int n,id,score;
	cin>>n;
	for(int i =0;i<n;i++){
		cin>>id>>score;
		s[id] += score;
	}
	int max = -1,index = 1;
	for(int i=1;i<=n;i++){
		if(s[i] > max){
			max = s[i];
			index = i;
		}
	}
	cout<<index<<" "<<max<<endl;
	return 0;
} 
