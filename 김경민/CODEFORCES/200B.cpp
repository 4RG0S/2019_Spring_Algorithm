#include<bits/stdc++.h>

using namespace std;

int main(void){
	int n;
	cin>>n;
	int val[n];
	double result=0;
	for(int i=0;i<n;i++){
		cin>>val[i];
		result+=val[i];
	}
	result=result/n;
	cout<<result;
}
