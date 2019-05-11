#include<bits/stdc++.h>
using namespace std;
struct Time{
	int start,end;
};

int N;
Time arr[100000];

bool cmp(const Time &a,const Time &b){
	if(a.end==b.end){
		return a.start<b.start;
	} else{
		return a.end<b.end;
	}
}

int main(void){
	
	cin>>N;
	
	for(int i=0;i<N;i++){
		cin>>arr[i].start>>arr[i].end;
	}
	
	sort(arr,arr+N,cmp);
	
	int now=0;
	int ans=0;
	for(int i=0;i<N;i++){
		if(now<=arr[i].start){
			now=arr[i].end;
			ans+=1;
		}
	}
	
	cout<<ans;
}