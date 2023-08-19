#include<stdio.h>	//����printf,scanf,getchar,putchar,gets,puts�����������ͷ�ļ�
#include<malloc.h>	//��malloc,free,realloc�����������ͷ�ļ�
#include<conio.h>	//����getch()ʹ����Ļ��ͣ���������ͷ�ļ�
#include<stdlib.h>
#define MAXSIZE 100	
#define SIZE 10	//�����Ա��ʼ����ռ��С
typedef int ElemType;	//���趨����Ԫ�ص�����Ϊ����

//����˳���Ľṹ����
typedef struct{
	ElemType *elem;
	int length;
	int listsize;
}SqList;

//��ʼ��˳���
int InitList_Sq(SqList &L ){
	L.elem = (ElemType * )malloc(MAXSIZE*sizeof(ElemType));
	if( ! L.elem ) exit(0);
	L.length = 0;
	L.listsize = MAXSIZE;
	return 0;
}

//��λԪ��
int Location_Sq(SqList L, ElemType e){
	 int i=1;
	for(int i=0;i<L.length;i++){
		if(*(L.elem+i)==e){
			return i;
		}
	}
	return 0;
	
}

//����
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

//ɾ��
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

//��ת��
void ReverseList(SqList &L){
	int temp;	
	for(int i=0,j=L.length-1;i<=j;i++,j--){
		temp=*(L.elem+j);
		*(L.elem+j)=*(L.elem+i);
		*(L.elem+i)=temp;
	}
	
}

//�ϲ����������
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

//��ӡ����Ԫ��ֵ
void PrintList(SqList &L){
	int i;
	for(i=0;i<L.length;i++)
		printf("%d\n",L.elem[i]);
}

//������
int  main()
{
	SqList La,Lb,Lc;
	int i,n,e;

	//������һ����
	printf("1. ����һ���� \n");	
	InitList_Sq(La);
	printf("������Ҫ��La���в���Ԫ�صĸ�����");
	scanf("%d",&n);
	printf("����%d�����������������\n",n);	
	for(i=1;i<=n;i++){
		scanf("%d",&e);
		ListInsert_Sq(La,i,e);
	}	
	printf("La��Ϊ��%d\n",La.length);
	PrintList(La);
	getch();  //��Ļ��ͣ���Ⱥ��κμ�����

	//ɾ��
	printf("\n2.ɾ��\n");
	printf("������Ҫɾ��Ԫ�ص�λ�ã�");
	scanf("%d",&i);
	ListDelete_Sq(La,i,e);
	printf("��ɾ����Ԫ���ǣ�%d\n",e);
	printf("ɾ����La��\n");	
	PrintList(La);
	printf("La���Ϊ��%d\n",La.length);

	//�����ڶ�����
	printf("\n3.���ڶ�����\n");
	InitList_Sq(Lb);
	printf("������Ҫ��Lb���в���Ԫ�صĸ�����");
	scanf("%d",&n);
	printf("����%d�����������������\n",n);
	for(i=1;i<=n;i++){
		scanf("%d",&e);
		ListInsert_Sq(Lb,i,e);
	}
	printf("Lb��Ϊ��%d\n",Lb.length);
	getch();

	//�ϲ������
	printf("\n4. �ϲ��������La,Lb����Ԫ�غϲ���Lc���У��Ա�������\n");
	InitList_Sq(Lc);
	MergeList(La,Lb,Lc);
	printf("�ϲ�������Lc��Ԫ��Ϊ��\n");
	PrintList(Lc);
	printf("�ϲ�������Lc���Ϊ��%d",Lc.length);
	getch();

	//��ת��
	printf("\n5. ��תLc��\n");
	ReverseList(Lc);
	printf("��תLc���Lc��Ԫ��Ϊ��\n");
	PrintList(Lc);
	getch();
}


 

