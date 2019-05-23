#include<bits/stdc++.h>

using namespace std;
int main(void){
	int friends;
	cin>>friends;
	int gift[friends];
	for(int i=0;i<friends;i++){
		cin>>gift[i];
	}
	for(int i=0;i<friends;i++){
		for(int j=0;j<friends;j++){
			if(gift[j]==i+1){
				cout<<j+1<<' ';
			}
		}
	}
}
