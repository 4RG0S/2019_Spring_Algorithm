#include<bits/stdc++.h>
using namespace std;
int main(void){
	int N;
	cin>>N;
	int ar[N];
	int count=1,result=1;
	for(int i=0;i<N;i++){
		cin>>ar[i];
	}
	sort(ar,ar+N);
	for(int i=1;i<N;i++){
		if(ar[i]==ar[i-1]){
			count++;
		}
		else{
			if(count>result){
				result=count;
				count=1;
			}
		}
	}
	cout<<result;
}
