//µ›πÈ√‘π¨
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 200
#define M 8
#define N 8 
int mg[M+2][N+2]=
{{1,1,1,1,1,1,1,1,1,1},{1,0,0,1,0,0,0,1,0,1},
 {1,0,0,1,0,0,0,1,0,1},{1,0,0,0,0,1,1,0,0,1},
 {1,0,1,1,1,0,0,0,0,1},{1,0,0,0,1,0,0,0,0,1},
 {1,0,1,0,0,0,1,0,0,1},{1,0,1,1,1,0,1,1,0,1},
 {1,1,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1}
 }; 
typedef struct{
	int i;
	int j;
}Box;
typedef struct{
	Box data[MaxSize];
	int length;
}PathType;
void mgpath(int xi,int yi,int xe,int ye,PathType path){
	int di,k,i,j;
	int count=0;
	if(xi==xe&&yi==ye){
		path.data[path.length].i=xi;
		path.data[path.length].j=yi;
		path.length++;
		printf("√‘π¨¬∑æ∂%d»Áœ¬:\n",++count);
		for(k=0;k<path.length;k++) printf("\t(%d,%d)",path.data[k].i,path.data[k].j);
		printf("\n");
	}
	else{
		if(mg[xi][yi]==0){
			di=0;
			while(di<4){
				path.data[path.length].i=xi;
				path.data[path.length].j=yi;
				path.length++;
				switch(di){
					case 0:i=xi-1;j=yi;break;
					case 1:i=xi;j=yi+1;break;
					case 2:i=xi+1;j=yi;break;
					case 3:i=xi;j=yi-1;break;
				}
				mg[xi][yi]=-1;
				mgpath(i,j,xe,ye,path);
				mg[xi][yi]=0;
				path.length--;
				di++; 
			}
		}
	}
} 

int main(){
	PathType path;
	mgpath(1,1,M,N,path);
	return 1;
}
