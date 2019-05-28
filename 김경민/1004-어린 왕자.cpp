#include<bits/stdc++.h>
using namespace std;
int count_cir=0;
struct Circle{
	int x,y,radius;
};
struct dot{
	int x,y;
};
void inCircle(struct Circle Circle, struct dot dot1, struct dot dot2){
	double length1=sqrt((dot1.x-Circle.x)*(dot1.x-Circle.x)+(dot1.y-Circle.y)*(dot1.y-Circle.y));
	double length2=sqrt((dot2.x-Circle.x)*(dot2.x-Circle.x)+(dot2.y-Circle.y)*(dot2.y-Circle.y));
	if(length1<Circle.radius^length2<Circle.radius){
		count_cir++;
	}
}
int main(){
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		count_cir=0;
		struct dot start,end;
		cin>>start.x>>start.y>>end.x>>end.y;
		int n;
		cin>>n;
		struct Circle circle[n];
		for(int j=0;j<n;j++){
			cin>>circle[j].x>>circle[j].y>>circle[j].radius;
			inCircle(circle[j],start,end);
		}
		cout<<count_cir<<'\n';
	} 
}
