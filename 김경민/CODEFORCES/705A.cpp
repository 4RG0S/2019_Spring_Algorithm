#include <bits/stdc++.h>

using namespace std;
int main(void){
	int boolean,n;
	cin>>n;
	boolean=0;
	for(int i=0;i<n;i++){
		if(boolean==0){
			cout<<"I hate ";
			boolean=1;
		}
		else if(boolean==1){
			cout<<"I love ";
			boolean=0;
		}
		if(i+1==n)
			cout<<"it ";
		else
			cout<<"that ";
	}
}
