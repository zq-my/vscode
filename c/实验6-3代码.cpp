#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

using std::queue;

#define MaxVex 10				//���赱ǰ���������Ϊ10��
typedef char VertexType;		//Ԫ���������ַ�
int visited[MaxVex];			//������ŵ�ǰ�����Ƿ������

//*****�����ڽӾ���****
typedef struct
{
	VertexType vexs[MaxVex];
	int arcs[MaxVex][MaxVex];
	int vexnum,arcnum;
}MGraph;

//******�����ڽӱ�******
typedef struct ArcNode			//�ڽӱ��еı߽������
{
	int adjvex;					//�ڽӵ��������е�λ��
	struct ArcNode *nextarc;	//ָ����һ���߽�������
}ArcNode;
typedef struct VNode			//�ڽӱ��ͷ�������
{
	VertexType data;
	ArcNode *firstarc;
}VNode;
typedef struct					//�ڽӱ�
{
	VNode vertices[MaxVex];   
	int vexnum,arcnum;
}ALGraph; 

//��G�д���v,�򷵻ظö�����ͼ��λ��,���򷵻�-1
int LocateVex(MGraph G, VertexType v)
{ 
	for (int i = 0; i < G.vexnum; i++) if (G.vexs[i] == v) return i;
	return -1;
}
int LocateVex(ALGraph G, VertexType v)
{
	int i;
	for(i=0; i<G.vexnum; i++)
	{
    	if(G.vertices[i].data==v)
       		return i;
	}
	return -1;
}

//���ض���v�ĵ�һ���ٽӵ�λ��,���򷵻�-1
int FisrtAdjVertex(MGraph G, int v)
{
	for (int i = 0; i < G.vexnum; i++) if (G.arcs[v][i] == 1) return i;
	return -1;
}

//���ض���v�����w����һ���ٽӵ�λ��,���򷵻�-1
int NextAdjVertex(MGraph G, int v, int w)
{
	for (int i = w+1; i < G.vexnum; i++) if (G.arcs[v][i] == 1) return i;
	return -1;
}

//�ڽӾ���洢��ʽ��������ͼ
void CreateMGraph(MGraph &G)
{	
	/*
	1.����ͼ�ж���������ߵ�������
	2.����ͼ�ж�����Ϣ����ŵ�G.vexs[i]�����С�
	3.��ʼ���ڽӾ���������ֵΪ0
	4.����ߵ���Ϣ���޸��ڽӾ��������Ӧ��Ԫ��ֵ��
	*/
	int n, m;
	printf("��������������ͱ�����");
	scanf("%d%d", &n, &m);
	G.vexnum = n; G.arcnum = m;
	getchar();
	printf("������%d�������Ϣ������Ҫ�ո��������", n);
	for (int i = 0; i < n; i++) scanf("%c", &(G.vexs[i]));
	printf("������%d���ߵ���Ϣ���磺0 2��ʾ0��2���������һ������ߣ�������0~%d����\n", m, n-1);
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) G.arcs[i][j] = 0;
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		G.arcs[x][y] = G.arcs[y][x] = 1;
	}
}

//���ͼ���ڽӾ���
void PrintMGraph(MGraph MG)
{
	int i,j;
	printf("�±�   Ԫ��ֵ  �ߵ���Ϣ\n");
	for(i=0; i<MG.vexnum; i++)
	{
		printf("%d\t%c\t",i,MG.vexs[i]);		
		for(j=0; j<MG.vexnum; j++)
			printf("%d ",MG.arcs[i][j]);
		printf("\n");
	}	
}

//�ӵ�i�����㿪ʼ��ȱ���
void DFSMGraph(MGraph G,int i)
{
	if (i >= G.vexnum) return ;
	visited[i] = 1;
	printf("%d ", i);
	for (int j = 0; j < G.vexnum; j++) 
		if (!visited[j] && G.arcs[i][j]) 
			DFSMGraph(G, j);
}

//�ӵ�i�����㿪ʼ��ȱ���
void BFSMGraph(MGraph G,int i)
{
	queue<int>q;
	q.push(i); visited[i] = 1;
	while (!q.empty()) {
		int u = q.front(); printf("%d ", u);
		for (int j = 0; j < G.vexnum; j++) if (!visited[j] && G.arcs[i][j]) {
			q.push(j); visited[j] = 1;
		} q.pop();
	}
}

//�����ڽӱ�洢��ʽ������ͼ
void CreateALGraph(ALGraph &G)
{
	/*	1.����ͼ�ж���������ߵ�����
		2.����ͼ�ж�����Ϣ����ŵ�G.vertices[i].data�С�
		3.����ߵ���Ϣ�������߽�㣬���뵽���Ӧ����Ԫ�غ�ı߱��У�ע������ͼ��ÿ������Ҫ���������߽�㣩��*/
	int i,j,k;
	printf("�����붥����,����:");
	scanf("%d,%d",&G.vexnum,&G.arcnum);
	getchar();

	for(i=0; i<G.vexnum; i++)
	{
		printf("�������%d��������Ϣ:",i+1);
		scanf("%c",&G.vertices[i].data);
		G.vertices[i].firstarc=NULL;
		getchar();
	}
	
	VertexType v1,v2;
	ArcNode *p, *q;
    for(k=0; k<G.arcnum; k++){//�����ڽӾ���
		printf("�������%d���ߵ���������(a,b):",k+1);
		scanf("%c,%c",&v1,&v2);
		//ȷ��v1��v2��G�е�λ��
    	i=LocateVex(G, v1); 
		j=LocateVex(G, v2);

		//��i�������������(ͷ��)
		p=G.vertices[i].firstarc;
		q=(ArcNode*)malloc(sizeof(ArcNode));
		q->adjvex=j;
		q->nextarc=p;
		G.vertices[i].firstarc=q;
		//��j�������������(ͷ��)
		p=G.vertices[j].firstarc;
		q=(ArcNode*)malloc(sizeof(ArcNode));
		q->adjvex=i;
		q->nextarc=p;
		G.vertices[j].firstarc=q;

		getchar();
	}
}

