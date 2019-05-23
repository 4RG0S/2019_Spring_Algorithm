#include <bits/stdc++.h>

using namespace std;
int main(void){
	int count,num;
	string str;
	num=0;
	cin>>count;
	for(int i=0;i<count;i++){
		cin>>str;
		if(str=="Tetrahedron")
		num=num+4;
		else if(str=="Cube")
		num=num+6;
		else if(str=="Octahedron")
		num=num+8;
		else if(str=="Dodecahedron")
		num=num+12;
		else if(str=="Icosahedron")
		num=num+20;
	}
	cout<<num;
	
}
