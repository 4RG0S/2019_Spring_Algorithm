#include<bits/stdc++.h>
using namespace std;
int main(void){
	int n;
	cin>>n;
	int count_2=0,count_3=0;
	while(true){
		if(n-2>=0&n-2!=1){
			n=n-2;
			count_2++;
		}
		else if(n==3){
			n=n-3;
			count_3++;
		}
		else if(n==0)
		break;
	}
	cout<<count_2+count_3<<'\n';
	for(int i=0;i<count_2;i++){
		cout<<"2 ";
	}
	for(int i=0;i<count_3;i++){
		cout<<"3 ";
	}
}
