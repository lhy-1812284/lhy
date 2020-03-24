#include<stdio.h>
#include<stdlib.h>
void yuesehuan(int count,int a){
	int alive=count;
	int number=0;
	int index=0;
	int *circle=NULL;
	
	circle=(int *)calloc(sizeof(int),count);
	
	while(alive>0){
		number+=1-circle[index];
		if(number==a){
			if(alive==1){
				printf("最后剩下第%d个人",index+1);
			}
			circle[index]=1;
			alive--;
			number=0;
		}
		index=(index+1)%count;
	}
}
void yuesehuan(int count,int a);
int main(){
	yuesehuan(30,4);
	return 0;
} 
