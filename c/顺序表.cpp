#include<stdio.h>	//若用printf,scanf,getchar,putchar,gets,puts函数需包含该头文件
#include<malloc.h>	//用malloc,free,realloc函数需包含该头文件
#include<conio.h>	//若用getch()使得屏幕暂停，需包含该头文件
#include<stdlib.h>
#define MAXSIZE 100	
#define SIZE 10	//设线性表初始分配空间大小
typedef int ElemType;	//先设定数据元素的类型为整型

//定义顺序表的结构类型
typedef struct{
	ElemType *elem;
	int length;
	int listsize;
}SqList;

//初始化顺序表
int InitList_Sq(SqList &L ){
	L.elem = (ElemType * )malloc(MAXSIZE*sizeof(ElemType));
	if( ! L.elem ) exit(0);
	L.length = 0;
	L.listsize = MAXSIZE;
	return 0;
}

//定位元素
int Location_Sq(SqList L, ElemType e){
	 int i=1;
	for(int i=0;i<L.length;i++){
		if(*(L.elem+i)==e){
			return i;
		}
	}
	return 0;
	
}

//插入
int ListInsert_Sq(SqList &L,int i,ElemType e){
	int *newbase,*q,*p;
	if(i<1||i>L.length+1) return 0;
	if(L.length>=L.listsize){
		newbase = (ElemType * )realloc(L.elem,(L.listsize+SIZE) * sizeof(ElemType));
		if(!newbase) exit(0);
		L.elem = newbase;
		L.listsize+=SIZE;
	}
	q = &(L.elem[i-1]);
	for (p = &(L.elem[L.length-1]);p>=q;--p)*(p+1) = *p;
	*q = e;
	++L.length;
	return 0;
}

//删除
int ListDelete_Sq(SqList &L, int i, ElemType &e){	
	int *p,*q;
	if((i<1)||(i>L.length)) return 0;
	p=&(L.elem[i-1]);
	e=*p;
	q = L.elem+L.length-1;
	for (++p;p<=q;++p) 
	*(p-1) =*p;
	--L.length;
	return 0;
}

//翻转表
void ReverseList(SqList &L){
	int temp;	
	for(int i=0,j=L.length-1;i<=j;i++,j--){
		temp=*(L.elem+j);
		*(L.elem+j)=*(L.elem+i);
		*(L.elem+i)=temp;
	}
	
}

//合并两个有序表
void MergeList(SqList La, SqList Lb, SqList &Lc){
	int *pa,*pb,*pc,*pa_last,*pb_last,*pc_last;
	pa = La.elem;pb=Lb.elem;
	Lc.listsize = Lc.length = La.length+Lb.length;
	pc = Lc.elem = (ElemType*)malloc(Lc.listsize*sizeof(ElemType));
	if(!Lc.elem) exit(0);
	pa_last = La.elem+La.length-1;
	pb_last = Lb.elem+Lb.length-1;
	while(pa<=pa_last&&pb<=pb_last){
		if(*pa<=*pb) *pc++=*pa++;
		else *pc++=*pb++;
	}
	while(pa<=pa_last) * pc++= *pa++;
	while(pb<=pb_last) * pc++ = *pb++;
}

//打印表中元素值
void PrintList(SqList &L){
	int i;
	for(i=0;i<L.length;i++)
		printf("%d\n",L.elem[i]);
}

//主函数
int  main()
{
	SqList La,Lb,Lc;
	int i,n,e;

	//创建第一个表
	printf("1. 建第一个表 \n");	
	InitList_Sq(La);
	printf("请输入要往La表中插入元素的个数：");
	scanf("%d",&n);
	printf("输入%d个递增有序的整数：\n",n);	
	for(i=1;i<=n;i++){
		scanf("%d",&e);
		ListInsert_Sq(La,i,e);
	}	
	printf("La表长为：%d\n",La.length);
	PrintList(La);
	getch();  //屏幕暂停，等候按任何键继续

	//删除
	printf("\n2.删除\n");
	printf("请输入要删除元素的位置：");
	scanf("%d",&i);
	ListDelete_Sq(La,i,e);
	printf("被删除的元素是：%d\n",e);
	printf("删除后La表：\n");	
	PrintList(La);
	printf("La表表长为：%d\n",La.length);

	//创建第二个表
	printf("\n3.建第二个表\n");
	InitList_Sq(Lb);
	printf("请输入要往Lb表中插入元素的个数：");
	scanf("%d",&n);
	printf("输入%d个递增有序的整数：\n",n);
	for(i=1;i<=n;i++){
		scanf("%d",&e);
		ListInsert_Sq(Lb,i,e);
	}
	printf("Lb表长为：%d\n",Lb.length);
	getch();

	//合并有序表
	printf("\n4. 合并有序表，将La,Lb表中元素合并到Lc表中，仍保持有序。\n");
	InitList_Sq(Lc);
	MergeList(La,Lb,Lc);
	printf("合并有序表后，Lc表元素为：\n");
	PrintList(Lc);
	printf("合并有序表后，Lc表表长为：%d",Lc.length);
	getch();

	//翻转表
	printf("\n5. 翻转Lc表\n");
	ReverseList(Lc);
	printf("翻转Lc表后，Lc表元素为：\n");
	PrintList(Lc);
	getch();
}


 

