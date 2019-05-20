#include<bits/stdc++.h>

using namespace std;

int main(void){
	int day,count_S=0,count_F=0;
	cin>>day;
	char place[day];
	for(int i=0;i<day;i++){
		cin>>place[i];
	}
	for(int i=1;i<day;i++){
		if(place[i-1]=='S'&place[i]=='F')
		count_F++;
		else if(place[i-1]=='F'&place[i]=='S')
		count_S++;
	}
	if(count_F>count_S)
	cout<<"YES";
	else
	cout<<"NO";
}
