#include<stdio.h>
void Hanoil(int n,char x,char y, char z){
	if(n==1) printf("����%d����Ƭ��%c�ƶ���%c\n",n,x,y);
	else{
		Hanoil(n-1,x,z,y);
		printf("����%d����Ƭ��%c�ƶ���%c\n",n,x,z);
		Hanoil(n-1,y,x,z);
	}
}


