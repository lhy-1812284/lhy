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
	printf("中缀表达式:%s\n",exp);
	printf("后缀表达式:%s\n",postexp);
	printf("表达式的值：%g\n",compvalue(postexp));
	return 0;
}
