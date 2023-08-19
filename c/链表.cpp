#include<stdio.h>		//若用printf,scanf,getchar,putchar,gets,puts函数需包含该头文件
#include<malloc.h>		//用malloc,free,realloc函数需包含该头文件
#include<conio.h>		//若用getch()使得屏幕暂停，需包含该头文件

typedef int ElemType;	//先设定数据元素的类型为整型

//定义类型
typedef struct LNode
{
	ElemType data;
	struct LNode *next; 
}LNode, *LinkList;

//求表长
int ListLength(LinkList L)
{
	int i=0;
	while(L!=NULL){
		i++;
		L=L->next; 
	}
	return i;
}

//查找元素，获取表中第i个元素的值
int GetElem(LinkList L,int i,ElemType &e)
{
	LNode * p = L->next;  
	int j = 1;			//p指向第一个结点，j为计数器
	while (p && j<i)	//顺指针向后查找，直到p指向第i个元素或p为空
	{	
		p = p->next; 
		++j;  
	}        
	if ( !p || j>i )
    	return 0;		//第i个元素不存在
	e = p->data;        //取得第i个元素
	return e; 
}

//判断元素e是否在该链表中
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

//打印表中元素值
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

//插入操作
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

//删除操作
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

//头插法建表
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

//合并两个有序表
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

//主函数
int main()
{
	LinkList La;
	ElemType e;  
	int i,n;
	
	//创建第一个表
	printf("1.建第一个表 \n");	
	printf("请输入要往La表中插入元素的个数：");
	scanf("%d",&n);
	printf("输入%d个元素值：(头插法建表，请逆序输入)\n",n);	
	CreateList(La,n);
	printf("表中元素为：\n");
	PrintList(La);	
	
	//取值
	printf("\n2.查找第i位元素的值\n请输入位序：");	
	scanf("%d",&n);
	GetElem(La,n,e);
	printf("第%d位元素的值为：%d\n",n,e);

	//定位
	printf("\n3.定位操作\n请输入要查找的元素:");	
	scanf("%d",&e);
	i=LocateElem(La,e);
	if(i)
		printf("所要查找的元素在表中第%d位\n",i);
	else
		printf("表中无该元素\n");
	
	//插入
	printf("\n4.插入操作\n输入要插入元素的位序：");	
	scanf("%d",&i);
	printf("输入要插入的元素值：");	
	scanf("%d",&e);
	ListInsert(La,i,e);
	printf("插入后表中元素为：\n");	
	PrintList(La);
	
	//删除
	printf("\n5.删除操作\n输入要删除元素的位序：");	
	scanf("%d",&n);
	ListDelete(La,n,e);
	printf("要删除的元素值为：%d\n",e);	
	printf("删除后表中元素为：\n");	
	PrintList(La);
	
	//建立第二个表
	LinkList Lb,Lc;
	printf("\n6.建第二个表\n");	
	printf("请输入Lb表中元素个数:");	
	scanf("%d",&n);
	printf("输入%d个元素值：(头插法建表，请逆序输入)\n",n);	
	CreateList(Lb,n);
	printf("表中元素为：\n");
	PrintList(Lb);

	//合并
	printf("\n7.合并两个有序表：\n");	
	MergeList(La,Lb,Lc);
	printf("合并后Lc表中元素为：\n");
	PrintList(Lc);
}

	


