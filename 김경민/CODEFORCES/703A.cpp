#include<bits/stdc++.h>
using namespace std;
int main(void){
	int n;
	cin>>n;
	int m,c,m_w=0,c_w=0;
	for(int i=0;i<n;i++){
		cin>>m>>c;
		if(m>c)
		m_w++;
		else if(m<c)
		c_w++;
	}
	if(m_w>c_w)
	cout<<"Mishka";
	else if(m_w<c_w)
	cout<<"Chris";
	else if(m_w==c_w)
	cout<<"Friendship is magic!^^";
}
