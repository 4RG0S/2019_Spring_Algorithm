#include<bits/stdc++.h>

using namespace std;

int main(void){
	int array[5][5],count=0;
	int rows,columns;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cin>>array[i][j];
			if(array[i][j]==1){
				rows=i;
				columns=j;
			}
		}
	}
	count=abs(2-rows)+abs(2-columns);
	cout<<count;
}
