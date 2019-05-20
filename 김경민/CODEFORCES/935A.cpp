#include <bits/stdc++.h>

using namespace std;
int main(void){
	int n,count,temp;
	count=0;
	cin>>n;
	for(int i=0;i<n;i++){
		temp=i+1;
		if(n%temp==0&n!=temp){
			count++;
		}
	}
	cout<<count;
}
