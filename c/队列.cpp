#include <stdio.h>
#include<stdlib.h>
#include <malloc.h>
#define MAXQSIZE 100	//�����г��ȣ�ʵ��ʹ��MAXQSIZE-1

typedef  int  ElemType;

//ѭ������(����һ���洢��Ԫ)
typedef struct
{
	ElemType *base;
	int front;
	int rear; 
}SqQueue;

//����һ���ն���Q
int InitQueue(SqQueue &Q)
{
    Q.base=(ElemType *)malloc(MAXQSIZE*sizeof(ElemType));
    if(! Q.base) exit(0);
    Q.front=Q.rear=0;
    return 1;
}

//�����пգ�������QΪ�ն��У��򷵻�1�����򷵻�0
int QueueEmpty(SqQueue &Q)
{	
	if(Q.front==Q.rear) return 1;
	else return 0;
	
}

//����еĳ���
int QueueLength(SqQueue &Q)
{
	return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}

//���ͷԪ��ֵ�������в�Ϊ�գ�����e����Q�Ķ�ͷԪ�أ�������1�����򷵻�0
int GetHead(SqQueue &Q,ElemType &e)
{
	if(Q.front==Q.rear)
	return 0;
	else{
		e=Q.base[Q.front];
		return 1;
	}
}

//����Ԫ��e��ΪQ���µĶ�βԪ��
int EnQueue(SqQueue &Q,ElemType e)
{
	if(Q.front==(Q.rear+1)%MAXQSIZE)
	return 0;
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAXQSIZE;
	return 1;
}

//�����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������1,���򷵻�0
int DeQueue(SqQueue &Q,ElemType &e)
{
	if(Q.front==Q.rear)
	return 0;
	else{
		e=Q.base[Q.front];
		Q.front=(Q.front+1)%MAXQSIZE;
		return 1;
	}
}

//���������Ԫ��ֵ,��ͷ��β
void PrintQueue(SqQueue &Q)
{
	for(int i=Q.front;i<Q.rear;i++){
		printf("%d\n",Q.base[i]);
	}
}

//������
int main( )
{
	SqQueue Q;
	int select;
	ElemType e;
	if ((InitQueue(Q))==0)
		printf("����ʧ�ܣ������˳�����\n");	
	else
	{
		do
		{
			printf("\n1���ж϶����Ƿ�Ϊ��\n");
			printf("2������г���\n");
			printf("3��ȡ��ͷԪ��ֵ\n");
			printf("4�����\n");
			printf("5������\n");
			printf("6����ʾ����Ԫ��\n");
			printf("0������\n\n");

			printf("����������ѡ��");			
			scanf("%d",&select);			

			switch(select)
			{
				case 1: 
					if(QueueEmpty(Q)==1)	
						printf("����Ϊ��\n");
					else	
						printf("���в�Ϊ��\n");
					break;
				case 2: 
					printf("���г���Ϊ��%d\n",QueueLength(Q));
					break;
				case 3: 
					if(GetHead(Q,e)==0)		
						printf("����Ϊ��\n");
					else	
						printf("����Ԫ��Ϊ��%d\n",e);
					break;
				case 4:
					printf("������Ҫ�����Ԫ��ֵ��");
					scanf("%d",&e);
					if(EnQueue(Q,e)==0)
						printf("������������ʧ��\n");
					else
						printf("Ԫ�سɹ�����\n");
					break;
				case 5: 
					if(DeQueue(Q,e)==0)
						printf("���пգ������ݿ�ɾ\n");
					else
						printf("ɾ��Ԫ��Ϊ��%d\n",e);
					break;
				case 6:
					PrintQueue(Q);
					break;
				case 0: 
					printf("��������\n");
					break;
				default:
					printf("����ѡ�����\n");
			}
		}while(select);
	}
}
