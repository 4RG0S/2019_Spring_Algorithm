#include<bits/stdc++.h>
using namespace std;
int main(void){
	int n,large=INT_MIN,count=0;
	cin>>n;
	int num[n];
	for(int i=0;i<n;i++){
		cin>>num[i];
		if(large<num[i]){
			large=num[i];
		}
	}
	for(int i=0;i<n;i++){
		while(true){
			if(num[i]<large){
				count=count+(large-num[i]);
				break;
			}
			else
			break;
		}
	}
	cout<<count;
}
