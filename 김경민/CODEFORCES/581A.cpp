#include<bits/stdc++.h>
using namespace std;
int main(void){
	int a,b,count=0,large=0,small=0;
	cin>>a>>b;
	if(a>b){
		large=a;
		small=b;
		cout<<b<<' ';
	}
	else if(a<b){
		large=b;
		small=a;
		cout<<a<<' ';
	}
	else if(a==b)
	cout<<a<<' ';
	while(true){
		if(large-2>=small){
			large=large-2;
			count++;
		}
		else
		break;
	}
	cout<<count;
}
