#include<bits/stdc++.h>
using namespace std;
int main(void){
	int val=0;
	int ar[4];
	for(int i=0;i<4;i++){
		cin>>ar[i];
	}
	char st[100000];
	cin>>st;
	for(int i=0;;i++){
		if(st[i]=='1'){
			val=val+ar[0];
		}
		else if(st[i]=='2'){
			val=val+ar[1];
		}
		else if(st[i]=='3'){
			val=val+ar[2];
		}
		else if(st[i]=='4'){
			val=val+ar[3];
		}
		else
		break;
	}
	cout<<val;
}
