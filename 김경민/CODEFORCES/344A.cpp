#include<bits/stdc++.h>

using namespace std;
int main(void){
	int n;
	int count=0;
	cin>>n;
	int i[n];
	for(int j=0;j<n;j++){
		cin>>i[n];
	}
	for(int j=1;j<n;j++){
		if(i[j]==10&i[j-1]==1){
			count++;
		}
		if(i[j]==1&i[j-1]==10){
			count++;
		}
	}
	cout<<count;
	cout<<i[2];
}