//���ͼ���ڽӱ�
void PrintALGraph(ALGraph G)
{
	int i;
	ArcNode *p;
	printf("�±�   Ԫ��ֵ   �ߵ���Ϣ\n");
	for(i=0; i<G.vexnum; i++)
	{
		printf("%d\t%c\t",i,G.vertices[i].data);
		p=G.vertices[i].firstarc;
		while(p)
		{
			printf("->%d ",p->adjvex);
			p=p->nextarc;
		}
		printf("\n");
	}	
}

//��ȱ����ڽӱ�
void DFSALGraph(ALGraph G,int i)
{
	if (i >= G.vexnum) return ;
	printf("%d ", i); visited[i] = 1;
	VNode p = G.vertices[i];
	for (ArcNode *j = p.firstarc; j != NULL; j = j->nextarc) {
		int v = j->adjvex;
		if (!visited[v]) DFSALGraph(G, v);
	}
}

//��ȱ����ڽӱ�
void BFSALGraph(ALGraph G,int i)
{
	queue<int>q;
	q.push(i); visited[i] = 1;
	while (!q.empty()) {
		int u = q.front(); printf("%d ", u);
		VNode p = G.vertices[u];
		for (ArcNode *j = p.firstarc; j != NULL; j = j->nextarc) {
			int v = j->adjvex;
			if (!visited[v]) visited[v] = 1, q.push(v);
		}q.pop();
	}
}

//�ڽӾ���ת��Ϊ�ڽӱ�
void GraphChange(MGraph MG, ALGraph &ALG)
{
	int i,j;
	ALG.vexnum=MG.vexnum;
	ALG.arcnum=MG.arcnum;
	for(i=0;i<MG.vexnum;i++)
	{
		ALG.vertices[i].data=MG.vexs[i];
		ALG.vertices[i].firstarc=NULL;
	}
	for(i=0; i<MG.vexnum; i++)
	{
		for(j=0; j<MG.vexnum; j++)
		{
			if(MG.arcs[i][j]!=0)
			{
				ArcNode *p=(ArcNode*)malloc(sizeof(ArcNode));
				p->adjvex=j;
				p->nextarc=ALG.vertices[i].firstarc;
				ALG.vertices[i].firstarc=p;
			}
		}
	}
}

//������
int main()
{
	int i,v;
	MGraph MG;
	ALGraph ALG;
	int select;

	while(1)
	{
		printf("\n");
		printf("1.����ͼ(�ڽӾ���洢)\n");
		printf("2.��ȱ���(�ڽӾ���)\n");
		printf("3.��ȱ���(�ڽӾ���)\n");
		printf("4.����ͼ(�ڽӱ�洢)\n");		
		printf("5.��ȱ���(�ڽӱ�)\n");
		printf("6.��ȱ���(�ڽӱ�)\n");
		printf("7.ͼ���ڽӾ���洢ת��Ϊ�ڽӱ�洢\n");
		printf("8.�˳�\n");

		printf("��ѡ��Ҫִ�еĲ���:");
		scanf("%d",&select);
		switch(select)
		{
		case 0:
			return 0;
		case 1:
			printf("\n����ͼ���ڽӾ���洢\n");
			CreateMGraph(MG);
			printf("\n���ͼ���ڽӾ���\n");
			PrintMGraph(MG);			
			break;
		case 2:			
			printf("\n������ȱ�������ʼ����λ��:");
			scanf("%d",&v);			
			for(i=0; i<MG.vexnum; i++)
				visited[i]=0;
			printf("��ȱ�������(�ڽӾ���): ");
			DFSMGraph(MG,v);
			printf("\n");
			break;
		case 3:	
			printf("\n�����ȱ�������ʼ����λ��:");
			scanf("%d",&v);			
			for(i=0; i<MG.vexnum; i++)
				visited[i]=0;
			printf("��ȱ�������(�ڽӾ���): ");					
			BFSMGraph(MG,v);
			printf("\n");
			break;
		case 4:
			printf("\n����ͼ���ڽӱ�洢\n");				
			CreateALGraph(ALG);
			printf("\n���ͼ���ڽӱ�\n");				
			PrintALGraph(ALG);
			break;		
		case 5:
			printf("\n������ȱ�������ʼ����λ��:");
			scanf("%d",&v);
			for(i=0; i<ALG.vexnum; i++)
				visited[i]=0;
			printf("��ȱ�������(�ڽӱ�):");			
			DFSALGraph(ALG,v);
			printf("\n");
			break;
		case 6:			
			printf("\n�����ȱ�������ʼ����λ��:");	
			scanf("%d",&v);	
			for(i=0; i<ALG.vexnum; i++)
				visited[i]=0;		
			printf("��ȱ�������(�ڽӱ�):");
			BFSALGraph(ALG,v);
			printf("\n");
			break;
		case 7:
			GraphChange(MG,ALG);
			printf("\n���ͼ���ڽӱ�\n");
			PrintALGraph(ALG);
			printf("\n");
			break;
		case 8:
			return 0;	
		default:
			printf("��ȷ��ѡ����!\n");
		}
	}
	return 0;
}
