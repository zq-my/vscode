#include <stdio.h> 
int amount,Board[100][100];
void Cover(int tr,int tc,int dr,int dc,int size)
{ 
  int s,t;
	if(size<2)
     return ;
	amount++;
	t=amount;
	s=size/2;
	if(dr<tr+s&&dc<tc+s)
		//��ȱ�����Ͻ�
	{
		//�����м�λ��
		Board[tr+s-1][tc+s]=t;
		Board[tr+s][tc+s-1]=t;
		Board[tr+s][tc+s]=t;
		Cover(tr,tc,dr,dc,s);
		//��������
		Cover(tr,tc+s,tr+s-1,tc+s,s);
		//��������
		Cover(tr+s,tc,tr+s,tc+s-1,s);
		//��������
		Cover(tr+s,tc+s,tr+s,tc+s,s);
		//��������
	}
	else if(dr<tr+s&&dc>=tc+s)
		//��ȱ�����Ͻ�
	{
		Board[tr+s-1][tc+s-1]=t;
		Board[tr+s][tc+s-1]=t;
		Board[tr+s][tc+s]=t;
		Cover(tr,tc,tr+s-1,tc+s-1,s);
		Cover(tr,tc+s,dr,dc,s);
		Cover(tr+s,tc,tr+s,tc+s-1,s);
		Cover(tr+s,tc+s,tr+s,tc+s,s);
	}
	else if(dr>=tr+s&&dc<tc+s)
		//��ȱ������
	{
		Board[tr+s-1][tc+s-1]=t;
		Board[tr+s-1][tc+s]=t;
		Board[tr+s][tc+s]=t;
		Cover(tr,tc,tr+s-1,tc+s-1,s);
		Cover(tr,tc+s,tr+s-1,tc+s,s);
		Cover(tr+s,tc,dr,dc,s);
		Cover(tr+s,tc+s,tr+s,tc+s,s);
	}
	else
	{
		Board[tr+s-1][tc+s-1]=t;
		Board[tr+s-1][tc+s]=t;
		Board[tr+s][tc+s-1]=t;
		Cover(tr,tc,tr+s-1,tc+s-1,s);
		Cover(tr,tc+s,tr+s-1,tc+s,s);
		Cover(tr+s,tc,tr+s,tc+s-1,s);
		Cover(tr+s,tc+s,dr,dc,s);
	}
}

void Print(int s)
{
	for(int i=1; i<=s; i++)
	{
		for(int j=1; j<=s; j++)
		printf("%5d ",Board[i][j]);
		printf("\n");
	}

}

int main()
{
	int s=1,k,x,y;
	printf("����2��ȱ���̵Ĺ�ģ:2^k,k=");
	scanf("%d",&k);
	for(int i=1; i<=k; i++)
		s*=2;
	printf("�������̲�ȱλ��(x,y):");
	scanf("%d%d",&x,&y);
	Board[x][y]=0;
	Cover(1,1,x,y,s);
	Print(s);
	return
	    0;
}






