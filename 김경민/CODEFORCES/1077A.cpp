#include<bits/stdc++.h>
using namespace std;
int main(void){
	int n;
	cin>>n;
	long long val[n];
	for(int i=0;i<n;i++){
		int a,b;
		long long k;
		val[i]=0;
		cin>>a>>b>>k;
		if(k%2==0){
			val[i]=k/2*(a-b);
		}
		else if(k%2==1){
			val[i]=(k-1)/2*(a-b)+a;
		}
	}
	for(int i=0;i<n;i++){
		cout<<val[i]<<'\n';
	}
}
