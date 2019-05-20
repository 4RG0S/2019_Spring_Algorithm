#include<bits/stdc++.h>

using namespace std;
int main(void){
	int n,h;
	int count=0;
	cin>>n>>h;
	int input;
	for(int i=0;i<n;i++){
		cin>>input;
		if(input>h)
		count+=2;
		else
		count++;
	}
	cout<<count;
}
