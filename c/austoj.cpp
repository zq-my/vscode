#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef char ElemType;	//������������ֵ������Ϊ�ַ���

typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode, *BiTree;

void CreateBiTree(BiTree &T)//������������룬�������ַ���ʾ����
{	
	char ch;
	scanf("%c",&ch);
	if(ch=='#')
	T=NULL;
	 else{
	 	if(!(T=(BiTNode *)malloc(sizeof(BiTNode))))
	 	exit(0);
	 	T->data=ch;
	 	CreateBiTree(T->lchild);
	 	CreateBiTree(T->rchild);
	  } 	  
}
void PreOrderTraverse(BiTree T)//�������
{
	if(T){
		printf("%c",T->data);
		PreOrderTraverse(T->lchild);
   		PreOrderTraverse(T->rchild);
	} 
}

void InOrderTraverse(BiTree T)//�������
{
	if(T){
		InOrderTraverse(T->lchild);
		printf("%c",T->data);
   		InOrderTraverse(T->rchild);
	} 

}

void PostOrderTraverse(BiTree T)//�������
{
	if(T){
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%c",T->data);
	} 

}
int main()
{
	BiTree T=NULL;

	CreateBiTree(T); 
	PreOrderTraverse(T);
	printf("\n");
	InOrderTraverse(T);
	printf("\n");
	PostOrderTraverse(T);
	return 0;	
}
