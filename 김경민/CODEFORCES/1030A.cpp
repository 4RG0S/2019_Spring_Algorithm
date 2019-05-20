#include <bits/stdc++.h>

using namespace std;
int main(void){
	int n;
	int boolean;
	cin>>n;
	int array[n];
	for(int i=0;i<n;i++){
		cin>>array[i];
	}
	for(int i=0;i<n;i++){
		if(array[i]==1){
			boolean=1;
		}
	}
	if(boolean==1)
		cout<<"HARD";
	else
		cout<<"EASY";
}
