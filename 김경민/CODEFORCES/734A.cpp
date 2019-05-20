#include<bits/stdc++.h>

using namespace std;
int main(void){
	int n;
	int count_A=0,count_D=0;
	cin>>n;
	char name[n];
	for(int i=0;i<n;i++){
		cin>>name[i];
	}
	for(int i=0;i<n;i++){
		if(name[i]=='A')
		count_A++;
		else if(name[i]=='D')
		count_D++;
	}
	if(count_A>count_D)
	cout<<"Anton";
	else if(count_A<count_D)
	cout<<"Danik";
	else if(count_A==count_D)
	cout<<"Friendship";
}
