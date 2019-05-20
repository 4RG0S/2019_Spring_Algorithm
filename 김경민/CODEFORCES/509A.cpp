#include<bits/stdc++.h>
using namespace std;
int main(void){
	int n;
	cin>>n;
	int array[n][n];
	for(int i=0;i<n;i++){
		array[0][i]=1;
		array[i][0]=1;
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			array[i][j]=array[i-1][j]+array[i][j-1];
		}
	}
	cout<<array[n-1][n-1];
}
