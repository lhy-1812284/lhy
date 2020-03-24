#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node *next;
}LinkList;
void yuesehuan(int n,int m){
	LinkList *p=NULL,*x=NULL,*list=NULL;
	int i;
	for(i=1;i<=n;i++){
		p=(LinkList *)malloc(sizeof(LinkList));
		p->data=i;
		if(list==NULL) list=p;
		else x->next=p;
		x=p;
	}
	p->next=list;
	p=list;
	while(p->next!=p){
		for(i=1;i<m;i++){
			x=p;
			p=p->next;
		}
		x->next=p->next;
		free(p);
		p=x->next;
	}
	printf("最后剩下第%d个人",p->data);
	free(p);
}
void yuesehuan(int n,int m);
int main(){
	yuesehuan(30,4);
	return 0;
}
