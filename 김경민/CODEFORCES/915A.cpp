#include <bits/stdc++.h>

using namespace std;
int main(void){
	int n,k,temp,count,result;
	result=10000;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		count=0;
		temp=k;
		while(true){
			temp=temp-a[i];
			count++;
			if(temp<=0)
			break;
		}
		if(temp==0&count<result){
			result=count;
		}
	}
	cout<<result;
}
