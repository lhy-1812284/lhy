#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
typedef struct{
	int n;
	char x,y,z;
	bool flag;
}ElemType;
typedef struct{
	ElemType data[MaxSize];
	int top;
}StackType;
void InitStack(StackType *&s){
	s=(StackType *)malloc(sizeof(StackType));
	s->top=-1;
}
bool Push(StackType *&s,ElemType e){
	if(s->top==MaxSize-1) return false;
	s->top++;
	s->data[s->top]=e;
	return true;
}
bool StackEmpty(StackType *s){
	return(s->top==-1);
}
bool Pop(StackType *&s,ElemType &e){
	if(s->top==-1) return false;
	e=s->data[s->top];
	s->top--;
}
void DestroyStack(StackType *&s){
	free(s);
}
void Hanoil2(int n,char x,char y,char z){
	StackType *st;
	ElemType e,e1,e2,e3;
	if(n<=0) return;
	InitStack(st);
	e.n=n,e.x=x,e.y=y,e.z=z;e.flag=false;
	Push(st,e);
	while(!StackEmpty(st)){
		Pop(st,e);
		if(e.n<0){
			exit(1);
		} 
		if(e.flag==false){
			e1.n=e.n-1;e1.x=e.y;e1.y=e.x;e1.z=e.z;
			if(e1.n==1) e.flag=true;
			else e1.flag=false;
			Push(st,e1);
			e2.n=e.n;e2.x=e.x;e2.y=e.y;e2.z=e.z;e2.flag=true;
			Push(st,e2);
			e3.n=e.n-1;e3.x=e.x;e3.y=e.z;e3.z=e.y;
			if(e3.n==1) e3.flag=true;
			else e3.flag=true;
			Push(st,e3);
		}
		else printf("\t将第%d个盘片从%c移动到%c\n",e.n,e.x,e.z);
	}
	DestroyStack(st);
}
int main(){
	int n;
	printf("请输入盘片个数:\n");
	scanf("%d",&n);
	Hanoil2(n,'A','B','C');
	return 0;
}
