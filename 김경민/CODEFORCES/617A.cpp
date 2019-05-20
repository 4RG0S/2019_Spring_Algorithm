#include<bits/stdc++.h>

using namespace std;
int main(void){
	int x;
	int count=0;
	cin>>x;
	while(true){
		if(x-5>=0){
			x=x-5;
			count++;
		}
		else
		break;
	}
		while(true){
		if(x-4>=0){
			x=x-4;
			count++;
		}
		else
		break;
	}
		while(true){
		if(x-3>=0){
			x=x-3;
			count++;
		}
		else
		break;
	}
		while(true){
		if(x-2>=0){
			x=x-2;
			count++;
		}
		else
		break;
	}
		while(true){
		if(x-1>=0){
			x=x-1;
			count++;
		}
		else
		break;
	}
	cout<<count;
}
