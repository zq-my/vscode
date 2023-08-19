#include<stdio.h>	//若用printf,scanf,getchar,putchar,gets,puts函数需包含该头文件
#include<malloc.h>	//用malloc,free,realloc函数需包含该头文件
#include<conio.h>	//若用getch()使得屏幕暂停，需包含该头文件
#include<stdlib.h>
#define MAXSIZE 100
#define STACKINCREMENT 10

typedef int ElemType;

typedef struct STACK
{
	ElemType *base;
	ElemType *top; 
	int stacksize;
}SqStack;

//函数声明
int InitStack(SqStack &s);
void ClearStack(SqStack &S);
int StackEmpty(SqStack S);
int StackLength(SqStack S);
int GetTop(SqStack s,ElemType &e);
int Push(SqStack &s,ElemType e);
int Pop(SqStack &s,ElemType &e);

//初始化,创建空栈
int InitStack(SqStack &s)
{
	SqStack S;
	S.base=(ElemType *)malloc(MAXSIZE*sizeof(ElemType));
	if(!S.base)
	exit(0);
	S.top=S.base;
	S.stacksize=MAXSIZE;
	return 1;     
}

//清空栈
void ClearStack(SqStack &S)
{
	if(S.base){
		S.top==S.base;
	}
	
}

//判栈空
int StackEmpty(SqStack S)
{
	if(S.top ==S.base ) return 1;
	else return 0;	
}

//求栈中元素个数
int StackLength(SqStack S)
{
  	int length;
  	length=S.top-S.base;
  	return length;
}

//获取栈顶元素值
int GetTop(SqStack s,ElemType &e)
{
    if(s.top == s.base)  return 0;
    e = *(s.top-1);
	return 1;	
}

//入栈
int Push(SqStack &s,ElemType e)
{
	if(s.top - s.base >=s.stacksize){
		s.base  = (ElemType * )realloc(s.base ,(s.stacksize + STACKINCREMENT)*sizeof(ElemType));
		if(!s.base ) exit(0);
		s.top = s.base +s.stacksize ;
		s.stacksize +=STACKINCREMENT;
	}
	*s.top++=e;
	return 1;
}

//出栈
int Pop(SqStack &s,ElemType &e)
{ 
	if(s.top ==s.base ) return 0;
	e = * --s.top ;
	return 1;
}

//打印栈中元素
void PrintElem(SqStack S)
{
	ElemType *p = S.base;
	while(p<S.top)
	{
		printf("%d\n",*p);
		p++;
	}
}

//数制转换函数
void conversion()
{
	ElemType e;
	SqStack S;
	InitStack(S);
	int n,R;
	int i=0;
	printf("请输入需要被转换的十进制数：");
	scanf("%d",&n);
	printf("请输入被转换成的R进制（2<=R<=10）：");
	scanf("%d",&R);
	while(n){
		Push(S,n%R);
		n=n/R;
	}
	while(!StackEmpty(S))
	{
		Pop(S,e);
		printf("%d",e);
	}
	printf("\n");
}

//主函数
int main()
{
	ElemType e;
	SqStack S;

	printf("1.初始化栈\n");
	InitStack(S);
	printf("现在栈为空.\n");
	printf("请输入第一个要入栈的元素值：");
	scanf("%d",&e);
	Push(S,e);
	printf("现在栈中有一个元素：\n");
	PrintElem(S);
	printf("请输入第二个要入栈的元素值：");
	scanf("%d",&e);
	Push(S,e);
	printf("现在栈中有两个元素：\n");	
	PrintElem(S);

	int n;
	printf("请输入还要入栈的元素的个数:");
	scanf("%d",&n);

	for(int i=1; i<=n; i++)
	{
		printf("请输入第%d个元素：",i+2);
		scanf("%d",&e);
		Push(S,e);
	}
	printf("现在栈中元素有：%d个\n",StackLength(S));
	printf("现在栈中元素为：\n");	
	PrintElem(S); 

	printf("2.现在出栈\n出栈前栈顶元素为：");	
	Pop(S,e);
	printf("%d\n",e);
	GetTop(S,e);
	printf("出栈后新的栈顶元素为：%d\n",e);
	printf("栈中剩余元素有：\n");
	PrintElem(S);
	printf("现在栈中元素个数为：%d\n",StackLength(S));
	
	printf("\n3.数制转换\n");
	conversion();
}
