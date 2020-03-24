#include<stdio.h>
#include<stdlib.h>
typedef struct lnode{
	int tag;
	union{
		char data;
		struct lnode *sublist;
	}val;
	struct lnode *link;
}GLNode;

int GLLength(GLNode *g){
	int n=0;
	GLNode *g1;
	g1=g->val.sublist;
	while(g1!=NULL){
		n++;
		g1=g1->link;
	}
	return n;
}

int GLDepth(GLNode *g){
	GLNode *g1;
	int maxd=0,dep;
	if(g->tag==0) return 0;
	g1=g->val.sublist;
	if(g1==NULL) return 1;
	while(g1!=NULL){
		if(g1->tag==1){
			dep=GLDepth(g1);
			if(dep>maxd) dep=maxd;
		}
		g1=g1->link;
	}
	return(maxd+1);
}

void DispGL(GLNode *g){
	if(g!=NULL){
		if(g->tag==0) printf("%c",g->val.data);
		else{
			printf("(");
			if(g->val.sublist==NULL) printf("#");
			else DispGL(g->val.sublist);
			printf(")");
		}
		if(g->link!=NULL){
			printf(",");
			DispGL(g->link);
		}
	}
}

GLNode *CreateGL(char *&s){
	GLNode *g;
	char ch=*s++;
	if(ch!='\0'){
		g=(GLNode *)malloc(sizeof(GLNode));
		if(ch=='('){
			g->tag=1;
			g->val.sublist=CreateGL(s);
		}
		else if(ch==')') g==NULL;
		else if(ch=='#') g=NULL;
		else{
			g->tag=0;
			g->val.data=ch;
		}
	}
	else g=NULL;
	ch=*s++;
	if(g!=NULL){
		if(ch==',') g->link=CreateGL(s);
		else g->link=NULL;
	}
	return g;
}

void DestroyGL(GLNode *&g){
	GLNode *g1,*g2;
	g1=g->val.sublist;
	while(g1!=NULL){
		if(g1->tag==0){
			g2=g1->link;
			free(g1);
			g1=g2;
		}
		else{
			g2=g1->link;
			DestroyGL(g1);
			g1=g2;
		}
	}
	free(g);
}

int Count(GLNode *g){
	int n=0;
	if(g!=NULL){
		if(g->tag==0) n++;
		else n+=Count(g->val.sublist);
		n+=Count(g->link); 
	}
	return n;
}
