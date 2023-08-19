#include<stdio.h>	//����printf,scanf,getchar,putchar,gets,puts�����������ͷ�ļ�
#include<malloc.h>	//��malloc,free,realloc�����������ͷ�ļ�
#include<conio.h>	//����getch()ʹ����Ļ��ͣ���������ͷ�ļ�
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

//��������
int InitStack(SqStack &s);
void ClearStack(SqStack &S);
int StackEmpty(SqStack S);
int StackLength(SqStack S);
int GetTop(SqStack s,ElemType &e);
int Push(SqStack &s,ElemType e);
int Pop(SqStack &s,ElemType &e);

//��ʼ��,������ջ
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

//���ջ
void ClearStack(SqStack &S)
{
	if(S.base){
		S.top==S.base;
	}
	
}

//��ջ��
int StackEmpty(SqStack S)
{
	if(S.top ==S.base ) return 1;
	else return 0;	
}

//��ջ��Ԫ�ظ���
int StackLength(SqStack S)
{
  	int length;
  	length=S.top-S.base;
  	return length;
}

//��ȡջ��Ԫ��ֵ
int GetTop(SqStack s,ElemType &e)
{
    if(s.top == s.base)  return 0;
    e = *(s.top-1);
	return 1;	
}

//��ջ
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

//��ջ
int Pop(SqStack &s,ElemType &e)
{ 
	if(s.top ==s.base ) return 0;
	e = * --s.top ;
	return 1;
}

//��ӡջ��Ԫ��
void PrintElem(SqStack S)
{
	ElemType *p = S.base;
	while(p<S.top)
	{
		printf("%d\n",*p);
		p++;
	}
}

//����ת������
void conversion()
{
	ElemType e;
	SqStack S;
	InitStack(S);
	int n,R;
	int i=0;
	printf("��������Ҫ��ת����ʮ��������");
	scanf("%d",&n);
	printf("�����뱻ת���ɵ�R���ƣ�2<=R<=10����");
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

//������
int main()
{
	ElemType e;
	SqStack S;

	printf("1.��ʼ��ջ\n");
	InitStack(S);
	printf("����ջΪ��.\n");
	printf("�������һ��Ҫ��ջ��Ԫ��ֵ��");
	scanf("%d",&e);
	Push(S,e);
	printf("����ջ����һ��Ԫ�أ�\n");
	PrintElem(S);
	printf("������ڶ���Ҫ��ջ��Ԫ��ֵ��");
	scanf("%d",&e);
	Push(S,e);
	printf("����ջ��������Ԫ�أ�\n");	
	PrintElem(S);

	int n;
	printf("�����뻹Ҫ��ջ��Ԫ�صĸ���:");
	scanf("%d",&n);

	for(int i=1; i<=n; i++)
	{
		printf("�������%d��Ԫ�أ�",i+2);
		scanf("%d",&e);
		Push(S,e);
	}
	printf("����ջ��Ԫ���У�%d��\n",StackLength(S));
	printf("����ջ��Ԫ��Ϊ��\n");	
	PrintElem(S); 

	printf("2.���ڳ�ջ\n��ջǰջ��Ԫ��Ϊ��");	
	Pop(S,e);
	printf("%d\n",e);
	GetTop(S,e);
	printf("��ջ���µ�ջ��Ԫ��Ϊ��%d\n",e);
	printf("ջ��ʣ��Ԫ���У�\n");
	PrintElem(S);
	printf("����ջ��Ԫ�ظ���Ϊ��%d\n",StackLength(S));
	
	printf("\n3.����ת��\n");
	conversion();
}
