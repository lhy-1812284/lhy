#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
//KMP算法 
typedef struct{
	char data[MaxSize];
	int length;
}SqString;
void GetNext(SqString t,int next[]){
	int j,k;
	j=0;k=-1;
	next[0]=-1;
	while(j<t.length-1){
		if(k==-1||t.data[j]==t.data[k]){
			j++;k++;
			next[j]=k;
		}
		else k=next[k];
	}
}
int KMPIndex(SqString s,SqString t){
	int next[MaxSize],i=0,j=0;
	GetNext(t,next);
	while(i<s.length&&j<t.length){
		if(j==-1||s.data[i]==t.data[j]){
			i++;j++;
		}
		else j=next[j];
	}
	if(j>=t.length) return(i-t.length);
	else return(-1);
}
//改进KMP算法 
void GetNextval(SqString t,int nextval[]){
	int j=0,k=-1;
	nextval[0]=-1;
	while(j<t.length){
		if(k==-1||t.data[j]==t.data[k]){
			j++;k++;
			if(t.data[j]!=t.data[k]) nextval[j]=k;
			else nextval[j]=nextval[k];
		}
		else k=nextval[k];
	}
}
int KMPIndex1(SqString s,SqString t){
	int nextval[MaxSize],i=0,j=0;
	GetNextval(t,nextval);
	while(i<s.length&&j<t.length){
		if(j==-1||s.data[i]==t.data[j]){
			i++;j++;
		}
		else j=nextval[j];
	}
	if(j>=t.length) return(i-t.length);
	else return(-1);
}
