#include<bits/stdc++.h>

using namespace std;

int main(void){
	int check=0;
	char cardset[2];
	char card[2];
	cin>>cardset;
	for(int i=0;i<5;i++){
		cin>>card;
		if(cardset[1]==card[1]||cardset[0]==card[0]){
			check=1;
		}
	}
	if(check==1)
	cout<<"YES";
	else
	cout<<"NO";
}
