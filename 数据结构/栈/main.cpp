#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100 
void trans(char *exp,char postexp[]);
double compvalue(char *postexp);
int main(){
	char exp[MaxSize];
	scanf("%s",exp);
	char postexp[MaxSize];
	trans(exp,postexp);
	printf("��׺���ʽ:%s\n",exp);
	printf("��׺���ʽ:%s\n",postexp);
	printf("���ʽ��ֵ��%g\n",compvalue(postexp));
	return 0;
}
