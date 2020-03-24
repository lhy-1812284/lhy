#define M 10
#define N 10
#define MaxSize 100 
#include<stdio.h>
typedef struct{
	int r;
	int c;
	int d;
}TupNode;
typedef struct{
	int rows;
	int cols;
	int nums;
	TupNode data[MaxSize];
}TSMatrix;
void CreateMat(TSMatrix &t,int A[M][N]){
	int i,j;
	t.rows=M;t.cols=N;t.nums=0;
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			if(A[i][j]!=0){
				t.data[t.nums].r=i;t.data[t.nums].c=j;
				t.data[t.nums].d=A[i][j];t.nums++;
			}
		}
	}
}
bool Value(TSMatrix &t,int x,int i,int j){
	int k=0,k1;
	if(i>=t.rows||j>=t.cols) return false;
	while(k<t.nums&&i>t.data[k].r) k++;
	while(k<t.nums &&i==t.data[k].r&&j>t.data[k].c) k++;
	if(t.data[k].r==i&&t.data[k].c==j) t.data[k].d=x;
	else{
		for(k1=t.nums-1;k1>=k;k1--){
			t.data[k1+1].r=t.data[k1].r;
			t.data[k1+1].c=t.data[k1].c;
			t.data[k1+1].d=t.data[k1].d;
		}
		t.data[k].r=i;t.data[k].c=j;t.data[k].d=x;
		t.nums++;
	}
	return true;
}
bool Assign(TSMatrix t,int &x,int i,int j){
	int k=0;
	if(i>=t.rows||j>=t.cols) return false;
	while(k<t.nums&&i>t.data[k].r) k++;
	while(k<t.nums&&i==t.data[k].r&&j>t.data[k].c) k++;
	if(t.data[k].r==i&&t.data[k].c==j) x=t.data[k].d;
	else x=0;
	return true;
}
void DispMat(TSMatrix t){
	int k;
	if(t.nums<=0) return;
	printf("\t%d\t%d\t%d\n",t.rows,t.cols,t.nums);
	printf("\t--------");
	for(k=0;k<t.nums;k++) printf("\t%d\t%d\t%d",t.data[k].r,t.data[k].c,t.data[k].d); 
}
void TranTat(TSMatrix t,TSMatrix &tb){
	int k,k1=0,v;
	tb.rows=t.cols;tb.cols=t.rows;tb.nums=t.nums;
	if(t.nums!=0){
		for(v=0;v<t.cols;v++){
			for(k=0;k<t.nums;k++){
				if(t.data[k].c==v){
					tb.data[k1].r=t.data[k].c;
					tb.data[k1].c=t.data[k].r;
					tb.data[k].d=t.data[k].d;
					k1++;
				}
			}
		}
	}
}

