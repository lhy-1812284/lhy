#pragma warning(disable:4996)
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
typedef struct snode{
	char data;
	struct snode *next;
}LinkStrNode;
void CreateStr(LinkStrNode *&s,char t[]){
	int i;
	LinkStrNode *r,*p;
	s=(LinkStrNode *)malloc(sizeof(LinkStrNode));
	s->next=NULL;
	r=s;
	for(i=0;t[i]!='\0';i++){
		p=(LinkStrNode *)malloc(sizeof(LinkStrNode));
		p->data=t[i];
		r->next=p;r=p;
	}
	r->next=NULL;
}
void Rep(LinkStrNode *&s){
	LinkStrNode *p=s->next,*q;int find=0;
	while(p->next!=NULL&&find==0){
		if(p->data=='a'&&p->next->data=='b'){
			p->data='x';p->next->data='z';
			q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
			q->data='y';
			q->next=p->next;
			p->next=q;
			find=1;
		}
		else p=p->next;
	}
}
void DispStr(LinkStrNode *s){
	LinkStrNode *p=s->next;
	while(p!=NULL){
		printf("%c",p->data);
		p=p->next;
	}
	printf("\n");
}
void CreateStr(LinkStrNode *&s,char t[]);
void Rep(LinkStrNode *&s);
void DispStr(LinkStrNode *s);
int main(){
	LinkStrNode *s;
	char t[10];
	scanf("%s", t);
	CreateStr(s,t);
	Rep(s);
	DispStr(s);
	return 0;
} 
