#include<bits/stdc++.h>
using namespace std;
int main(void){
	int n,c;
	cin>>n>>c;
	int ar[n];
	for(int i=0;i<n;i++){
		cin>>ar[i];
	}
	sort(ar,ar+n);
	
	int left=1;	//가능한 최소 거 리  
	int right=ar[n-1]-ar[0]; //가능한 최대 거리
	int d=0;
	int ans=0;
	
	while(left<=right){
		int mid=(left+right)/2; //기준  
		int start=ar[0];
		int cnt=1;
		
		//간격(d)를 기준으로 공유기 설치  
		for(int i=1;i<n;i++){
			d=ar[i]-start;
			if(mid<=d){
				cnt++;
				start=ar[i];
			}
		}
		
		if(cnt>=c){
			//공유기의 수를 줄임
			ans=mid;
			left=mid+1;
		} else{
            //공유기의 수를 늘림
			right=mid-1;
		}
	}
	cout<<ans;
}