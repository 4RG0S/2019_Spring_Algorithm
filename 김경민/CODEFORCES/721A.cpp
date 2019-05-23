#include<bits/stdc++.h>
using namespace std;
int main(void){
	int input;
	cin>>input;
	int count=0;
	int temp=0;
	int c_temp=0;
	char array[input];
	for(int i=0;i<input;i++){
		cin>>array[i];
	}
	for(int i=0;i<input;i++){
		if(array[i]=='B'){
			count++;
		}
		if(array[i]=='B'&&array[i+1]=='B'){
			count--;
		}
	}
	int count_ar[count];
	for(int i=0;i<input;i++){
		if(array[i]=='B'){
			temp++;
		}
		
		if(array[i-1]=='B'&&array[i]=='W'){
			count_ar[c_temp]=temp;
			c_temp++;
			temp=0;
		}
	}
	for(int i=0;i<count;i++){
		cout<<count_ar[i]<<' ';
	}
}
