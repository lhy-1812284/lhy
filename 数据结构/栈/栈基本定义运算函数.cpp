#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
typedef struct{
	char data[MaxSize];
	int top;
}SqStack;
void InitStack(SqStack *&s){
	s=(SqStack *)malloc(sizeof(SqStack));
	s->top=-1;
} 
void DestroyStack(SqStack *&s){
	free(s);
}
bool StackEmpty(SqStack *&s){
	return(s->top==-1);
}
bool Push(SqStack *&s,char e){
	if(s->top==MaxSize-1) return false;
	s->top++;
	s->data[s->top]=e;
	return true;
}
bool Pop(SqStack *&s,char &e){
	if(s->top==-1) return false;
	e=s->data[s->top];
	s->top--;
	
	return true;
}
bool GetTop(SqStack *&s,char &e){
	if(s->top==-1) return false;
	e=s->data[s->top];
	return true;
}
