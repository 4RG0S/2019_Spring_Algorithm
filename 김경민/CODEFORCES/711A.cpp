#include<bits/stdc++.h>
using namespace std;
int main(void){
	int n;
	bool val=false;
	cin>>n;
	char array[n][5];
	for(int i=0;i<n;i++){
		cin>>array[i];
	}
	for(int i=0;i<n;i++){
		if(array[i][0]=='O'&array[i][1]=='O'){
			val=true;
			array[i][0]='+';
			array[i][1]='+';
			break;
		}
		if(array[i][3]=='O'&array[i][4]=='O'){
			val=true;
			array[i][3]='+';
			array[i][4]='+';
			break;
		}
	}
	if(val==true){
		
		cout<<"YES"<<'\n';
		
	}
	
	else if(val==false)
		cout<<"NO";
	if(val==true){
		for(int i=0;i<n;i++){
		cout<<array[i][0];
		cout<<array[i][1];
		cout<<array[i][2];
		cout<<array[i][3];
		cout<<array[i][4]<<'\n';
	}
	}
}
