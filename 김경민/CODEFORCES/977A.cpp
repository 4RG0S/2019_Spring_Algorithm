#include <iostream>

int main(void){
	int num,count;
	std::cin>>num;
	std::cin>>count;
	while(count--){
		if(num%10!=0){
			num=num-1;
		}
		else{
			num=num/10;
		}
	}
	std::cout<<num;
}
