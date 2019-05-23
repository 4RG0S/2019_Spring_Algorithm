#include<bits/stdc++.h>

using namespace std;
int main(void){
	int n;
	cin>>n;
	int count=1;
	char val[n][2];
	for(int i=0;i<n;i++){
		cin>>val[i];
	}
	for(int i=1;i<n;i++){
		if(val[i][1]=='0'&val[i-1][1]=='1')
		count++;
		if(val[i][1]=='1'&val[i-1][1]=='0')
		count++;

	}
	cout<<count;
}
