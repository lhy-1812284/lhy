#include<stdio.h>
#define MaxSize 100
void josephus(int n,int m){
	int p[MaxSize];
	int i,j,t;
	for(i=0;i<n;i++){
		p[i]=i+1;
	}
	t=0;
	printf("出列顺序:\n");
	for(i=n;i>=1;i--){
		t=(t+m-1)%i;
		printf("%d\t",p[t]);
		for(j=t+1;j<=i-1;j++) p[j-1]=p[j];
	}
	printf("\n");
}
int main(){
	int n,m;
	printf("请输入参与人数n和出列编号m：\n");
	scanf("%d %d",&n,&m);
	josephus(n,m);
	return 0;
}
