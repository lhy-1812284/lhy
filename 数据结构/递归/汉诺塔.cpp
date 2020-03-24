#include<stdio.h>
void Hanoil(int n,char x,char y, char z){
	if(n==1) printf("将第%d个盘片从%c移动到%c\n",n,x,y);
	else{
		Hanoil(n-1,x,z,y);
		printf("将第%d个盘片从%c移动到%c\n",n,x,z);
		Hanoil(n-1,y,x,z);
	}
}


