#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
typedef struct{
	char data[MaxSize];
	int top;
}SqStack;
void InitStack(SqStack *&s);
void DestroyStack(SqStack *&s);
bool StackEmpty(SqStack *&s);
bool Push(SqStack *&s,char e);
bool Pop(SqStack *&s,char &e);
bool GetTop(SqStack *&s,char &e); 
//Õ» 


typedef struct{
	double data[MaxSize];
	int top;
}SqStack1;
void InitStack1(SqStack1 *&s){
	s=(SqStack1 *)malloc(sizeof(SqStack1));
	s->top=-1;
} 
void DestroyStack1(SqStack1 *&s){
	free(s);
}
bool StackEmpty1(SqStack1 *&s){
	return(s->top==-1);
}
bool Push1(SqStack1 *&s,double e){
	if(s->top==MaxSize-1) return false;
	s->top++;
	s->data[s->top]=e;
	return true;
}
bool Pop1(SqStack1 *&s,double &e){
	if(s->top==-1) return false;
	e=s->data[s->top];
	s->top--;
	
	return true;
}
bool GetTop1(SqStack1 *&s,double &e){
	if(s->top==-1) return false;
	e=s->data[s->top];
	return true;
}
//²Ù×÷ÊýÕ»

 
void trans(char *exp,char postexp[])
{
	char e;
	SqStack *Opstr;
	InitStack(Opstr);
	int i=0;
	while(*exp!='\0'){
		switch(*exp){
			case'(':
				Push(Opstr,'(');
				exp++;
				break;
			case')':
				Pop(Opstr,e);
				while(e!='('){
					postexp[i++]=e;
					Pop(Opstr,e);
				}
				exp++;
				break;
			case'+':
			case'-':
				while(!StackEmpty(Opstr)){
					GetTop(Opstr,e);
					if(e!='('){
						postexp[i++]=e;
						Pop(Opstr,e);
					}
					else break;
					
				}
				Push(Opstr,*exp);
				exp++;
				break;
			case'*':
			case'/':
				while(!StackEmpty(Opstr)){
					GetTop(Opstr,e);
					if(e=='*'||e=='/'){
						postexp[i++]=e;
						Pop(Opstr,e);
						
					}
					else break;
				}
				Push(Opstr,*exp);
				exp++;
				break;
			default:
				while(*exp>='0'&&*exp<='9'){
					postexp[i++]=*exp;
					exp++;
				}
				postexp[i++]='#';
		}
	}
	while(!StackEmpty(Opstr)){
		Pop(Opstr,e);
		postexp[i++]=e;
	}
	postexp[i++]='\0';
	DestroyStack(Opstr);
}
double compvalue(char *postexp){
	double d,a,b,c,e;
	SqStack1 *Opnd;
	InitStack1(Opnd);
	while(*postexp!='\0'){
		switch(*postexp){
			case'+':
				Pop1(Opnd,a);
				Pop1(Opnd,b);
				c=a+b;
				Push1(Opnd,c);
				break;
			case'-':
				Pop1(Opnd,a);
				Pop1(Opnd,b);
				c=b-a;
				Push1(Opnd,c);
				break;
			case'/':
				Pop1(Opnd,a);
				Pop1(Opnd,b);
				if(a!=0){
					c=b/a;
					Push1(Opnd,c);
					break;
				}
				else{
					printf("\n\t³ýÁã´íÎó!\n");
					exit(0);
				}
				break;
			case'*':
				Pop1(Opnd,a);
				Pop1(Opnd,b);
				c=a*b;
				Push1(Opnd,c);
				break; 
			default:
				d=0;
				while(*postexp>='0'&&*postexp<='9'){
					d=10*d+*postexp-'0';
					postexp++;
				}
				Push1(Opnd,d);
				break;
		}
		postexp++;
	}
	GetTop1(Opnd,e);
	DestroyStack1(Opnd);
	return e;
}

