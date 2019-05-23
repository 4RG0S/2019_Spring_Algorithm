#include<bits/stdc++.h>
using namespace std;
int main(void){
	int second=0;
	int n,pos,l,r;
	cin>>n>>pos>>l>>r;
	if(abs(l-pos)>=abs(r-pos)&&r!=n){
		second=second+r-pos;
		if(r!=n){
			second=second+1;
		}
		second=second+r-l;
		if(l!=1){
			second=second+1;
		}
	}
	else if(abs(l-pos)<abs(r-pos)&&l!=1){
		second=second+l-pos;
		if(r!=n){
			second=second+1;
		}
		second=second+r-l;
		if(l!=1){
			second=second+1;
		}
	}
	cout<<second;
}
