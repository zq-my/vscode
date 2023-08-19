#include<stdio.h>		//����printf,scanf,getchar,putchar,gets,puts�����������ͷ�ļ�
#include<malloc.h>		//��malloc,free,realloc�����������ͷ�ļ�
#include<conio.h>		//����getch()ʹ����Ļ��ͣ���������ͷ�ļ�

typedef int ElemType;	//���趨����Ԫ�ص�����Ϊ����

//��������
typedef struct LNode
{
	ElemType data;
	struct LNode *next; 
}LNode, *LinkList;

//���
int ListLength(LinkList L)
{
	int i=0;
	while(L!=NULL){
		i++;
		L=L->next; 
	}
	return i;
}

//����Ԫ�أ���ȡ���е�i��Ԫ�ص�ֵ
int GetElem(LinkList L,int i,ElemType &e)
{
	LNode * p = L->next;  
	int j = 1;			//pָ���һ����㣬jΪ������
	while (p && j<i)	//˳ָ�������ң�ֱ��pָ���i��Ԫ�ػ�pΪ��
	{	
		p = p->next; 
		++j;  
	}        
	if ( !p || j>i )
    	return 0;		//��i��Ԫ�ز�����
	e = p->data;        //ȡ�õ�i��Ԫ��
	return e; 
}

//�ж�Ԫ��e�Ƿ��ڸ�������
int LocateElem(LinkList La,ElemType e)
{
	LNode *p = La->next;
	int j =1;
	while(p){
		if(p->data==e){
			return j;
		}
		p=p->next;
		j++;
	}
	return 0;	
}

//��ӡ����Ԫ��ֵ
void PrintList(LinkList L)
{ 
    L=L->next;  
    while(L)  
    {  
        printf("%d  ",L->data);  
        L=L->next;  
    }
    printf("\n");

}

//�������
int ListInsert(LinkList &L,int i,ElemType e)
{
	LNode *p=L;
	LNode *s;
	s=(LinkList)malloc(sizeof(LNode));
	int j=0;
	while(p&&j<i-1){
		p=p->next;
		j++;
	}
	if(!p||j>i-1)
	return 0;
	s->data=e;
	s->next=p->next;
	p->next=s;
	return 0;
}

//ɾ������
int ListDelete(LinkList &L,int i,ElemType &e)
{
	LNode *p;
	LNode *q;
	int j=0;
	p=L;
	while(p->next&&j<i-1){
		p=p->next;
		j++;
	}
	if(!(p->next)||j>i-1)
	return 0;
	q=p->next;
	p->next=q->next;
	e=q->data;
	free(q);
	return 0;
}

//ͷ�巨����
void CreateList(LinkList &L,int n)
{
	LinkList p;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	for(int i=n;i>0;--i){
		p=(LinkList)malloc(sizeof(LNode));
		scanf("%d",&p->data);
		p->next=L->next;
		L->next=p;
	}
}

//�ϲ����������
void MergeList(LinkList La,LinkList Lb,LinkList &Lc)
{
	LinkList pa=La->next;  
	LinkList pb=Lb->next; 
	LinkList pc;
	Lc=pc=La;
  	while(pa&&pb)
	{
	    if(pa->data<=pb->data)
		{
			pc->next=pa;
			pc=pa; 
			pa=pa->next;
		}
	    else
		{ 
			pc->next=pb; 
			pc=pb; 
			pb=pb->next; 
		}
	}	
  	pc->next=pa?pa:pb;  
	free(Lb);  
}

//������
int main()
{
	LinkList La;
	ElemType e;  
	int i,n;
	
	//������һ����
	printf("1.����һ���� \n");	
	printf("������Ҫ��La���в���Ԫ�صĸ�����");
	scanf("%d",&n);
	printf("����%d��Ԫ��ֵ��(ͷ�巨��������������)\n",n);	
	CreateList(La,n);
	printf("����Ԫ��Ϊ��\n");
	PrintList(La);	
	
	//ȡֵ
	printf("\n2.���ҵ�iλԪ�ص�ֵ\n������λ��");	
	scanf("%d",&n);
	GetElem(La,n,e);
	printf("��%dλԪ�ص�ֵΪ��%d\n",n,e);

	//��λ
	printf("\n3.��λ����\n������Ҫ���ҵ�Ԫ��:");	
	scanf("%d",&e);
	i=LocateElem(La,e);
	if(i)
		printf("��Ҫ���ҵ�Ԫ���ڱ��е�%dλ\n",i);
	else
		printf("�����޸�Ԫ��\n");
	
	//����
	printf("\n4.�������\n����Ҫ����Ԫ�ص�λ��");	
	scanf("%d",&i);
	printf("����Ҫ�����Ԫ��ֵ��");	
	scanf("%d",&e);
	ListInsert(La,i,e);
	printf("��������Ԫ��Ϊ��\n");	
	PrintList(La);
	
	//ɾ��
	printf("\n5.ɾ������\n����Ҫɾ��Ԫ�ص�λ��");	
	scanf("%d",&n);
	ListDelete(La,n,e);
	printf("Ҫɾ����Ԫ��ֵΪ��%d\n",e);	
	printf("ɾ�������Ԫ��Ϊ��\n");	
	PrintList(La);
	
	//�����ڶ�����
	LinkList Lb,Lc;
	printf("\n6.���ڶ�����\n");	
	printf("������Lb����Ԫ�ظ���:");	
	scanf("%d",&n);
	printf("����%d��Ԫ��ֵ��(ͷ�巨��������������)\n",n);	
	CreateList(Lb,n);
	printf("����Ԫ��Ϊ��\n");
	PrintList(Lb);

	//�ϲ�
	printf("\n7.�ϲ����������\n");	
	MergeList(La,Lb,Lc);
	printf("�ϲ���Lc����Ԫ��Ϊ��\n");
	PrintList(Lc);
}

	


