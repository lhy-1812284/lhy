#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
typedef struct{
	char data[MaxSize];
	int length;
}SqString;
SqString PublicChar(SqString s1,SqString s2){
	SqString s3;
	int i,j,k=0;
	for(i=0;i<s1.length;i++){
		for(j=0;j<s2.length;j++){
			if(s1.data[i]==s2.data[j]) break;
		}
		if(j<s2.length){
			s3.data[k]=s1.data[i];
			k++;
		} 
	}
	s3.length=k;
	return s3;
}
