#include<bits/stdc++.h>

using namespace std;

int main(void){
	long long n;
	int count=0;
	int i;
	cin>>n;
	i=n/100;
	n=n-i*100;
	count=count+i;
	i=n/20;
	n=n-i*20;
	count=count+i;
	i=n/10;
	n=n-i*10;
	count=count+i;
	i=n/5;
	n=n-i*5;
	count=count+i;
	i=n/1;
	n=n-i*1;
	count=count+i;
	cout<<count;
}
