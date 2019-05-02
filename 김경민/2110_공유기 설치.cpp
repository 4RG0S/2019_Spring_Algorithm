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
	
	int left=1;	//������ �ּ� �� ��  
	int right=ar[n-1]-ar[0]; //������ �ִ� �Ÿ�
	int d=0;
	int ans=0;
	
	while(left<=right){
		int mid=(left+right)/2; //����  
		int start=ar[0];
		int cnt=1;
		
		//����(d)�� �������� ������ ��ġ  
		for(int i=1;i<n;i++){
			d=ar[i]-start;
			if(mid<=d){
				cnt++;
				start=ar[i];
			}
		}
		
		if(cnt>=c){
			//�������� ���� ����
			ans=mid;
			left=mid+1;
		} else{
            //�������� ���� �ø�
			right=mid-1;
		}
	}
	cout<<ans;
}