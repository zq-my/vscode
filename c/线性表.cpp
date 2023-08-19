#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
typedef struct{
	int a;
	int b;
}ElemType;

typedef struct{
	ElemType *data;//ElemType *data; data为数组的地址 
	int length;	
}Sqlist;

int main()
{
	Sqlist L;
	L.data=(ElemType*)malloc(sizeof(ElemType)*MaxSize);
	
	

}  
