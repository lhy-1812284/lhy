#include<stdio.h>
#include<stdlib.h>
#define Max_Size 15
int main(){
	static int square[Max_Size][Max_Size];
	int i,j,row,column,count,size;
	printf("��������С:\n");
	scanf("%d",&size);
	if(size<1||size>Max_Size){
		printf("��������С������Ҫ��"); 
		exit(1); 
	}
	if(!(size%2)){
		printf("������������С"); 
	}
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			square[i][j]=0;
		}
	}
	square[0][(size-1)/2]=1;
	i=0;j=(size-1)/2;
	for(count=2;count<=size*size;count++){
		row=(i-1<0)?(size-1):(i-1);
		column=(j-1<0)?(size-1):(j-1);
		if(square[row][column]) i=(++i)%size;
		else{
			i=row;
			j=column;
		}
		square[i][j]=count;
	}
	printf("��СΪ%d��ħ������Ϊ:\n",size);
	for(i=0;i<size;i++){
		for(j=0;j<size;j++) printf("%4d",square[i][j]);
		printf("\n");
	}
}
