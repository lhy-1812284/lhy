//队列迷宫 
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
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
	int i,j;
	int pre;
}Box;
typedef struct{
	Box data[MaxSize];
	int front,rear;
}QuType;
void InitQueue(QuType *&q){
	q=(QuType *)malloc(sizeof(QuType));
	q->front=q->rear=-1;
}
void DestroyQueue(QuType *&q){
	free(q);
} 
bool QueueEmpty(QuType *q){
	return(q->front==q->rear);
}
bool enQueue(QuType *&q,Box e){
	if(q->rear==MaxSize-1) return false;
	q->rear++;
	q->data[q->rear]=e;
	return true;
}
bool deQueue(QuType *&q,Box &e){
	if(q->front==q->rear) return false;
	q->front++;
	e=q->data[q->front];
	return true;
}
void print(QuType *qu,int front); 
bool mgpath1(int xi,int yi,int xe,int ye){
	Box e;
	int i,j,di,i1,j1;
	QuType *qu;
	InitQueue(qu);
	e.i=xi;e.j=yi;e.pre=-1;
	enQueue(qu,e);
	mg[xi][yi]=-1;
	while(!QueueEmpty(qu)){
		deQueue(qu,e);
		i=e.i;j=e.j;
		if(i==xe&&j==ye){
			print(qu,qu->front);
			DestroyQueue(qu);
			return true;
		}
		for(di=0;di<4;di++){
			switch(di){
				case 0:i1=i-1;j1=j;break;
				case 1:i1=i;j1=j+1;break;
				case 2:i1=i+1;j1=j;break;
				case 3:i1=i;j1=j-1;break;
			}
			if(mg[i1][j1]==0){
				e.i=i1;e.j=j1;
				e.pre=qu->front;
				enQueue(qu,e);
				mg[i1][j1]=-1;
			}
		}
	}
	DestroyQueue(qu);
	return false;
}
void print(QuType *qu,int front){
	int k=front,j,ns=0;
	printf("\n");
	do{
		j=k;
		k=qu->data[k].pre;
		qu->data[j].pre=-1;
	}while(k!=0);
	printf("一条迷宫的路径如下:\n");
	k=0;
	while(k<MaxSize){
		if(qu->data[k].pre==-1){
			ns++;
			printf("\t(%d,%d)",qu->data[k].i,qu->data[k].j);
			if(ns%5==0) printf("\n");
		}
		k++;
	}
	printf("\n");
}

int main(){
	if(!mgpath1(1,1,M,N)) printf("该迷宫没有解!\n");
	return 1;
}
